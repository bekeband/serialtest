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

istream& operator >> (istream& i, const PICProgramLine& p)
{
  char startchar;
  HexClass bytecount(0, 2), linetype(0, 2);
  HexClass address(0, 4);
  
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
    cout << bytecount << endl;
    i >> address;
    i >> linetype; 
  }catch (exception e)
  {
      cout << "Exception raising. Type = " << e.what() << endl;
      return i;
  }
  p.SetByteCount(10); // ByteCount = (bytecount.GetValue());
  p.Address = address.GetValue();
  p.LineType = (enum PICProgramLine::e_DataType)linetype.GetValue();
  
  vector<unsigned char>::iterator it;
  for (int ptr = 0; ptr < p.ByteCount; ptr++)
  {
    p.DataLine.insert(p.DataLine.end(), '4');
  }
  return i;
}

ostream& operator << (ostream& o, const PICProgramLine& p)
{
#if defined (DEBUG)
    cout << "ByteCount = ";
#endif
  o << p.ByteCount;
  #if defined (DEBUG)
    cout << "Address = ";
#endif
  o << p.Address;
  #if defined (DEBUG)
    cout << "LineType = ";
#endif
  o << p.LineType;
  vector<unsigned char>::iterator it;
  for (p.DataLine.begin() ; it != p.DataLine.end(); ++it)
  {
    o << *it;  
  }
  return o;
}