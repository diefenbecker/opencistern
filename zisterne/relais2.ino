//***********************************************************
// Schaltet ein zweites externes Relais an Ausgang D3 / Pin 2
// in Abhaengigkeit von zwei Werten
// NOCH NICHT IMPLEMENTIERT
//***********************************************************
void relais2() {
  currentMillisRelais2 = millis();
  if (currentMillisRelais2 - startMillisRelais2 >= (30 * 1000)) {
    
    startMillisRelais2 = currentMillisRelais2;

    Serial.println("Relais2"); 
     
  }
}
