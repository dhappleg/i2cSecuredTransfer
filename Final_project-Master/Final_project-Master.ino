/*
 * Author: Drew Applegath
 * Course: EE4723 - Network Security
 * Updated: 04/17/2018
 * 
 * About: 
 *  This is the sender unit for an I2C secure communication protocol 
 *  using RC4 encryption. 
 */
 
#include <Wire.h>
#include "RC4.h"

String __KEY__ = "DKOELFJDOI@*(#23"; 
String ret = ""; 
RC4 crypt; 

/*
 * Decrypt the data passed to this function with the 
 * key value declared by the "__KEY__" string variable. 
 */
String decryptString(String buf) {
  return crypt.omni_crypt(buf, __KEY__); 
}

/*
 * Encrypt the data passed to this function with the 
 * key value delcared by the "__KEY__" string variable. 
 */
String encryptString(String buf) {
  return crypt.omni_crypt(buf, __KEY__); 
}

void sendValid(String buf) {
  String ret = encryptString(buf); 
  Serial.println("Sending valid data"); 
  Serial.println(buf); 
  writeData(ret); 
}

void sendInvalid(String buf) {
  //String ret = encryptString(buf); 
  Serial.println("Sending invalid data"); 
  Serial.println(buf); 
  writeData(buf); 
}

/*
 * Used to write strings to the i2c bus slave device. 
 */
int writeData(String buf) {
  Wire.beginTransmission(8); 
  Wire.write(buf.c_str()); 
  Wire.endTransmission(); 
  return 1; 
}

/*
 * Initializes the serial baudrate to 9600 and declares and I2C connection. 
 */
void setup() {
  Serial.begin(9600); 
  Wire.begin(); // join i2c bus (address optional for master)
}

/*
 * Encrypt the string and send it to the slave device address 8. 
 */
void loop() {
  //ret = encryptString("Test String"); 
  //Serial.println(ret); 
  //writeData(encryptString("Test String"));
  sendValid(__KEY__ + "Valid Data"); 
  delay(500);
  sendInvalid("Invalid Data"); 
  delay(500); 
}
