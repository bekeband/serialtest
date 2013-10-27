/* 
 * File:   PICProgramLine.cpp
 * Author: user
 * 
 * Created on 2013. október 24., 8:16
 */

#include <iomanip>
#include "PICProgramLine.h"

PICProgramLine::PICProgramLine() {
}

PICProgramLine::PICProgramLine(const PICProgramLine& orig) {
}

PICProgramLine::~PICProgramLine() {
}

istream& operator >> (istream& i, PICProgramLine p)
{
  unsigned char startchar, bytecount, linetype;
  unsigned int address;
  
  i >> startchar;
  if (startchar == START_CHARACTER)
  {
      
  } else
  {
      throw(E_NO_START_CHARACTER);
  };
  try
  {
    i >> hex;
    i.width(2);
    i >> bytecount;
    i.width(4);
    i >> address;
    i.width(2);
    i >> linetype; 
  }catch (exception e)
  {
      cout << "Exception raising. Type = " << e.what() << endl;
      return i;
  }
  p.ByteCount = bytecount;
  p.Address = address;
  p.LineType = (enum PICProgramLine::e_DataType)linetype;
  vector<unsigned char>::iterator it;
  for (int ptr = 0; ptr < p.ByteCount; ptr++)
  {
    p.DataLine.insert(p.DataLine.end(), '4');
  }
  
/*  p.DataBuffer = new unsigned char[p.ByteCount];
  
  if (p.DataBuffer != NULL)
  {
    for (int i = 0; i < p.ByteCount; i++)
    {
      i >> p.DataBuffer[i];
    }
  }*/
  return i;
}

ostream& operator << (ostream& o, const PICProgramLine& p)
{
  o << p.ByteCount;
  o << p.Address;
  o << p.LineType;
  vector<unsigned char>::iterator it;
  for (p.DataLine.begin() ; it != p.DataLine.end(); ++it)
  {
    o << *it;  
  }
  return o;
}