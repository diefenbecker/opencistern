void webHandleRoot() {
  String inhalt;
  float vcc = ESP.getVcc() / 1000.0;
  inhalt  = "<!DOCTYPE html>";
  inhalt += "<html><head><meta charset='utf-8' name='viewport' content='width=device-width, initial-scale=1.0'><meta http-equiv='refresh' content='60'><title>" + anwendungsname + "</title></head><body style='font-family:verdana;background-color:#B9DFF8;color:#000000;margin:0px'>";
  inhalt += "<p style='background-color:#FFFFFF;color:#000000;padding:20px;padding-left:10px;margin:0px;'><img style='vertical-align: middle;width:50px;' src=' data:image/png;base64,iVBORw0KGgoAAAANSUhEUgAAADIAAAAyCAMAAAAp4XiDAAAABGdBTUEAALGPC/xhBQAAAAFzUkdCAK7OHOkAAAAJcEhZcwAADr8AAA6/ATgFUyQAAAL6UExURUdwTAAAAC2EwCiBukul8St/fy2FwF6s3hf//wAA/yKGqkOq/ziRw16s3lit4F2r3zCGujOCzBl//yWCtC2Hwl2r3iyEwCd3sT9/vyyFvi2FwB9/ulur3SyEwCuDv1ur3imGxFut4CyFv1ut2iyEv1ar5DGJwyyDvyyEwCqFvkyq3SyEvSyEvyyEvyyCv1yr312r3iyEvyuDvCyEvkq05yyDvyyDvhxxuCuEvyyEwCqEviyEwCyCvyyDwCyFwCyGvyyFv1us3iqCuiyEvyuEvy2DvyyFwCyEvSp/tDyTzDqQyS+HwVys3VSm3lys3lqw41iq31er3leq3jSLxVKp3yuCvESz5iN9syp/uymCuiqDvFar3yyBuCyFwCyDv1yr3iyEvyyEwFar3yuEwC2GvyuCui2EvyyEwCqAvSyDviqBvi2EvyyEwC2EvyyDvi6Fvyl5tjNmmSuDvSqDvi2HwyyEv1ur4FSk2Umc0Vqp30ab0Fqp3Fqq3lqr3CV4sViq3Vys3lms31yr3Vqq3l2r3Vur3FKp3Fqq31Oq3leq3k6g1EOYz12r3yd8tlir3kap4lmq3iqBuyyFwCiBuiiCuyuDvSyEvy2BviuFviyFwC6EuC2FwCyFvy1/vyiEwS2EvyyEwC2FwC2Fvlup3CyEvyyHvy2FwCuEvy2Fvy2GwCuEvS6DvimCvCuDvSuEvSyFwCyEviyGvyqCv1yt3y6Lw0SZ0UCXz0SVzVqs3k2g1VOk2UW551ip3Eue01mq21mn3Fuq3jaNxlCs3Vut3VSp3Ves4FWn2kOr5FWr2z2Uy1yr2zePylqo2lWo3Vms4Vms3Vyr3FKs2SqCvVev31uq3leu4Vqo3Fuq3Fuq3VSl2iuEvlat4Vaq4Fmp3FOk2TSMxymDvU6w11ir3yyDvlGi0CyEwC6DvyqAuCyEvSuCuCuEvi6EvyqCvyuDuC2DwCyBty2FvyqCvi2GuyuBvTWGySyEwSqDvV6s3y6GwV2r3i6GwFur3lio212s38UGdO0AAAD3dFJOUwAB7AYEAv7+AQEDAwn8G/sOBQIKIv7xGQQV/AikRmWnDBnhHMUd/iD4Lhk0ne4j6/X1hukY23YJ5cM80FSW6Tndpy3GwKOsXxL8/f7zJ+UPXEeL/Rc+BhNcJomhKPPMpdLwokpMKdV6Fo9xruzjliwQBbRYEdmo/v3K/f7cyi8/8kjgse7gLNBLfP37+Sp6Ep+bK5MadLpRbb0x+lwcGanIcEOljFSFgsz3a6bGQGKI9jYwqAv8/P5m/P0Lh/2R+M78eME2df0xa+nuUqkpTaD8IpUglFXD6NT8ql5k4fCOHw2ZfhZRzYN9kbdorB2zcqii02YTmkKlVbe7AAAEA0lEQVQYGY3BBVxTCQAH4P82hu9tE3gDDtwYMZHu0eAoaaUbRAaHDBAYaWBgnp0YOLs7uS6v0+vuLq/rPcD7/e5tNAzY92FCltsia4IL3DV8GEt94Ji3VuIfEeAuwBQevb3xoU2bPtn4eZ2EYZlyP3LF5OY9tnSNb0eH76efbclm9Pz3UJjMC7f8rOl+fZuzGT23lZhQ3u2sl+lhPR8muzA6ARW5uztDSIxnsmqtHz1K+8NPMSx/lbJs394SCuPk7JxLj9HzuAuj1ytReMUKMNbqtGn0WHdTmAGmqrdsMNYT0+lxepa4MIO4BUKM5rGcNmDx/Q8+kJydyrB6SwsxSl6WNW1IT491+yPLUlIZhnEr4mOknBX0xPoWb0llmF5FPoaJ3n5tPT2Z9uRehjHdhiHp2+97/w16UptdGIZZiQF58173o6dyN4Vh/G3QzyTzPXN6Sn3LXLS7+Og3a+1W2gjPL3npFT76ZS63po3wX9+TK54loPeiL20k61fTofd0B22s9av40MlIo421LoOCzoal02gjrcugoCN6bi5tpLTVYugFPkMb6dabGLDjnTV+5jrTJ2G+1feDd4UYlJ65/avi4uLy8nI71smTCxwcYhx02m7ebGuLiYlZYGe3M+vjDSYYJvzym8DAQA8PDyeWh5nOTJ1ZOjPNzMycnHJ25HEwlsCRB1ZjCwVWo6UY4FDdAgA8RwKGcCrra3gAP3LOvQSAiqtWBMT/1seS6K65aAVDbA/Ju9SAT5jkrBAQHI27LkaSl6JZQF53VslgSL4XN1gK6QWlVkZAHK44akXCPaL0Bkkl1h1zhSGV30V4ErBKcPtVA+TXqo53A4nKq0lo+ce7KgSGfKuYPQPY/ZNcxgEnPFR+gg8cOFfRCJ+w1igChpyRN/MAqWeuCLD92q3UFcCRKA0H4cqEwxjlcJV9oSUBdIV5ijHgizBJtRQDgkPtQwAOpT5o70OARcqc73E+7imCV5Uag1y9unJJDLgzu0EM28JD8a1B+ymwODYV9fLQrr2VJZ0CDOIVuoswSG0lBe/E79GqhcGuAuiQ1Iz9YfO55+yTCAwh+BhCErzYM63zgwI8LfgYRN34+bypougICYNEf5W5mYbJLAiMZHE6Ppq7706Dho/RSOrvy/EK7sIAHz7GILov10dwI06FazgYQdSQGN8anWB/UAoDhJ2y2dGquB9iKQzRJDbJr8VdKRRxYBBJqaMuenPjfvuFgB7lc0ruH1TtbklgYoTN2UWSa00lHLCEV/48L6mN6iYxOYuKP1TcAluwqCJt3QU1iSkRnc6Lmm3B4lVrm1pgDIs5ykghWLw92lpHGENzSXlaCJZ0lyTBEcZIuqSMFIDF+77sxxCM8z/EjXuZgyh7FAAAAABJRU5ErkJggg=='>&nbsp;&nbsp;";
  inhalt += "<span style='font-size:24px;font-weight:bold;'>" + anwendungsname + "</span>&nbsp;<span style='font-size:12px;font-weight:normal;'>v" + fw_version + "</span></p>";  
  inhalt += "<p style='font-size:18px;font-weight:bold;background-color:#85C5EE;padding-left:10px;padding-top:10px;padding-bottom:10px;margin:0px;'>Startseite</p>";
  inhalt += "<br>";
  inhalt += "<div style='padding-left:10px;padding_right:10px;'>";

  int breite_anzeige = 0;

  //  inhalt += "<table border=0>";
  //  inhalt += "<tr><td colspan=";
  //   if (cfg.data_anzeige_liter_check==1) {
  //     inhalt += "3";
  //     breite_anzeige=33;
  //  } else {
  //     inhalt += "2";
  //     breite_anzeige=50;
  //  }
  //  inhalt += " style='color:#ffffff;background-color:#2e86c1;padding:5px;'>Sensordaten</td></tr>";
  //
  //  //Balken über die komplette Breite anzeigen
  //  //Aktuell nicht genutzt
  //  //inhalt += "<tr><td colspan=";
  //  // if (cfg.data_anzeige_liter_check==1) {
  //  //   inhalt += "3";
  //  //   breite_anzeige=33;
  //  //} else {
  //  //   inhalt += "2";
  //  //   breite_anzeige=50;
  //  //}
  //  //inhalt += "><div style='padding: 2px;border:1px solid #2e86c1'><div style='background: #7bd930 none repeat scroll 0% 0%; width: ";
  //  //inhalt += (int)roundf(fuellstand);
  //  //inhalt +="%; color: #000000;'><div style='position:relative;'><span style='position:absolute;left:50%;right:50%'>F&uuml;llstand</span></div>&nbsp;</div></div></td></tr>";
  //
  //  inhalt += "<tr><td style='font-size:90px;width:300px;text-align:center;background-color:#85C5EE;width:";
  //  inhalt += breite_anzeige;
  //  inhalt += "%;'>";
  //  if (cfg.data_dezstellen_anzeige==0) {
  //    inhalt += (int)roundf(fuellstand);
  //  } else if (cfg.data_dezstellen_anzeige==1) {
  //    inhalt += roundf(fuellstand*10.0)/10.0;
  //  } else if (cfg.data_dezstellen_anzeige==2) {
  //    inhalt += roundf(fuellstand*100)/100;
  //  } else {
  //    inhalt += (int)roundf(fuellstand);
  //  }
  //  inhalt += "</td>";
  //
  //  if (cfg.data_anzeige_liter_check==1) {
  //     // Volumen für Zylinder
  //     if (strcmp(cfg.data_zisterne_bauform,"1")==0) {
  //      volumen=((cfg.data_abst_sen_boden*0.01)-(abstand*0.01))*(0.5*cfg.data_zisterne_durchmesser*0.01)*(0.5*cfg.data_zisterne_durchmesser*0.01)*3.1415*1000;
  //     }
  //     // Volumen für liegenden Zylinder
  //     if (strcmp(cfg.data_zisterne_bauform,"5")==0) {
  //      float radius=0.5*cfg.data_zisterne_durchmesser_liegend;
  //      float wasserhoehe=(cfg.data_abst_sen_boden)-(abstand);
  //      float laenge=cfg.data_zisterne_laenge_liegend;
  //      volumen=radius*radius*laenge*(acos((radius-wasserhoehe)/radius)-(radius-wasserhoehe)*(sqrt(2*radius*wasserhoehe-(wasserhoehe*wasserhoehe))/(radius*radius)))/1000;
  //     }
  //     // Volumen Quader berechnen
  //     if (strcmp(cfg.data_zisterne_bauform,"2")==0) {
  //      volumen=((cfg.data_abst_sen_boden*0.01)-(abstand*0.01))*cfg.data_zisterne_x*0.01*cfg.data_zisterne_y*0.01*1000;
  //     }
  //     // Volumen über Grundfläche berechnen
  //     if (strcmp(cfg.data_zisterne_bauform,"3")==0) {
  //      volumen=((cfg.data_abst_sen_boden*0.01)-(abstand*0.01))*cfg.data_zisterne_fl*0.01*1000;
  //     }
  //     // Volumen über maximalen Inhalt berechnen
  //     if (strcmp(cfg.data_zisterne_bauform,"4")==0) {
  //      volumen=cfg.data_zisterne_vl*(int)roundf(fuellstand)/100;
  //     }
  //     inhalt += "<td rowspan=2 style='font-size:70px;text-align:center;background-color:#85C5EE;width:";
  //     inhalt += breite_anzeige;
  //     inhalt += "%;'>";
  //     inhalt += (int)volumen;
  //     inhalt += "</td>";
  //  }
  //
  //  inhalt += "<td rowspan=2 style='font-size:90px;text-align:center;background-color:#85C5EE;width:";
  //  inhalt += breite_anzeige;
  //  inhalt += "%;'>";
  //  inhalt += abstand;
  //  inhalt += "</td></tr>";
  //
  //  //Füllstandsbalken
  //  inhalt += "<tr><td><div style='padding: 2px;border:1px solid #2e86c1'><div style='background: ";
  //  if ((int)roundf(fuellstand)>60) {
  //    inhalt += " #7bd930 ";
  //  }
  //  else if ((int)roundf(fuellstand)<=60 && (int)roundf(fuellstand)>41) {
  //    inhalt += " #FFA500 ";
  //  }
  //  else if ((int)roundf(fuellstand)<=40) {
  //    inhalt += " #FE2E2E ";
  //  }
  //  else {
  //    inhalt += " #2e86c1 ";
  //  }
  //
  //  inhalt += " none repeat scroll 0% 0%; width: ";
  //  inhalt += (int)roundf(fuellstand);
  //  inhalt +="%; color: #000000;'><div style='position:relative;'><span style='position:absolute;left:50%;right:50%'></span></div>&nbsp;</div></div></td></tr>";
  //
  //  inhalt += "<tr><td style='vertical-align:top;text-align:center;background-color:#5EACDF;'>F&uuml;llstand in %</td>";
  //  if (cfg.data_anzeige_liter_check==1) {
  //     inhalt += "<td style='vertical-align:top;text-align:center;background-color:#5EACDF;'>Volumen in Liter (von max. ";
  //     float volumen_max = 0;
  //     if (strcmp(cfg.data_zisterne_bauform,"1")==0) {
  //      volumen_max=((cfg.data_abst_sen_boden*0.01)-(cfg.data_abst_sen_max*0.01))*(0.5*cfg.data_zisterne_durchmesser*0.01)*(0.5*cfg.data_zisterne_durchmesser*0.01)*3.1415*1000;
  //     }
  //     if (strcmp(cfg.data_zisterne_bauform,"5")==0) {
  //      float radius=0.5*cfg.data_zisterne_durchmesser_liegend;
  //      float wasserhoehe=(cfg.data_abst_sen_boden)-(cfg.data_abst_sen_max);
  //      float laenge=cfg.data_zisterne_laenge_liegend;
  //      volumen_max=radius*radius*laenge*(acos((radius-wasserhoehe)/radius)-(radius-wasserhoehe)*(sqrt(2*radius*wasserhoehe-wasserhoehe*wasserhoehe)/(radius*radius)))/1000;
  //     }
  //     if (strcmp(cfg.data_zisterne_bauform,"2")==0) {
  //      volumen_max=((cfg.data_abst_sen_boden*0.01)-(cfg.data_abst_sen_max*0.01))*cfg.data_zisterne_x*0.01*cfg.data_zisterne_y*0.01*1000;
  //     }
  //     if (strcmp(cfg.data_zisterne_bauform,"3")==0) {
  //      volumen_max=((cfg.data_abst_sen_boden*0.01)-(cfg.data_abst_sen_max*0.01))*cfg.data_zisterne_fl*0.01*1000;
  //     }
  //     if (strcmp(cfg.data_zisterne_bauform,"4")==0) {
  //      // volumen_max=((cfg.data_zisterne_vl/100)*1000)-((abstand-cfg.data_abst_sen_max)/((cfg.data_abst_sen_boden-cfg.data_abst_sen_max)/1000));
  //      volumen_max=cfg.data_zisterne_vl;
  //     }
  //     inhalt += (int)volumen_max;
  //     inhalt += ")</td>";
  //  }
  //  inhalt += "<td style='vertical-align:top;text-align:center;background-color:#5EACDF;'>Abstand Sensor-Wasser in cm</td></tr>";
  //
  //  // Temperaturdaten
  //  if (cfg.data_temperatur_enable == 1) {
  //    inhalt += "<tr>";
  //    inhalt += "<td style='font-size:80px;text-align:center;background-color:#ECF7FD;'>";
  //    inhalt += temperature;
  //    inhalt += "</td>";
  //    inhalt += "<td style='font-size:80px;text-align:center;background-color:#ECF7FD;'>";
  //    inhalt += (int)roundf(humidity);
  //    inhalt += "</td>";
  //    inhalt += "</tr>";
  //    inhalt += "<tr><td style='vertical-align:top;text-align:center;background-color:#ADADAD;color:#ffffff;'>Temperatur in °C</td>";
  //    inhalt += "<td style='vertical-align:top;text-align:center;background-color:#5EACDF;'>Luftfeuchte in %</td></tr>";
  //  }
  //
  //  inhalt += "</table>";

  //*******************************
  //Kästchen zur Anzeigen der Werte
  //*******************************
  //Füllstand
  inhalt += "<div style='float:left; width: 160px; height: 120px; background: #85C5EE; padding: 5px; font-size:40px; vertical-align: middle; text-align: center; margin: 2px;'>";
  if (cfg.data_dezstellen_anzeige == 0) {
    inhalt += (int)roundf(fuellstand);
  } else if (cfg.data_dezstellen_anzeige == 1) {
    inhalt += roundf(fuellstand * 10.0) / 10.0;
  } else if (cfg.data_dezstellen_anzeige == 2) {
    inhalt += roundf(fuellstand * 100) / 100;
  } else {
    inhalt += (int)roundf(fuellstand);
  }
  inhalt += "<span style='font-size:20px;'>%</span>";
  //Balken
  inhalt += "<div style='margin-top:10px; padding: 1px;border:1px solid #2e86c1'><div style='background: ";
  if ((int)roundf(fuellstand) > 60) {
    inhalt += " #7bd930 ";
  }
  else if ((int)roundf(fuellstand) <= 60 && (int)roundf(fuellstand) > 41) {
    inhalt += " #FFA500 ";
  }
  else if ((int)roundf(fuellstand) <= 40) {
    inhalt += " #FE2E2E ";
  }
  else {
    inhalt += " #2e86c1 ";
  }
  inhalt += " none repeat scroll 0% 0%; width: ";
  inhalt += (int)roundf(fuellstand);
  inhalt += "%; height:12px; color: #000000;'><div style='position:relative;'><span style='position:absolute;left:50%;right:50%'></span></div>&nbsp;</div></div>";

  inhalt += "<p style='width:150px; background: #5EACDF; padding: 5px; font-size:14px; vertical-align: middle; text-align: center; margin-top:20px;'>F&uuml;llstand</p></div>";

  if (cfg.data_anzeige_liter_check == 1) {
    //Volumen Liter
    float volumen_max = 0;
    if (strcmp(cfg.data_zisterne_bauform, "1") == 0) {
      volumen_max = ((cfg.data_abst_sen_boden * 0.01) - (cfg.data_abst_sen_max * 0.01)) * (0.5 * cfg.data_zisterne_durchmesser * 0.01) * (0.5 * cfg.data_zisterne_durchmesser * 0.01) * 3.1415 * 1000;
    }
    if (strcmp(cfg.data_zisterne_bauform, "5") == 0) {
      float radius = 0.5 * cfg.data_zisterne_durchmesser_liegend;
      float wasserhoehe = (cfg.data_abst_sen_boden) - (cfg.data_abst_sen_max);
      float laenge = cfg.data_zisterne_laenge_liegend;
      volumen_max = radius * radius * laenge * (acos((radius - wasserhoehe) / radius) - (radius - wasserhoehe) * (sqrt(2 * radius * wasserhoehe - wasserhoehe * wasserhoehe) / (radius * radius))) / 1000;
    }
    if (strcmp(cfg.data_zisterne_bauform, "2") == 0) {
      volumen_max = ((cfg.data_abst_sen_boden * 0.01) - (cfg.data_abst_sen_max * 0.01)) * cfg.data_zisterne_x * 0.01 * cfg.data_zisterne_y * 0.01 * 1000;
    }
    if (strcmp(cfg.data_zisterne_bauform, "3") == 0) {
      volumen_max = ((cfg.data_abst_sen_boden * 0.01) - (cfg.data_abst_sen_max * 0.01)) * cfg.data_zisterne_fl * 0.01 * 1000;
    }
    if (strcmp(cfg.data_zisterne_bauform, "4") == 0) {
      // volumen_max=((cfg.data_zisterne_vl/100)*1000)-((abstand-cfg.data_abst_sen_max)/((cfg.data_abst_sen_boden-cfg.data_abst_sen_max)/1000));
      volumen_max = cfg.data_zisterne_vl;
    }

    inhalt += "<div style='float:left; width: 160px; height: 120px; background: #85C5EE; padding: 5px; font-size:45px; vertical-align: middle; text-align: center; margin: 2px;'>";
    inhalt += (int)volumen;
    inhalt += "<span style='font-size:20px;'>l</span><p style='font-size:12px;'>von max. ";
    inhalt += (int)volumen_max;
    inhalt += "</p>";
    inhalt += "<p style='width:150px; background: #5EACDF; padding: 5px; font-size:14px; vertical-align: middle; text-align: center; margin-top:13px;'>Volumen</p></div>";
  }

  //Abstand
  inhalt += "<div style='float:left; width: 160px; height: 120px; background: #85C5EE; padding: 5px; font-size:45px; vertical-align: middle; text-align: center; margin: 2px;'>";
  inhalt += abstand;
  inhalt += "<span style='font-size:20px;'>cm</span>";
  inhalt += "<p style='width:150px; background: #5EACDF; padding: 5px; font-size:14px; vertical-align: middle; text-align: center; margin-top:40px;'>Abstand Wasser</p></div>";

  if (cfg.data_temperatur_enable == 1) {
    //Temperatur
    inhalt += "<div style='float:left; width: 160px; height: 120px; background: #E1E1E1; padding: 5px; font-size:45px; vertical-align: middle; text-align: center; margin: 2px;'>";
    inhalt += temperature;
    inhalt += "<span style='font-size:20px;'>°C</span>";
    inhalt += "<p style='width:150px; background: #ADADAD; color:#ffffff;; padding: 5px; font-size:14px; vertical-align: middle; text-align: center; margin-top:40px;'>Temperatur</p></div>";

    //Luftfeuchte
    inhalt += "<div style='float:left; width: 160px; height: 120px; background: #E1E1E1; padding: 5px; font-size:45px; vertical-align: middle; text-align: center; margin: 2px;'>";
    inhalt += (int)roundf(humidity);
    inhalt += "<span style='font-size:20px;'>%</span>";
    inhalt += "<p style='width:150px; background: #ADADAD; color:#ffffff; padding: 5px; font-size:14px; vertical-align: middle; text-align: center; margin-top:40px;'>Luftfeuchte</p></div>";
  }
  //*******************************

  if (cfg.data_relais_enable == 1) {
    int relais_status_int = digitalRead(relaisPIN);
    String relais_status;
    if (relais_status_int == 1) { relais_status="An <span style='font-size:35px;'>&#10004;</span>"; }
    if (relais_status_int == 0) { relais_status="Aus <span style='font-size:35px;'>&#10008;</span>"; }
    //Relais Status
    inhalt += "<div style='float:left; width: 160px; height: 120px; background: #ADADAD; padding: 5px; color:#ffffff; font-size:45px; vertical-align: middle; text-align: center; margin: 2px;'>";
    inhalt += relais_status;
    inhalt += "<span style='font-size:20px;'></span>";
    inhalt += "<p style='width:150px; background: #676767; padding: 5px; font-size:14px; color:#ffffff; vertical-align: middle; text-align: center; margin-top:40px;'>Schalter an D4</p></div>";
  }
  
  //if (cfg.data_relais2_enable == 1) {
  //  int relais2_status_int = digitalRead(relais2PIN);
  //  String relais2_status;
  //  if (relais2_status_int == 1) { relais2_status="An <span style='font-size:35px;'>&#10004;</span>"; }
  //  if (relais2_status_int == 0) { relais2_status="Aus <span style='font-size:35px;'>&#10008;</span>"; }
  //  //Relais2 Status
  //  inhalt += "<div style='float:left; width: 160px; height: 120px; background: #ADADAD; padding: 5px; color:#ffffff; font-size:45px; vertical-align: middle; text-align: center; margin: 2px;'>";
  //  inhalt += relais2_status;
  //  inhalt += "<span style='font-size:20px;'></span>";
  //  inhalt += "<p style='width:150px; background: #676767; padding: 5px; font-size:14px; color:#ffffff; vertical-align: middle; text-align: center; margin-top:40px;'>Schalter an D3</p></div>";
  //}
  
  if (cfg.data_webapi_check == 1) {    
    inhalt += "<div style='float:left; width: 160px; height: 120px; background: #ADADAD; padding: 5px; color:#ffffff; font-size:45px; vertical-align: middle; text-align: center; margin: 2px;'>";
    inhalt += "<a href='http://www.bubux.de/heimautomatisierung/zisternen_auswertung.php?mac=";
    inhalt += macAdresse;
    inhalt += "' style='text-decoration:none;'><img style='padding:12px;' src=\"data:image/png;base64,iVBORw0KGgoAAAANSUhEUgAAAEIAAAA8CAMAAADlopxrAAAABGdBTUEAALGPC/xhBQAAAAFzUkdCAK7OHOkAAAAJcEhZcwAADsAAAA7AAWrWiQkAAAD8UExURUdwTAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAOBZMRsAAABTdFJOUwCr64sIVNeAAfsCFPM4BOcMGDwoyxz+A8MHbFFwMJ+jQBHPfOMJRPdY/SQKXEwTDZN024O2u8AgaAYLEDQVmzm/BZojs3+tUGmmSU1m9mBqZHP4SBL89AAAAdBJREFUSMftlsd22zAQRZ9kSR4yDElVy5Z7d3rvidN7v///L1lIVBKRgAo3XmhW5AHn4nJwAIyAVZWLJWKJWCKKY6ssorYSbPyPWDfJ5iBcbkD0MGcRzqMA8DKHMElrsyoA1XpxLWqzKlC55CinXZ1LwbsitZkUfIjjw4GkcGKVzicVPIhnEbxWune0bl4FN6KdALyv+avgQzTvAECnO03BhUj3GUWyO0XBgYj7APf2AUYbwalQjIgrAPfjdAeA7ZpT4bELcQugc1PS7QCg88ajUIg4AGg0JUm7CUDgqoID8QgguTJ663aywjoUChD1AIi2/i7ltl8hj2hFQNDKtr4kbQSfPAqTCGtHQDAxY1vH+TwrRlg3AdiUK8PMzLwWzQbA3Xz+UXYkWhh6EKa0D/AiO0jH39orm3aPHAw/jN8CVOIs8cnEL/sQv4ZPOwD9dDwSrs14nAM/JEkrAI30n3ltdsRXSdoEOGzOdx+NET9NOgVI2vnxMJ6O+F39LnVPgKhVQHh+Y2pJeid8kfQhIri+4A1/BgNJalWvLdpf9GC4JZ4u3KKc9aiX7HJ6wbfT8o3SwEojPpe3+Fge8W7Z/V4AhO2NGiDgwWqpEKXjYiD+AEWsyWhYQWN3AAAAAElFTkSuQmCC\">";
    inhalt += "<span style='font-size:20px;'></span>";
    inhalt += "<p style='width:150px; background: #676767; padding: 5px; font-size:14px; color:#ffffff; vertical-align: middle; text-align: center; margin-top:1px;text-decoration:none;'>Auswertung</p></a></div>";
  }

  //*******************************
  inhalt += "<div style='clear: both;'></div>";

  inhalt += "<br><br><br>";

  inhalt += "<details>";
  inhalt += "<summary style='background-color:#2e86c1;color:#ffffff;padding:5px;'>Technische Daten</summary>";
  inhalt += "<table style='font-size:14px;'>";

  inhalt += "<tr><td>Systemzeit</td><td>";
  inhalt += timeClient.getFormattedTime();
  //inhalt += timeClient.getHoures();
  //inhalt += ":";
  //inhalt += timeClient.getMinutes();
  //inhalt += ":";
  //inhalt += timeClient.getSeconds();
  //inhalt += "</td></tr>";

  inhalt += "<tr><td>IP-Adresse</td><td>";
  inhalt += ipAdresse;
  inhalt += "</td></tr>";

  inhalt += "<tr><td>MAC-Adresse</td><td>";
  inhalt += macAdresse;
  inhalt += "</td></tr>";

  inhalt += "<tr><td>Ausgew&auml;hlter Sensor</td><td>";
  if (cfg.data_zisterne_sensor == 1) {
    inhalt += "HC-SR04";
  }
  if (cfg.data_zisterne_sensor == 2) {
    inhalt += "VL53L0X";
  }
  if (cfg.data_zisterne_sensor == 3) {
    inhalt += "VL53L1X";
  }
  inhalt += "</td></tr>";


  inhalt += "<tr><td>Spannung am ESP</td><td>";
  inhalt += vcc;
  inhalt += " V</td></tr>";

  inhalt += "<tr><td>WIFI Signal</td><td>";
  inhalt += WiFi.RSSI();
  inhalt += " dBm</td></tr>";

  //  inhalt += "<tr><td>WIFI Qualit&auml;t</td><td>";
  //  inhalt += vcc;
  //  inhalt += " %</td></tr>";

  inhalt += "<tr><td>Freier Heapspeicher</td><td>";
  inhalt += ESP.getFreeHeap();
  inhalt += "</td></tr>";

  inhalt += "<tr><td>Heap Fragmentierung (<50% OK)</td><td>";
  inhalt += ESP.getHeapFragmentation();
  inhalt += "%</td></tr>";

  //inhalt += "<tr><td>Freier Heapspeicher</td><td>";
  //inhalt += freeheap;
  //inhalt += "</td></tr>";

  inhalt += "<tr><td>Aufrufe eigene API seit Start</td><td>";
  inhalt += eigenapi_anz_aufrufe;
  inhalt += "</td></tr>";

  inhalt += "<tr><td>Aufrufe WebAPI seit Start</td><td>";
  inhalt += webapi_anz_aufrufe;
  inhalt += "</td></tr>";

  inhalt += "<tr><td>Web API</td><td>";
  if (cfg.data_webapi_check == 1) {
    inhalt += "<span style='color:#008700'>aktiviert</span>"; // (" ;
    //inhalt += webapi_zeit;
    //inhalt += "s)" ;
  } else {
    inhalt += "<i>nicht aktiviert</i>";
  }
  inhalt += "</td></tr>";

  inhalt += "<tr><td>Temperatursensor</td><td>";
  if (cfg.data_temperatur_enable == 1) {
    inhalt += "<span style='color:#008700'>aktiviert</span>"; // (" ;
  } else {
    inhalt += "<i>nicht aktiviert</i>";
  }
  inhalt += "</td></tr>";

  inhalt += "<tr><td>MQTT</td><td>";
  if (cfg.data_mqtt_check == 1) {
    inhalt += "<span style='color:#008700'>aktiviert</span>"; // (" ;
  } else {
    inhalt += "<i>nicht aktiviert</i>";
  }
  inhalt += "</td></tr>";

  inhalt += "<tr><td>OverTheAir Update</td><td>";
  if (cfg.data_ota_check == 1) {
    inhalt += "<span style='color:#008700'>aktiviert</span>"; // (" ;
    //inhalt += ota_zeit;
    //inhalt += "s)" ;
  } else {
    inhalt += "<i>nicht aktiviert</i>";
  }
  inhalt += "</td></tr>";
  inhalt += "<tr><td>Pushover-Nachricht</td><td>";
  if (cfg.data_pushover_check == 1) {
    inhalt += "<span style='color:#008700'>aktiviert</span>"; // (" ;
  } else {
    inhalt += "<i>nicht aktiviert</i>";
  }
  inhalt += "</td></tr>";
  inhalt += "<tr><td>Externes Display</td><td>";
  if (cfg.data_display_enable == 1) {
    inhalt += "<span style='color:#008700'>aktiviert</span>"; // (" ;
  } else {
    inhalt += "<i>nicht aktiviert</i>";
  }
  inhalt += "</td></tr>";
  inhalt += "<tr><td>Ausgang an D4 schalten</td><td>";
  if (cfg.data_relais_enable == 1) {
    inhalt += "<span style='color:#008700'>aktiviert</span>"; // (" ;
  } else {
    inhalt += "<i>nicht aktiviert</i>";
  }
  inhalt += "</td></tr>";
  //inhalt += "</td></tr>";
  inhalt += "</table>";
  inhalt += "</details>";

  inhalt += "<br>";

  inhalt += "<details>";
  inhalt += "<summary style='background-color:#2e86c1;color:#ffffff;padding:5px;'>Sonstiges</summary>";
  inhalt += "<table style='font-size:14px;'>";
  inhalt += "<tr><td><a href=\"/cfg\"><button style=\"background-color: #F7D358; padding: 8px 24px; color: black; border: none; font-size: 14px; border-radius: 4px; width: 150px;\">Konfiguration</button></a></td></tr>";
  inhalt += "<tr><td><br><br><br></td></tr>";
  inhalt += "<tr><td><a href=\"/boot\"><button style=\"background-color: #fa0000; padding: 8px 24px; color: white; border: none; font-size: 14px; border-radius: 4px; width: 150px;\">Sensor restarten</button></a></td></tr>";
  inhalt += "</table>";
  inhalt += "</details>";

  inhalt += "</div>";

  inhalt += "</body>";
  inhalt += "</html>";

  server.send(200, "text/html", inhalt);
}


//********************************************************
void webHandleConfig() {
  String inhalt;

  inhalt  = "<!DOCTYPE html>";
  inhalt += "<html><head><meta name='viewport' content='width=device-width, initial-scale=1.0'><title>" + anwendungsname + "</title></head><body style='font-family:verdana;background-color:#B9DFF8;color:#000000;margin:0px;font-size:11px;'>";
  inhalt += "<p style='font-size:24px;font-weight:bold;background-color:#FFFFFF;color:#000000;padding:30px;padding-left:10px;margin:0px;'>" + anwendungsname + " <span style='font-size:12px;font-weight:normal;'>v" + fw_version + "</span></p>";
  inhalt += "<p style='font-size:18px;font-weight:bold;background-color:#85C5EE;padding-left:10px;padding-top:10px;padding-bottom:10px;margin:0px;'>Konfiguration</p>";

  inhalt += "<div style='padding-left:10px;padding-right:10px;'>";
  if (stationList == "") {
    inhalt += "<br>";
    inhalt += "<a href=\"/\"><button style=\"background-color: #F7D358; padding: 10px 26px; color: black; border: none; font-size: 16px; border-radius: 4px;\">zur&uuml;ck zur Startseite</button></a>";
    inhalt += "<br>";
  }

  inhalt += "</p><form method='get' action='save' enctype='multipart/form-data'>";

  inhalt += "<table style=''>";


  //**********
  //WLAN
  //**********
  inhalt += "<tr><td colspan=2 style='color:#ffffff;background-color:#2e86c1;padding:5px;'>WLAN</td></tr>";
  if (stationList != "") {
    inhalt += "<tr><td colspan=2>Folgende WLAN-Netze wurden gefunden:</td></tr>";
    inhalt += "<tr>";
    inhalt += stationList;
    inhalt += "<br><br></tr>";
  }
  inhalt += "<tr><td>SSID</td><td><input type='text' size=25 maxlength=30 name='SSID' value='";
  if (stationList == "") {
    inhalt += cfg.SSID;
  }
  inhalt += "'></td></tr>";
  inhalt += "<tr><td>Passwort (<i>max. 63 Zeichen</i>)</td><td><input type='text' size=35 maxlength=63 name='password' value='";
  if (stationList == "") {
    inhalt += cfg.password;
  }
  inhalt += "'></td></tr>";
  inhalt += "<tr><td>Dauer Access Point-Modus</td><td><input type='text' size=5 maxlength=4 name='dauer_ap_form' disabled value='";
  //if (stationList == "") { inhalt += cfg.data_dauer_ap; }
  inhalt += "'> Sekunden <span style='font-size:12px;'>(z.Zt. noch deaktiviert)</span></td></tr>";
  inhalt += "<tr><td><br></td><td><br></td></tr>";

  if (stationList == "") {

    //**********
    //Eigene API
    //**********
    inhalt += "<tr><td colspan=2 style='color:#ffffff;background-color:#2e86c1;padding:5px;'><input type='checkbox' name='eigenapi_check_form' ";
    if (cfg.data_eigenapi_check == 1) {
      inhalt += " checked ";
    }
    inhalt += ">Daten an eigene API senden (POST)</td></tr>";
    inhalt += "<tr><td colspan=2 style='font-size:12px;color:#084B8A;'>Hier k&ouml;nnen die Sensorwerte an eine eigene API &uuml;bergeben werden. Dabei wird eine konfigurierbare URL aufgerufen und die Werte f&uuml;r den Abstand und den F&uuml;llstand in den Variablen _abstand und _fuellstand &uuml;bergeben.<br>Beispiel: &lt;server&gt;:&lt;port&gt;/&lt;pfad&gt;?abs=_abstand&hoehe=_fuellstand</td></tr>";
    inhalt += "<tr><td>Server</td><td><input type='text' size=25 maxlength=30 name='eigenapi_server_form' value='";
    if (stationList == "") {
      inhalt += cfg.data_eigenapi_server;
    }
    inhalt += "'></td></tr>";
    inhalt += "<tr><td>Pfad</td><td><input type='text' size=35 maxlength=50 name='eigenapi_pfad_form' value='";
    if (stationList == "") {
      inhalt += cfg.data_eigenapi_pfad;
    }
    inhalt += "'></td></tr>";
    inhalt += "<tr><td>Port</td><td><input type='text' size=4 maxlength=5 name='eigenapi_port_form' value='";
    if (stationList == "") {
      inhalt += cfg.data_eigenapi_port;
    }
    inhalt += "'></td></tr>";
    inhalt += "<tr><td>Intervall</td><td><input type='number' size=6 maxlength=5 name='eigenapi_intervall_form' value='";
    if (stationList == "") {
      inhalt += cfg.data_eigenapi_intervall;
    }
    inhalt += "'> Sekunden</td></tr>";
    inhalt += "<tr><td><br></td><td><br></td></tr>";


    //*********
    //Web API
    //*********
    inhalt += "<tr><td colspan=2 style='color:#ffffff;background-color:#2e86c1;padding:5px;'><input type='checkbox' name='webapi_check_form' ";
    if (cfg.data_webapi_check == 1) {
      inhalt += " checked ";
    }
    inhalt += ">bubux.de Web-API nutzen</td></tr>";
    inhalt += "<tr><td colspan=2 style='font-size:12px;color:#084B8A;'>Mit der WebAPI werden die Daten (F&uuml;llstand, MAC-Adresse, lokale IP und Firmware-Version) an www.bubux.de gesendet wo eine graphische Auswertung des Zisternenf&uuml;llstands der letzten 30 Tage aufbereitet wird. Auf diese Auswertung kann &uuml;ber einen Link in der Web-Oberfl&auml;che des jeweiligen Sensors zugegriffen werden.</td></tr>";
    inhalt += "<tr><td><br></td><td><br></td></tr>";


    //****************
    //Temperatursensor
    //****************
    inhalt += "<tr><td colspan=2 style='color:#ffffff;background-color:#2e86c1;padding:5px;'><input type='checkbox' name='temp_check_enable' ";
    if (cfg.data_temperatur_enable == 1) {
      inhalt += " checked ";
    }
    inhalt += ">Temperatur-/Luftfeuchte-Sensor integrieren</td></tr>";

    inhalt += "<tr><td>DHT22-Sensor</td><td><input type='radio' name='temp_check_form' value='1'";
    if (cfg.data_temperatur == 1) {
      inhalt += " checked ";
    }
    inhalt += "'> an GPIO-Pin 14 (D5) mit 10k&#8486; von Daten gegen VCC</td></tr>";
    inhalt += "<tr><td></td><td></td></tr>";

    inhalt += "<tr><td>BME280</td><td><input type='radio' disabled='disabled' name='temp_check_form' value='2'";
    if (cfg.data_temperatur == 2) {
      inhalt += " checked ";
    }
    inhalt += "'> (noch nicht implementiert)</td></tr>";
    
    inhalt += "<tr><td>DS18B20</td><td><input type='radio' disabled='disabled' name='temp_check_form' value='3'";
    if (cfg.data_temperatur == 3) {
      inhalt += " checked ";
    }
    inhalt += "'> (noch nicht implementiert)</td></tr>";
    inhalt += "<tr><td><br></td><td><br></td></tr>";


    //**********
    //MQTT
    //**********
    inhalt += "<tr><td colspan=2 style='color:#ffffff;background-color:#2e86c1;padding:5px;'><input type='checkbox' name='mqtt_check_form' ";
    if (cfg.data_mqtt_check == 1) {
      inhalt += " checked ";
    }
    inhalt += ">Daten an MQTT-Broker senden</td></tr>";
    //inhalt += "<tr><td colspan=2 style='font-size:12px;color:#084B8A;'>Wenn aktiviert, werden die Sensordaten f&uuml;r F&uuml;llstand und Abstand an einen MQTT-Broker gesendet.</td></tr>";
    inhalt += "<tr><td>Server</td><td><input type='text' size=25 maxlength=30 name='mqtt_server_form' placeholder='IP oder URL des MQTT-Servers' value='";
    if (stationList == "") {
      inhalt += cfg.data_mqtt_server;
    }
    inhalt += "'></td></tr>";
    inhalt += "<tr><td>Port</td><td><input type='text' size=4 maxlength=5 name='mqtt_port_form' value='";
    if (stationList == "") {
      inhalt += cfg.data_mqtt_port;
    }
    inhalt += "'> wenn leer bzw. '0' wird der MQTT-Standardport 1883 genutzt</td></tr>";
    inhalt += "<tr><td>Benutzer</td><td><input type='text' size=35 maxlength=50 name='mqtt_benutzer_form' placeholder='Benutzername' value='";
    if (stationList == "") {
      inhalt += cfg.data_mqtt_benutzer;
    }
    inhalt += "'></td></tr>";
    inhalt += "<tr><td>Passwort</td><td><input type='text' size=35 maxlength=50 name='mqtt_passwort_form' placeholder='Passwort' value='";
    if (stationList == "") {
      inhalt += cfg.data_mqtt_passwort;
    }
    inhalt += "'></td></tr>";
    inhalt += "<tr><td>Topic <i>F&uuml;llstand</i></td><td><input type='text' size=35 maxlength=50 name='mqtt_topic_form' placeholder='z.B. /hausautomation/garten/zisternenfuellstand' value='";
    if (stationList == "") {
      inhalt += cfg.data_mqtt_topic;
    }
    inhalt += "'></td></tr>";
    inhalt += "<tr><td>Topic <i>Abstand</i></td><td><input type='text' size=35 maxlength=50 name='mqtt_topic_abstand_form' value='";
    if (stationList == "") {
      inhalt += cfg.data_mqtt_abstand_topic;
    }
    inhalt += "'></td></tr>";
    inhalt += "<tr><td>Topic <i>Liter</i> (nur wenn Literangabe aktiviert ist)</td><td><input type='text' size=35 maxlength=40 name='mqtt_topic_liter_form' value='";
    if (stationList == "") {
      inhalt += cfg.data_mqtt_liter_topic;
    }
    inhalt += "'></td></tr>";
    inhalt += "<tr><td>Topic <i>Temperatur</i> (nur wenn Sensor genutzt wird)</td><td><input type='text' size=35 maxlength=50 name='mqtt_topic_temperature_form' value='";
    if (stationList == "") {
      inhalt += cfg.data_mqtt_temperature_topic;
    }
    inhalt += "'></td></tr>";
    inhalt += "<tr><td>Topic <i>Luftfeuchtigkeit</i> (nur wenn Sensor genutzt wird)</td><td><input type='text' size=35 maxlength=50 name='mqtt_topic_humidity_form' value='";
    if (stationList == "") {
      inhalt += cfg.data_mqtt_humidity_topic;
    }
    inhalt += "'></td></tr>";
    inhalt += "<tr><td>Intervall</td><td><input type='number' size=6 maxlength=5 name='mqtt_intervall_form' value='";
    if (stationList == "") {
      inhalt += cfg.data_mqtt_intervall;
    }
    inhalt += "'> Sekunden</td></tr>";
    inhalt += "<tr><td><br></td><td><br></td></tr>";
    //*********
    //Hinweis zum JSON
    //*********
    inhalt += "<tr><td colspan=2 style='color:#ffffff;background-color:#2e86c1;padding:5px;'>Daten per JSON abfragen</td></tr>";
    inhalt += "<tr><td colspan=2 style='font-size:12px;color:#084B8A;'>Mit /json hinter die URL des Sensor, k&ouml;nnen die Messwerte per JSON abgefragt werden <a href='/json' target='_BLANK'>" + ipAdresse + "/json</a>.</td></tr>";
    inhalt += "<tr><td><br></td><td><br></td></tr>";


    //*********
    //OTA
    //*********
    inhalt += "<tr><td colspan=2 style='color:#ffffff;background-color:#2e86c1;padding:5px;'><input type='checkbox' name='ota_check_form' ";
    if (cfg.data_ota_check == 1) {
      inhalt += " checked ";
    }
    inhalt += ">OverTheAir Update aktivieren</td></tr>";
    inhalt += "<tr><td colspan=2 style='font-size:12px;color:#084B8A;'>Mit der Aktivierung von OTA pr&uuml;ft der Sensor in regelm&auml;&szlig;igen Abst&auml;nden ob eine neue Firmwareversion verf&uuml;gbar ist und installiert diese.<br>Aktuell geschieht die Bereitstellung neuer Updates nur auf Anfrage mit Angabe der MAC-Adresse.</td></tr>";
    inhalt += "<tr><td><br></td><td><br></td></tr>";

    //**********
    //Sensor
    //**********
    inhalt += "<tr><td colspan=2 style='color:#ffffff;background-color:#2e86c1;padding:5px;'>Sensordaten & Bauform</td></tr>";

    inhalt += "<tr><td>Sensorname</td><td><input type='text' size=20 width=60 maxlength=30 name='sensorname_form' value='";
    if (stationList == "") {
      inhalt += cfg.data_sensorname;
    }
    inhalt += "'> <i> Wird erst nach Neustart des Sensors aktiv</i></td></tr>";
    
    inhalt += "<tr><td><br><br></td><td></td></tr>";
    inhalt += "<tr><td colspan=2 style='color:red;'>Bei Wechsel des Sensors und der Abstands-Modis etc. ist ein Neustart des Sensors notwendig (ESP vom Strom trennen!!)</td></tr>";
    
    inhalt += "<tr><td>HC-SR04 Ultraschallsensor (D1->Echo, D2->Trigger)</td><td><input type='radio' name='zisterne_sensor_form' value='1' ";
    if (cfg.data_zisterne_sensor == 1) {
      inhalt += " checked ";
    }
    inhalt += " ></td></tr>";

    inhalt += "<tr><td>VL53L0X TOF-Sensor (D1->SCL, D2->SDA, I&sup2;C 0x29)</td><td><input type='radio' name='zisterne_sensor_form' value='2' ";
    if (cfg.data_zisterne_sensor == 2) {
      inhalt += " checked ";
    }
    inhalt += " ></td></tr>";

    inhalt += "<tr><td><br><br></td><td>&nbsp;&nbsp;&nbsp; Abstands-Modus: <select name='distance_mode_vl53l0x_form'><option value=0 ";
    if (stationList == "" && cfg.data_distance_mode_vl53l0x == 0) {
      inhalt += " selected";
    }
    inhalt += ">Short</option><option value=1 ";
    if (stationList == "" && cfg.data_distance_mode_vl53l0x == 1) {
      inhalt += " selected";
    }
    inhalt += ">Long</option></select></td></tr>";

    inhalt += "<tr><td><br><br></td><td>&nbsp;&nbsp;&nbsp; Timing: <select name='accuracy_mode_vl53l0x_form'><option value=0 ";
    if (stationList == "" && cfg.data_accuracy_mode_vl53l0x == 0) {
      inhalt += " selected";
    }
    inhalt += ">Normal</option><option value=1 ";
    if (stationList == "" && cfg.data_accuracy_mode_vl53l0x == 1) {
      inhalt += " selected";
    }
    inhalt += ">High Accuracy</option><option value=2 ";
    if (stationList == "" && cfg.data_accuracy_mode_vl53l0x == 2) {
      inhalt += " selected";
    }
    inhalt += ">High Speed</option></select></td></tr>";


    inhalt += "<tr><td>VL53L1X TOF-Sensor (D1->SCL, D2->SDA, I&sup2;C 0x29)</td><td><input type='radio' name='zisterne_sensor_form' value='3' ";
    if (cfg.data_zisterne_sensor == 3) {
      inhalt += " checked ";
    }
    inhalt += " ></td></tr>";

    inhalt += "<tr><td><br><br></td><td>&nbsp;&nbsp;&nbsp; Abstands-Modus: <select name='distance_mode_vl53l1x_form'><option value=0 ";
    if (stationList == "" && cfg.data_distance_mode_vl53l1x == 0) {
      inhalt += " selected";
    }
    inhalt += ">Short (1,3m)</option><option value=1 ";
    if (stationList == "" && cfg.data_distance_mode_vl53l1x == 1) {
      inhalt += " selected";
    }
    inhalt += ">Long (4m)</option></select></td></tr>";

    inhalt += "<tr><td><br><br></td><td></td></tr>";

    inhalt += "<tr><td>Abstand Sensor/Boden</td><td><input type='text' size=4 width=60 maxlength=4 name='abst_sen_boden_form' value='";
    if (stationList == "") {
      inhalt += cfg.data_abst_sen_boden;
    }
    inhalt += "'> cm</td></tr>";
    inhalt += "<tr><td>Abstand Sensor/Max. Wasserstand</td><td><input type='text' size=4 width=60 maxlength=4 name='abst_sen_max_form' value='";
    if (stationList == "") {
      inhalt += cfg.data_abst_sen_max;
    }
    inhalt += "'> cm</td></tr>";


    //****************
    //Zisternenbauform
    //****************
    //Zylinder
    inhalt += "<tr><td>Zisternenform zur Berechnung des Volumen</td><td><input type='radio' name='zisterne_bauform_form' value='1' ";
    if (strcmp(cfg.data_zisterne_bauform, "1") == 0) {
      inhalt += " checked ";
    }
    inhalt += " >Zylinderf&ouml;rmig (stehend) mit einem Durchmesser von <input type='text' name='zisterne_durchmesser_form' size=4 width=10 maxlength=5 value='";
    if (stationList == "") {
      inhalt += cfg.data_zisterne_durchmesser;
    }
    inhalt += "'> cm</td></tr>";

    //Zylinder liegend
    inhalt += "<tr><td></td><td><input type='radio' name='zisterne_bauform_form' value='5' ";
    if (strcmp(cfg.data_zisterne_bauform, "5") == 0) {
      inhalt += " checked ";
    }
    inhalt += " >Zylinderf&ouml;rmig (liegend) mit einem Durchmesser von <input type='text' name='zisterne_durchmesser_liegend_form' size=4 width=10 maxlength=5 value='";
    if (stationList == "") {
      inhalt += cfg.data_zisterne_durchmesser_liegend;
    }
    inhalt += "'> cm";
    inhalt += " und L&auml;nge von <input type='text' name='zisterne_laenge_liegend_form' size=4 width=10 maxlength=5 value='";
    if (stationList == "") {
      inhalt += cfg.data_zisterne_laenge_liegend;
    }
    inhalt += "'> cm</td></tr>";

    //Quader
    inhalt += "<tr><td></td><td><input type='radio' name='zisterne_bauform_form' value='2' ";
    if (strcmp(cfg.data_zisterne_bauform, "2") == 0) {
      inhalt += " checked ";
    }
    inhalt += ">Quaderf&ouml;rmig mit Seite A <input type='text' name='zisterne_x_form' size=4 width=10 maxlength=5 value='";
    if (stationList == "") {
      inhalt += cfg.data_zisterne_x;
    }
    inhalt += "'> cm";
    inhalt += " und Seite B <input type='text' name='zisterne_y_form' size=4 width=10 maxlength=5 value='";
    if (stationList == "") {
      inhalt += cfg.data_zisterne_y;
    }
    inhalt += "'> cm</td></tr>";
    inhalt += "<tr><td></td><td><input type='radio' name='zisterne_bauform_form' value='3' ";

    //mit Grundfläche
    if (strcmp(cfg.data_zisterne_bauform, "3") == 0) {
      inhalt += " checked ";
    }
    inhalt += ">Grundfl&auml;che von <input type='text' name='zisterne_fl_form' size=4 width=10 maxlength=5 value='";
    if (stationList == "") {
      inhalt += cfg.data_zisterne_fl;
    }
    inhalt += "'> cm&sup2;</td></tr>";

    //mit max. Volumen
    inhalt += "<tr><td></td><td><input type='radio' name='zisterne_bauform_form' value='4' ";
    if (strcmp(cfg.data_zisterne_bauform, "4") == 0) {
      inhalt += " checked ";
    }
    inhalt += ">Maximalvolumen der Zisterne <input type='text' name='zisterne_vl_form' size=4 width=10 maxlength=5 value='";
    if (stationList == "") {
      inhalt += cfg.data_zisterne_vl;
    }
    inhalt += "'> Liter</td></tr>";


    inhalt += "<tr><td>Anzeige 'Liter' aktivieren</td><td><input type='checkbox' name='anzeige_liter_check_form' ";
    if (cfg.data_anzeige_liter_check == 1) {
      inhalt += " checked ";
    }
    inhalt += "></td></tr>";
    inhalt += "<tr><td>Anzeige Dezimalstellen</td><td><select name='dezstellen_anzeige_form'><option value=0 ";
    if (stationList == "" && cfg.data_dezstellen_anzeige == 0) {
      inhalt += " selected";
    }
    inhalt += ">keine</option><option value=1 ";
    if (stationList == "" && cfg.data_dezstellen_anzeige == 1) {
      inhalt += " selected";
    }
    inhalt += ">1</option><option value=2 ";
    if (stationList == "" && cfg.data_dezstellen_anzeige == 2) {
      inhalt += " selected";
    }
    inhalt += ">2</option></select></td></tr>";
    inhalt += "<tr><td><br></td><td><br></td></tr>";


    //****************
    //Externes Display
    //****************
    inhalt += "<tr><td colspan=2 style='color:#ffffff;background-color:#2e86c1;padding:5px;'><input type='checkbox' name='display_on' ";
    if (cfg.data_display_enable == 1) {
      inhalt += " checked ";
    }
    inhalt += ">Externes Display &uuml;ber I&sup2;C angeschlossen</td></tr>";

    inhalt += "<tr><td>LCD '1602' Display an: (I&sup2;C 0x27)</td><td><input type='radio' name='display_form' value='1'";
    if (cfg.data_display == 1) {
      inhalt += " checked ";
    }
    inhalt += "'></td></tr>";
    inhalt += "<tr><td></td><td></td></tr>";

    inhalt += "<tr><td>LCD '1604, 2004' Display an: (I&sup2;C 0x27)</td><td><input type='radio' name='display_form' value='2'";
    if (cfg.data_display == 2) {
      inhalt += " checked ";
    }
    inhalt += "'></td></tr>";
    inhalt += "<tr><td></td><td></td></tr>";

    inhalt += "<tr><td>OLED 'SSD 1106, 1306', 128x64 Display an: (I&sup2;C 0x3C, 0x3D)</td><td><input type='radio' name='display_form' value='3'";
    if (cfg.data_display == 3) {
      inhalt += " checked ";
    }
    inhalt += "'></td></tr>";
    inhalt += "<tr><td><br></td><td><br></td></tr>";


    //***************
    //Externes Relais
    //***************
    inhalt += "<tr><td colspan=2 style='color:#ffffff;background-color:#2e86c1;padding:5px;'><input type='checkbox' name='relais_on' ";
    if (cfg.data_relais_enable == 1) {
      inhalt += " checked ";
    }
    inhalt += ">Ausgang D4 schalten (z.B. f&uuml;r Pumpe &uuml;ber Relais)</td></tr>";

    inhalt += "<tr><td>Anschalten wenn Wasserstand</td><td><select name='relais_an_krit_form'><option value=0 ";
    if (stationList == "" && cfg.data_relais_an_krit == 0) {
      inhalt += " selected";
    }
    inhalt += ">&lt;</option><option value=1 ";
    if (stationList == "" && cfg.data_relais_an_krit == 1) {
      inhalt += " selected";
    }
    inhalt += ">&gt;</option></select><input type='text' name='relais_an_wert_form' size=4 width=10 maxlength=3 value='";
    if (stationList == "") {
      inhalt += cfg.data_relais_an_wert;
    }
    inhalt += "'> %</td></tr>";
    inhalt += "<tr><td></td><td></td></tr>";

    inhalt += "<tr><td>Ausschalten wenn Wasserstand</td><td><select name='relais_aus_krit_form'><option value=0 ";
    if (stationList == "" && cfg.data_relais_aus_krit == 0) {
      inhalt += " selected";
    }
    inhalt += ">&lt;</option><option value=1 ";
    if (stationList == "" && cfg.data_relais_aus_krit == 1) {
      inhalt += " selected";
    }
    inhalt += ">&gt;</option></select><input type='text' name='relais_aus_wert_form' size=4 width=10 maxlength=3 value='";
    if (stationList == "") {
      inhalt += cfg.data_relais_aus_wert;
    }
    inhalt += "'> %</td></tr>";
    inhalt += "<tr><td><br></td><td><br></td></tr>";

    //****************
    //Externes Relais2
    //****************
    /*
    inhalt += "<tr><td colspan=2 style='color:#ffffff;background-color:#2e86c1;padding:5px;'><input type='checkbox' name='relais2_on' ";
    if (cfg.data_relais2_enable == 1) {
      inhalt += " checked ";
    }
    inhalt += ">Ausgang D3 schalten (z.B. zum &Ouml;ffnen von Magnetventil zur Sp&uuml;lung)</td></tr>";
    inhalt += "<tr><td>Anschalten f&uuml;r</td><td><input type='text' name='relais2_dauer_form' size=2 maxlength=1 value='";
    if (stationList == "") {
      inhalt += cfg.data_relais2_dauer;
    }
    inhalt += "'> Minuten jeweils <select name='relais2_tag_form'><option value=0 ";
    if (stationList == "" && cfg.data_relais2_tag == 0) {
      inhalt += " selected";
    }
    inhalt += ">t&auml;glich</option><option value=1 ";
    if (stationList == "" && cfg.data_relais2_tag == 1) {
      inhalt += " selected";
    }
    inhalt += ">Montag</option><option value=2 ";
    if (stationList == "" && cfg.data_relais2_tag == 2) {
      inhalt += " selected";
    }
    inhalt += ">Dienstag</option><option value=3 ";
    if (stationList == "" && cfg.data_relais2_tag == 3) {
      inhalt += " selected";
    }
    inhalt += ">Mittwoch</option><option value=4 ";
    if (stationList == "" && cfg.data_relais2_tag == 4) {
      inhalt += " selected";
    }
    inhalt += ">Donnerstag</option><option value=5 ";
    if (stationList == "" && cfg.data_relais2_tag == 5) {
      inhalt += " selected";
    }
    inhalt += ">Freitag</option><option value=6 ";
    if (stationList == "" && cfg.data_relais2_tag == 6) {
      inhalt += " selected";
    }
    inhalt += ">Samsatg</option><option value=7 ";
    if (stationList == "" && cfg.data_relais2_tag == 7) {
      inhalt += " selected";
    }
    inhalt += ">Sonntag</option>";
    inhalt += "</select> um <select name='relais2_zeit_form'>";
    int r;
    for (r = 0; r <= 23; r++) {
      inhalt += "<option ";
      if (stationList == "" && cfg.data_relais2_zeit == r) {
        inhalt += " selected";
      }
      inhalt += ">";
      inhalt += r;
      inhalt += "</option>";
    }
    r = 0;
    inhalt += "</select> Uhr</td></tr>";
    inhalt += "<tr><td><br></td><td><br></td></tr>";
    */


    //*****************************************************
    //Display an D5 angeschlossen (wichtig für Sensorreset)
    //*****************************************************
    //inhalt += "<tr><td colspan=2 style='color:#ffffff;background-color:#2e86c1;padding:5px;'><input type='checkbox' name='sens_on' ";
    //if (cfg.data_senson == 1) {
    //inhalt +=" checked ";
    //}
    //inhalt += ">Sensor VCC an D5 angeschlossen</td></tr>";
    //inhalt += "</td></tr>";
    //inhalt += "<tr><td><br></td><td><br></td></tr>";


    //**********
    //NTP
    //**********
    // Aktuell noch deakiviert
    inhalt += "<tr><td colspan=2 style='color:#ffffff;background-color:#2e86c1;padding:5px;'>NTP</td></tr>";
    inhalt += "<tr><td>Zeitserver</td><td><input type='text' size=25 maxlength=50 name='ntp_server_form' disabled value=''";
    //if (stationList == "") { inhalt += cfg.data_ntp_server; }
    inhalt += "'> wenn leer wird 'pool.ntp.org' genutzt <span style='font-size:12px;'>(Konfiguration z.Zt. noch deaktiviert)</span></td></tr>";
    inhalt += "<tr><td><br></td><td><br></td></tr>";


    //*********
    //Pushover
    //*********
    inhalt += "<tr><td colspan=2 style='color:#ffffff;background-color:#2e86c1;padding:5px;'><input type='checkbox' name='pushover_check_form' ";
    if (cfg.data_pushover_check == 1) {
      inhalt += " checked ";
    }
    inhalt += ">F&uuml;llstand per Pushover versenden</td></tr>";
    inhalt += "<tr><td colspan=2 style='font-size:12px;color:#084B8A;'>Sendet einmal t&auml;glich zur gew&auml;hlten Stunde den Zisternenf&uuml;llstand per Pushover-Nachricht</td></tr>";
    inhalt += "<tr><td>Pushover AppToken</td><td><input type='text' size=35 maxlength=30 name='pushover_apptoken_form' value='";
    if (stationList == "") {
      inhalt += cfg.data_pushover_apptoken;
    }
    inhalt += "'></td></tr>";
    inhalt += "<tr><td>Pushover UserToken</td><td><input type='text'size=35 maxlength=30 name='pushover_usertoken_form' value='";
    if (stationList == "") {
      inhalt += cfg.data_pushover_usertoken;
    }
    inhalt += "'></td></tr>";
    inhalt += "<tr><td>Uhrzeit (Stunde)</td><td><select name='relais2_zeit_form'>";
    int i;
    for (i = 0; i <= 23; i++) {
      inhalt += "<option ";
      if (stationList == "" && cfg.data_pushover_zeit == i) {
        inhalt += " selected";
      }
      inhalt += ">";
      inhalt += i;
      inhalt += "</option>";
    }
    i = 0;
    inhalt += "</select></td></tr>";
    inhalt += "<tr><td><br></td><td><br></td></tr>";
    //inhalt += "<tr><td></td><td><a href=\"/pushtest\" style=\"padding:5px 14px;border:1px solid #999;background:#A9A9A9;color:#fff;text-decoration:none;font-size: 14px;\">Testnachricht senden</a> (Daten vorher speichern)</td></tr>";
    //inhalt += "<tr><td><br></td><td><br></td></tr>";


    //*********
    //Mailteil
    //*********
    //  inhalt += "<tr><td colspan=2 style='color:#ffffff;background-color:#2e86c1;padding:5px;'><input type='checkbox' name='mail_check_form' ";
    //  if (cfg.data_mail_check==1) {
    //    inhalt +=" checked ";
    //  }
    //  inhalt += ">Mail versenden</td></tr>";
    //  inhalt += "<tr><td colspan=2 style='font-size:12px;color:#084B8A;'>Sendet einmal t&auml;glich zur gew&auml;hlten Stunde den Zisternenf&uuml;llstand per E-Mail</td></tr>";
    //  inhalt += "<tr><td>Mailserver</td><td><input type='text' size=25 maxlength=30 name='mail_server_form' value='";
    //  if (stationList == "") { inhalt += cfg.data_mail_server; }
    //  inhalt += "'></td></tr>";
    //  inhalt += "<tr><td>Port</td><td><input type='text' size=5 maxlength=4 name='mail_port_form' value='";
    //  if (stationList == "") { inhalt += cfg.data_mail_port; }
    //  inhalt += "'></td></tr>";
    //  inhalt += "<tr><td>SSL</td><td><input type='checkbox' name='mail_ssl_form' ";
    //  if (cfg.data_mail_ssl==1) {
    //    inhalt +=" checked ";
    //  }
    //  inhalt += "'></td></tr>";
    //  inhalt += "<tr><td>Benutzer</td><td><input type='text' size=25 maxlength=30 name='mail_benutzer_form' value='";
    //  if (stationList == "") { inhalt += cfg.data_mail_benutzer; }
    //  inhalt += "'></td></tr>";
    //  inhalt += "<tr><td>Passwort</td><td><input type='text' size=25 maxlength=30 name='mail_passwort_form' value='";
    //  if (stationList == "") { inhalt += cfg.data_mail_passwort; }
    //  inhalt += "'></td></tr>";
    //  inhalt += "<tr><td>Uhrzeit (Stunde)</td><td><select name='mail_zeit_form'>";
    //  for (i=0;i<=23;i++) {
    //    inhalt += "<option ";
    //    if (stationList == "" && cfg.data_mail_zeit==i) { inhalt += " selected";}
    //    inhalt += ">";
    //    inhalt += i;
    //    inhalt += "</option>";
    //  }
    //  i=0;
    //  inhalt += "</select></td></tr>";
    //  inhalt += "<tr><td><br></td><td><br></td></tr>";
    //  inhalt += "<tr><td></td><td><a href=\"/mailtest\" style=\"padding:5px 14px;border:1px solid #999;background:#A9A9A9;color:#fff;text-decoration:none;font-size: 14px;\">Testmail senden</a> (Daten vorher speichern)</td></tr>";

    inhalt += "<tr><td><br></td><td><br></td></tr>";

  }

  inhalt += "<tr><br><td colspan=2><input type=\"submit\" style=\"background-color: #4CAF50; padding: 10px 26px; color: white; border: none; font-size: 16px; border-radius: 4px;\" value=\"Konfiguration speichern\"></td></tr>";
  inhalt += "</table>";
  inhalt += "</div>";
  inhalt += "</form>";
  inhalt += "</body>";
  inhalt += "</html>";
  inhalt += "\r\n\r\n";
  server.send(200, "text/html", inhalt);
}

//********************************************************
void webHandleConfigSave() {
  String inhalt;

  inhalt  = "<!DOCTYPE html>";
  inhalt += "<html>";
  inhalt += "<html><head><meta name='viewport' content='width=device-width, initial-scale=1.0'><title>" + anwendungsname + "</title></head><body style='font-family:verdana;background-color:#B9DFF8;color:#000000;margin:0px'>";
  inhalt += "<p style='font-size:24px;font-weight:bold;background-color:#FFFFFF;color:#000000;padding:30px;padding-left:10px;margin:0px;'>" + anwendungsname + "</p>";
  inhalt += "<p style='font-size:18px;font-weight:bold;background-color:#85C5EE;padding-left:10px;padding-top:10px;padding-bottom:10px;margin:0px;'>Einstellungen gespeichert</p>";
  inhalt += "<br>";
  inhalt += "<div style='padding-left:10px'>";
  inhalt += "<a href=\"/\"><button style=\"background-color: #F7D358; padding: 10px 26px; color: black; border: none; font-size: 16px; border-radius: 4px;\">zur&uuml;ck zur Startseite</button></a>";
  inhalt += "<br>";
  inhalt += "<p>Die Konfiguration wurde erfolgreich gespeichert<br><br><b>Bei &Auml;nderungen an der WLAN-Konfiguration muss der ESP resetet oder vom Strom getrennt werden!</b></p>";
  inhalt += "</div>";
  inhalt += "</body>";
  inhalt += "</html>";
  inhalt += "\r\n\r\n";
  server.send(200, "text/html", inhalt);

  // ToDo: Weblink unterschiedlich bei AP und STA

  eraseConfig();

  cfg.valid = 1;

  //************************************************************
  //Sensordaten
  //************************************************************
  if (server.hasArg("abst_sen_boden_form")) {
    cfg.data_abst_sen_boden = server.arg("abst_sen_boden_form").toInt();
    //Serial.println(cfg.data_abst_sen_boden);
  }
  if (server.hasArg("abst_sen_max_form")) {
    cfg.data_abst_sen_max = server.arg("abst_sen_max_form").toInt();
    //Serial.println(cfg.data_abst_sen_max);
  }

  //************************************************************
  //WLAN
  //************************************************************
  if (server.hasArg("SSID")) {
    String SSID;
    SSID = server.arg("SSID");
    SSID.replace("%2F", "/");
    SSID.toCharArray(cfg.SSID, (sizeof(cfg.SSID) - 1) );
  }
  if (server.hasArg("password")) {
    String password;
    password = server.arg("password");
    password.replace("%2F", "/");
    password.toCharArray(cfg.password, (sizeof(cfg.password) - 1) );
  }

  //************************************************************
  //Eigene API
  //************************************************************
  if (server.hasArg("eigenapi_check_form")) {
    //Serial.print(cfg.data_eigenapi_check);
    if (server.arg("eigenapi_check_form") == "on") {
      cfg.data_eigenapi_check = 1;
    } else {
      cfg.data_eigenapi_check = 0;
    }
  } else {
    cfg.data_eigenapi_check = 0;
  }
  if (server.hasArg("eigenapi_server_form")) {
    String ea_server;
    ea_server = server.arg("eigenapi_server_form");
    ea_server.replace("%2F", "/");
    ea_server.toCharArray(cfg.data_eigenapi_server, (sizeof(cfg.data_eigenapi_server) - 1) );
  }
  if (server.hasArg("eigenapi_pfad_form")) {
    String ea_pfad;
    ea_pfad = server.arg("eigenapi_pfad_form");
    ea_pfad.replace("%2F", "/");
    ea_pfad.toCharArray(cfg.data_eigenapi_pfad, (sizeof(cfg.data_eigenapi_pfad) - 1) );
  }
  if (server.hasArg("eigenapi_port_form")) {
    cfg.data_eigenapi_port = server.arg("eigenapi_port_form").toInt();
  }
  if (server.hasArg("eigenapi_intervall_form")) {
    cfg.data_eigenapi_intervall = server.arg("eigenapi_intervall_form").toInt();
  }

  //************************************************************
  //Web API
  //************************************************************
  if (server.hasArg("webapi_check_form")) {
    //Serial.print(cfg.data_webapi_check);
    if (server.arg("webapi_check_form") == "on") {
      cfg.data_webapi_check = 1;
    } else {
      cfg.data_webapi_check = 0;
    }
  } else {
    cfg.data_webapi_check = 0;
  }

  //OTA
  if (server.hasArg("ota_check_form")) {
    if (server.arg("ota_check_form") == "on") {
      cfg.data_ota_check = 1;
    } else {
      cfg.data_ota_check = 0;
    }
  } else {
    cfg.data_ota_check = 0;
  }

  //************************************************************
  //Temperatursensoren
  //************************************************************
  if (server.hasArg("temp_check_enable")) {
    if (server.arg("temp_check_enable") == "on") {
      cfg.data_temperatur_enable = 1;
    } else {
      cfg.data_temperatur_enable = 0;
    }
  } else {
    cfg.data_temperatur_enable = 0;
  }
  if (server.arg("temp_check_form") == "1") {
    cfg.data_temperatur = 1;
  }
  if (server.arg("temp_check_form") == "2") {
    cfg.data_temperatur = 2;
  }


  //************************************************************
  //MQTT
  //************************************************************
  if (server.hasArg("mqtt_check_form")) {
    if (server.arg("mqtt_check_form") == "on") {
      cfg.data_mqtt_check = 1;
    } else {
      cfg.data_mqtt_check = 0;
    }
  } else {
    cfg.data_mqtt_check = 0;
  }
  if (server.hasArg("mqtt_server_form")) {
    String mqtt_server;
    mqtt_server = server.arg("mqtt_server_form");
    mqtt_server.replace("%2F", "/");
    mqtt_server.toCharArray(cfg.data_mqtt_server, (sizeof(cfg.data_mqtt_server) - 1) );
  }
  if (server.hasArg("mqtt_port_form")) {
    cfg.data_mqtt_port = server.arg("mqtt_port_form").toInt();
  }
  if (server.hasArg("mqtt_benutzer_form")) {
    String mqtt_benutzer;
    mqtt_benutzer = server.arg("mqtt_benutzer_form");
    mqtt_benutzer.replace("%2F", "/");
    mqtt_benutzer.toCharArray(cfg.data_mqtt_benutzer, (sizeof(cfg.data_mqtt_benutzer) - 1) );
  }
  if (server.hasArg("mqtt_passwort_form")) {
    String mqtt_passwort;
    mqtt_passwort = server.arg("mqtt_passwort_form");
    mqtt_passwort.replace("%2F", "/");
    mqtt_passwort.toCharArray(cfg.data_mqtt_passwort, (sizeof(cfg.data_mqtt_passwort) - 1) );
  }
  if (server.hasArg("mqtt_topic_form")) {
    String mqtt_topic;
    mqtt_topic = server.arg("mqtt_topic_form");
    mqtt_topic.replace("%2F", "/");
    mqtt_topic.toCharArray(cfg.data_mqtt_topic, (sizeof(cfg.data_mqtt_topic) - 1) );
  }
  if (server.hasArg("mqtt_topic_abstand_form")) {
    String mqtt_abstand_topic;
    mqtt_abstand_topic = server.arg("mqtt_topic_abstand_form");
    mqtt_abstand_topic.replace("%2F", "/");
    mqtt_abstand_topic.toCharArray(cfg.data_mqtt_abstand_topic, (sizeof(cfg.data_mqtt_abstand_topic) - 1) );
  }
  if (server.hasArg("mqtt_topic_liter_form")) {
    String mqtt_liter_topic;
    mqtt_liter_topic = server.arg("mqtt_topic_liter_form");
    mqtt_liter_topic.replace("%2F", "/");
    mqtt_liter_topic.toCharArray(cfg.data_mqtt_liter_topic, (sizeof(cfg.data_mqtt_liter_topic) - 1) );
  }
  if (server.hasArg("mqtt_topic_temperature_form")) {
    String mqtt_temperature_topic;
    mqtt_temperature_topic = server.arg("mqtt_topic_temperature_form");
    mqtt_temperature_topic.replace("%2F", "/");
    mqtt_temperature_topic.toCharArray(cfg.data_mqtt_temperature_topic, (sizeof(cfg.data_mqtt_temperature_topic) - 1) );
  }
  if (server.hasArg("mqtt_topic_humidity_form")) {
    String mqtt_humidity_topic;
    mqtt_humidity_topic = server.arg("mqtt_topic_humidity_form");
    mqtt_humidity_topic.replace("%2F", "/");
    mqtt_humidity_topic.toCharArray(cfg.data_mqtt_humidity_topic, (sizeof(cfg.data_mqtt_humidity_topic) - 1) );
  }
  if (server.hasArg("mqtt_intervall_form")) {
    cfg.data_mqtt_intervall = server.arg("mqtt_intervall_form").toInt();
  }

  //************************************************************
  //Zisterne Sensortyp und Name
  //************************************************************
  if (server.arg("zisterne_sensor_form") == "1") {
    cfg.data_zisterne_sensor = 1;
  }
  if (server.arg("zisterne_sensor_form") == "2") {
    cfg.data_zisterne_sensor = 2;
  }
  if (server.arg("zisterne_sensor_form") == "3") {
    cfg.data_zisterne_sensor = 3;
  }
  if (server.hasArg("sensorname_form")) {
    String sensorname;
    sensorname = server.arg("sensorname_form");
    sensorname.replace("%2F", "/");
    sensorname.toCharArray(cfg.data_sensorname, (sizeof(cfg.data_sensorname) - 1) );
  }
  if (server.arg("distance_mode_vl53l1x_form") == "0") {
    cfg.data_distance_mode_vl53l1x = 0;
  }
  if (server.arg("distance_mode_vl53l1x_form") == "1") {
    cfg.data_distance_mode_vl53l1x = 1;
  }
  if (server.arg("distance_mode_vl53l0x_form") == "0") {
    cfg.data_distance_mode_vl53l0x = 0;
  }
  if (server.arg("distance_mode_vl53l0x_form") == "1") {
    cfg.data_distance_mode_vl53l0x = 1;
  }
  if (server.arg("accuracy_mode_vl53l0x_form") == "0") {
    cfg.data_accuracy_mode_vl53l0x = 0;
  }
  if (server.arg("accuracy_mode_vl53l0x_form") == "1") {
    cfg.data_accuracy_mode_vl53l0x = 1;
  }
  if (server.arg("accuracy_mode_vl53l0x_form") == "2") {
    cfg.data_accuracy_mode_vl53l0x = 2;
  }

  //************************************************************
  //Zisterne Bauform
  //************************************************************
  if (server.hasArg("zisterne_bauform_form")) {
    String zisterne_bauform;
    zisterne_bauform = server.arg("zisterne_bauform_form");
    zisterne_bauform.replace("%2F", "/");
    zisterne_bauform.toCharArray(cfg.data_zisterne_bauform, (sizeof(cfg.data_zisterne_bauform) - 1) );
  }
  if (server.hasArg("zisterne_durchmesser_form")) {
    cfg.data_zisterne_durchmesser = server.arg("zisterne_durchmesser_form").toInt();
  }
  if (server.hasArg("zisterne_durchmesser_liegend_form")) {
    cfg.data_zisterne_durchmesser_liegend = server.arg("zisterne_durchmesser_liegend_form").toInt();
  }
  if (server.hasArg("zisterne_laenge_liegend_form")) {
    cfg.data_zisterne_laenge_liegend = server.arg("zisterne_laenge_liegend_form").toInt();
  }
  if (server.hasArg("zisterne_x_form")) {
    cfg.data_zisterne_x = server.arg("zisterne_x_form").toInt();
  }
  if (server.hasArg("zisterne_y_form")) {
    cfg.data_zisterne_y = server.arg("zisterne_y_form").toInt();
  }
  if (server.hasArg("zisterne_fl_form")) {
    cfg.data_zisterne_fl = server.arg("zisterne_fl_form").toInt();
  }
  if (server.hasArg("zisterne_vl_form")) {
    cfg.data_zisterne_vl = server.arg("zisterne_vl_form").toInt();
  }

  if (server.hasArg("anzeige_liter_check_form")) {
    if (server.arg("anzeige_liter_check_form") == "on") {
      cfg.data_anzeige_liter_check = 1;
    } else {
      cfg.data_anzeige_liter_check = 0;
    }
  } else {
    cfg.data_anzeige_liter_check = 0;
  }

  //************************************************************
  // Sonstiges
  //************************************************************
  if (server.hasArg("dezstellen_anzeige_form")) {
    cfg.data_dezstellen_anzeige = server.arg("dezstellen_anzeige_form").toInt();
  }


  //************************************************************
  // Displays
  //************************************************************
  if (server.hasArg("display_on")) {
    if (server.arg("display_on") == "on") {
      cfg.data_display_enable = 1;
    } else {
      cfg.data_display_enable = 0;
    }
  } else {
    cfg.data_display_enable = 0;
  }
  if (server.arg("display_form") == "1") {
    cfg.data_display = 1;
  }
  if (server.arg("display_form") == "2") {
    cfg.data_display = 2;
  }
  if (server.arg("display_form") == "3") {
    cfg.data_display = 3;
  }

  //************************************************************
  // Sensor an D5 angeschlossen?
  //************************************************************
  //  if (server.hasArg("sens_on")) {
  //    if (server.arg("sens_on")=="on") {
  //      cfg.data_senson=1;
  //    } else {
  //      cfg.data_senson=0;
  //    }
  //  } else {
  //    cfg.data_senson=0;
  //  }
  //************************************************************
  // NTP
  //************************************************************
  if (server.hasArg("ntp_server_form")) {
    String ntp_server;
    ntp_server = server.arg("ntp_server_form");
    ntp_server.replace("%2F", "/");
    ntp_server.toCharArray(cfg.data_ntp_server, (sizeof(cfg.data_ntp_server) - 1) );
  }

  //************************************************************
  // PUSHOVER
  //************************************************************
  if (server.hasArg("pushover_check_form")) {
    if (server.arg("pushover_check_form") == "on") {
      cfg.data_pushover_check = 1;
    } else {
      cfg.data_pushover_check = 0;
    }
  } else {
    cfg.data_pushover_check = 0;
  }
  if (server.hasArg("pushover_apptoken_form")) {
    String pushover_apptoken;
    pushover_apptoken = server.arg("pushover_apptoken_form");
    pushover_apptoken.replace("%2F", "/");
    pushover_apptoken.toCharArray(cfg.data_pushover_apptoken, (sizeof(cfg.data_pushover_apptoken) - 1) );
  }
  if (server.hasArg("pushover_usertoken_form")) {
    String pushover_usertoken;
    pushover_usertoken = server.arg("pushover_usertoken_form");
    pushover_usertoken.replace("%2F", "/");
    pushover_usertoken.toCharArray(cfg.data_pushover_usertoken, (sizeof(cfg.data_pushover_usertoken) - 1) );
  }
  if (server.hasArg("pushover_zeit_form")) {
    cfg.data_pushover_zeit = server.arg("pushover_zeit_form").toInt();
  }

  //************************************************************
  //Externes Relais
  //************************************************************
  if (server.hasArg("relais_on")) {
    if (server.arg("relais_on")=="on") {
      cfg.data_relais_enable=1;
    } else {
      cfg.data_relais_enable=0;
    }
  } else {
    cfg.data_relais_enable=0;
  }
  if (server.arg("relais_an_krit_form") == "0") {
    cfg.data_relais_an_krit = 0;
  }
  if (server.arg("relais_an_krit_form") == "1") {
    cfg.data_relais_an_krit = 1;
  }
  if (server.arg("relais_aus_krit_form") == "0") {
    cfg.data_relais_aus_krit = 0;
  }
  if (server.arg("relais_aus_krit_form") == "1") {
    cfg.data_relais_aus_krit = 1;
  }
  if (server.hasArg("relais_an_wert_form")) {
    cfg.data_relais_an_wert = server.arg("relais_an_wert_form").toInt();
  }
  if (server.hasArg("relais_aus_wert_form")) {
    cfg.data_relais_aus_wert = server.arg("relais_aus_wert_form").toInt();
  }

  //************************************************************
  //Externes Relais 2
  //************************************************************
  /*
  if (server.hasArg("relais2_on")) {
    if (server.arg("relais2_on")=="on") {
      cfg.data_relais2_enable=1;
    } else {
      cfg.data_relais2_enable=0;
    }
  } else {
    cfg.data_relais2_enable=0;
  }
  if (server.hasArg("relais2_dauer_form")) {
    cfg.data_relais2_dauer = server.arg("relais2_dauer_form").toInt();
  }
  if (server.hasArg("relais2_zeit_form")) {
    cfg.data_relais2_zeit = server.arg("relais2_zeit_form").toInt();
  }
  if (server.hasArg("relais2_tag_form")) {
    cfg.data_relais2_tag = server.arg("relais2_tag_form").toInt();
  }
  */


  //************************************************************
  //Mailserver
  //************************************************************
  if (server.hasArg("mail_check_form")) {
    if (server.arg("mail_check_form") == "on") {
      cfg.data_mail_check = 1;
    } else {
      cfg.data_mail_check = 0;
    }
  } else {
    cfg.data_mail_check = 0;
  }
  if (server.hasArg("mail_server_form")) {
    String mail_server;
    mail_server = server.arg("mail_server_form");
    mail_server.replace("%2F", "/");
    mail_server.toCharArray(cfg.data_mail_server, (sizeof(cfg.data_mail_server) - 1) );
  }
  if (server.hasArg("mail_port_form")) {
    cfg.data_mail_port = server.arg("mail_port_form").toInt();
  }
  if (server.hasArg("mail_ssl_form")) {
    if (server.arg("mail_ssl_form") == "on") {
      cfg.data_mail_ssl = 1;
    } else {
      cfg.data_mail_ssl = 0;
    }
  } else {
    cfg.data_mail_ssl = 0;
  }
  if (server.hasArg("mail_benutzer_form")) {
    String mail_benutzer;
    mail_benutzer = server.arg("mail_benutzer_form");
    mail_benutzer.replace("%2F", "/");
    mail_benutzer.toCharArray(cfg.data_mail_benutzer, (sizeof(cfg.data_mail_benutzer) - 1) );
  }
  if (server.hasArg("mail_passwort_form")) {
    String mail_passwort;
    mail_passwort = server.arg("mail_passwort_form");
    mail_passwort.replace("%2F", "/");
    mail_passwort.toCharArray(cfg.data_mail_passwort, (sizeof(cfg.data_mail_passwort) - 1) );
  }
  if (server.hasArg("mail_zeit_form")) {
    cfg.data_mail_zeit = server.arg("mail_zeit_form").toInt();
  }

  Serial.println("Speichere Konfiguration in EEPROM...");
  speicherekonfig();
  Serial.println("...fertig!");
  //system_restart();
}

//********************************************************
void webHandleJSON() {
  String inhalt;

  inhalt = "{\"Sensor\":\"";
  inhalt += anwendungsname;
  inhalt += "\",\"IP\":\"";
  inhalt += ipAdresse;
  inhalt += "\"";

  inhalt += ",\"Fuellstand\":\"";
  int fuellstand_int = (int)(fuellstand + .5);
  inhalt += fuellstand;
  inhalt += "\"";

  inhalt += ",\"Abstand\":\"";
  inhalt += abstand;
  inhalt += "\"";

  if (cfg.data_anzeige_liter_check == 1) {
    inhalt += ",\"Liter\":\"";
    inhalt += volumen;
    inhalt += "\"";
  }

  if (cfg.data_temperatur_enable == 1) {
    inhalt += ",\"Temperatur\":\"";
    inhalt += temperature;
    inhalt += "\"";
    inhalt += ",\"Luftfeuchtigkeit\":\"";
    inhalt += humidity;
    inhalt += "\"";
  }

  if (cfg.data_relais_enable == 1) {
    int relais_status = digitalRead(relaisPIN);
    inhalt += ",\"Relaisausgang\":\"";
    inhalt += relais_status;
    inhalt += "\"";
  }

  inhalt += "}";

  server.send(200, "application/json", inhalt);
}

//********************************************************
void webHandlePushTest() {
  String inhalt;

  inhalt  = "<!DOCTYPE html>";
  inhalt += "<html><head><meta name='viewport' content='width=device-width, initial-scale=1.0'><title>" + anwendungsname + "</title></head><body style='font-family:verdana;background-color:#B9DFF8;color:#000000;margin:0px'>";
  inhalt += "<p style='font-size:24px;font-weight:bold;background-color:#FFFFFF;color:#000000;padding:30px;padding-left:10px;margin:0px;'>" + anwendungsname + " <span style='font-size:12px;font-weight:normal;'>v" + fw_version + "</span></p>";
  inhalt += "<p style='font-size:18px;font-weight:bold;background-color:#85C5EE;padding-left:10px;padding-top:10px;padding-bottom:10px;margin:0px;'>Test Pushover</p>";
  inhalt += "<br>";
  inhalt += "<div style='padding-left:10px;padding_right:10px;'>";

  Pushover pushover = Pushover(cfg.data_pushover_apptoken, cfg.data_pushover_usertoken, UNSAFE);
  pushover.setTitle("Zisterne");
  pushover.setMessage("Testnachricht von Zisterne");
  if (DEBUG) Serial.println("Pushover-Testnachricht getriggert");
  inhalt += pushover.send();

  //inhalt += cfg.data_pushover_apptoken;
  //inhalt += "<br>";
  //inhalt += cfg.data_pushover_usertoken;

  inhalt += "<p>0 = Fehler</p>";
  inhalt += "<p>1 = Erfolg</p>";
  inhalt += "<p><a href=\"/\">zur&uuml;ck</a></p>";
  inhalt += "</body>";
  inhalt += "</html>";
  inhalt += "\r\n\r\n";
  server.send(200, "text/html", inhalt);
}


//********************************************************
void webHandleRelais() {
  String inhalt;

  if (cfg.data_relais_enable == 0) {
    inhalt += "{\"Relaisausgang\":\"";
    inhalt += "nicht aktiviert";
    inhalt += "\"}";
  }

  if (cfg.data_relais_enable == 1) {
    
    if (server.hasArg("status")) {
      if (server.arg("status") == "1") {
        digitalWrite(relaisPIN,HIGH);
        Serial.println("Relaisausgang High");
      }
      if (server.arg("status") == "0") {
        digitalWrite(relaisPIN,LOW);
        Serial.println("Relaisausgang Low");
      }
    }
    
    int relais_status = digitalRead(relaisPIN);
    inhalt += "{\"Relaisausgang\":\"";
    inhalt += relais_status;
    inhalt += "\"}";
  }

  server.send(200, "application/json", inhalt);
}


//********************************************************
void webHandleMailTest() {
  String inhalt;

  inhalt  = "<!DOCTYPE html>";
  inhalt += "<html><head><meta name='viewport' content='width=device-width, initial-scale=1.0'><title>" + anwendungsname + "</title></head><body style='font-family:verdana;background-color:#B9DFF8;color:#000000;margin:0px'>";
  inhalt += "<p style='font-size:24px;font-weight:bold;background-color:#FFFFFF;color:#000000;padding:30px;padding-left:10px;margin:0px;'>" + anwendungsname + " <span style='font-size:12px;font-weight:normal;'>v" + fw_version + "</span></p>";
  inhalt += "<p style='font-size:18px;font-weight:bold;background-color:#85C5EE;padding-left:10px;padding-top:10px;padding-bottom:10px;margin:0px;'>Test Mailversand</p>";
  inhalt += "<br>";
  inhalt += "<div style='padding-left:10px;padding_right:10px;'>";

  //  SendEmail e("mailserver", 587, "benutzer", "passwort", 5000, true);
  //  inhalt += e.send("chris@bubux.de", "chris@bubux.de", "Zisterne", "Testmail von der Zisterne");
  //
  //  if (DEBUG) Serial.println("Testmail getriggert");

  inhalt += "<p><a href=\"/\">zur&uuml;ck</a></p>";
  inhalt += "</body>";
  inhalt += "</html>";
  inhalt += "\r\n\r\n";
  server.send(200, "text/html", inhalt);
}


//********************************************************
void webHandleBoot() {
  String inhalt;

  inhalt  = "<!DOCTYPE html>";
  inhalt += "<html><head><meta name='viewport' content='width=device-width, initial-scale=1.0'></head><title>" + anwendungsname + "</title><body style='font-family:verdana;background-color:#B9DFF8;color:#000000;margin:0px'>";
  inhalt += "<p style='font-size:24px;font-weight:bold;background-color:#FFFFFF;color:#000000;padding:30px;padding-left:10px;margin:0px;'>" + anwendungsname + " <span style='font-size:12px;font-weight:normal;'>v" + fw_version + "</span></p>";
  inhalt += "<p style='font-size:18px;font-weight:bold;background-color:#85C5EE;padding-left:10px;padding-top:10px;padding-bottom:10px;margin:0px;'>Reboot des Sensors</p>";
  inhalt += "<br>";
  inhalt += "<div style='padding-left:10px;padding_right:10px;'>";
  inhalt += "<p>Der Sensor wird <b>jetzt</b> rebootet</p>";
  inhalt += "<p>Bitte in ca. 20 Sekunden <a href=\"/\">hier</a> klicken</p>";
  inhalt += "</body>";
  inhalt += "</html>";
  inhalt += "\r\n\r\n";
  server.send(200, "text/html", inhalt);
  //if (cfg.data_senson==1) {
  //   digitalWrite(sensor, LOW);
  //   delay (1500);
  //} else {
  system_restart();
  //}
}
