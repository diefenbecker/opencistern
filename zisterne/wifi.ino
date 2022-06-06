//********************************************************
// WIFI Funktionen
//********************************************************

void starteWLAN() {
  Serial.println("Starte WLAN-Verbindung");
  if ( sizeof(cfg.SSID) > 1 ) {
    WiFi.disconnect();
    delay(100);
    WiFi.mode(WIFI_STA);
    Serial.print("Verbinde mit WLAN (per STA): ");
    Serial.println(cfg.SSID);
    WiFi.begin(cfg.SSID, cfg.password);
    if ( checkWifi() == 20 ) {
      launchWeb(0);
      return;
    }
  }
  //AP aufbauen wenn keine Verbindung zustande kam
  Serial.println("Öffne Access-Point");
  setupAP();
}

//********************************************************
int checkWifi(void) {
  //Prüfe ob WLAN-Verbindung besteht
  int c = 0;
  int zeitWLANSuche = 60;
  Serial.print("Prüfe WLAN-Verbindung...");
  while ( c < zeitWLANSuche ) {
    if (WiFi.status() == WL_CONNECTED) {
      return (20);
    }
    delay(500);
    Serial.print(".");
    c++;
  }
  Serial.println("\nWiFi Zeitüberschreitung bei Verbindung");
  return (10);
}

//********************************************************
void launchWeb(int webtype) {
  // Starte den Webserver: 1=AccessPoint, 0=Normaler Webserver
  Serial.println("\nWLAN verbinden");
  //**************
  // 1=AP aufbauen
  //**************
  if (webtype == 1) {
    ipAdresse = ipAddress(1);
    Serial.print("IP: "); Serial.println(ipAdresse);
    server.on("/", webHandleConfig);                                // Zeige Konfigseite
    server.on("/save", webHandleConfigSave);                        // Speichere Konfigdaten
  //*******************************
  // 0=Normalen Webserver erstellen
  //*******************************
  } else {                                                          
    // DNS Hostnamen erstellen solange Sensor Client im WIFI-Netz ist
    if (!MDNS.begin((char*) myHostname.c_str())) {
      Serial.println("Fehler beim Erstellen des MDNS responder!");
      //while (1) {
      //  delay(1000);
      //  Serial.println("Starte Check...");
      //  checkWifi();
      //}
    } else {
      Serial.println("MDNS responder gestartet: " + myHostname);
    }
    ipAdresse = ipAddress(0);
    Serial.print("MAC-Adresse: "); Serial.println(macAdresse);
    Serial.print("IP-Adresse: "); Serial.println(ipAdresse);
    Serial.print("Hostname: "); Serial.println(myHostname);

    server.on("/", webHandleRoot);                          // Starseite anzeigen
    server.on("/cfg", webHandleConfig);                     // Konfigurationsseite anzeigen
    server.on("/json", webHandleJSON);                      // Messwerte per JSON anzeigen
    server.on("/save", webHandleConfigSave);                // Infoseite zur Speicherung anzeigen
    server.on("/boot", webHandleBoot);                      // Sensor rebooten
    server.on("/pushtest", webHandlePushTest);              // Pushover testen
    server.on("/mailtest", webHandleMailTest);              // Mailversand testen
    server.on("/relais", webHandleRelais);                  // Relais schalten
  }
  server.begin();
  Serial.println("Webserver gestartet");
  webtypeGlob = webtype;                                     
}

//********************************************************
void setupAP(void) {
  // Erstelle AP mit eigenen WIFI.-Netzwerk zur konfiguration des Sensors
  WiFi.mode(WIFI_STA);
  WiFi.disconnect();
  delay(100);
  int n = WiFi.scanNetworks();                              // Scanne WLAN-Netzwerke
  Serial.println("Verfügare WLANs durchsucht");
  if (n == 0) {                                             // Keine WLAN-Netze gefunden
    Serial.println("Keine WLAN-Netzwerke gefunden");
    stationList = "<b>Keine WLAN-Netzwerke gefunden!</b>";
  } else {                                                  // WLAN-Netze gefunden
    Serial.print(n);
    Serial.println("WLAN Netzwerke gefunden:");
    stationList = "<ul>";
    for (int i = 0; i < n; ++i)
    {
      // Anzeigen der SSID der gefundenen Netzwerke
      Serial.print(i + 1);
      Serial.print(": ");
      Serial.print(WiFi.SSID(i));
      Serial.print(" (");
      Serial.print(WiFi.RSSI(i));
      Serial.print(" dB)");
      Serial.println((WiFi.encryptionType(i) == ENC_TYPE_NONE) ? " (Offen)" : "*");

      // Anzeigen der SSID der gefundenen Netzwerke
      stationList += "<td colspan=2>";
      stationList += i + 1;
      stationList += ": ";
      stationList += WiFi.SSID(i);
      stationList += " (";
      stationList += WiFi.RSSI(i);
      stationList += " dB)";
      stationList += (WiFi.encryptionType(i) == ENC_TYPE_NONE) ? " (Offen)" : "*";
      stationList += "</td>";
      delay(10);
    }
    stationList += "</ul>";
  }
  Serial.println();
  WiFi.disconnect();
  delay(100);
  WiFi.mode(WIFI_AP);

  WiFi.softAP((char*) apSSID.c_str());
  WiFi.begin((char*) apSSID.c_str());
  Serial.print("Access point (AP) mit Namen: ");
  Serial.println(apSSID); 
  Serial.print("gestartet");
  setupTimeOut_timer.attach(1, setupTimeOutCount);
  launchWeb(1);
}

//********************************************************
