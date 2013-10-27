/* 
 * File:   ByteClass.cpp
 * Author: user
 * 
 * Created on 2013. október 26., 21:02
 */

#include <stdlib.h>
#include "HexClass.h"

HexClass::~HexClass() {
}

ostream& operator << (ostream& o, const HexClass& b)
{
  o << b.Value;
  return o;
}

istream& operator >> (istream& i, HexClass b)
{ char c; long result = 0; 
  i >> c;
  for (int i = 0; i < b.FieldWidth; i++)
  {
    if (isxdigit(c))
    {
//      b.SetValue(c - '0');
      result += (strtol(c,NULL,16) * pow(16, b.FieldWidth - i));
    } else
    {
      throw(CONVERSION_ERROR);
    }
  };  
  return i;
}

