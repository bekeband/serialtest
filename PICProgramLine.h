/*
 * PICProgramLine class a line for PIC program 
 *  
 * Created on 2013. október 24., 8:16
 */

#ifndef PICPROGRAMLINE_H
#define	PICPROGRAMLINE_H

#include <iostream>
#include <vector>
#include "HexClass.h"
//#include "serialstream.h"

#define START_CHARACTER ':'

using namespace std;

class PICProgramLine {
public:
    PICProgramLine();
    PICProgramLine(const PICProgramLine& orig);
    virtual ~PICProgramLine();
//    inline void SetByteCount(unsigned char aByteCount) {ByteCount = aByteCount;}; //
    /* Type of program data. */
    enum e_DataType {PRG, EEPROM, CONFIG};
    
public:
    
    /* Write the program line to output stream. */
    friend ostream& operator << (ostream &, PICProgramLine&);
    
    /* Write the program line to serialstream. */
//    friend serialstream& operator << (serialstream &, PICProgramLine&);
    
    /* A program line reading from input stream. */
    friend istream& operator >> (istream &, PICProgramLine&);    

public:
  HexClass<BYTE> ByteCount;
  HexClass<WORD> Address;
  HexClass<BYTE> CrcByte;
  HexClass<BYTE> LineType;
    
  vector< HexClass<BYTE> > DataLine;
    
private:     
public:
};


#endif	/* PICPROGRAMLINE_H */

