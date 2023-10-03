#define BLYNK_PRINT Serial
#define BLYNK_TEMPLATE_ID "TMPL3C9Oz7lg4"
#define BLYNK_TEMPLATE_NAME "SMART SREET LIGHT"
#include <Arduino.h>
#include <WiFi.h>
#include <BlynkSimpleEsp32.h>
#include "ThingSpeak.h"

//#include <ESP8266WiFi.h>
//#include <BlynkSimpleEsp8266.h>

char ssid[] = "dev";
char pass[] = "12345678";
char auth[] = "qcu2TZUoduHj5eUA1wbDqTCXssO1Ko6k";
unsigned long myChannelNumber = 2068532;
const char * myWriteAPIKey = "VT5UCR2WX4D9Y2QA";


BlynkTimer timer;
WiFiClient client;

int V1State = 0;
int V2State = 0;
int V3State = 0;
int sliderValue = 0;
int newValue=0;

// ThingSpeak settings
const char* apiKey = "VT5UCR2WX4D9Y2QA";
const unsigned long postingInterval = 15 * 1000;  // Posting interval in milliseconds (15 seconds)

#define pwmPin 2
#define relay 4

void setup() {
  // Debug console
  Serial.begin(9600);
  ThingSpeak.begin(client);
  Blynk.begin(auth, ssid, pass);

  Blynk.virtualWrite(V2, 0, V3, 0, V4, 0);  // Initially, turn off virtual pins V2, V3, V4
  pinMode(relay, OUTPUT);
}




void loop() {
  Blynk.run();
  timer.run();
  if (V1State == 0) {
    Blynk.virtualWrite(V2, 0, V3, 0, V4, 0);
    Serial.println("Switch is off");
  }
  else
  {
    Serial.println("The System in On");
  }
  // Create a ThingSpeak write channel update
 
  
  if (V1State == 1 && V2State == 1 && V3State == 0) {
    //ThingSpeak.setField(1, value);
    int x = ThingSpeak.writeField(myChannelNumber,1,1, myWriteAPIKey);
    analogWrite(pwmPin, newValue);
    Serial.println("Mannual Mode");
    sliderValue = newValue;

    Serial.print("Slider Value : ");
    Serial.println(sliderValue);
    int z = ThingSpeak.writeField(myChannelNumber,3,sliderValue, myWriteAPIKey);
  }
  else
  {
    analogWrite(pwmPin,0);
  }
  if (V2State == 0 && V3State == 1 && V1State==1) {
    Blynk.virtualWrite(V2, 0, V4, 0);
    Serial.println("Automatic Mode");
   int y = ThingSpeak.writeField(myChannelNumber,2,1, myWriteAPIKey);
    digitalWrite(relay,1);
  } 
  else 
  {
    digitalWrite(relay, 0);
  }
}

BLYNK_WRITE(V1) {
  V1State = param.asInt();
  // Serial.print("V1State");
  // Serial.println(V1State);
  // if (V1State == 0) {
  //   Blynk.virtualWrite(V2, 0, V3, 0, V4, 0);
  //   Serial.println("Switch is on");
  // }
  // else
  // {
  //   Serial.println("The System in OFF");
  // }
   
}

BLYNK_WRITE(V2) {
  V2State = param.asInt();
  // Serial.print("V2State");
  // Serial.println(V2State);
  // if (V2State == HIGH && V3 == HIGH) {
  //   Blynk.virtualWrite(V3, 0);
  // } 
  // else {
  //   analogWrite(pwmPin, 0);
  // }
}

BLYNK_WRITE(V4) {
  newValue = param.asInt();
  // if (V1State == 1 && V2State == 1 && V3 == 0) {
  //   analogWrite(pwmPin, newValue);
  //   Serial.println("Mannual Mode");
  //   sliderValue = newValue;
  //   Serial.print("Slider Value : ");
  //   Serial.println(sliderValue);
  // }
}

BLYNK_WRITE(V3) {
  V3State = param.asInt();
  // Serial.print("V3State");
  // Serial.println(V3State);
  // if (V2State == 0 && V3State == 1 && V1State==1) {
  //   Blynk.virtualWrite(V2, 0, V4, 0);
  //   Serial.println("Automatic Mode");
  //   digitalWrite(relay, 1);
  // } else {
  //   digitalWrite(relay, 0);
  // }
}
