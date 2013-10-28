/*
 * PICProgramLine class a line for PIC program 
 *  
 * Created on 2013. október 24., 8:16
 */

#ifndef PICPROGRAMLINE_H
#define	PICPROGRAMLINE_H

#include <iostream>
#include <vector>

#define START_CHARACTER ':'

#define E_NO_START_CHARACTER 34

using namespace std;

class PICProgramLine {
public:
    PICProgramLine();
    PICProgramLine(const PICProgramLine& orig);
    virtual ~PICProgramLine();
    inline void const SetByteCount(unsigned char aByteCount) const {}; //ByteCount = aByteCount;
    /* Type of program data. */
    enum e_DataType {PRG, EEPROM, CONFIG};
    
public:
    
    /* Write the program line to output stream. */
    friend ostream& operator << (ostream &, const PICProgramLine&);
    /* A program line reading from input stream. */
    friend istream& operator >> (istream &, const PICProgramLine&);    

private:  
    unsigned char ByteCount;
    unsigned int Address;
    enum e_DataType LineType;   
    
    vector<unsigned char> DataLine;
    
//    unsigned char* DataBuffer;
    
private:     
public:
};


#endif	/* PICPROGRAMLINE_H */

