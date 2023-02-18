# Octopus-Agile-API-via-ESP32-Dev-Board

This code was developed to allow an ESP32 Development Module to connect to local WiFi, get the time of day and then collect the Octopus Energy 'Agile Tariff' eletcricity prices. The Afile tariff offers dynamic pricing, updated every 1/2 hour. Rates for the coming day are issued by Octopus at approx. 16:00 UTC each day.
This version of the code also provides for a 128 x 64 pixel OLED display that shows the current tariff, plus other details.

The code contains a hard-coded theshold_tariff : when the live tariff is below this level an output on the ESP32 Board is set. This signal may be used to turn on external devices, e.g. an electric water heater

The code was developed in the Arduino IDE and this was used to load the software to the ESP32 Dev Module. 

NOTE: the core code call on an external text file - secrets.h - to collect the WiFi credentials and your personal Octopus Agile autorisation code. an example pf this file is provided in this repository as secrets.h dummy,txt Edit and rename this file and place a copy in the same directory as the .INO file before compilation 

Please see here for a view of the code running https://youtu.be/q1LvupyJpJs
