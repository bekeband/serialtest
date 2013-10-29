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
  /* Clearing, and emptying DataLine for next data reading. */
   DataLine.clear();
   ByteCount = Address = CrcByte = 0;
}

PICProgramLine::PICProgramLine(const PICProgramLine& orig) {
}

PICProgramLine::~PICProgramLine() {
}

istream& operator >> (istream& i, PICProgramLine& p)
{
  char startchar;
  HexClass bytecount(0, 2), linetype(0, 2), crc(0, 2);
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
    i >> bytecount >> address >> linetype;
  p.ByteCount = bytecount.Value;
  p.Address = address.Value;
  p.LineType = (enum PICProgramLine::e_DataType)linetype.Value;
  
  for (int ptr = 0; ptr < p.ByteCount; ptr++)
  {
    i >> nextbyte;
    p.DataLine.insert(p.DataLine.end(), nextbyte.Value);
  }
  
  /* At the end we read the crc byte. */
  i >> crc;
  p.CrcByte = crc.Value;
  
  }catch (exception e)
  {
    cout << "Exception raising. Type = " << e.what() << endl;
    return i;
  }catch (...)
  {
    cout << "Unhandled exception raising." << endl;
    return i;
  }
  return i;
}

ostream& operator << (ostream& o, PICProgramLine& p)
{
#if defined (DEBUG)
    cerr << " ByteCount = ";
#endif
  o << p.ByteCount;
#if defined (DEBUG)
    cerr << " Address = ";
#endif
  o << p.Address;
#if defined (DEBUG)
    cerr << " LineType = ";
#endif
  o << p.LineType;

vector<unsigned char>::iterator it;
  
#if defined (DEBUG)
int numb = 0;
  cerr << " p.DataLine.size() = " << hex << (int)p.DataLine.size() << endl;
  
  for (it = p.DataLine.begin(); it != p.DataLine.end(); ++it)
  {   
    cerr << hex << "p.DataLine.at(" << setw(2) << setfill('0') << dec << 
      numb++ <<  ") = " << hex << setw(2) << setfill('0') << (int)(*it) << endl;
  } 
#endif


  for (it = p.DataLine.begin(); it != p.DataLine.end(); ++it)
  {
    o << (*it);  
  }
  
#if defined (DEBUG) 
  cerr << " CrcByte = " << hex << (int)p.CrcByte << endl;
#endif  
  o << hex << p.CrcByte;
  
  return o;
}