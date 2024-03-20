
#include <SPI.h>
#include <MFRC522.h>
#include "SoftwareSerial.h"
#define SS_PIN D4
#define RST_PIN D3
#define BUZZ D1
MFRC522 mfrc522(SS_PIN, RST_PIN);   // Create MFRC522 instance.
SoftwareSerial ser(2,3); // RX, TX 
void setup() 
{
  Serial.begin(9600);   // Initiate a serial communication
  ser.begin (115200);
  SPI.begin();      // Initiate  SPI bus
  mfrc522.PCD_Init();   // Initiate MFRC522
  Serial.println("Put RFID Card to Scan...");
  Serial.println();
 
}
void loop() 
{
  // Look for new cards
  if ( ! mfrc522.PICC_IsNewCardPresent()) 
  {
    return;
  }
  // Select one of the cards
  if ( ! mfrc522.PICC_ReadCardSerial()) 
  {
    return;
  }
  //Show UID on serial monitor
  
  String content= "";
  byte letter;
  for (byte i = 0; i < mfrc522.uid.size; i++) 
  {
     
     content.concat(String(mfrc522.uid.uidByte[i] < 0x10 ? " 0" : " "));
     content.concat(String(mfrc522.uid.uidByte[i], HEX));
  }
  Serial.println();
  Serial.print("User No./Name:    ");
  content.toUpperCase();
  if (content.substring(1) == "13 2B D6 1A" ) //change here the UID of the card/cards that you want to give access
  {
    Serial.println("1- AYMAN");
    ser.write(1);
    Serial.println();
    ringBuzzer();
    
    delay(3000);
  }
   if (content.substring(1) ==  "07 8A CD D7" ) //change here the UID of the card/cards that you want to give access
  {
    Serial.println("2- VARAD");
    ser.write(2);
    Serial.println();
    ringBuzzer();
    
    delay(3000);
  }
   if (content.substring(1) == "43 91 3D 16" ) //change here the UID of the card/cards that you want to give access
  {
    Serial.println("3-ISHIKA");
    ser.write(3);
    Serial.println();
    ringBuzzer();
    
    delay(3000);
  }
   if (content.substring(1) == "C3 65 4A 16" ) //change here the UID of the card/cards that you want to give access
  {
    Serial.println("4- RUCHESH");
    ser.write(4);
    Serial.println();
    ringBuzzer();
    
    delay(3000);
  }
}

void ringBuzzer(){
  digitalWrite(BUZZ, HIGH);
  delay(200);
  digitalWrite(BUZZ,LOW);
}



































// #include <SPI.h>
// #include <MFRC522.h>

// #define SS_PIN D4
// #define RST_PIN D3
// #define BUZZ D1
 
// MFRC522 rfid(SS_PIN, RST_PIN); // Instance of the class

// MFRC522::MIFARE_Key key; 

// // Init array that will store new NUID 
// byte nuidPICC[4];

// void setup() { 
//   Serial.begin(9600);
//   pinMode(BUZZ, OUTPUT);
//   SPI.begin(); // Init SPI bus
//   rfid.PCD_Init(); // Init MFRC522 

//   for (byte i = 0; i < 6; i++) {
//     key.keyByte[i] = 0xFF;
//   }

//   Serial.println(F("This code scan the MIFARE Classsic NUID."));
//   Serial.print(F("Using the following key:"));
//   printHex(key.keyByte, MFRC522::MF_KEY_SIZE);
// }
 
// void loop() {

//   // Reset the loop if no new card present on the sensor/reader. This saves the entire process when idle.
//   if ( ! rfid.PICC_IsNewCardPresent())
//     return;

//   // Verify if the NUID has been readed
//   if ( ! rfid.PICC_ReadCardSerial())
//     return;

//   Serial.print(F("PICC type: "));
//   MFRC522::PICC_Type piccType = rfid.PICC_GetType(rfid.uid.sak);
//   Serial.println(rfid.PICC_GetTypeName(piccType));

//   // Check is the PICC of Classic MIFARE type
//   if (piccType != MFRC522::PICC_TYPE_MIFARE_MINI && 
//     piccType != MFRC522::PICC_TYPE_MIFARE_1K &&
//     piccType != MFRC522::PICC_TYPE_MIFARE_4K) {
//     Serial.println(F("Your tag is not of type MIFARE Classic."));
//     return;
//   }

//   if (rfid.uid.uidByte[0] != nuidPICC[0] || 
//       rfid.uid.uidByte[1] != nuidPICC[1] || 
//       rfid.uid.uidByte[2] != nuidPICC[2] || 
//       rfid.uid.uidByte[3] != nuidPICC[3] ) 
//     {
//       Serial.println(F("A new card has been detected."));
//       ringBuzzer();

//       // Store NUID into nuidPICC array
//       for (byte i = 0; i < 4; i++) {
//         nuidPICC[i] = rfid.uid.uidByte[i];
//       }
    
//       Serial.println(F("The NUID tag is:"));
//       Serial.print(F("In hex: "));
//       printHex(rfid.uid.uidByte, rfid.uid.size);
//       Serial.println();
//       Serial.print(F("In dec: "));
//       printDec(rfid.uid.uidByte, rfid.uid.size);
//       Serial.println();
//   }
//   else {
//     Serial.println(F("Card read previously."));
//     ringBuzzer();
//   }


//   // Halt PICC
//   rfid.PICC_HaltA();

//   // Stop encryption on PCD
//   rfid.PCD_StopCrypto1();
// }


// /**
//  * Helper routine to dump a byte array as hex values to Serial. 
//  */
// void printHex(byte *buffer, byte bufferSize) {
//   for (byte i = 0; i < bufferSize; i++) {
//     Serial.print(buffer[i] < 0x10 ? " 0" : " ");
//     Serial.print(buffer[i], HEX);
//   }
// }

// /**
//  * Helper routine to dump a byte array as dec values to Serial.
//  */
// void printDec(byte *buffer, byte bufferSize) {
//   for (byte i = 0; i < bufferSize; i++) {
//     Serial.print(buffer[i] < 0x10 ? " 0" : " ");
//     Serial.print(buffer[i], DEC);
//   }
// }


// void ringBuzzer(){
//   digitalWrite(BUZZ, HIGH);
//   delay(200);
//   digitalWrite(BUZZ,LOW);
// }
