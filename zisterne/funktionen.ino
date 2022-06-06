//********************************************************
void setupTimeOutCount()
//Prüft ob der AP zu lange läuft. Sensor wird ggf. resettet
{
  if (setupTimeOut >= setupTimeOutLimit) {
    Serial.println("Sensor-Restart weil AP zu lange geöffnet");
    system_restart();
  } else {
    //Serial.println("Ticker1");
    setupTimeOut++;
  }
}

//********************************************************
String macToStr(const uint8_t* mac)
//Erstellt einen String der MAC-Adresse
{
  String result;
  for (int i = 0; i < 6; ++i) {
    result += String(mac[i], 16);
    if (i < 5)
      result += ':';
  }
  return result;
}

//********************************************************
String macToHostname(const uint8_t* mac)
//Erstellt einen Hostnamen aus den letzten drei Stellen der MAC-Adresse
{
  String result = "ESP_";
  for (int i = 3; i < 6; ++i) {
    result += String(mac[i], 16);
  }
  result.toUpperCase();
  return result;
}

//********************************************************
String ipAddress(int Mode) {
  //Gibt die IP als String zurück
  IPAddress ip;
  if (Mode == 0) {
    ip = WiFi.localIP();
  }
  else
  { // WiFi access point
    ip = WiFi.softAPIP();
  }
  String ipStr = String(ip[0]) + '.' + String(ip[1]) + '.' + String(ip[2]) + '.' + String(ip[3]);
  return ipStr;
}

//********************************************************
String getHostname(int Mode) {
  // Gibt den Hostnamen als String zurück
  uint8_t mac[6];

  if (Mode == 0) {                            // WiFi Client
    WiFi.macAddress(mac);
  }
  else
  { // WiFi access point
    WiFi.softAPmacAddress(mac);
  }
  String hostname = macToHostname(mac);
  return hostname;
}
