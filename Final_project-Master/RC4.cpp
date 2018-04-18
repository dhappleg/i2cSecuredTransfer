//****************************************
//*       Omni_Crypt Version 1.0         *
//*            RC4 Cipher                *
//*      Author: Matthew (last_name)     *
//*           Date: 7/29/2013            *
//****************************************
// syntax for encrypt & decrypt
// obj.omni_crypt("Plaintext","Key");
//
// obj.omni_crypt(String,String); return type is string
//
//*****************************************
// this lib is a cut and dry RC4 cipher
//*****************************************

#include "Arduino.h"
#include "RC4.h"

/*
// be a doll and uncomment this to check speed
int freeRam() 
{
  extern int __heap_start, *__brkval; 
  int v; 
  return (int) &v - (__brkval == 0 ? (int) &__heap_start : (int) __brkval); 
}
*/


String RC4::omni_crypt(String text, String key)
{
  text.trim(); //de-craperator
  key.trim(); //de-craperator
  byte S[256]; //table

  for(int i = 0; i < 256; i++)
    S[i] = i; //populate 255 byte table

  //(KSA) key-scheduling algorithm
  byte j = 0;
  for(int i = 0; i < 256; i++) 
  {
    j = (j + S[i] + key[i%(key.length())])%256;
    byte temp = S[i]; //start of swap chunk
    S[i] = S[j];
    S[j] = temp; //end of swap chunk
  }

  //(PNRG) pseudo-random generator algorithm
  byte i = 0; 
  j = 0;
  byte K = 0;
  String throw_it;
  for(int z = 0; z < text.length(); z++)
  {
    i = (i+1)%256;
    j = (j + S[i])%256;
    byte temp = S[i]; //start of swap chunk
    S[i] = S[j];
    S[j] = temp; //end of swap chunk
    K = S[(S[i] + S[j])%256];
    throw_it += (char)(text[z] ^ K);
  }
  //Serial.println(freeRam()); // uncomment this to for mem test
  return throw_it;
}