//**********************************************
// OTA-Update
//**********************************************
void checkForUpdates() {
  currentMillisOta = millis();
  if (currentMillisOta - startMillisOta >= (ota_zeit * 1000)) {
    
    startMillisOta = currentMillisOta;
  
    String mac = macAdresse;
    String fwURL = String( fw_url );
    fwURL.concat( mac );
    String fwVersionURL = fwURL;
    fwVersionURL.concat( ".version" );
    
    Serial.println( "Suche nach Firmware-Update..." );
    Serial.print( "MAC-Adresse: " );
    Serial.println( mac );
    Serial.print( "URL zur Firmware: " );
    Serial.println( fwVersionURL );
    
    HTTPClient httpClient;
    httpClient.begin( fwVersionURL );
    int httpCode = httpClient.GET();
    if( httpCode == 200 ) {
      String newFWVersion = httpClient.getString();
      
      Serial.print( "Aktuelle Firmware-Version: " );
      Serial.println( fw_version );
      Serial.print( "Vorhandene Firmware-Version: " );
      Serial.println( newFWVersion );
      
      int newVersion = newFWVersion.toInt();
      
      if( newVersion > fw_version ) {
        Serial.println( "Bereite Update vor..." );
      
        String fwImageURL = fwURL;
        fwImageURL.concat( ".bin" );
        t_httpUpdate_return ret = ESPhttpUpdate.update( fwImageURL );
      
        switch(ret) {
          case HTTP_UPDATE_FAILED:
            Serial.printf("HTTP_UPDATE_FAILD Error (%d): %s", ESPhttpUpdate.getLastError(), ESPhttpUpdate.getLastErrorString().c_str());
            break;
      
          case HTTP_UPDATE_NO_UPDATES:
            Serial.println("HTTP_UPDATE_NO_UPDATES");
            break;
        }
      }
      else {
        Serial.println("Aktuelle Firmware-Version bereits installiert");
      }
    }
    else {
      Serial.print("Firmware version check failed, got HTTP response code ");
      Serial.println( httpCode );
    }
    httpClient.end();
  }
  
}
