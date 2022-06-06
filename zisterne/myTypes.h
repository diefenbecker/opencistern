#ifndef myTypes_h
#define myTypes_h

#include <WString.h>

typedef struct {
  int valid;                        

  //WLAN
  char SSID[31];
  char password[64];

  //Abstandssensor
  int data_abst_sen_boden;    
  int data_abst_sen_max; 

  //eigene API
  int data_eigenapi_check;
  char data_eigenapi_server[31];
  char data_eigenapi_pfad[81];
  int data_eigenapi_port;
  int data_eigenapi_intervall;
  int data_eigenapi_anz_aufrufe;

  //Web API
  int data_webapi_check;

  //OTA
  int data_ota_check;

  //MQTT
  int data_mqtt_check;
  char data_mqtt_server[31];
  char data_mqtt_benutzer[51];
  char data_mqtt_passwort[51];
  char data_mqtt_topic[51];
  int data_mqtt_intervall;

  //Zisternenform
  char data_zisterne_bauform[10];
  int data_zisterne_durchmesser;
  int data_zisterne_x;
  int data_zisterne_y;
  int data_zisterne_fl;
  int data_zisterne_vl;
  
  //Sonstiges
  int data_dezstellen_anzeige;
  int data_anzeige_liter_check;

  //weitere MQTT
  char data_mqtt_abstand_topic[51];
  int data_mqtt_port;  
  
  //Displays
  int data_display_enable;
  int data_display;

  //Sensoranschluss
  //int data_senson;

  //NTP
  char data_ntp_server[50];

  //Pushover
  int data_pushover_check;
  char data_pushover_apptoken[32];
  char data_pushover_usertoken[32];
  int data_pushover_zeit;

  //weitere Zisternenformen
  int data_zisterne_durchmesser_liegend;
  int data_zisterne_laenge_liegend;

  //Temperatursensoren
  int data_temperatur_enable;
  int data_temperatur;

  //weitere MQTTs
  char data_mqtt_temperature_topic[51];
  char data_mqtt_humidity_topic[51];
  char data_mqtt_liter_topic[51];

  //Sensortyp HC04 oder VL53L0X
  int data_zisterne_sensor;
  char data_sensorname[20];

  int data_distance_mode_vl53l1x;
  int data_distance_mode_vl53l0x;
  int data_accuracy_mode_vl53l0x;

  //externes Relais
  int data_relais_enable;
  int data_relais_an_krit;
  int data_relais_an_wert;
  int data_relais_aus_krit;
  int data_relais_aus_wert;

  //externes Relais2
  int data_relais2_enable;
  int data_relais2_tag;
  int data_relais2_dauer;
  int data_relais2_zeit;
  
  //***********************************************************************************
  //ab hier muessen neue Definition folgen damit alte Werte nicht ueberschrieben werden
  //***********************************************************************************

  //Mail (ist noch nicht aktiv)
  int data_mail_check;
  char data_mail_server[31];
  int data_mail_port;
  int data_mail_ssl;
  char data_mail_benutzer[31];
  char data_mail_passwort[31];
  int data_mail_zeit;
  
} configData_t;

#endif
