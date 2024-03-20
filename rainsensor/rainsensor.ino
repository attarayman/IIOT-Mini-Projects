// #include <ESP8266WiFi.h>

// const char* ssid = "Examination";
// const char* password = "mitwpu0323";

// void setup(){
//  Serial.begin(9600);
//  pinMode(2, INPUT);
// }
// void loop(){
//  //analog output
//  if(analogRead(0)<300) Serial.println("Heavy Rain");
//  else if(analogRead(0)<500) Serial.println("Moderate Rain");
//  else Serial.println("No Rain");

// // //digital output
// // if(digitalRead(2) == HIGH) Serial.println("No Rain
// // Detected");
// // else Serial.println("Rain Detected");

//  delay(250);
// }



#include <ESP8266WiFi.h>
#include <ThingSpeak.h>  // Include the ThingSpeak library

const char* ssid = "Examination";
const char* password = "mitwpu0323";
const unsigned long channelID = 2251463;  // Replace with your ThingSpeak channel ID
const char* writeAPIKey = "CX8RKYAAO4JN4T7V";   // Replace with your ThingSpeak write API key

const int rainSensorPin = A0;  // Analog pin connected to the resistive rain sensor
bool rainStat = false;

WiFiClient client;

void setup() {
  Serial.begin(9600);
  pinMode(rainSensorPin, INPUT);
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.println("Connecting to WiFi...");
  }
  Serial.println("Connected to WiFi");
  ThingSpeak.begin(client);  // Initialize ThingSpeak library
}

void loop() {
  int rainValue = analogRead(rainSensorPin);
  
  if (rainValue < 500) {
    Serial.println("Rain detected!");
    rainStat = true;
    Serial.println(rainValue);
    // Send data to ThingSpeak
    ThingSpeak.writeField(channelID, 1, rainValue, writeAPIKey);
  } else {
    Serial.println("No rain detected.");
    Serial.println(rainValue);
    rainStat = false;
  }
  
  delay(1000);
}
