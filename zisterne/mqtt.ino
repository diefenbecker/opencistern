//**********************************************
// MQTT
//**********************************************
void mqtt_api() {
  currentMillisMQTT = millis();
  if (currentMillisMQTT - startMillisMQTT >= (cfg.data_mqtt_intervall * 1000)) {
    startMillisMQTT = currentMillisMQTT;
    
    String clientName;
    clientName += "esp8266-";
    clientName += macAdresse;
    
    Serial.print("Client-Name: ");
    Serial.println(clientName);

    Serial.print("MQTT-Broker Server: ");
    Serial.println(cfg.data_mqtt_server);

    int mqtt_port=0;
    //schauen ob MQTT-Port gesetzt wurde und ggf. nutzen
    if (cfg.data_mqtt_port!=0) {
      mqtt_port=cfg.data_mqtt_port;      
      Serial.print("MQTT-Broker Port: ");
      Serial.println(cfg.data_mqtt_port);
    } else {
      mqtt_port=1883;      
      Serial.print("MQTT-Broker Port nicht definiert Nutze Standardport 1883 ");
      Serial.println(cfg.data_mqtt_port);
    }

    
    PubSubClient client(cfg.data_mqtt_server, mqtt_port, callback, wifiClient);
    //client.setServer(cfg.data_mqtt_server, 1883);

    //if (client.connect((char*) clientName.c_str())) {
    if (client.connect((char*) clientName.c_str(), cfg.data_mqtt_benutzer, cfg.data_mqtt_passwort)) {
      Serial.println("Verbunden zu MQTT-Broker");
      
      //Fuellstand senden
      Serial.print("Topic fuer Fuellstand ist: ");
      Serial.println(cfg.data_mqtt_topic);

      int fuellstand_int=(int)(fuellstand+.5);
      char fuellstand_char[3];
      
      if (client.publish(cfg.data_mqtt_topic, itoa(fuellstand_int,fuellstand_char,10))) {
        Serial.print("Publish erfolgreich: ");
        Serial.println(itoa(fuellstand_int,fuellstand_char,10));
      }
      else {
        Serial.println("Publish fehlgeschlagen");
      }

      //Abstand senden
      Serial.print("Topic fuer Abstand ist: ");
      Serial.println(cfg.data_mqtt_abstand_topic);

      int abstand_int=(int)(abstand+.5);
      char abstand_char[3];
      
      if (client.publish(cfg.data_mqtt_abstand_topic, itoa(abstand_int,abstand_char,10))) {
        Serial.print("Publish erfolgreich: ");
        Serial.println(itoa(abstand_int,abstand_char,10));
      }
      else {
        Serial.println("Publish fehlgeschlagen");
      }

      //Fuellstand in Liter senden
      if (cfg.data_anzeige_liter_check==1) {
        Serial.print("Topic fuer Liter ist: ");
        Serial.println(cfg.data_mqtt_liter_topic);
        if (client.publish(cfg.data_mqtt_liter_topic, String(volumen).c_str(), true)) {
          Serial.print("Publish erfolgreich: ");
          Serial.println(volumen);
        }
        else {
          Serial.println("Publish fehlgeschlagen");
        }
      } 

      //Temperatur senden
      if (cfg.data_temperatur_enable == 1) {
        Serial.print("Topic fuer Temperatur ist: ");
        Serial.println(cfg.data_mqtt_temperature_topic);
        //Temperatur senden
        if (client.publish(cfg.data_mqtt_temperature_topic, String(temperature).c_str(), true)) {
          Serial.print("Publish erfolgreich: ");
          Serial.println(temperature);
        }
        else {
          Serial.println("Publish fehlgeschlagen");
        }
  
        //Luftfeuchtigkeit senden
        Serial.print("Topic fuer Luftfeuchtigkeit ist: ");
        Serial.println(cfg.data_mqtt_humidity_topic); //ToDo MCH  
        if (client.publish(cfg.data_mqtt_humidity_topic, String(humidity).c_str(), true)) {
          Serial.print("Publish erfolgreich: ");
          Serial.println(humidity);
        }
        else {
          Serial.println("Publish fehlgeschlagen");
        }
      } 
    }
    else {
      Serial.println("Verbindung zum MQTT-Broker fehlgeschlagen");
    }
  }
}
