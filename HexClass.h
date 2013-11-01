/* 
 * File:   ByteClass.h
 * Author: user
 *
 * Created on 2013. október 26., 21:02
 */

#ifndef BYTECLASS_H
#define	BYTECLASS_H

#include <iostream>
#include <iomanip>
#include <sstream>

#if defined (LINUX)
#define unsigned char BYTE
#define unsigned short WORD
#define unsigned int DWORD
#else
#include <windows.h>
#endif

#define CONVERSION_ERROR 76

using namespace std;

template <typename TYPE> class HexClass {
public:
  inline HexClass() {Value = 0;};
  inline HexClass(TYPE aValue) {Value = aValue; };
  inline HexClass(const HexClass& orig) {Value = orig.Value; };
  inline virtual ~HexClass() {};
    
  inline void const SetValue(const long aValue) {Value = aValue; };
  inline unsigned char GetValue() {return Value; };
 
  /* Getting hexadecimal text string to parametric output stream. */
  istream& GetHex(istream& istr)
  { 
    long bValue;
    try
    {
      char* buffer = new char[(sizeof(Value) * 2) + 1];
      buffer[(sizeof(Value) * 2)] = '\0';
      istr.read(buffer, sizeof(Value) * 2);
      string str(buffer);
      stringstream ss(str);
      ss >> hex >> bValue;
      Value = bValue;
      delete buffer;
      return istr;    
    } catch (bad_alloc ba)
    {
      
    } catch (exception e)
    {
      
    }
  }
  
  /* Printing hexadecimal text string to parametric output stream. */
  ostream& PrintHex(ostream& o)
  { unsigned char* chr = (unsigned char*)&Value;
    o << hex << setw(sizeof(Value) * 2) << std::setfill('0') << (WORD)Value;
    return o; 
  };

  /* Getting the Value (text) from instream. */
  inline istream& GetText(istream& istr) { istr >> Value; return istr; };
  
  /* Printing Value (text) to stream. */
  inline ostream& PrintText(ostream& o) { o << Value; return o;};

  /* Reading binary data to stream. */
  istream& GettBin(istream& istr)
  { unsigned char* chr = (unsigned char*)&Value;
    for (int i = 0; i < sizeof(Value); i++)
    { 
      istr >> chr[i];
    }
    return istr;  
  }
  
  /* Printing binary data to stream. */
  ostream& PrintBin(ostream& o)
  { unsigned char* chr = (unsigned char*)&Value;
    for (int i = 0; i < sizeof(Value); i++)
    { 
      o << chr[i];
    }
    return o;  
  }
    
private:
  /* This is the value type correspondong the template typename definition. */
    TYPE Value;
};

#endif	/* BYTECLASS_H */

