/*
 * Author: Drew Applegath 
 * Course: EE4723 - Network Security
 * Updated: 04/17/2018
 * 
 * About: 
 *  This is the receiver unit for the secure data control
 *  of a motor. Key must be received for authentication. 
 */
 
#include <Wire.h>
#include "RC4.h"

String __KEY__ = "DKOELFJDOI@*(#23";  
char buf [256]; // stores input from the i2c connection
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

void clearBuf() {
  int i = 0; 
  for (i=0; i<256; i++) {
    buf[i] = 0; 
  }
}

int checkIfValid(String buf) {
  int i = 0; 
  String ret = ""; 
  for(i=0; i<__KEY__.length(); i++) {
    if (buf[i] != __KEY__[i]) {
      return 0; 
    }
  }
  return 1; 
}

String stripKey(String buf){
  int i, j =0; 
  char ret[256]; 
  for(i=__KEY__.length(); i<buf.length(); i++) {
    ret[j] = buf[i]; 
    j++;
  }
  return ret; 
}

/*
 * 
 */
void receiveEvent(int howMany) {
  int i = 0;
  clearBuf(); 
  while (0 < Wire.available()) {
    char c = Wire.read();
    buf[i++] = c; 
    //Serial.print(c);
  }
  Serial.println(""); 
  if(checkIfValid(decryptString(buf))){
    //buf = stripKey(decryptString(buf)); 
     Serial.println(decryptString(buf)); 
  } else {
    Serial.println("Invalid"); 
  }
  
  //Serial.println(decryptString(buf)); 
}

/*
 * Declare the I2C connection as device id 8 and 
 * setup the function to read and store the event 
 * data in a character array. 
 * 
 * Begin the serial monitor at a baudrate of 9600. 
 */
void setup() {
  Wire.begin(8);                
  Wire.onReceive(receiveEvent);
  Serial.begin(9600);
}

/*
 * Do nohing while waiting for an interrupt from the 
 * I2C recieve event function. 
 */
void loop() {
  delay(100);
}


