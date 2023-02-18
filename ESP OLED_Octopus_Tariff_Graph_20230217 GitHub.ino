/*
  Code to Collect Octopus Agile Tariff Data & Use it to set a pin high when tariff is below a specified threshold. This pin signal may be used to turn on other devices, e.g. immersiion heater

  Based on Wifi secure connection example for ESP32
  Running on TLS 1.2 using mbedTLS
  Suporting the following chipersuites:
  "TLS_ECDHE_ECDSA_WITH_AES_256_GCM_SHA384","TLS_ECDHE_RSA_WITH_AES_256_GCM_SHA384","TLS_DHE_RSA_WITH_AES_256_GCM_SHA384","TLS_ECDHE_ECDSA_WITH_AES_256_CCM","TLS_DHE_RSA_WITH_AES_256_CCM","TLS_ECDHE_ECDSA_WITH_AES_256_CBC_SHA384","TLS_ECDHE_RSA_WITH_AES_256_CBC_SHA384","TLS_DHE_RSA_WITH_AES_256_CBC_SHA256","TLS_ECDHE_ECDSA_WITH_AES_256_CBC_SHA","TLS_ECDHE_RSA_WITH_AES_256_CBC_SHA","TLS_DHE_RSA_WITH_AES_256_CBC_SHA","TLS_ECDHE_ECDSA_WITH_AES_256_CCM_8","TLS_DHE_RSA_WITH_AES_256_CCM_8","TLS_ECDHE_ECDSA_WITH_CAMELLIA_256_GCM_SHA384","TLS_ECDHE_RSA_WITH_CAMELLIA_256_GCM_SHA384","TLS_DHE_RSA_WITH_CAMELLIA_256_GCM_SHA384","TLS_ECDHE_ECDSA_WITH_CAMELLIA_256_CBC_SHA384","TLS_ECDHE_RSA_WITH_CAMELLIA_256_CBC_SHA384","TLS_DHE_RSA_WITH_CAMELLIA_256_CBC_SHA256","TLS_DHE_RSA_WITH_CAMELLIA_256_CBC_SHA","TLS_ECDHE_ECDSA_WITH_AES_128_GCM_SHA256","TLS_ECDHE_RSA_WITH_AES_128_GCM_SHA256","TLS_DHE_RSA_WITH_AES_128_GCM_SHA256","TLS_ECDHE_ECDSA_WITH_AES_128_CCM","TLS_DHE_RSA_WITH_AES_128_CCM","TLS_ECDHE_ECDSA_WITH_AES_128_CBC_SHA256","TLS_ECDHE_RSA_WITH_AES_128_CBC_SHA256","TLS_DHE_RSA_WITH_AES_128_CBC_SHA256","TLS_ECDHE_ECDSA_WITH_AES_128_CBC_SHA","TLS_ECDHE_RSA_WITH_AES_128_CBC_SHA","TLS_DHE_RSA_WITH_AES_128_CBC_SHA","TLS_ECDHE_ECDSA_WITH_AES_128_CCM_8","TLS_DHE_RSA_WITH_AES_128_CCM_8","TLS_ECDHE_ECDSA_WITH_CAMELLIA_128_GCM_SHA256","TLS_ECDHE_RSA_WITH_CAMELLIA_128_GCM_SHA256","TLS_DHE_RSA_WITH_CAMELLIA_128_GCM_SHA256","TLS_ECDHE_ECDSA_WITH_CAMELLIA_128_CBC_SHA256","TLS_ECDHE_RSA_WITH_CAMELLIA_128_CBC_SHA256","TLS_DHE_RSA_WITH_CAMELLIA_128_CBC_SHA256","TLS_DHE_RSA_WITH_CAMELLIA_128_CBC_SHA","TLS_ECDHE_ECDSA_WITH_3DES_EDE_CBC_SHA","TLS_ECDHE_RSA_WITH_3DES_EDE_CBC_SHA","TLS_DHE_RSA_WITH_3DES_EDE_CBC_SHA","TLS_DHE_PSK_WITH_AES_256_GCM_SHA384","TLS_DHE_PSK_WITH_AES_256_CCM","TLS_ECDHE_PSK_WITH_AES_256_CBC_SHA384","TLS_DHE_PSK_WITH_AES_256_CBC_SHA384","TLS_ECDHE_PSK_WITH_AES_256_CBC_SHA","TLS_DHE_PSK_WITH_AES_256_CBC_SHA","TLS_DHE_PSK_WITH_CAMELLIA_256_GCM_SHA384","TLS_ECDHE_PSK_WITH_CAMELLIA_256_CBC_SHA384","TLS_DHE_PSK_WITH_CAMELLIA_256_CBC_SHA384","TLS_PSK_DHE_WITH_AES_256_CCM_8","TLS_DHE_PSK_WITH_AES_128_GCM_SHA256","TLS_DHE_PSK_WITH_AES_128_CCM","TLS_ECDHE_PSK_WITH_AES_128_CBC_SHA256","TLS_DHE_PSK_WITH_AES_128_CBC_SHA256","TLS_ECDHE_PSK_WITH_AES_128_CBC_SHA","TLS_DHE_PSK_WITH_AES_128_CBC_SHA","TLS_DHE_PSK_WITH_CAMELLIA_128_GCM_SHA256","TLS_DHE_PSK_WITH_CAMELLIA_128_CBC_SHA256","TLS_ECDHE_PSK_WITH_CAMELLIA_128_CBC_SHA256","TLS_PSK_DHE_WITH_AES_128_CCM_8","TLS_ECDHE_PSK_WITH_3DES_EDE_CBC_SHA","TLS_DHE_PSK_WITH_3DES_EDE_CBC_SHA","TLS_RSA_WITH_AES_256_GCM_SHA384","TLS_RSA_WITH_AES_256_CCM","TLS_RSA_WITH_AES_256_CBC_SHA256","TLS_RSA_WITH_AES_256_CBC_SHA","TLS_ECDH_RSA_WITH_AES_256_GCM_SHA384","TLS_ECDH_RSA_WITH_AES_256_CBC_SHA384","TLS_ECDH_RSA_WITH_AES_256_CBC_SHA","TLS_ECDH_ECDSA_WITH_AES_256_GCM_SHA384","TLS_ECDH_ECDSA_WITH_AES_256_CBC_SHA384","TLS_ECDH_ECDSA_WITH_AES_256_CBC_SHA","TLS_RSA_WITH_AES_256_CCM_8","TLS_RSA_WITH_CAMELLIA_256_GCM_SHA384","TLS_RSA_WITH_CAMELLIA_256_CBC_SHA256","TLS_RSA_WITH_CAMELLIA_256_CBC_SHA","TLS_ECDH_RSA_WITH_CAMELLIA_256_GCM_SHA384","TLS_ECDH_RSA_WITH_CAMELLIA_256_CBC_SHA384","TLS_ECDH_ECDSA_WITH_CAMELLIA_256_GCM_SHA384","TLS_ECDH_ECDSA_WITH_CAMELLIA_256_CBC_SHA384","TLS_RSA_WITH_AES_128_GCM_SHA256","TLS_RSA_WITH_AES_128_CCM","TLS_RSA_WITH_AES_128_CBC_SHA256","TLS_RSA_WITH_AES_128_CBC_SHA","TLS_ECDH_RSA_WITH_AES_128_GCM_SHA256","TLS_ECDH_RSA_WITH_AES_128_CBC_SHA256","TLS_ECDH_RSA_WITH_AES_128_CBC_SHA","TLS_ECDH_ECDSA_WITH_AES_128_GCM_SHA256","TLS_ECDH_ECDSA_WITH_AES_128_CBC_SHA256","TLS_ECDH_ECDSA_WITH_AES_128_CBC_SHA","TLS_RSA_WITH_AES_128_CCM_8","TLS_RSA_WITH_CAMELLIA_128_GCM_SHA256","TLS_RSA_WITH_CAMELLIA_128_CBC_SHA256","TLS_RSA_WITH_CAMELLIA_128_CBC_SHA","TLS_ECDH_RSA_WITH_CAMELLIA_128_GCM_SHA256","TLS_ECDH_RSA_WITH_CAMELLIA_128_CBC_SHA256","TLS_ECDH_ECDSA_WITH_CAMELLIA_128_GCM_SHA256","TLS_ECDH_ECDSA_WITH_CAMELLIA_128_CBC_SHA256","TLS_RSA_WITH_3DES_EDE_CBC_SHA","TLS_ECDH_RSA_WITH_3DES_EDE_CBC_SHA","TLS_ECDH_ECDSA_WITH_3DES_EDE_CBC_SHA","TLS_RSA_PSK_WITH_AES_256_GCM_SHA384","TLS_RSA_PSK_WITH_AES_256_CBC_SHA384","TLS_RSA_PSK_WITH_AES_256_CBC_SHA","TLS_RSA_PSK_WITH_CAMELLIA_256_GCM_SHA384","TLS_RSA_PSK_WITH_CAMELLIA_256_CBC_SHA384","TLS_RSA_PSK_WITH_AES_128_GCM_SHA256","TLS_RSA_PSK_WITH_AES_128_CBC_SHA256","TLS_RSA_PSK_WITH_AES_128_CBC_SHA","TLS_RSA_PSK_WITH_CAMELLIA_128_GCM_SHA256","TLS_RSA_PSK_WITH_CAMELLIA_128_CBC_SHA256","TLS_RSA_PSK_WITH_3DES_EDE_CBC_SHA","TLS_PSK_WITH_AES_256_GCM_SHA384","TLS_PSK_WITH_AES_256_CCM","TLS_PSK_WITH_AES_256_CBC_SHA384","TLS_PSK_WITH_AES_256_CBC_SHA","TLS_PSK_WITH_CAMELLIA_256_GCM_SHA384","TLS_PSK_WITH_CAMELLIA_256_CBC_SHA384","TLS_PSK_WITH_AES_256_CCM_8","TLS_PSK_WITH_AES_128_GCM_SHA256","TLS_PSK_WITH_AES_128_CCM","TLS_PSK_WITH_AES_128_CBC_SHA256","TLS_PSK_WITH_AES_128_CBC_SHA","TLS_PSK_WITH_CAMELLIA_128_GCM_SHA256","TLS_PSK_WITH_CAMELLIA_128_CBC_SHA256","TLS_PSK_WITH_AES_128_CCM_8","TLS_PSK_WITH_3DES_EDE_CBC_SHA","TLS_EMPTY_RENEGOTIATION_INFO_SCSV"]
  2017 - Evandro Copercini - Apache 2.0 License.
*/
char Date[] = "18/02/2023";
#include <WiFi.h>
#include "time.h"
#include "sntp.h"
#include <WiFiClientSecure.h>
#include <ArduinoJson.h>
#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include "secrets.h" // include text file (from same directory) that contains SSID, WiFi password & Octopus personal authorisation code
//
#define SCREEN_WIDTH 128     // OLED display width, in pixels
#define SCREEN_HEIGHT 64     // OLED display height, in pixels
#define OLED_RESET -1        // Reset pin # (or -1 if sharing Arduino reset pin)
#define SCREEN_ADDRESS 0x3c  ///< See datasheet for Address; 0x3D for 128x64, 0x3C for 128x32
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);
//
//
// Declare Functions
//
void printTime(time_t timeToPrint);  // Print time to serial monitor
void Get_Octopus_Data();             // Get Octopus Data
//void printLocalTime();
void timeavailable(struct timeval* t);  // Callback function (get's called when time adjusts via NTP)
void updateOLED();                      // Routine Refresh of OLED Display
void graphOLED();                       // Draw tariff graph on OLED
//
// WiFi Credentials
//
//const char* ssid = "YOUR SSID HERE";  NOTE: These data now picked up from secrets.h file
//const char* password = "YOUR PASSWORD HERE";
//
//Set API Sources
//
//const char* auth_string = "PUT YOUR OCTOPUS AUTHORISATION CODE HERE"
const char* server = "api.octopus.energy";  // Server URL
const char* ntpServer1 = "pool.ntp.org";
const char* ntpServer2 = "time.nist.gov";
const long gmtOffset_sec = 0;
const int daylightOffset_sec = 0;
const char* time_zone = "CET-1CEST,M3.5.0,M10.5.0/3";  // TimeZone rule for Europe/Rome including daylight adjustment rules (optional)
//
// Cert for Octopus
//
const char* octopus =
  "-----BEGIN CERTIFICATE-----\n"
  "MIIEdTCCA12gAwIBAgIJAKcOSkw0grd/MA0GCSqGSIb3DQEBCwUAMGgxCzAJBgNV\n"
  "BAYTAlVTMSUwIwYDVQQKExxTdGFyZmllbGQgVGVjaG5vbG9naWVzLCBJbmMuMTIw\n"
  "MAYDVQQLEylTdGFyZmllbGQgQ2xhc3MgMiBDZXJ0aWZpY2F0aW9uIEF1dGhvcml0\n"
  "eTAeFw0wOTA5MDIwMDAwMDBaFw0zNDA2MjgxNzM5MTZaMIGYMQswCQYDVQQGEwJV\n"
  "UzEQMA4GA1UECBMHQXJpem9uYTETMBEGA1UEBxMKU2NvdHRzZGFsZTElMCMGA1UE\n"
  "ChMcU3RhcmZpZWxkIFRlY2hub2xvZ2llcywgSW5jLjE7MDkGA1UEAxMyU3RhcmZp\n"
  "ZWxkIFNlcnZpY2VzIFJvb3QgQ2VydGlmaWNhdGUgQXV0aG9yaXR5IC0gRzIwggEi\n"
  "MA0GCSqGSIb3DQEBAQUAA4IBDwAwggEKAoIBAQDVDDrEKvlO4vW+GZdfjohTsR8/\n"
  "y8+fIBNtKTrID30892t2OGPZNmCom15cAICyL1l/9of5JUOG52kbUpqQ4XHj2C0N\n"
  "Tm/2yEnZtvMaVq4rtnQU68/7JuMauh2WLmo7WJSJR1b/JaCTcFOD2oR0FMNnngRo\n"
  "Ot+OQFodSk7PQ5E751bWAHDLUu57fa4657wx+UX2wmDPE1kCK4DMNEffud6QZW0C\n"
  "zyyRpqbn3oUYSXxmTqM6bam17jQuug0DuDPfR+uxa40l2ZvOgdFFRjKWcIfeAg5J\n"
  "Q4W2bHO7ZOphQazJ1FTfhy/HIrImzJ9ZVGif/L4qL8RVHHVAYBeFAlU5i38FAgMB\n"
  "AAGjgfAwge0wDwYDVR0TAQH/BAUwAwEB/zAOBgNVHQ8BAf8EBAMCAYYwHQYDVR0O\n"
  "BBYEFJxfAN+qAdcwKziIorhtSpzyEZGDMB8GA1UdIwQYMBaAFL9ft9HO3R+G9FtV\n"
  "rNzXEMIOqYjnME8GCCsGAQUFBwEBBEMwQTAcBggrBgEFBQcwAYYQaHR0cDovL28u\n"
  "c3MyLnVzLzAhBggrBgEFBQcwAoYVaHR0cDovL3guc3MyLnVzL3guY2VyMCYGA1Ud\n"
  "HwQfMB0wG6AZoBeGFWh0dHA6Ly9zLnNzMi51cy9yLmNybDARBgNVHSAECjAIMAYG\n"
  "BFUdIAAwDQYJKoZIhvcNAQELBQADggEBACMd44pXyn3pF3lM8R5V/cxTbj5HD9/G\n"
  "VfKyBDbtgB9TxF00KGu+x1X8Z+rLP3+QsjPNG1gQggL4+C/1E2DUBc7xgQjB3ad1\n"
  "l08YuW3e95ORCLp+QCztweq7dp4zBncdDQh/U90bZKuCJ/Fp1U1ervShw3WnWEQt\n"
  "8jxwmKy6abaVd38PMV4s/KCHOkdp8Hlf9BRUpJVeEXgSYCfOn8J3/yNTd126/+pZ\n"
  "59vPr5KW7ySaNRB6nJHGDn2Z9j8Z3/VyVOEVqQdZe4O/Ui5GjLIAZHYcSNPYeehu\n"
  "VsyuLAOQ1xk4meTKCRlb/weWsKh/NEnfVqn3sF/tM+2MR7cwA130A4w=\n"
  "-----END CERTIFICATE-----\n";
//
//Define Variables
//
// Create arrays to store start times of each 1/2hr tariff slot and agile tariff for each
//
double tariffArray[200];
double lowestTariffVisible = 99.99;  // to store lowest tariff & time slot present in available data
double lowestTariffTime = 0;
time_t startTimeArray[200];
time_t currentTime;
double currentTariff = 99.99;  // to hold live tariff for display
// Set LED Pins
int greenLEDPin = 19;
int redLEDPin = 18;
int boostButtonPin = 15;
boolean boostActive = false;                    // Flag for boost state
int boostIncrement = 1800000;                   // boost interval (millis) per button press (1800000 = 30m 3600000 = 1h)
int boostDemand = 0;                            // Total boost millis set by user
int boostStart = 0;                             // store for boost start time (millis)
int buttonTimeOut = 10000;                      // interval allowed for string of boost presses. After this delay button reverts to turning immersion off, i.e. terminates boost period early
const double tariffThreshold = 7.0;             // Tariff level below which the output pin (greenLEDPin) will be set LOW (Gas 9.84p / kWh at 6/1/2023)
long int lastTariffUpdate = 0;                  // used to store millis() of last tariff update
const long int tariffUpdateInterval = 3600000;  // millis() between successive tariff updates from Octopus (3600000ms = 1h, 10800s = 3h, 14400s = 4h)
int numRecords = 0;                             // No. of tariff records available from Octopus API
long int setOutputInterval = 10000;             // interval between checks of current tariff data against tariffThreshold
int d = 1;                                      // Counter for cycling the display content
//
WiFiClientSecure client;
DynamicJsonDocument doc(20000);
//
void setup() {
  // SSD1306_SWITCHCAPVCC = generate display voltage from 3.3V internally
  if (!display.begin(SSD1306_SWITCHCAPVCC, SCREEN_ADDRESS)) {
    Serial.println(F("SSD1306 allocation failed"));
    for (;;)
      ;  // Don't proceed, loop forever
  }
  // Clear the display buffer
  display.clearDisplay();
  // Display date of this code
  display.setTextColor(SSD1306_WHITE);
  display.setTextSize(1);  // Draw 2X-scale text
  display.setCursor(0, 0);
  display.print(Date);
  display.setCursor(0, 15);
  display.setTextSize(2);  // Draw 2X-scale text
  display.print(F("Starting.."));
  display.setCursor(0, 40);
  display.setTextSize(1);  // Draw 2X-scale text
  display.print(F("Threshold = "));
  display.print(tariffThreshold,2);
  display.print("p");
  display.display();  // Show initial text
  delay(2000);
  //
  // Time Setup
  sntp_set_time_sync_notification_cb(timeavailable);
  /**
     NTP server address could be aquired via DHCP,

     NOTE: This call should be made BEFORE esp32 aquires IP address via DHCP,
     otherwise SNTP option 42 would be rejected by default.
     NOTE: configTime() function call if made AFTER DHCP-client run
     will OVERRIDE aquired NTP server address
  */
  sntp_servermode_dhcp(1);  // (optional)
  /**
     This will set configured ntp servers and constant TimeZone/daylightOffset
     should be OK if your time zone does not need to adjust daylightOffset twice a year,
     in such a case time adjustment won't be handled automagicaly.
  */
  configTime(gmtOffset_sec, daylightOffset_sec, ntpServer1, ntpServer2);
  //
  //Initialize serial and wait for port to open:
  Serial.begin(115200);
  delay(100);
  // Set LEDs as output
  pinMode(greenLEDPin, OUTPUT);
  pinMode(redLEDPin, OUTPUT);
  pinMode(boostButtonPin, INPUT);
  //
  Serial.print("Attempting to connect to SSID: ");
  Serial.println(ssid);
  WiFi.begin(ssid, password);
  // Attempt to connect to Wifi network:
  while (WiFi.status() != WL_CONNECTED) {
    Serial.print(".");
    digitalWrite(redLEDPin, HIGH);  // Set red LED on while unconnected
    // wait 1 second before re-trying
    delay(1000);
  }
  //
  digitalWrite(redLEDPin, LOW);  // turn off red LED once connected to WiFi
  Serial.print("Connected to ");
  Serial.println(ssid);
  display.clearDisplay();
  //
  display.setTextSize(2);  // Draw 2X-scale text
  display.setTextColor(SSD1306_WHITE);
  display.setCursor(5, 0);
  display.println(F("SSID: "));
  display.println(F(ssid));
  display.display();  // Show initial text
  //
  delay(5000);
  Get_Octopus_Data();  // Load initial Octopus Data
  lastTariffUpdate = millis();
}
//**************************************
void loop() {
  // Check for Boost Button
  if (digitalRead(boostButtonPin) && !boostActive)  // button pressed outside boost seesion
  {
    delay(200);                                       // debounce delay
    if (digitalRead(boostButtonPin) && !boostActive)  // button still pressed after de-bounce delay
    {
      digitalWrite(redLEDPin, HIGH);
      delay(200);  // flash Red LED
      digitalWrite(redLEDPin, LOW);
      boostActive = true;
      digitalWrite(greenLEDPin, HIGH);  // turn on immersion heater
      boostStart = millis();            // record boost start time
      boostDemand = boostIncrement;     // Set boost demand period
      updateOLED();
    }
  }
  if (digitalRead(boostButtonPin) && (millis() - boostStart < buttonTimeOut) && boostActive)  // check for further button presses during button time out delay & increment boost time if found
  {
    delay(200);
    if (digitalRead(boostButtonPin) && (millis() - boostStart < buttonTimeOut) && boostActive)  // check button was really pressed
    {
      digitalWrite(redLEDPin, HIGH);
      delay(200);  // flash Red LED
      digitalWrite(redLEDPin, LOW);
      boostDemand = boostDemand + boostIncrement;
      updateOLED();
    }
  }
  if (digitalRead(boostButtonPin) && (millis() - boostStart > buttonTimeOut) && boostActive)  // if button pressed outside buttonTimeOut delay, then cancel Boost
  {
    delay(200);  // debounce delay
    if (digitalRead(boostButtonPin) && (millis() - boostStart > buttonTimeOut) && boostActive) {
      digitalWrite(redLEDPin, HIGH);
      delay(500);  // flash Red LED
      digitalWrite(redLEDPin, LOW);
      boostActive = false;
      digitalWrite(greenLEDPin, LOW);  // turn off immersion heater
      boostDemand = 0;                 // reset ready for next boost session
      updateOLED();
    }
  }
  if ((millis() - boostStart > boostDemand) && boostActive)  // check for end of boost period
  {
    boostActive = false;
    digitalWrite(greenLEDPin, LOW);  // turn off immersion heater
    boostDemand = 0;                 // reset ready for next boost session
    updateOLED();
  }
  //
  if (millis() > (lastTariffUpdate + tariffUpdateInterval))  // update Octopus tariff periodically
  {
    Get_Octopus_Data();
    lastTariffUpdate = millis();
  }
  //
  if ((millis() % setOutputInterval) == 0)  // START OF TIMED LOOP : Code run each time tariff is checked & immersion output set
  {
    //   Serial.println(millis());
    digitalWrite(redLEDPin, HIGH);  // Heartbeat on red LED
    delay(200);
    digitalWrite(redLEDPin, LOW);
    //
    //printLocalTime();  // it will take some time to sync time :)
    //
    if (!boostActive)  // only do this if boost is not active
    {
      //CHECK TARIFF AND SET OUTPUT PIN HERE
      struct tm timeinfo;
      getLocalTime(&timeinfo);
      currentTime = mktime(&timeinfo);
      Serial.print("currentTime is ");
      Serial.println(currentTime);
      Serial.print("Number of Octopus Tariff Records = ");
      Serial.print(numRecords);
      Serial.print(", Tariff Threshold is ");
      Serial.println(tariffThreshold);
      int i = 0;
      lowestTariffVisible = 99.99;  // reset to 'crazy' values immediately before setting correctly
      lowestTariffTime = 0;
      while (i <= numRecords) {
        if ((currentTime > startTimeArray[i]) && ((currentTime - startTimeArray[i]) < 1800)) {
//        if (currentTime > (startTimeArray[i] + 1800)) {
          Serial.print("Current Tariff is ");
          // Serial.print(tariffArray[i], 2);
          currentTariff = tariffArray[i];
          Serial.print(currentTariff, 2);
          Serial.print("p (Record #");
          Serial.print(i);
          Serial.println(")");
          if (tariffArray[i] < tariffThreshold) {
            digitalWrite(greenLEDPin, HIGH);
            Serial.println("************** LOW TARIFF CONDITION **************");
          } else {
            digitalWrite(greenLEDPin, LOW);
          }
        }
        if ((tariffArray[i] < lowestTariffVisible) && (startTimeArray[i] + 1800) > currentTime)  // find lowest published tariff beyond present one
        {
          lowestTariffVisible = tariffArray[i];  // find lowest tariff present in available data
          lowestTariffTime = startTimeArray[i];
          Serial.print("Lowest tariff is ");
          Serial.println(lowestTariffVisible);
          Serial.print(", Array Values - ");
          Serial.print(tariffArray[i]);
          Serial.print(", ");
          Serial.println(startTimeArray[i]);
        }
        i++;
      }
      Serial.print("Lowest Future Tariff Published = ");
      Serial.println(lowestTariffVisible);
      Serial.print("Time to Lowest Tariff is ");
      Serial.print((lowestTariffTime - currentTime) / 3600);
      Serial.println(" h");
      if (d == 1) {
        updateOLED();
      }
      if (d == 2) {
        graphOLED();
      }
      d++;
      if (d > 2) {
        d = 1;  //Reset display content counter
      }
    } else {
      updateOLED();  // update OLED during boost periods
    }
  }  // End of Timed Refresh Loop
}  // END OF MAIN LOOP
//
//FUNCTIONS
//
void Get_Octopus_Data()  // Get Octopus Data
{
  client.setCACert(octopus);
  Serial.println("\nStarting connection to Octopus server...");
  if (!client.connect(server, 443)) {
    Serial.println("Connection failed!");
    digitalWrite(redLEDPin, HIGH);  // Set LED to indicate connection failure
  } else {
    Serial.println("Connected to server!");
    digitalWrite(redLEDPin, LOW);
    // Make a HTTP request:
    client.println("GET https://api.octopus.energy/v1/products/AGILE-18-02-21/electricity-tariffs/E-1R-AGILE-18-02-21-E/standard-unit-rates/ HTTP/1.1");
    client.println("Host: api.octopus.energy");
    client.println(auth_string); // enter Octopus authorisation string, collected from secrets.h
    client.println("Connection: close");
    client.println();
    //
    while (client.connected()) {
      String line = client.readStringUntil('\n');
      if (line == "\r") {
        Serial.println("headers received");
        break;
      }
    }
    // If there are incoming bytes available
    // from the server, read them and print them:
    while (client.available()) {
      String line = client.readStringUntil('\n');
      DeserializationError error = deserializeJson(doc, line);
      if (error) {
        Serial.print(F("deserializing JSON failed"));
        Serial.println(error.f_str());
        Serial.println("Here's the JSON I tried to parse");
        Serial.println(line);
      } else {
        JsonArray results = doc["results"];
        numRecords = results.size();
        Serial.print("# of Records is ");
        Serial.println(numRecords);
        int i = 0;
        while (i < numRecords) {
          double tariff = doc["results"][i]["value_inc_vat"];
          tariffArray[i] = tariff;
          String periodStart = doc["results"][i]["valid_from"];
          struct tm tmpTime;
          strptime(periodStart.c_str(), "%Y-%m-%dT%H:%M:%SZ", &tmpTime);
          startTimeArray[i] = mktime(&tmpTime);
          Serial.print(tariff, 2);
          Serial.print("p, from ");
          //          Serial.println(periodStart);
          Serial.print(periodStart);
          Serial.print(" ");
          Serial.println(startTimeArray[i]);
          //          printTime(startTimeArray[i]);
          i++;
        }
      }
      client.stop();
    }
  }
}
//
void printTime(time_t timeToPrint)  // Print time to serial monitor
{
  char buff1[100];
  struct tm tmpTime;
  gmtime_r(&timeToPrint, &tmpTime);
  strftime(buff1, 100, "%A, %B-%Y, %T", &tmpTime);
  Serial.print("buff1 = ");
  Serial.println(buff1);
}
// Clock Functions
//
/*
void printLocalTime() {
  struct tm timeinfo;
  if (!getLocalTime(&timeinfo)) {
    Serial.println("No time available (yet)");
    return;
  }
  //
  Serial.println(&timeinfo, "%A, %B %d %Y %H:%M:%S");
//  display.print(&timeinfo, "%A, %B %d %Y %H:%M:%S");
}
*/
void updateOLED() {
  display.clearDisplay();
  //
  struct tm timeinfo;
  if (!getLocalTime(&timeinfo)) {
    Serial.println("No time available (yet)");
    return;
  }
  //
  Serial.println(&timeinfo, "%A, %B %d %Y %H:%M:%S");
  //  display.print(&timeinfo, "%A, %B %d %Y %H:%M:%S");
  //
  display.setTextSize(1);
  display.setTextColor(SSD1306_WHITE);
  display.setCursor(0, 0);
  display.print(&timeinfo, "%A, %B %d");
  display.setCursor(0, 11);
  display.print(&timeinfo, "       %H:%M:%S");
  // display.print(&timeinfo, "%A, %B %d %Y %H:%M:%S");
  display.setCursor(0, 28);
  if (!boostActive) {
    display.print("Tariff ");
    display.setTextSize(2);
    display.print(currentTariff);
    //  display.setTextSize(1);
    display.print(" p");
    //
    //   display.drawRect(0, 45, 43, 19, SSD1306_WHITE);
    display.fillRect(0, 45, 43, 19, SSD1306_WHITE);  //
    display.setTextSize(2);
    display.setTextColor(SSD1306_BLACK);
    display.setCursor(4, 48);
    if (currentTariff < tariffThreshold) {
      display.print("ON");
    } else {
      display.print("OFF");
    }
    display.setTextSize(1);
    display.setTextColor(SSD1306_WHITE);
    display.setCursor(50, 48);
    display.print("Next Lowest");
    display.setCursor(50, 57);
    display.print(lowestTariffVisible);
    display.print(" p");
    display.display();  // push to OLED
    delay(4500);
    display.fillRect(50, 48, (128 - 50), (64 - 48), SSD1306_BLACK);
    display.setCursor(50, 48);
    display.print("Next Lowest");
    display.setCursor(50, 57);
    display.print("In ");
    display.print(int((lowestTariffTime - currentTime) / 3600));
    display.print("h ");
    display.print(int((((lowestTariffTime - currentTime) / 3600) - int((lowestTariffTime - currentTime) / 3600)) * 60));
    display.print("m");
  } else {
    display.setTextSize(2);
    display.setCursor(5, 30);
    display.print("Boost ");
    //    display.setTextSize(2);
    display.setCursor(43, 49);
    display.print((boostDemand - (millis() - boostStart)) / 60000);
    display.setTextSize(1);
    display.print(" mins");
  }
  display.display();
}
// Callback function (get's called when time adjusts via NTP)
//
void timeavailable(struct timeval* t) {
  Serial.println("Got time adjustment from NTP!");
  //  printLocalTime();
}
//
void graphOLED() {
  display.clearDisplay();
  //  display.drawLine(0, 15, 0, 63, SSD1306_WHITE);  // Draw Axes
  display.drawLine(0, 63, 127, 63, SSD1306_WHITE);
  int i = 1;
  while (i < 128) {
    if (i % 3 == 0) {
      display.drawPixel(i, 53, SSD1306_WHITE);  // Draw grid line at 10p intervals
      display.drawPixel(i, 43, SSD1306_WHITE);
      display.drawPixel(i, 33, SSD1306_WHITE);
      display.display();
    }
    i++;
  }  //
  i = 0;
  while (i <= numRecords) {
    if (currentTime < startTimeArray[i])  // only plot future values
    {
      if (startTimeArray[i] == lowestTariffTime) { // Draw circle around the lowest tariff visible, to highlight it
        display.fillCircle(((startTimeArray[i] - currentTime) / 1800) * (127 / ((startTimeArray[0] - currentTime) / 1800)), (63 - int(tariffArray[i])), 4, SSD1306_WHITE);
        display.fillCircle(((startTimeArray[i] - currentTime) / 1800) * (127 / ((startTimeArray[0] - currentTime) / 1800)), (63 - int(tariffArray[i])), 3, SSD1306_BLACK);
        // Change above to triangles?
        display.drawLine(((startTimeArray[i] - currentTime) / 1800) * (127 / ((startTimeArray[0] - currentTime) / 1800)), 63, ((startTimeArray[i] - currentTime) / 1800) * (127 / ((startTimeArray[0] - currentTime) / 1800)), (63 - int(tariffArray[i])), SSD1306_WHITE);
        display.display();
      } else {
        //      Serial.println(int(tariffArray[i]));
        //      display.drawLine((startTimeArray[i] - currentTime) / 900, 63, (startTimeArray[i] - currentTime) / 900, (63 - int(tariffArray[i])), SSD1306_WHITE);
        display.drawLine(((startTimeArray[i] - currentTime) / 1800) * (127 / ((startTimeArray[0] - currentTime) / 1800)), 63, ((startTimeArray[i] - currentTime) / 1800) * (127 / ((startTimeArray[0] - currentTime) / 1800)), (63 - int(tariffArray[i])), SSD1306_WHITE);
        Serial.print(((startTimeArray[0] - currentTime) / 1800));
        Serial.print(" ");
        Serial.println(((startTimeArray[i] - currentTime) / 1800) * (127 / ((startTimeArray[0] - currentTime) / 1800)));
        display.display();
      }
    }
    i++;
    display.setTextSize(1);
    display.setTextColor(SSD1306_WHITE);
    display.setCursor(4, 0);
    display.print("Next Lowest ");
    //    display.setCursor(50, 57);
    display.print(lowestTariffVisible);
    display.print("p");
    display.setCursor(30, 12);
    //  display.print("Next Lowest ");
    // display.setCursor(50, 57);
    display.print("In ");
    display.print(int((lowestTariffTime - currentTime) / 3600));
    display.print("h ");
    display.print(int((((lowestTariffTime - currentTime) / 3600) - int((lowestTariffTime - currentTime) / 3600)) * 60));
    display.print("m");
  }
  display.display();
}