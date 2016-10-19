/* Plug in all WiFiDomo modules you want to use with this Switch.
   With your browser/app/WiFiDomo-Manager, set every module to your preferred color scheme.
   Now plug in the power of the WiFiDomo-Switch. Goto your wifi settings and connect to the
   "wifidomo" network (ssid). Goto your browser and type "192.168.4.1" in your address bar
   followed by an "enter". Setup your home wifi network settings. After clicking the "save"
   button, wait for about ten minutes while the switch is scanning your network for WiFiDomo
   modules and their current color/brightness.
   That's it. Your Switch is now programmed to your colorscheme and ready to be pushed.
   To reset all settings push the FLASH button once in normal operation mode, then repeat
   the above steps*/



#include <ESP8266WiFi.h>          //https://github.com/esp8266/Arduino

//needed for library
#include <ESP8266WebServer.h>
#include <DNSServer.h>
#include <WiFiManager.h>          //https://github.com/tzapu/WiFiManager
#include <Arduino.h>
#include <EEPROM.h>
#include <ESP8266WiFi.h>
#include <ESP8266HTTPClient.h>

#define SWITCHPIN 4
#define TRIGGER_PIN 0
#define USE_SERIAL Serial
String payload;
String outputString;
String outPut;
String prefix;
String data0 = "";
String data1 = "";
String data2 = "";
String data3 = "";
String data4 = "";
String data5 = "";
String data6 = "";
String data7 = "";
String data8 = "";
String data9 = "";
String data10 = "";
String data11 = "";
String data12 = "";
String data13 = "";
String data14 = "";
String data15 = "";
String data16 = "";
String data17 = "";
String data18 = "";
String data19 = "";
char totalStr[40];
char character;
int count = 0;
int k = 0;
int httpCode = 0;
int indx = 0;


HTTPClient http;


void writeEEPROM(int addrByteW, String inputString) {
  inputString.toCharArray(totalStr, sizeof(totalStr));
  for (int i = 0; i <= sizeof totalStr; i++) {
    char c = (char)totalStr[i];
    EEPROM.write( addrByteW + i, (byte)c );
  }
}

String readEEPROM(int addrByteR)  {
  int value;
  outputString = "";
  for (int v = addrByteR; v < addrByteR + 39; v++)  {
    value = EEPROM.read( addrByteR + v );
    if (( value == '\0' ) or (value == ' ')) {
      //Do nothing
    } else {
      outputString += (char)(value);
    }
  }
  return (outputString);
}

void checkStatus(){
  //check for light status
  outPut = readEEPROM(0);
  if (outPut != "") {
    indx = outPut.indexOf("/"); //Locate the character, return character number
    outPut.remove(indx); // Remove everything after this "/" character in the String.
    outPut += "/status"; // Call for the state of the first IP in memory
    prefix = "http://";
    prefix += outPut;
    http.begin(prefix); //HTTP
    httpCode = http.GET();
    USE_SERIAL.println(prefix);
    delay(2);
    payload = http.getString();
    http.end();
  }
}

void sendPreset(){
  USE_SERIAL.printf("Sending 'ON' values...\n");
  http.begin(data0); //HTTP
  httpCode = http.GET();
  http.end();
  http.begin(data1); //HTTP
  httpCode = http.GET();
  http.end();
  http.begin(data2); //HTTP
  httpCode = http.GET();
  http.end();
  http.begin(data3); //HTTP
  httpCode = http.GET();
  http.end();
  http.begin(data4); //HTTP
  httpCode = http.GET();
  http.end();
  http.begin(data5); //HTTP
  httpCode = http.GET();
  http.end();
  http.begin(data6); //HTTP
  httpCode = http.GET();
  http.end();
  http.begin(data7); //HTTP
  httpCode = http.GET();
  http.end();
  http.begin(data8); //HTTP
  httpCode = http.GET();
  http.end();
  http.begin(data9); //HTTP
  httpCode = http.GET();
  http.end();
}

void sendOff(){
  USE_SERIAL.printf("Sending 'OFF' values...\n");
  http.begin(data10); //HTTP
  httpCode = http.GET();
  http.end();
  http.begin(data11); //HTTP
  httpCode = http.GET();
  http.end();
  http.begin(data12); //HTTP
  httpCode = http.GET();
  http.end();
  http.begin(data13); //HTTP
  httpCode = http.GET();
  http.end();
  http.begin(data14); //HTTP
  httpCode = http.GET();
  http.end();
  http.begin(data15); //HTTP
  httpCode = http.GET();
  http.end();
  http.begin(data16); //HTTP
  httpCode = http.GET();
  http.end();
  http.begin(data17); //HTTP
  httpCode = http.GET();
  http.end();
  http.begin(data18); //HTTP
  httpCode = http.GET();
  http.end();
  http.begin(data19); //HTTP
  httpCode = http.GET();
  http.end();
}

void prepareOn(){
  USE_SERIAL.printf("Assembling 'ON' values...\n");
  for (int y = 0; y <= 10; y++) {
    delay(2);
    switch (y) {
    case 1:
      outPut = readEEPROM(0);
      if(outPut != ""){
        outPut.replace("/", "/switch");
        prefix = "http://";
        prefix += outPut;
        data0 = prefix;
      }
      break;
    case 2:
      outPut = readEEPROM(20);
      if(outPut != ""){
        outPut.replace("/", "/switch");
        prefix = "http://";
        prefix += outPut;
        data1 = prefix;
      }
      break;
    case 3:
      outPut = readEEPROM(40);
      if(outPut != ""){
        outPut.replace("/", "/switch");
        prefix = "http://";
        prefix += outPut;
        data2 = prefix;
      }
      break;
    case 4:
      outPut = readEEPROM(60);
      if(outPut != ""){
        prefix = "http://";
        outPut.replace("/", "/switch");
        prefix += outPut;
        data3 = prefix;
      }
      break;
    case 5:
      outPut = readEEPROM(80);
      if(outPut != ""){
        outPut.replace("/", "/switch");
        prefix = "http://";
        prefix += outPut;
        data4 = prefix;
      }
      break;
    case 6:
      outPut = readEEPROM(100);
      if(outPut != ""){
        outPut.replace("/", "/switch");
        prefix = "http://";
        prefix += outPut;
        data5 = prefix;
      }
      break;
    case 7:
      outPut = readEEPROM(120);
      if(outPut != ""){
        outPut.replace("/", "/switch");
        prefix = "http://";
        prefix += outPut;
        data6 = prefix;
      }
      break;
    case 8:
      outPut = readEEPROM(140);
      if(outPut != ""){
        outPut.replace("/", "/switch");
        prefix = "http://";
        prefix += outPut;
        data7 = prefix;
      }
      break;
    case 9:
      outPut = readEEPROM(160);
      if(outPut != ""){
        outPut.replace("/", "/switch");
        prefix = "http://";
        prefix += outPut;
        data8 = prefix;
      }
      break;
    case 10:
      outPut = readEEPROM(180);
      if(outPut != ""){
        outPut.replace("/", "/switch");
        prefix = "http://";
        prefix += outPut;
        data9 = prefix;
      }
      break;
    }
    USE_SERIAL.println(prefix);
  }
}

void prepareOff(){
  USE_SERIAL.printf("Assembling 'OFF' values...\n");
  for (int v = 0; v < 10; v++) {
    delay(2);
    switch (v) {
    case 1:
      if(data0 != ""){
        outPut = data0;
        indx = outPut.lastIndexOf("/"); //Locate the character, return character number
        outPut.remove(indx); // Remove everything after this "/" character in the String.
        outPut += "/switch?r=1023&g=1023&b=1023"; //Turn lights off
        data10 = outPut;
      }
      break;
    case 2:
      if(data1 != ""){
        outPut = data1;
        indx = outPut.lastIndexOf("/"); //Locate the character, return character number
        outPut.remove(indx); // Remove everything after this "/" character in the String.
        outPut += "/switch?r=1023&g=1023&b=1023"; //Turn lights off
        data11 = outPut;
      }
      break;
    case 3:
      if(data2 != ""){
        outPut = data2;
        indx = outPut.lastIndexOf("/"); //Locate the character, return character number
        outPut.remove(indx); // Remove everything after this "/" character in the String.
        outPut += "/switch?r=1023&g=1023&b=1023"; //Turn lights off
        data12 = outPut;
      }
      break;
    case 4:
      if(data3 != ""){
        outPut = data3;
        indx = outPut.lastIndexOf("/"); //Locate the character, return character number
        outPut.remove(indx); // Remove everything after this "/" character in the String.
        outPut += "/switch?r=1023&g=1023&b=1023"; //Turn lights off
        data13 = outPut;
      }
      break;
    case 5:
      if(data4 != ""){
        outPut = data4;
        indx = outPut.lastIndexOf("/"); //Locate the character, return character number
        outPut.remove(indx); // Remove everything after this "/" character in the String.
        outPut += "/switch?r=1023&g=1023&b=1023"; //Turn lights off
        data14 = outPut;
      }
      break;
    case 6:
      if(data5 != ""){
        outPut = data5;
        indx = outPut.lastIndexOf("/"); //Locate the character, return character number
        outPut.remove(indx); // Remove everything after this "/" character in the String.
        outPut += "/switch?r=1023&g=1023&b=1023"; //Turn lights off
        data15 = outPut;
      }
      break;
    case 7:
      if(data6 != ""){
        outPut = data6;
        indx = outPut.lastIndexOf("/"); //Locate the character, return character number
        outPut.remove(indx); // Remove everything after this "/" character in the String.
        outPut += "/switch?r=1023&g=1023&b=1023"; //Turn lights off
        data16 = outPut;
      }
      break;
    case 8:
      if(data7 != ""){
        outPut = data7;
        indx = outPut.lastIndexOf("/"); //Locate the character, return character number
        outPut.remove(indx); // Remove everything after this "/" character in the String.
        outPut += "/switch?r=1023&g=1023&b=1023"; //Turn lights off
        data17 = outPut;
      }
      break;
    case 9:
      if(data8 != ""){
        outPut = data8;
        indx = outPut.lastIndexOf("/"); //Locate the character, return character number
        outPut.remove(indx); // Remove everything after this "/" character in the String.
        outPut += "/switch?r=1023&g=1023&b=1023"; //Turn lights off
        data18 = outPut;
      }
      break;
    case 10:
      if(data9 != ""){
        outPut = data9;
        indx = outPut.lastIndexOf("/"); //Locate the character, return character number
        outPut.remove(indx); // Remove everything after this "/" character in the String.
        outPut += "/switch?r=1023&g=1023&b=1023"; //Turn lights off
        data19 = outPut;
      }
      break;
    }
    USE_SERIAL.println(outPut);
  }
}


void startPortal(){
  WiFiManager wifiManager;
  wifiManager.resetSettings();
  if (!wifiManager.startConfigPortal("OnDemandAP")) {
    Serial.println("failed to connect and hit timeout");
    delay(3000);
    //reset and try again, or maybe put it to deep sleep
    ESP.reset();
    delay(5000);
  }
  findModules();
}

void eraseAndFind(){
  USE_SERIAL.printf("Erasing Memory...\n");
  for (int i = 0; i < 512; i++) {
    delay(2);
    EEPROM.write((i), (byte)'\0');
  }
  EEPROM.commit();
  findModules();
}

void findModules() {
  Serial.println("Scanning for active WiFiDomo Modules...");
  if ((WiFi.status() == WL_CONNECTED)) {
    for (int u = 2; u < 40; u++) {
      String x = String(u);
      String IP = ("http://192.168.192." + x + "/status");
      http.begin(IP); //HTTP
      int httpCode = http.GET();
      if (httpCode > 0) {
        if (httpCode == HTTP_CODE_OK) {
          payload = http.getString();
          if ((payload == "[1023:1023:1023]") or (httpCode != HTTP_CODE_OK)) {
            // do nothing
          }
          else {
            payload.replace("[", "/?r=");
            payload.setCharAt(payload.lastIndexOf(":"), '|');
            payload.replace(":", "&g=");
            payload.replace("|", "&b=");
            payload.replace("]", "");
            USE_SERIAL.println("192.168.192." + x + payload);
            String arrayToSave = ("192.168.192." + x + payload);
            writeEEPROM(k * 40, arrayToSave);
            //yield();
            EEPROM.commit();
            delay(50);
            if (k < 10) {
              k++;
            } else {
              k = 0;
            }
          }
        }
      } else {
        USE_SERIAL.printf("No Active WiFiDomo here... 192.168.x.%d\n", u);
      }
      http.end();
    }
  }
  delay(1000);
}

void setup() {
  // put your setup code here, to run once:
  USE_SERIAL.begin(115200);
  EEPROM.begin(512);
  USE_SERIAL.println();
  USE_SERIAL.println();
  USE_SERIAL.println();
  for (uint8_t t = 4; t > 0; t--) {
    USE_SERIAL.printf("[SETUP] WAIT %d...\n", t);
    USE_SERIAL.flush();
    delay(1000);
  }
  pinMode(SWITCHPIN, INPUT_PULLUP);
  pinMode(TRIGGER_PIN, INPUT);

  //LOAD ALL DATA FROM MEMORY
  prepareOn();
  delay(1000);
  prepareOff();
  USE_SERIAL.printf("Done preparing data...\n");
}


void loop() {
  // is configuration portal requested?
  if ( digitalRead(TRIGGER_PIN) == LOW ) {
    delay(2000);
    if ( digitalRead(TRIGGER_PIN) == LOW ) {
      eraseAndFind();
    } else {
      startPortal();
    }
  }

  //MAIN CODE
  if ( digitalRead(SWITCHPIN) == LOW ) {
    USE_SERIAL.printf("Button is pressed!\n");
    checkStatus();
    if (payload == "[1023:1023:1023]") {
      sendPreset();
    } else {
      sendOff();
    }
  }
}

