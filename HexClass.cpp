/* 
 * File:   ByteClass.cpp
 * Author: user
 * 
 * Created on 2013. október 26., 21:02
 */

#include <stdlib.h>
#include <sstream>
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
char* buffer;

i.exceptions(ios::failbit | ios::badbit);
try {
  /* malloc a buffer to the input datas. */
  buffer = new char[b.FieldWidth + 1];
  /* read Fieldwidth bytes from input stream. */
  i.read(buffer, b.FieldWidth); 
  string in(buffer, b.FieldWidth);
  cout << "String = " << in << endl;
  stringstream si(in);

  si >> hex >> b.Value;
  
  cout << "Input Value = " << b.Value << endl;
  
}catch (exception e)
{ 
  cout << "HexClass operator >> exception e = " << e.what() << endl;
}catch (bad_alloc ba)
{
  cout << "Memory allocation error ba = " << ba.what() << endl;    
}


delete buffer;

/*  i >> c;
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
  };  */
  return i;
}

