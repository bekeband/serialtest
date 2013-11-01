/* 
 * File:   PICProgramLine.cpp
 * Author: user
 * 
 * Created on 2013. október 24., 8:16
 */

#include <iomanip>
#include "PICProgramLine.h"
#include "HexClass.h"

PICProgramLine::PICProgramLine() : ByteCount(0), Address(0), CrcByte(0), LineType(0) {
  /* Clearing, and emptying DataLine for next data reading. */
  DataLine.clear();
//   ByteCount = Address = CrcByte = 0;
}

PICProgramLine::PICProgramLine(const PICProgramLine& orig) {
}

PICProgramLine::~PICProgramLine() {
}

istream& operator >> (istream& i, PICProgramLine& p)
{
  char startchar;
  HexClass<BYTE> nextbyte;
/*  HexClass<short int> address;*/
  
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
    p.ByteCount.GetHex(i);
    p.Address.GetHex(i);
    p.LineType.GetHex(i);
    
  for (int ptr = 0; ptr < p.ByteCount.GetValue(); ptr++)
  {
    nextbyte.GetHex(i);
    p.DataLine.insert(p.DataLine.end(), nextbyte.GetValue());
  }
  
  /* At the end we read the crc byte. */
    p.CrcByte.GetHex(i);
  
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
  p.ByteCount.PrintHex(cerr);
#endif
  p.ByteCount.PrintBin(o);
#if defined (DEBUG)
  cerr << " Address = ";
  p.Address.PrintHex(cerr);
#endif
  p.Address.PrintBin(o);
#if defined (DEBUG)
  cerr << " LineType = ";
  p.LineType.PrintHex(cerr);
#endif
  p.LineType.PrintBin(o);

/* HecClass class type iterator for line vector. */
vector< HexClass<BYTE> >::iterator it;
  
#if defined (DEBUG)
int numb = 0;
  cerr << " p.DataLine.size() = " << hex << (int)p.DataLine.size() << endl;
  
  for (it = p.DataLine.begin(); it != p.DataLine.end(); ++it)
  {   
    cerr << hex << "p.DataLine.at(" << setw(2) << setfill('0') << dec << numb++ <<  ") = ";
    it->PrintHex(cerr); cerr << endl;
  } 
#endif
  for (it = p.DataLine.begin(); it != p.DataLine.end(); ++it)
  {
    it->PrintBin(o);
  }
  
#if defined (DEBUG) 
  cerr << " CrcByte = ";
  p.CrcByte.PrintHex(cerr);
  cerr << endl;
#endif  
  p.CrcByte.PrintBin(o);
  return o;
}