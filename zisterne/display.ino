  //***********************
  //LCD Setup
  //***********************
  void ladeLCDdisplay() {
    Wire.begin(12, 13); //SDA-D6, SCL-D7      // LCD Setup (bei beiden LCD Displays gleich)
  
    // *******************Boot mit LAN-Info für 1602 Display**************************
    if (cfg.data_display ==1) {
      timer.setInterval(1000);
      lcd.begin();
      lcd.backlight();
      lcd.print(cfg.SSID);
      lcd.setCursor(0, 1);
      lcd.print("Verbinde...");
      lcd.setCursor(0, 1);
      WiFi.mode ( WIFI_STA );
      WiFi.begin ( cfg.SSID, cfg.password );
    }
    // Warte kurz auf Verbindung
    while ( WiFi.status() != WL_CONNECTED ) {
      delay (2500);
      lcd.print(WiFi.localIP());
      delay (5000);
      lcd.noBacklight();
      backlstatus = 0;
    }
    // *******************Boot mit LAN-Info für 1604 Display**************************
    if (cfg.data_display ==2) {
      timer.setInterval(1000);
      lcd.begin();
      lcd.backlight();
      lcd.setCursor(0, 0);
      lcd.print("Ihre SSID:");
      lcd.setCursor(0, 1);
      lcd.print(cfg.SSID);
      lcd.setCursor(0, 2);
      lcd.print("Verbinde...");
      lcd.setCursor(0, 2);
      WiFi.mode ( WIFI_STA );
      WiFi.begin ( cfg.SSID, cfg.password );
    }
    while ( WiFi.status() != WL_CONNECTED ) {   // Warte kurz auf Verbindung
      delay (2500);
      lcd.print("Ihre IP Adresse:");
      lcd.setCursor(0, 3);
      lcd.print(WiFi.localIP());
      delay (5000);
      lcd.noBacklight();
    }
  }
  
 void ladeOLEDdisplay() {
 //*******************************Initialisierung und DEBUG OLED************************************
  int rc;
   rc = oledInit(&ssoled, OLED_128x64, -1, 0, 0, 0, 12, 13, -1, 400000L); // OLED settings
    if (rc != OLED_NOT_FOUND)
    {
        char *msgs[] =
        {
          (char *)"SSD1306 an 0x3C",
          (char *)"SSD1306 an 0x3D",
          (char *)"SH1106 an 0x3C",
          (char *)"SH1106 an 0x3D"
        };
    if (DEBUG) Serial.println(msgs[rc]);
        oledFill(&ssoled, 0, 1);
        oledWriteString(&ssoled, 0, 0, 0, (char *)"OLED gefunden:", FONT_NORMAL, 0, 1);
        oledWriteString(&ssoled, 0, 10, 2, msgs[rc], FONT_NORMAL, 0, 1);
        delay(5000);
    }
   oledSetBackBuffer(&ssoled, ucBackBuffer);                         // OLED Puffer wird gesetzt   
   // *******************Boot mit LAN-Info für OLED Display**************************
   if (cfg.data_display ==3) {
   oledFill(&ssoled, 0, 1);
   oledWriteString(&ssoled, 0,0,0,(char *)"Systemstart:", FONT_NORMAL, 0, 1);
   oledWriteString(&ssoled, 0,0,2,(char *)"Ihre SSID:", FONT_NORMAL, 0, 1);
   oledWriteString(&ssoled, 0,0,3,cfg.SSID, FONT_NORMAL, 0, 1);
   oledWriteString(&ssoled, 0,0,5,(char *)"Verbinde...", FONT_NORMAL, 0, 1);
   WiFi.mode ( WIFI_STA );
   WiFi.begin ( cfg.SSID, cfg.password );
   }
   while ( WiFi.status() != WL_CONNECTED ) {  // Warte kurz auf Verbindung
   delay (2500);
   char ipbuffer [50];
   IPAddress ip = WiFi.localIP();
   sprintf(ipbuffer, "%u.%u.%u.%u", ip[0], ip[1], ip[2], ip[3]);
   oledWriteString(&ssoled, 0,0,5,(char *)"Ihre IP-Adresse:", FONT_NORMAL, 0, 1);
   oledWriteString(&ssoled, 0,0,6,ipbuffer, FONT_NORMAL, 0, 1);
   delay (6000);
   oledFill(&ssoled, 0, 1);
   }
    }  
//******************************************************** 
// Ab hier die LOOP Schleifen
//********************************************************
  //***********************
  //LCD mit Tastersteuerung für 1602 Display
  //***********************
 void loop1602() { 
    if ( millis() - displayMicros >= 5000 ) {
    displayMicros = millis();
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print(volumen);
    lcd.print( " Liter,");
    lcd.setCursor(0,1);
    lcd.print(fuellstand);
    lcd.print( " % voll");
    }
    
    if ((backlstatus == 0) && (digitalRead(taster) == HIGH)) {
    lcd.backlight();
    backlstatus = 1;
    delay (300);                                                 //gegen Tastenprellen 
    }  
    unsigned long tasterMicros = millis();
    if (tasterMicros - previousMicros >= 90000 ) {
    previousMicros = tasterMicros;
    lcd.noBacklight();
    }
    if ((backlstatus == 1) && (digitalRead(taster) == HIGH)) {
    lcd.noBacklight();
    backlstatus = 0;
    delay (300);                                                 //gegen Tastenprellen
    }
      }

//***********************
//LCD mit Tastersteuerung für 1604 Display
//***********************
 void loop1604() { 
    if ( millis() - displayMicros >= 5000 ) {
    displayMicros = millis();
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print( "F\365llstand:"); // Ueberschrift
    lcd.setCursor(0,1);
    lcd.print(volumen);
    lcd.print( " Liter,");
    lcd.setCursor(0,3);
    lcd.print(fuellstand);
    lcd.print( " % voll");
    }
    
    if ((backlstatus == 0) && (digitalRead(taster) == HIGH)) {
     lcd.backlight();
     backlstatus = 1;
     delay (300);                                                  //gegen Tastenprellen
     }  
     unsigned long tasterMicros = millis();
     if (tasterMicros - previousMicros >= 180000 ) {
     previousMicros = tasterMicros;
     lcd.noBacklight();
     }
     if ((backlstatus == 1) && (digitalRead(taster) == HIGH)) {
     lcd.noBacklight();
     backlstatus = 0;
     delay (300);                                                 //gegen Tastenprellen
     }
      }
//***********************
// OLED Display
//***********************
  void loopOLED() { 
      if (((backlstatus == 0) && (digitalRead(taster) == HIGH)) || (backlstatus == 1)){ 
       backlstatus = 1;
       delay (300);
       if ( millis() - displayMicros >= 5000 ) {
       displayMicros = millis();
       oledFill(&ssoled, 0, 1);
       char Volumen[10];
       sprintf(Volumen,"%.2f l", volumen);
       char Fuellstand[10];
       sprintf(Fuellstand,"%.2f%%", fuellstand);
       oledWriteString(&ssoled, 0,0,0,(char *)"Fuellstand:" , FONT_NORMAL, 0, 1);
       oledWriteString(&ssoled, 0,60,3,Volumen, FONT_SMALL, 0, 1); 
       oledWriteString(&ssoled, 0,60,5,Fuellstand, FONT_SMALL, 0, 1);
       //*********************Grafik **********************
       rest = map(fuellstand, 0, 100, 62, 13);                // Hoehe des Balkens ermitteln
       oledRectangle(&ssoled, (1), (13), (45), (62), 1, 0);   // aeussere Linie zeichnen
       oledRectangle(&ssoled, (1), (rest), (45), (62), 1, 1); // Fuellbalken
       oledDumpBuffer(&ssoled, NULL);
       }
      
       unsigned long tasterMicros = millis();
      if (tasterMicros - previousMicros >= 180000 ) {
       previousMicros = tasterMicros;
       oledFill(&ssoled, 0, 1);
       backlstatus = 0;
       }
      if ((backlstatus == 1) && (digitalRead(taster) == HIGH)) {
       oledFill(&ssoled, 0, 1);
       backlstatus = 0;
       delay (300);
      }
      }
}
