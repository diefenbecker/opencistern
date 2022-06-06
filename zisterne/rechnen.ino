void looprechnen() {

  //****************************************************
  // Ultraschallensor auslesen
  //****************************************************
  if (cfg.data_zisterne_sensor == 1) {
    digitalWrite(TRIGGER, LOW);
    delay(5);
    digitalWrite(TRIGGER, HIGH);
    delay(10);
    digitalWrite(TRIGGER, LOW);
    dauer = pulseIn(ECHO, HIGH);
    abstand = (dauer / 2) / 29.1;  
  }

  //****************************************************
  // TOF Sensor VL53L0X
  //****************************************************
  if (cfg.data_zisterne_sensor == 2) {
    //VL53L0X_RangingMeasurementData_t measure;   
    //Serial.print("Lese TOF-Sensor... ");
    //lox.rangingTest(&measure, false); 
    //if (measure.RangeStatus != 4)
    //{ 
      //Serial.print("Abstand (mm): "); Serial.println(measure.RangeMilliMeter);
    //} else {
    //  Serial.println(" out of range ");
    //}
    //abstand=measure.RangeMilliMeter/10;
    
    abstand=l0x_sensor.readRangeSingleMillimeters()/10;
    
    delay(100);
  }

  //****************************************************
  // TOF Sensor VL53L1X
  //****************************************************
  if (cfg.data_zisterne_sensor == 3) {
    l1x_sensor.startRanging();
    //while (!distanceSensor.checkForDataReady())
    //{
    //  delay(1);
    //}
    int distance = l1x_sensor.getDistance();
    l1x_sensor.clearInterrupt();
    l1x_sensor.stopRanging();
    //Serial.print("Abstand (mm): ");
    //Serial.print(distance);
    //Serial.println();
    abstand=distance/10;
    delay(100);
  }

  //abstand = 100; //nur testweise wenn kein Sensor dran haengt
  
  //Fuellstand prozentual berechnen
  fuellstand = abstand;
  fuellstand = ((fuellstand-cfg.data_abst_sen_boden)/(cfg.data_abst_sen_max-cfg.data_abst_sen_boden))*100;
  
  if(DEBUG) {
    //Serial.print(F("Abstand: "));
    //Serial.println(abstand);
  }

  //****************************************************
  //             Volumen berechnen
  //****************************************************
  
  // Volumen für Zylinder
  if (strcmp(cfg.data_zisterne_bauform,"1")==0) {
    volumen=((cfg.data_abst_sen_boden*0.01)-(abstand*0.01))*(0.5*cfg.data_zisterne_durchmesser*0.01)*(0.5*cfg.data_zisterne_durchmesser*0.01)*3.1415*1000;
  }
  // Volumen für liegenden Zylinder
  if (strcmp(cfg.data_zisterne_bauform,"5")==0) {
    float radius=0.5*cfg.data_zisterne_durchmesser_liegend;
    float wasserhoehe=(cfg.data_abst_sen_boden)-(abstand);
    float laenge=cfg.data_zisterne_laenge_liegend;
    volumen=radius*radius*laenge*(acos((radius-wasserhoehe)/radius)-(radius-wasserhoehe)*(sqrt(2*radius*wasserhoehe-(wasserhoehe*wasserhoehe))/(radius*radius)))/1000;
  }
  // Volumen Quader berechnen
  if (strcmp(cfg.data_zisterne_bauform,"2")==0) {
    volumen=((cfg.data_abst_sen_boden*0.01)-(abstand*0.01))*cfg.data_zisterne_x*0.01*cfg.data_zisterne_y*0.01*1000;
  }
  // Volumen über Grundfläche berechnen
  if (strcmp(cfg.data_zisterne_bauform,"3")==0) {
    volumen=((cfg.data_abst_sen_boden*0.01)-(abstand*0.01))*cfg.data_zisterne_fl*0.01*1000;
  }
  // Volumen über maximalen Inhalt berechnen
  if (strcmp(cfg.data_zisterne_bauform,"4")==0) {
    volumen=cfg.data_zisterne_vl*(int)roundf(fuellstand)/100;
  }
  

  //****************************************************
  //             Volumen_max berechnen
  //****************************************************
    
  if (strcmp(cfg.data_zisterne_bauform,"1")==0) {
    volumen_max=((cfg.data_abst_sen_boden*0.01)-(cfg.data_abst_sen_max*0.01))*(0.5*cfg.data_zisterne_durchmesser*0.01)*(0.5*cfg.data_zisterne_durchmesser*0.01)*3.1415*1000;
  }
  if (strcmp(cfg.data_zisterne_bauform,"5")==0) {
    float radius=0.5*cfg.data_zisterne_durchmesser_liegend;
    float wasserhoehe=(cfg.data_abst_sen_boden)-(cfg.data_abst_sen_max);
    float laenge=cfg.data_zisterne_laenge_liegend;    
    volumen_max=radius*radius*laenge*(acos((radius-wasserhoehe)/radius)-(radius-wasserhoehe)*(sqrt(2*radius*wasserhoehe-wasserhoehe*wasserhoehe)/(radius*radius)))/1000;
    //fuer den leigenden Zylinder muss der Füllstand anders berechnet werden
    //wert von oben wird ueberschrieben
    fuellstand = volumen/volumen_max*100;
  }
  if (strcmp(cfg.data_zisterne_bauform,"2")==0) {
    volumen_max=((cfg.data_abst_sen_boden*0.01)-(cfg.data_abst_sen_max*0.01))*cfg.data_zisterne_x*0.01*cfg.data_zisterne_y*0.01*1000;
  }
  if (strcmp(cfg.data_zisterne_bauform,"3")==0) {
    volumen_max=((cfg.data_abst_sen_boden*0.01)-(cfg.data_abst_sen_max*0.01))*cfg.data_zisterne_fl*0.01*1000;
  }
  if (strcmp(cfg.data_zisterne_bauform,"4")==0) {
    // volumen_max=((cfg.data_zisterne_vl/100)*1000)-((abstand-cfg.data_abst_sen_max)/((cfg.data_abst_sen_boden-cfg.data_abst_sen_max)/1000));
    volumen_max=cfg.data_zisterne_vl;
  }
  
}

  
