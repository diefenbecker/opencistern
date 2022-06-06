//********************************************************
// Ruft per HTTP-Post eine Webseite auf und übergibt
// verschiedene Werte per Argument
//********************************************************
void web_api() {
  currentMillisWeb = millis();
  if (currentMillisWeb - startMillisWeb >= (webapi_zeit * 1000)) {
    startMillisWeb = currentMillisWeb;
    
    String url = "/heimautomatisierung/zisternen.php";
    url += "?abstand=";
    url += abstand;
    url += "&fuellstand=";
    url += fuellstand;
    url += "&mac=";
    url += macAdresse;
    url += "&ip=";
    url += ipAdresse;
    url += "&fw=";
    url += fw_version;
    
    if(DEBUG) {
      Serial.println("");
      Serial.print("URL-Anfrage zu Web API: ");
      Serial.println(url);
    }
    
    WiFiClient client;
    const int httpPort = 80;
    const char* datahost = "www.bubux.de";
    if (!client.connect(datahost, httpPort)) {
      if(DEBUG) {
        Serial.println(F(" Fehler beim Verbinden mit Server"));
      }
      return;
    }
    client.print(String("GET ") + url + " HTTP/1.1\r\n" +
                 "Host: " + datahost + "\r\n" + 
                 "Connection: close\r\n\r\n");
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

    webapi_anz_aufrufe++;

    if(DEBUG) {
      Serial.println(F("Verbindung zu '"));
      Serial.print(datahost);
      Serial.print(" ");
      Serial.print(httpPort);
      Serial.println(F("' beendet."));
    }
    client.stop();
  }
  
}
