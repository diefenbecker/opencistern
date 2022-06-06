#include <ESP8266WiFi.h>
#include <ESP8266mDNS.h>
#include <ESP8266WebServer.h>
#include <WiFiClient.h>
#include <Ticker.h>
#include <EEPROM.h>
#include <ESP8266HTTPClient.h>
#include <ESP8266httpUpdate.h>
#include <LiquidCrystal_I2C.h>   //für LCD
#include <ss_oled.h>             //für OLED
#include <Wire.h>
#include <PubSubClient.h>
#include <NTPClient.h>
#include <WiFiUdp.h>
#include <SimpleTimer.h>
#include <Pushover.h>
//#include <sendemail.h>
#include "myTypes.h"
#include "DHT.h"
//#include "Adafruit_VL53L0X.h"
#include <VL53L0X.h>              //Pololu-Lib
#include "SparkFun_VL53L1X.h"

extern "C" {
  #include "user_interface.h"
}

//********************************************************
// Die Sensoren
//********************************************************
//HC-SR04
#define TRIGGER   4
#define ECHO      5
#define MAX_DIST  300

//VL53L0X
VL53L0X l0x_sensor;

//VL53L1X
SFEVL53L1X l1x_sensor;


//********************************************************
// Variablen für Abstandsmessung
//********************************************************
int abstand;
float fuellstand;
float volumen;
int volumen_max;
int var_abstand_sensor_wasser_min = 0;
int var_abstand_sensor_wasser_max = 0;
int dauer;
int rest;
unsigned long currentMillisAbstand;
unsigned long startMillisAbstand;

//*********************
// Temperatursensor
//*********************
#define DHTPIN  14 //D5
#define DHTTYPE DHT22
DHT dht(DHTPIN, DHTTYPE); 
float humidity;
float temperature;
unsigned long startMillisTemp;
unsigned long currentMillisTemp;


//********************************************************
// Konfiguration der Displays
// Deklaration der I2C Adresse, anz.Zeichen, anz.Zeilen
//********************************************************
SimpleTimer timer;
LiquidCrystal_I2C lcd(0x27, 16, 4);              // Konfiguration der LCD-Displays
static uint8_t ucBackBuffer[1025];               // Puffergroeße fuer OLED
SSOLED ssoled;                                   // benoetigt fuer OLED

//Taster fuer Display
//int sensor = 14; // D5 VCC Sensor
int taster = 15; // D8 für Taster
int tasterstatus = 0;
int previousMicros = 0;
int displayMicros = 0;
int backlstatus = 0;

//********************************************************
// Relais an D4
//********************************************************
const int relaisPIN = 2;  //D4
unsigned long startMillisRelais;
unsigned long currentMillisRelais;

//********************************************************
// Relais an D3
//********************************************************
const int relais2PIN = 2;  //D3
unsigned long startMillisRelais2;
unsigned long currentMillisRelais2;

//********************************************************
// Debug-Ausgabe aktivieren (true/false)
//********************************************************
#define DEBUG true

//********************************************************
// Variablen für zeitgesteuerte Aufrufe der eigenen API
//********************************************************+
unsigned long startMillisEigen;
unsigned long currentMillisEigen;
int eigenapi_anz_aufrufe = 0;
int webapi_anz_aufrufe = 0;

//********************************************************
// OTA-Variablen
//********************************************************
const char* fw_url = "http://www.bubux.de/heimautomatisierung/ota/zisterne/";
int ota_zeit = 3600;
unsigned long startMillisOta;
unsigned long currentMillisOta;

//********************************************************
// MQTT
//********************************************************
unsigned long startMillisMQTT;
unsigned long currentMillisMQTT;
void callback(char* topic, byte* payload, unsigned int length) {
  // Eingehende Nachricht verarbeiten
}

//********************************************************
// WEBAPI-Variablen
//********************************************************
int webapi_zeit = 3600;
unsigned long startMillisWeb;
unsigned long currentMillisWeb;

//********************************************************
// Zeit per NTP holen
//********************************************************
WiFiUDP ntpUDP;
unsigned long currentMillisNTP;
unsigned long startMillisNTP;
const long utcOffsetInSeconds = 7200;
NTPClient timeClient(ntpUDP, "pool.ntp.org", utcOffsetInSeconds);

//********************************************************
// Display refresh
//********************************************************
unsigned long startMillisDisplay;
unsigned long currentMillisDisplay;

//********************************************************
// Grundsätzliche Einstellungen
//********************************************************
const int fw_version = 1030;
String anwendungsname = "Zisternenf&uuml;llstand";
String apSSID = "WLAN-Zisterne";
const int cfgStart = 0;
const int setupTimeOutLimit = 300;        // Zeit die AP bestehen bleibt. War mal 600, jetzt nur noch 5 Minuten

ESP8266WebServer server(80);
WiFiClient wifiClient;
Ticker setupTimeOut_timer;                // Timer um AP zu resetten
configData_t cfg;

//Prüfung ob der EEPROM gelöscht werden soll...aktuell nicht genutzt
int eepromToClear = 0;

//********************************************************
// Globale Variablen
//********************************************************
int webtypeGlob;

uint8_t mac[6];
String stationList = "";
int setupTimeOut = 0;                     // Timeout für AP initialisieren

String macAdresse;
String ipAdresse;
String myHostname;

ADC_MODE(ADC_VCC);
uint32_t freeheap = system_get_free_heap_size();


//Fuer die taegliche Ausfuehrung
bool gesendet_pushover = false;
bool gesendet_mail = false;

//********************************************************
// SETUP
//********************************************************
void setup() {
  Wire.begin();
  
  Serial.begin(115200);
  delay(3000);
  Serial.println("Auf gehts...");

  //Lade Konfiguration aus EEPROM
  ladekonfig();

  if (cfg.data_sensorname!="") {
    Serial.print("Anwendungsname setzen: ");
    anwendungsname = cfg.data_sensorname;
    Serial.println(anwendungsname);
  }

  Serial.print("Sensor auswaehlen: ");
  //Serial.print(cfg.data_zisterne_sensor);
  Serial.print(" ");
  if (cfg.data_zisterne_sensor == 0) {
    Serial.println("Kein Sensor ausgewaehlt");
  }
  //Anschluss HC SR04
  if (cfg.data_zisterne_sensor == 1) {
    Serial.println("HC-SR04 ausgewaehlt");
    pinMode(TRIGGER, OUTPUT);
    pinMode(ECHO, INPUT);
    pinMode(taster, INPUT);
    //pinMode(sensor, OUTPUT);    
  }
  //VL53L0X
  if (cfg.data_zisterne_sensor == 2) {
    Serial.println("VL53L0X ausgewaehlt");
    
    //Pololu
    l0x_sensor.init();
    l0x_sensor.setTimeout(500);

    if (cfg.data_distance_mode_vl53l0x == 1) {
      Serial.println("Long-Range gesetzt");
      // lower the return signal rate limit (default is 0.25 MCPS)
      l0x_sensor.setSignalRateLimit(0.1);
      // increase laser pulse periods (defaults are 14 and 10 PCLKs)
      l0x_sensor.setVcselPulsePeriod(VL53L0X::VcselPeriodPreRange, 18);
      l0x_sensor.setVcselPulsePeriod(VL53L0X::VcselPeriodFinalRange, 14);
    } else {
      Serial.println("Short-Range gesetzt (default)");
    }

    //High accuracy
    if (cfg.data_accuracy_mode_vl53l0x == 1) {      
      l0x_sensor.setMeasurementTimingBudget(200000);
      Serial.println("Timing gesetzt auf High-Accuracy");
    }
    //High speed
    if (cfg.data_accuracy_mode_vl53l0x == 2) {
      l0x_sensor.setMeasurementTimingBudget(20000);
      Serial.println("Timing gesetzt auf High-Speed");
    }
    //Default
    if (cfg.data_accuracy_mode_vl53l0x == 0) {            
      l0x_sensor.setMeasurementTimingBudget(33000);
      Serial.println("Timing gesetzt auf Default");
    }
    

  }
  //VL53L1X
  if (cfg.data_zisterne_sensor == 3) {
    Serial.println("VL53L1X ausgewaehlt");
    if (l1x_sensor.begin() == true)
    {
      Serial.println("Sensor gefunden");
    }

    if (cfg.data_distance_mode_vl53l1x == 0) {
      l1x_sensor.setDistanceModeShort();
      Serial.println("Distanzmodus: Short");
    }
    if (cfg.data_distance_mode_vl53l1x == 1) {
      l1x_sensor.setDistanceModeLong();
      Serial.println("Distanzmodus: Long");
    }
    
  }
  
  //Zeit merken um EigenAPI, WebAPI und OTA zeitgesteuert aufzurufen
  //auch Intervall zum Refresh von Display und NTP
  startMillisEigen = millis();
  startMillisWeb = millis();
  startMillisOta = millis();
  startMillisMQTT = millis();
  startMillisDisplay = millis();
  startMillisNTP = millis();
  startMillisTemp = millis();
  startMillisAbstand = millis();

  //MAC auslesen und in Variablen schreiben
  WiFi.macAddress(mac);
  macAdresse = macToStr(mac);
  macAdresse.toUpperCase();
  myHostname = macToHostname(mac);

  //Starte WLAN-Verbindung
  starteWLAN();

  //NTP
  //NTPClient timeClient(ntpUDP, "pool.ntp.org", utcOffsetInSeconds);
  timeClient.begin();   //Timer starten
  timeClient.update();  //Zeit mit NTP updaten
  if (DEBUG) Serial.println("Initialales NTP-Update erfolgt");

  //Starte Display
  if ((cfg.data_display == 1) || (cfg.data_display == 2)){
    if (DEBUG) Serial.println("Initialisiere LCD Display");
    ladeLCDdisplay();
  }
  if (cfg.data_display == 3) {
    if (DEBUG) Serial.println("Initialisiere OLED Display");
    ladeOLEDdisplay();
  }

  //Starte Temperaturmessung
  dht.begin();
  //einmal initial messen
  humidity = dht.readHumidity();
  Serial.println(humidity);
  // Lese Temperatur
  temperature = dht.readTemperature();
  Serial.println(temperature);

  //Ausgang D4
  pinMode(relaisPIN, OUTPUT);
  digitalWrite(relaisPIN,LOW);
  //Serial.println("LED Test..");
  //digitalWrite(relaisPIN,HIGH);

  //Ausgang D3
  //pinMode(relais2PIN, OUTPUT);
  //digitalWrite(relais2PIN,LOW);
  
}

//********************************************************
// LOOP
//********************************************************
void loop() {

  //**********************
  //Status für Sensorpower
  //**********************
  //if (cfg.data_senson == 1) {
  //  digitalWrite(sensor, HIGH);
  //}
  //else {
  //  digitalWrite (sensor, LOW);
  //}

  //********************
  //Sensordaten auslesen
  //********************
  //alle 2 Sekunden Abstand messen
  currentMillisAbstand = millis();    
  if (currentMillisAbstand - startMillisAbstand >= 2000) {    
    startMillisAbstand = currentMillisAbstand;
    looprechnen();
  }

  //Temperatursensor
  if (cfg.data_temperatur_enable == 1) {

    //alle 60 Sekunden Temperatur messen
    currentMillisTemp = millis();    
    if (currentMillisTemp - startMillisTemp >= 60000) {    
      startMillisTemp = currentMillisTemp;
      Serial.println("Temperaturmessung");
   
      //DHT Sensor
      if (cfg.data_temperatur == 1) {
        // Lese Luftfeuchte
        humidity = dht.readHumidity();
        Serial.println(humidity);
        // Lese Temperatur
        temperature = dht.readTemperature();
        Serial.println(temperature);
      }
  
      //BME Sensor
      if (cfg.data_temperatur == 2) {
        //noch nix zu tun
      }
    }
  }
  
  //*****************************
  //Daten an eigene API übergeben
  //*****************************
  if (cfg.data_eigenapi_check == 1) {
    eigene_api();
  }

  //**************************
  //Daten an Web API übergeben
  //**************************
  if (cfg.data_webapi_check == 1) {
    web_api();
  }

  //**************************
  //Relais ggf. schalten
  //**************************
  if (cfg.data_relais_enable == 1) {
    relais();
  }

  //**************************
  //Relais2 ggf. schalten
  //**************************
  //if (cfg.data_relais2_enable == 1) {
  //  relais2();
  //}
 
  //**************************
  //Display setzen
  //**************************
  if ((cfg.data_display == 1) && (cfg.data_display_enable == 1)) {
    loop1602();
  }
  
  if ((cfg.data_display == 2) && (cfg.data_display_enable == 1)) {
    loop1604();
  }
  
  if ((cfg.data_display == 3) && (cfg.data_display_enable == 1)) {
    loopOLED();
  }
  
  //**************************
  //OTA-Update prüfen
  //**************************
  if (cfg.data_ota_check == 1) {
    checkForUpdates();
  }

  //**************************
  //MQTT
  //**************************
  if (cfg.data_mqtt_check == 1) {
    mqtt_api();
  }

  if (eepromToClear == 1) {
    if (DEBUG) Serial.println("Flag zur Löschung des EEPROM gesetzt!");
    eraseConfig();
    delay(1000);
    eepromToClear = 0;
    system_restart();
  }

  //******************
  //WLAN-Status prüfen
  //******************
  if (WiFi.status() == WL_CONNECTED || webtypeGlob == 1) {
    server.handleClient();
    delay(10);
  } else {
    if (DEBUG) Serial.println("WLAN nicht verbunden");
    delay(1000);
    starteWLAN();
  }

  //******************
  //NTP
  //******************
  currentMillisNTP = millis();
  //Alle 30 Minuten refreshen
  if (currentMillisNTP - startMillisNTP >= (1800 * 1000)) {
    startMillisNTP = currentMillisNTP;
    timeClient.update();
    if (DEBUG) Serial.println("NTP-Update erfolgt");
  }

  //********************************************
  //Taegliche Ausfuehrung zur gewaehlten Uhrzeit
  //********************************************
  if (cfg.data_pushover_check == 1) {
    if (timeClient.getHours() == cfg.data_pushover_zeit && gesendet_pushover==false) {
      Pushover pushover = Pushover(cfg.data_pushover_apptoken,cfg.data_pushover_usertoken, UNSAFE);
      pushover.setTitle("Zisterne");
      pushover.setMessage("Füllstand um " +(timeClient.getFormattedTime()) + " Uhr " + String(fuellstand) + "%25");
      if (DEBUG) Serial.println("Pushover-Nachricht gesendet");
      Serial.println(pushover.send());
      delay(300);
      gesendet_pushover=true;
    }
    if (timeClient.getHours() != cfg.data_pushover_zeit) {
      gesendet_pushover=false;
    }
  }

//  if (cfg.data_mail_check == 1) {
//    if (timeClient.getFormattedTime().substring(0,2) == (String)cfg.data_mail_zeit && gesendet_mail==false) {
//      //Testweise
//      SendEmail e("mailserver", 587, "benutzer", "passwort", 5000, true);
//      e.send("", "", "Zisterne", "Testmail von der Zisterne"); 
//      gesendet_mail=true;
//    }
//  
//    if (timeClient.getFormattedTime().substring(0,2) != (String)cfg.data_mail_zeit) {
//      gesendet_mail=false;
//    }
//  }

}
