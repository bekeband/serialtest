/* 
 * File:   PICProgramLine.cpp
 * Author: user
 * 
 * Created on 2013. október 24., 8:16
 */

#include <iomanip>
#include "PICProgramLine.h"
#include "HexClass.h"

PICProgramLine::PICProgramLine() {
}

PICProgramLine::PICProgramLine(const PICProgramLine& orig) {
}

PICProgramLine::~PICProgramLine() {
}

istream& operator >> (istream& i, PICProgramLine& p)
{
  char startchar;
  HexClass bytecount(0, 2), linetype(0, 2);
  HexClass address(0, 4);
  HexClass nextbyte(0, 2);
  
  /* read, and test the sterta character ... */
  i >> startchar;
  if (startchar == START_CHARACTER)
  {
      
  } else
  {
      throw(E_NO_START_CHARACTER);
  };
  try
  {
    i >> bytecount;
    i >> address;
    i >> linetype; 
    p.ByteCount = bytecount.Value;
    p.Address = address.Value;
  p.LineType = (enum PICProgramLine::e_DataType)linetype.Value;
  
//  vector<unsigned char>::iterator it;
  for (int ptr = 0; ptr < p.ByteCount; ptr++)
  {
    i >> nextbyte;
    p.DataLine.insert(p.DataLine.end(), nextbyte.Value);
  }
  }catch (exception e)
  {
    cout << "Exception raising. Type = " << e.what() << endl;
    return i;
  }catch (...)
  {
    cout << "Exception raising. Type = " << endl;
    return i;
  }
  return i;
}

ostream& operator << (ostream& o, PICProgramLine& p)
{
#if defined (DEBUG)
    cout << " ByteCount = ";
#endif
  o << p.ByteCount;
  #if defined (DEBUG)
    cout << " Address = ";
#endif
  o << p.Address;
#if defined (DEBUG)
    cout << " LineType = ";
#endif
  o << p.LineType;
  
#if defined (DEBUG)
    cout << " p.DataLine.size() = " << p.DataLine.size() << endl;
  
    for (int i = 0; i < p.DataLine.size(); i++)
    {
      cout << hex << "p.DataLine.at(i) = " << (int)p.DataLine.at(i) << endl;
    }
#endif
  
/*  vector<unsigned char>::iterator it;
  for (p.DataLine.begin() ; it != p.DataLine.end(); ++it)
  {
    o << *it;  
  }*/
  return o;
}