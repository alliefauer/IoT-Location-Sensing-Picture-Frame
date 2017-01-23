/*
IoT Location Sensing Picture Frame by Allie Fauer

Instructions for building this project can be found at 
http://www.instructables.com/id/IoT-Location-Sensing-Picture-Frame
*/

#include <LPD8806.h> 
#include <SPI.h>
#include <Ethernet.h>
#include <PubSubClient.h>


int dataPin = 11; //Edison Pin 11 (SPI Data)
int clockPin = 13; //Edison Pin 13 (Clock)
int nLEDs = 16; //Total number of LEDs

LPD8806 strip = LPD8806(nLEDs, dataPin, clockPin);


byte mac[]    = {   0xFC, 0xC2, 0xDE, 0x44, 0xEA, 0xF5 }; //byte mac
IPAddress ip(192, 168, 1, 103); //ip address of Edison
IPAddress server(107, 22, 157, 224); //ip address of m11.cloudmqtt.com

void callback(char* topic, byte* payload, unsigned int length);
  // handle message arrived
  
EthernetClient ethClient;
PubSubClient client(server, 11803, callback, ethClient); //Replace '11803' with your Port

void callback(char* topic, byte* payload, unsigned int length) {
  // handle message arrived

payload[length] = '\0';
String strPayload = String((char*)payload); //convert byte* to char*
String stringOne = strPayload; //make incoming char* payload stringOne 

//Declare the 'key words' to look for
 
int home = stringOne.indexOf("Home"); 
int half = stringOne.indexOf("Half Mile");
int one = stringOne.indexOf("One Mile");
int two = stringOne.indexOf("Two Miles");
int three = stringOne.indexOf("Three Miles");
int five = stringOne.indexOf("Five Miles");
int ten = stringOne.indexOf("Ten Miles");
int fifteen = stringOne.indexOf("Fifteen Miles");
int twentyfive = stringOne.indexOf("Twenty-five Miles");
int destination = stringOne.indexOf("Destination");
int enter = stringOne.indexOf("enter");
int leave = stringOne.indexOf("leave");  

payload[length] = '\0';
String sub = topic; //convert topic to string
String stringTwo = sub;

//Declare MQTT topics 

int person1 = stringTwo.indexOf("owntracks/jfcyrvev/allie/event"); //event MQTT topic of Person #1
int person2 = stringTwo.indexOf("owntracks/jfcyrvev/shari/event"); //event MQTT topic of Person #2
int person3 = stringTwo.indexOf("owntracks/jfcyrvev/steve/event"); //event MQTT topic of Person #3
int person4 = stringTwo.indexOf("owntracks/jfcyrvev/erin/event"); //event MQTT topic of Person #1

int i;

for(i=0; i<4; i++){  

if((person1 == 0) && (twentyfive > 0) && (leave > 0)) {
   strip.setPixelColor(i, 127, 127, 127);
   strip.show();
}
if(((person1 == 0) && (fifteen > 0) && (leave > 0)) || ((person1 == 0) && (twentyfive > 0) && (enter > 0))){
   strip.setPixelColor(i, 127,  0,  0);
   strip.show();
}
if(((person1 == 0) && (ten > 0) && (leave > 0)) || ((person1 == 0) && (fifteen > 0) && (enter > 0))){
   strip.setPixelColor(i, 127,  0,  4);
   strip.show();
}
if(((person1 == 0) && (five > 0) && (leave > 0)) || ((person1 == 0) && (ten > 0) && (enter > 0))){
    strip.setPixelColor(i, 127,  0,  10);
    strip.show();
} 
if(((person1 == 0) && (three > 0) && (leave > 0)) || ((person1 == 0) && (five > 0) && (enter > 0))){
    strip.setPixelColor(i, 127,  0,  20);
    strip.show();
}
if(((person1 == 0) && (two > 0) && (leave > 0)) || ((person1 == 0) && (three > 0) && (enter > 0))){
   strip.setPixelColor(i, 127,  0,  30);
   strip.show();
}
if(((person1 == 0) && (one > 0) && (leave > 0)) || ((person1 == 0) && (two > 0) && (enter > 0))){
   strip.setPixelColor(i, 127,  0,  50);
   strip.show();
}
if(((person1 == 0) && (half > 0) && (leave > 0)) || ((person1 == 0) && (one > 0) && (enter > 0))){
   strip.setPixelColor(i, 90,  0,  60);
   strip.show();
}
if(((person1 == 0) && (home > 0) && (leave > 0)) || ((person1 == 0) && (half > 0) && (enter > 0))){
   strip.setPixelColor(i, 60,  0,  90);
   strip.show();
}
if(((person1 == 0) && (home > 0) && (enter > 0))){
   strip.setPixelColor(i, 0,  0,  127);
   strip.show();
}
if(((person1 == 0) && (destination > 0) && (enter > 0))){
   strip.setPixelColor(i, 0,  127,  0);
   strip.show();
}}

for(i=4; i<8; i++){  

if((person2 == 0) && (twentyfive > 0) && (leave > 0)) {
   strip.setPixelColor(i, 127, 127, 127);
   strip.show();
}
if(((person2 == 0) && (fifteen > 0) && (leave > 0)) || ((person2 == 0) && (twentyfive > 0) && (enter > 0))){
   strip.setPixelColor(i, 127,  0,  0);
   strip.show();
}
if(((person2 == 0) && (ten > 0) && (leave > 0)) || ((person2 == 0) && (fifteen > 0) && (enter > 0))){
   strip.setPixelColor(i, 127,  0,  4);
   strip.show();
}
if(((person2 == 0) && (five > 0) && (leave > 0)) || ((person2 == 0) && (ten > 0) && (enter > 0))){
    strip.setPixelColor(i, 127,  0,  10);
    strip.show();
} 
if(((person2 == 0) && (three > 0) && (leave > 0)) || ((person2 == 0) && (five > 0) && (enter > 0))){
    strip.setPixelColor(i, 127,  0,  20);
    strip.show();
}
if(((person2 == 0) && (two > 0) && (leave > 0)) || ((person2 == 0) && (three > 0) && (enter > 0))){
   strip.setPixelColor(i, 127,  0,  30);
   strip.show();
}
if(((person2 == 0) && (one > 0) && (leave > 0)) || ((person2 == 0) && (two > 0) && (enter > 0))){
   strip.setPixelColor(i, 127,  0,  50);
   strip.show();
}
if(((person2 == 0) && (half > 0) && (leave > 0)) || ((person2 == 0) && (one > 0) && (enter > 0))){
   strip.setPixelColor(i, 90,  0,  60);
   strip.show();
}
if(((person2 == 0) && (home > 0) && (leave > 0)) || ((person2 == 0) && (half > 0) && (enter > 0))){
   strip.setPixelColor(i, 60,  0,  90);
   strip.show();
}
if(((person2 == 0) && (home > 0) && (enter > 0))){
   strip.setPixelColor(i, 0,  0,  127);
   strip.show();
}
if(((person2 == 0) && (destination > 0) && (enter > 0))){
   strip.setPixelColor(i, 0,  127,  0);
   strip.show();
}}

for(i=8; i<12; i++){  

if((person3 == 0) && (twentyfive > 0) && (leave > 0)) {
   strip.setPixelColor(i, 127, 127, 127);
   strip.show();
}
if(((person3 == 0) && (fifteen > 0) && (leave > 0)) || ((person3 == 0) && (twentyfive > 0) && (enter > 0))){
   strip.setPixelColor(i, 127,  0,  0);
   strip.show();
}
if(((person3 == 0) && (ten > 0) && (leave > 0)) || ((person3 == 0) && (fifteen > 0) && (enter > 0))){
   strip.setPixelColor(i, 127,  0,  4);
   strip.show();
}
if(((person3 == 0) && (five > 0) && (leave > 0)) || ((person3 == 0) && (ten > 0) && (enter > 0))){
    strip.setPixelColor(i, 127,  0,  10);
    strip.show();
} 
if(((person3 == 0) && (three > 0) && (leave > 0)) || ((person3 == 0) && (five > 0) && (enter > 0))){
    strip.setPixelColor(i, 127,  0,  20);
    strip.show();
}
if(((person3 == 0) && (two > 0) && (leave > 0)) || ((person3 == 0) && (three > 0) && (enter > 0))){
   strip.setPixelColor(i, 127,  0,  30);
   strip.show();
}
if(((person3 == 0) && (one > 0) && (leave > 0)) || ((person3 == 0) && (two > 0) && (enter > 0))){
   strip.setPixelColor(i, 127,  0,  50);
   strip.show();
}
if(((person3 == 0) && (half > 0) && (leave > 0)) || ((person3 == 0) && (one > 0) && (enter > 0))){
   strip.setPixelColor(i, 90,  0,  60);
   strip.show();
}
if(((person3 == 0) && (home > 0) && (leave > 0)) || ((person3 == 0) && (half > 0) && (enter > 0))){
   strip.setPixelColor(i, 60,  0,  90);
   strip.show();
}
if(((person3 == 0) && (home > 0) && (enter > 0))){
   strip.setPixelColor(i, 0,  0,  127);
   strip.show();
}
if(((person3 == 0) && (destination > 0) && (enter > 0))){
   strip.setPixelColor(i, 0,  127,  0);
   strip.show();
}}

for(i=12; i<16; i++){  

if((person4 == 0) && (twentyfive > 0) && (leave > 0)) {
   strip.setPixelColor(i, 127, 127, 127);
   strip.show();
}
if(((person4 == 0) && (fifteen > 0) && (leave > 0)) || ((person4 == 0) && (twentyfive > 0) && (enter > 0))){
   strip.setPixelColor(i, 127,  0,  0);
   strip.show();
}
if(((person4 == 0) && (ten > 0) && (leave > 0)) || ((person4 == 0) && (fifteen > 0) && (enter > 0))){
   strip.setPixelColor(i, 127,  0,  4);
   strip.show();
}
if(((person4 == 0) && (five > 0) && (leave > 0)) || ((person4 == 0) && (ten > 0) && (enter > 0))){
    strip.setPixelColor(i, 127,  0,  10);
    strip.show();
} 
if(((person4 == 0) && (three > 0) && (leave > 0)) || ((person4 == 0) && (five > 0) && (enter > 0))){
    strip.setPixelColor(i, 127,  0,  20);
    strip.show();
}
if(((person4 == 0) && (two > 0) && (leave > 0)) || ((person4 == 0) && (three > 0) && (enter > 0))){
   strip.setPixelColor(i, 127,  0,  30);
   strip.show();
}
if(((person4 == 0) && (one > 0) && (leave > 0)) || ((person4 == 0) && (two > 0) && (enter > 0))){
   strip.setPixelColor(i, 127,  0,  50);
   strip.show();
}
if(((person4 == 0) && (half > 0) && (leave > 0)) || ((person4 == 0) && (one > 0) && (enter > 0))){
   strip.setPixelColor(i, 90,  0,  60);
   strip.show();
}
if(((person4 == 0) && (home > 0) && (leave > 0)) || ((person4 == 0) && (half > 0) && (enter > 0))){
   strip.setPixelColor(i, 60,  0,  90);
   strip.show();
}
if(((person4 == 0) && (home > 0) && (enter > 0))){
   strip.setPixelColor(i, 0,  0,  127);
   strip.show();
}
if(((person4 == 0) && (destination > 0) && (enter > 0))){
   strip.setPixelColor(i, 0,  127,  0);
   strip.show();
}}

}

void setup()
{

int i;
   for(i=0; i<16; i++){
  strip.setPixelColor(i, 127, 127, 27); //Make all LEDs white on restart
   }

  
strip.begin(); // Start up the LED strip
strip.show(); // Update the strip, to start they are all 'on'

Ethernet.begin(mac, ip); 

if (client.connect("arduinoClient", "jfcyrvev", "**************")) { //change to your username and password
    client.subscribe("owntracks/jfcyrvev/allie/event"); //event MQTT topic of Person #1
    client.subscribe("owntracks/jfcyrvev/shari/event"); //event MQTT topic of Person #2
    client.subscribe("owntracks/jfcyrvev/steve/event"); //event MQTT topic of Person #3
    client.subscribe("owntracks/jfcyrvev/erin/event"); //event MQTT topic of Person #4
}

Serial.begin(115200);

}

void loop()
{ 
  
    client.loop();
}

