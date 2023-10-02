2
 
// Include library
#include "SevSeg.h"
 
// Create object
SevSeg sevseg;
 
// Number of digits in display
byte numDigits = 4;
// Display select pins
byte digitPins[] = {10, 11, 12, 13};
// Display segment pins A,B,C,D,E,F,G,DP
byte segmentPins[] = {9, 2, 3, 5, 6, 8, 7, 4};
// Dropping resistors used
bool resistorsOnSegments = true;
// Display type
byte hardwareConfig = COMMON_CATHODE;
 
// void setup() {
 
//   // Start display object
//   
//   rand
// }
 
// void loop() {
//   int num = r;
//   // Set the number to display
//   
//   // Refresh the display
//   
// }
void setup() {
  // Initialize serial communication
  Serial.begin(9600);
  sevseg.begin(hardwareConfig, numDigits, digitPins, segmentPins, resistorsOnSegments);
//   // Set brightness
//   sevseg.setBrightness(90);

  // Seed the random number generator with analogRead
  randomSeed(analogRead(0));
}
void loop(){
  Serial.println("\nEnter your name:");
   while (!Serial.available()) {
    // Do nothing while waiting for input
  }
  Serial.readString();
  Serial.println("Enter your crush name:");
  while (!Serial.available()) {
    // Do nothing while waiting for input
  }
  Serial.readString();
  
  int a = random(100);
  Serial.println(a);
  test(a);
}


void test(int num) {
  // Generate a random number between 0 and 10
  int randomNumber = num;

  // // Print the random number to the Serial Monitor
  // Serial.print("Random Number: ");
  // Serial.println(randomNumber);
  while(!Serial.available()) {
  sevseg.setNumber(num);
  // Wait for a short delay before generating the next random numbe
  sevseg.refreshDisplay();
}
Serial.readString();
}