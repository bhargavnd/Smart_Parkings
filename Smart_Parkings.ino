

//
// Copyright 2015 Google Inc.
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//     http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.
//

// FirebaseDemo_ESP8266 is a sample that demo the different functions
// of the FirebaseArduino API.

#include <ESP8266WiFi.h>
#include <FirebaseArduino.h>
#include <FirebaseHttpClient.h>
#include <Firebase.h>
#include <FirebaseCloudMessaging.h>
#include <FirebaseObject.h>
#include <FirebaseError.h>

// Set these to run example.
#define FIREBASE_HOST "smartparking07.firebaseio.com"
#define FIREBASE_AUTH "pYIo1gvzs7qttUXmq3Gk4guImFBrOW3DiulwsUnh"
#define WIFI_SSID "Srkd"
#define WIFI_PASSWORD "arsenal03"
#define ECHOA 5 
#define TRIGGERA 4
#define ECHOB 0 
#define TRIGGERB 2
#define ECHOC 14 
#define TRIGGERC 12
#define ECHOD 13
#define TRIGGERD 15


void setup() {
  pinMode(ECHOA,INPUT);
  pinMode(TRIGGERA,OUTPUT);
  pinMode(ECHOB,INPUT);
  pinMode(TRIGGERB,OUTPUT);
  pinMode(ECHOC,INPUT);
  pinMode(TRIGGERC,OUTPUT);
  pinMode(ECHOD,INPUT);
  pinMode(TRIGGERD,OUTPUT);
  
  Serial.begin(9600);
  // put your setup code here, to run once:

  // connect to wifi.
  WiFi.begin(WIFI_SSID, WIFI_PASSWORD);
  Serial.print("connecting");
  while (WiFi.status() != WL_CONNECTED) {
    Serial.print(".");
    delay(500);
  }
  Serial.println();
  Serial.print("connected: ");
  Serial.println(WiFi.localIP());
  
  Firebase.begin(FIREBASE_HOST, FIREBASE_AUTH);
}

//int n = 0;

void loop() {
  float durationA,distanceA;
  digitalWrite(TRIGGERA,LOW);
  delayMicroseconds(2);
  digitalWrite(TRIGGERA,HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIGGERA,LOW);
  durationA=pulseIn(ECHOA,HIGH);
  distanceA=((durationA/2)/29.1);
  if(distanceA<=5)
  {Firebase.setString("parkingA", "occupied");}
  else
  {Firebase.setString("parkingA", "unoccupied");}
  Serial.println(distanceA);
  float durationB,distanceB;
  digitalWrite(TRIGGERB,LOW);
  delayMicroseconds(2);
  digitalWrite(TRIGGERB,HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIGGERB,LOW);
  durationB=pulseIn(ECHOB,HIGH);
  distanceB=((durationB/2)/29.1);
  if(distanceB<=5)
  {Firebase.setString("parkingB", "occupied");}
  else
  {Firebase.setString("parkingB", "unoccupied");}
  Serial.println(distanceB);
  float durationC,distanceC;
  digitalWrite(TRIGGERC,LOW);
  delayMicroseconds(2);
  digitalWrite(TRIGGERC,HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIGGERC,LOW);
  durationC=pulseIn(ECHOC,HIGH);
  distanceC=((durationC/2)/29.1);
  if(distanceC<=5)
  {Firebase.setString("parkingC", "occupied");}
  else
  {Firebase.setString("parkingC", "unoccupied");}
  Serial.println(distanceC);
  float durationD,distanceD;
  digitalWrite(TRIGGERD,LOW);
  delayMicroseconds(2);
  digitalWrite(TRIGGERD,HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIGGERD,LOW);
  durationD=pulseIn(ECHOD,HIGH);
  distanceD=((durationD/2)/29.1);
  if(distanceD<=5)
  {Firebase.setString("parkingD", "occupied");}
  else
  {Firebase.setString("parkingD", "unoccupied");}
  Serial.println(distanceD);
  
  // set value
  /*Firebase.setFloat("number",distance );
  // handle error
  if (Firebase.failed()) {
      Serial.print("setting /number failed:");
      Serial.println(Firebase.error());  
      return;
  }*/
  //delay(5000);
  //delay(500);

  // put your main code here, to run repeatedly:









  
  // set value
  /*Firebase.setFloat("number", 42.0);
  // handle error
  if (Firebase.failed()) {
      Serial.print("setting /number failed:");
      Serial.println(Firebase.error());  
      return;
  }
  delay(1000);*/
  
  /*// update value
  Firebase.setFloat("number", 43.0);
  // handle error
  if (Firebase.failed()) {
      Serial.print("setting /number failed:");
      Serial.println(Firebase.error());  
      return;
  }
  delay(1000);*/

  /*// get value 
  Serial.print("number: ");
  Serial.println(Firebase.getFloat("number"));
  delay(1000);

  // remove value
  Firebase.remove("number");
  delay(1000);*/

  // set string value
  /*Firebase.setString("message", "asdfbasf");
  // handle error
  if (Firebase.failed()) {
      Serial.print("setting /message failed:");
      Serial.println(Firebase.error());  
      return;
  }*/
  delay(5000);
  
  /*// set bool value
  Firebase.setBool("truth", false);
  // handle error
  if (Firebase.failed()) {
      Serial.print("setting /truth failed:");
      Serial.println(Firebase.error());  
      return;
  }
  delay(1000);*/

  /*// append a new value to /logs
  String name = Firebase.pushInt("logs", n++);
  // handle error
  if (Firebase.failed()) {
      Serial.print("pushing /logs failed:");
      Serial.println(Firebase.error());  
      return;
  }
  Serial.print("pushed: /logs/");
  Serial.println(name);
  delay(1000);*/
}
