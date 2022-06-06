//********************************************************
void ladekonfig() {
  // Konfiguration von EEPROM laden
  EEPROM.begin(4095);
  EEPROM.get( cfgStart, cfg );
  EEPROM.end();
}

//********************************************************
void speicherekonfig() {
  // Konfiguration auf EEPROM speichern
  EEPROM.begin(4095);
  EEPROM.put( cfgStart, cfg );
  delay(200);
  EEPROM.commit();
  EEPROM.end();
}

//********************************************************
void eraseConfig() {
  // Konfiguration auf EEPROM löschen
  EEPROM.begin(4095);
  for (int i = cfgStart ; i < sizeof(cfg) ; i++) {
    EEPROM.write(i, 0);
  }
  delay(200);
  EEPROM.commit();
  EEPROM.end();
}
