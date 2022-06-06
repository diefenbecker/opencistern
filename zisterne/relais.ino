//********************************************************
// Schaltet ein externes Relais an Ausgang D4 / Pin 2
// in Abhaengigkeit von zwei Werten
//********************************************************
void relais() {
  currentMillisRelais = millis();
  if (currentMillisRelais - startMillisRelais >= (30 * 1000)) {
    
    startMillisRelais = currentMillisRelais;

    Serial.println("Relais"); 
    Serial.println(fuellstand); 

    //Anschalten
    if (cfg.data_relais_an_krit == 0) {
      if (fuellstand <= cfg.data_relais_an_wert) {
        digitalWrite(relaisPIN,HIGH);
        Serial.println("High");     
      }
    }
    if (cfg.data_relais_an_krit == 1) {
      if (fuellstand >= cfg.data_relais_an_wert) {
        digitalWrite(relaisPIN,HIGH);
        Serial.println("High");       
      }
    }

    //Ausschalten
    if (cfg.data_relais_aus_krit == 0) {
      if (fuellstand <= cfg.data_relais_aus_wert) {
        digitalWrite(relaisPIN,LOW);
        Serial.println("Low");     
      }
    }
    if (cfg.data_relais_aus_krit == 1) {
      if (fuellstand >= cfg.data_relais_aus_wert) {
        digitalWrite(relaisPIN,LOW);
        Serial.println("Low");       
      }
    }
     
  }
}
