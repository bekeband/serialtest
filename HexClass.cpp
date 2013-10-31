/* 
 * File:   ByteClass.cpp
 * Author: user
 * 
 * Created on 2013. október 26., 21:02
 */

#include <stdlib.h>
#include <sstream>
#include "HexClass.h"

#if defined (KELL_E)

template ostream& HexClass::PrintHex(ostream& o) 
{ unsigned char* chr = (unsigned char*)&Value;
  for (int i = 0; i < sizeof(Value); i++)
  { 
    o << hex << setw(2) << std::setfill('0') << (int)*chr++;
  }
  return o; 
};


istream& HexClass<typename>::operator >>(istream& i, HexClass& h)
{
 char* buffer;
long bValue;
int FieldWidth = sizeof(Value) ;
i.exceptions(ios::failbit | ios::badbit);
try {
  
//  buffer = new char[sizeof(Data) + 1]; /* malloc a buffer to the input datas. */
  
  i.read(buffer, FieldWidth); /* read Fieldwidth bytes from input stream. */
  string in(buffer, FieldWidth);
#ifdef DEBUG
  cerr << "String = " << in << endl;
#endif
  stringstream si(in);
  si >> hex >> bValue;
//  b.SetValue(bValue);
#ifdef DEBUG
  cerr << "Input Value = " << Value << endl;
#endif
  /* TODO I don't no what kind of exception generated if input not abuse of 
   * propriertary recommends! */
}catch (exception e)
{ 
#ifdef DEBUG
  cerr << "HexClass operator >> exception e = " << e.what() << endl;
#endif
}

delete buffer;

return i;
}

istream& operator >> (istream& i, HexClass& b)
{ 
    
char* buffer;
long bValue;

i.exceptions(ios::failbit | ios::badbit);
try {
  
  buffer = new char[b.FieldWidth + 1]; /* malloc a buffer to the input datas. */
  
  i.read(buffer, b.FieldWidth); /* read Fieldwidth bytes from input stream. */
  string in(buffer, b.FieldWidth);
#ifdef DEBUG
  cerr << "String = " << in << endl;
#endif
  stringstream si(in);
  si >> hex >> b.Value;
#ifdef DEBUG
  cerr << "Input Value = " << b.Value << endl;
#endif
  /* TODO I don't no what kind of exception generated if input not abuse of 
   * propriertary recommends! */
}catch (exception e)
{ 
#ifdef DEBUG
  cerr << "HexClass operator >> exception e = " << e.what() << endl;
#endif
}

delete buffer;

return i;
}

#endif