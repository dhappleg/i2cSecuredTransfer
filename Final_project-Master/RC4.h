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

#ifndef RC4_h
#define RC4_h

#define RC4_VERSION "Omni_Crypt 2.0"

#include "Arduino.h"

class RC4
{
public:
  String omni_crypt(String, String);
};

/*
// be a doll and uncomment this to check speed
int freeRam();
*/

#endif