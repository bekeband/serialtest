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

istream& HexClass::operator >>(istream& i)
{
 char* buffer;
long bValue;

i.exceptions(ios::failbit | ios::badbit);
try {
  
  buffer = new char[FieldWidth + 1]; /* malloc a buffer to the input datas. */
  
  i.read(buffer, FieldWidth); /* read Fieldwidth bytes from input stream. */
  string in(buffer, FieldWidth);
#ifdef DEBUG
  cout << "String = " << in << endl;
#endif
  stringstream si(in);
  si >> hex >> bValue;
//  b.SetValue(bValue);
#ifdef DEBUG
  cout << "Input Value = " << Value << endl;
#endif
  /* TODO I don't no what kind of exception generated if input not abuse of 
   * propriertary recommends! */
}catch (exception e)
{ 
#ifdef DEBUG
  cout << "HexClass operator >> exception e = " << e.what() << endl;
#endif
}

delete buffer;

return i;
}

istream& operator >> (istream& i, const HexClass& b)
{ 
    
char* buffer;
long bValue;

i.exceptions(ios::failbit | ios::badbit);
try {
  
  buffer = new char[b.FieldWidth + 1]; /* malloc a buffer to the input datas. */
  
  i.read(buffer, b.FieldWidth); /* read Fieldwidth bytes from input stream. */
  string in(buffer, b.FieldWidth);
#ifdef DEBUG
  cout << "String = " << in << endl;
#endif
  stringstream si(in);
  si >> hex >> bValue;
//  b.SetValue(bValue);
#ifdef DEBUG
  cout << "Input Value = " << b.Value << endl;
#endif
  /* TODO I don't no what kind of exception generated if input not abuse of 
   * propriertary recommends! */
}catch (exception e)
{ 
#ifdef DEBUG
  cout << "HexClass operator >> exception e = " << e.what() << endl;
#endif
}

delete buffer;

return i;
}

