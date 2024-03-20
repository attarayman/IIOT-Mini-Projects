#include <Arduino.h>
// #include <WiFi.h>
// #include <ThingSpeak.h>

// // WiFi credentials
// const char* ssid = "KAWAKI@007";
// const char* password = "kawaki@007";

// // ThingSpeak credentials
// const char* thingSpeakAPIKey = "PGPD8RJFCA1X9NIR";
// const unsigned long channelID = 2262667;

// // PIR sensor configuration
// // Define the PIR sensor pin
// const int pirSensorPin = 14;  // Connect PIR sensor to ESP32 GPIO 14 (D14)
// // const int pirSensorPin = 14;  // Connect PIR sensor to ESP32 GPIO 14 (D14)
// // bool motionDetected = false;
// int pirValue;

// int motionValue;

// void connectToWiFi();
// void uploadToThingSpeak();

// // void setup() {
// //   Serial.begin(115200);

// //   connectToWiFi();
// // }

// // void loop() {
// //   // Check for motion
// //   motionDetected = digitalRead(pirSensorPin);

// //   // If motion is detected, upload data to ThingSpeak
// //   if (motionDetected) {
// //     uploadToThingSpeak();
// //     Serial.println("Motion .....");
// //     Serial.println("motionDetected");
// //     Serial.println(motionDetected);
// //     Serial.println("motionValue");
// //     Serial.println(motionValue);
    
// //   }
// //   else{
// //     uploadToThingSpeak();
// //     Serial.println("No Motion ....");
// //     Serial.println("motionDetected");
// //     Serial.println(motionDetected);
// //     Serial.println("motionValue");
// //     Serial.println(motionValue);
// //   }

// //   // Wait for a moment before checking again
// //   delay(1000); // Adjust the delay as needed
// // }











// void setup() {
//   Serial.begin(115200);
//   pinMode(pirSensorPin, INPUT);
//   connectToWiFi();
// }

// void loop() {
//   // Read the PIR sensor
//   pirValue = digitalRead(pirSensorPin);

//   if (pirValue == HIGH) {
//     Serial.println("Motion detected!");
//     uploadToThingSpeak();
//     Serial.println("motionDetected");
//     Serial.println(pirValue);
//     Serial.println("motionValue");
//     Serial.println(motionValue);
//     // You can add additional actions here when motion is detected
//   } else {
//     Serial.println("No motion detected.");
//     uploadToThingSpeak();
//     Serial.println("motionDetected");
//     Serial.println(pirValue);
//     Serial.println("motionValue");
//     Serial.println(motionValue);

//     // You can add additional actions here when no motion is detected
//   }

//   delay(1000); // Adjust the delay as needed
// }


// void connectToWiFi() {
//   Serial.print("Connecting to ");
//   Serial.println(ssid);

//   WiFi.begin(ssid, password);

//   while (WiFi.status() != WL_CONNECTED) {
//     delay(250);
//     Serial.print(".");
//   }

//   Serial.println("");
//   Serial.println("WiFi connected");
//   Serial.println("IP address: ");
//   Serial.println(WiFi.localIP());
// }


// void uploadToThingSpeak() {
//   // Initialize ThingSpeak
//   WiFiClient client;
//   ThingSpeak.begin(client);

//   // Prepare data to send to ThingSpeak
//   motionValue = pirValue ;

//   // Send data to ThingSpeak
//   ThingSpeak.setField(1, motionValue);

//   // int statusCode = ThingSpeak.writeFields(channelID, thingSpeakAPIKey);

//   // if (statusCode == 200) {
//   //   Serial.println("Data sent to ThingSpeak successfully.");
//   // } else {
//   //   Serial.println("Failed to send data to ThingSpeak. Status code: " + String(statusCode));
//   // }
// }


const int pirPin = 14; // PIR sensor input pin

void setup() {
  Serial.begin(115200);
  pinMode(pirPin, INPUT);
}

void loop() {
  int pirState = digitalRead(pirPin);

  if (pirState == HIGH) {
    Serial.println("Motion Detected!");
  } else {
    Serial.println("No Motion");
  }

  delay(1000); // Adjust the delay time as needed
}