//********************************************************
// Ruft per HTTP-Post eine Webseite auf und uebergibt
// verschiedene Werte per Argument
//********************************************************
void eigene_api() {
  float vcc = ESP.getVcc() / 1000.0;
  currentMillisEigen = millis();
  if (currentMillisEigen - startMillisEigen >= (cfg.data_eigenapi_intervall * 1000)) {
    
    startMillisEigen = currentMillisEigen;
    String url = cfg.data_eigenapi_pfad;
    
    //hier die "Variablen" in der URL ersetzen
    url.replace("_abstand", String(abstand));
    url.replace("_fuellstand", String(fuellstand));

    //und am Ende noch die Spannung anhaengen
    url += "&vcc=";
    url += vcc;

    if(DEBUG) {
      Serial.println("");
      Serial.print("URL-Anfrage zu eigener API: ");
      Serial.println(url);
    }
    
    WiFiClient client;
    const int httpPort = cfg.data_eigenapi_port;
    const char* datahost = cfg.data_eigenapi_server;
    if (!client.connect(datahost, httpPort)) {
      if(DEBUG) {
        Serial.println(F(" Fehler beim Verbinden mit Server"));
      }
      return;
    }
    client.print(String("GET ") + url + " HTTP/1.1\r\n" +
                 "Host: " + datahost + "\r\n" + 
                 "Verbindung: close\r\n\r\n");
    unsigned long timeout = millis();
    while (client.available() == 0) {
      if (millis() - timeout > 5000) {
        if(DEBUG) {
          Serial.println("Timeout bei Verbindung mit Server");
        }
        client.stop();
        return;
      }
    }
     
    // Lese alle Daten aus der Antwort des Servers
    while(client.available()){
      String line = client.readStringUntil('\r');
      Serial.print(line);
    }

    eigenapi_anz_aufrufe++;

    if(DEBUG) {
      Serial.print(F("Verbindung zu '"));
      Serial.print(datahost);
      Serial.print(" ");
      Serial.print(httpPort);
      Serial.println(F("' beendet."));
    }
    client.stop();
  }
  
}
