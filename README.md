# zisternenmessung
Checks the level of your cistern using various possible sensors (Ultrasound, ToF). 
Selection of different cistern shapes (cylinder, square, horizontal, standing) with calculation of the volume. The measured values are output on a separate website (ESP8266), via MQTT to your own MQTT broker or via http to your own web interface. In addition, it is possible to prepare the data on ww.bubux.de.

## Supported distance sensors

- HC-SR04
- VL53L0X
- VL53L1X

## Supported temperature (humidity) sensors

- DHT22-Sensor

## Supported displays

- LCD '1602'
- LCD '1604, 2004'
- OLED 'SSD 1106, 1306'

## Use own api

The measured data can be sent to your own interface via http post. A configurable URL is called and the values for the distance and the level in the variables are _abstand and _fuellstand transferred. Example: http://server:port/path_to_own_api?abs=_abstand&hoehe=_fuellstand

## Use bubux api

With the WebAPI, the data (level, MAC address, local IP and firmware version) is sent to www.bubux.de where a graphical evaluation of the cistern level of the last 30 days is prepared. This evaluation can be accessed via a link in the web interface of the respective sensor. No central home automation is necessary here.
  
## JSON
  
With /json behind the URL of the sensor, the measured values can be queried via JSON. For example, 192.168.178.49/json.

![JSON example](https://github.com/diefenbecker/zisternenmessung/blob/main/json.PNG?raw=true)
  

![Startpage](https://github.com/diefenbecker/zisternenmessung/blob/main/startseite.PNG?raw=true)

![Configuration page (1)](https://github.com/diefenbecker/zisternenmessung/blob/main/konfig1.PNG?raw=true)

![Configuration page (2)](https://github.com/diefenbecker/zisternenmessung/blob/main/konfig2.PNG?raw=true)

![Configuration page (3)](https://github.com/diefenbecker/zisternenmessung/blob/main/konfig3.PNG?raw=true)
