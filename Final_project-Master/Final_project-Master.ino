/*
 * Author: Drew Applegath
 * Course: EE4723 - Network Security
 * Updated: 04/17/2018
 * 
 * About: 
 *  This is the sender unit for 
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

/*
 * 
 */
int writeData(String buf) {
  Wire.beginTransmission(8); 
  Wire.write(buf.c_str()); 
  Wire.endTransmission(); 
  return 1; 
}

/*
 * 
 */
void setup() {
  Serial.begin(9600); 
  Wire.begin(); // join i2c bus (address optional for master)
}

/*
 * 
 */
void loop() {
  ret = encryptString("Test String"); 
  Serial.println(ret); 
  writeData(encryptString("Test String"));
  delay(500);
}