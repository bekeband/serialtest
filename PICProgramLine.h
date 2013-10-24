/*
 * PICProgramLine class a line for PIC program 
 *  
 * Created on 2013. október 24., 8:16
 */

#ifndef PICPROGRAMLINE_H
#define	PICPROGRAMLINE_H

#include <iostream>
//#include <array>

using namespace std;

class PICProgramLine {
public:
    PICProgramLine();
    PICProgramLine(const PICProgramLine& orig);
    virtual ~PICProgramLine();

    /* Type of program data. */
    enum e_DataType {PRG, EEPROM, CONFIG};    
    
private:
    
public:
    
    /* Write the program line to output stream. */
    friend ostream& operator << (ostream &, const PICProgramLine &);
    /* A program line reading from input stream. */
    friend istream& operator >> (istream &, const PICProgramLine &);    

public:    
    unsigned char ByteCount;
    unsigned int Address;
    enum e_DataType LineType;   
    unsigned char* DataBuffer;
    
private:     
public:
};


#endif	/* PICPROGRAMLINE_H */

