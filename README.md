# zisternenmessung
Checks the level of your cistern using an ESP8266 with various possible distance sensors (Ultrasound, ToF). 
There is a selection of different cistern shapes (cylinder, square, horizontal, standing) with calculation of the volume. The measured values are output on a separate website (without Homeautomation central), data can be send via MQTT to your own MQTT broker or via HTTP to an own interface. In addition, it is possible to let prepare the data on www.bubux.de

## Supported distance sensors

- HC-SR04
- VL53L0X
- VL53L1X

## Supported temperature (humidity) sensors

- DHT22-Sensor

Planned:
- BME280
- DS18B20

## Supported displays

- LCD '1602'
- LCD '1604, 2004'
- OLED 'SSD 1106, 1306'


## Wiring

![Anschluss](https://github.com/diefenbecker/zisternenmessung/blob/main/wiring.PNG?raw=true)

The ToF sensors are also connected to D1/D2 as an alternative to the ultrasonic sensor.
On the picture the pin D4 for the switchable output e.g. for a relay is missing.

## Use own api

The measured data can be sent to your own interface via http post. A configurable URL is called and the values for the distance and the level in the variables are _abstand and _fuellstand transferred. Example: http://server:port/path_to_own_api?abs=_abstand&hoehe=_fuellstand

## Use bubux api

With the WebAPI, the data (level, MAC address, local IP and firmware version) is sent to www.bubux.de where a graphical evaluation of the cistern level of the last 30 days is prepared. This evaluation can be accessed via a link in the web interface of the respective sensor. No central home automation is necessary here.

## Latest version already compiled

Find here ![Version 1030](https://github.com/diefenbecker/zisternenmessung/blob/main/zisterne_1030.bin?raw=true) a already compiled version tested with NodeMCU and Wemos D1 mini

## JSON
  
With /json behind the URL of the sensor, the measured values can be queried via JSON. For example, 192.168.178.49/json.

![JSON example](https://github.com/diefenbecker/zisternenmessung/blob/main/json.PNG?raw=true)
  
## Use MQTT

Send the measured data to an MQTT broker

![MQTT Konfig](https://github.com/diefenbecker/zisternenmessung/blob/main/mqtt.PNG?raw=true)


## Used libraries

- ESP8266WiFi.h
- ESP8266mDNS.h
- ESP8266WebServer.h
- WiFiClient.h
- Ticker.h
- EEPROM.h
- ESP8266HTTPClient.h
- ESP8266httpUpdate.h
- LiquidCrystal_I2C.h
- ss_oled.h
- Wire.h
- PubSubClient.h
- NTPClient.h
- WiFiUdp.h
- SimpleTimer.h
- Pushover.h
- myTypes.h
- DHT.h
- VL53L0X.h (Pololu)
- SparkFun_VL53L1X.h

## Donation

To support this project 

## Some screenshots of the webinterface with it´s configuration page

![Startpage](https://github.com/diefenbecker/zisternenmessung/blob/main/startseite.PNG?raw=true)

![Configuration page (1)](https://github.com/diefenbecker/zisternenmessung/blob/main/konfig1.PNG?raw=true)

![Configuration page (2)](https://github.com/diefenbecker/zisternenmessung/blob/main/konfig2.PNG?raw=true)

![Configuration page (3)](https://github.com/diefenbecker/zisternenmessung/blob/main/konfig3.PNG?raw=true)
