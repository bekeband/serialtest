/* 
 * File:   PICProgramLine.cpp
 * Author: user
 * 
 * Created on 2013. október 24., 8:16
 */

#include "PICProgramLine.h"

PICProgramLine::PICProgramLine() {
}

PICProgramLine::PICProgramLine(const PICProgramLine& orig) {
}

PICProgramLine::~PICProgramLine() {
}

istream& operator >> (istream& i, PICProgramLine & p)
{
  unsigned char ib;
  unsigned int iw;
  
  i >> ib;
  p.ByteCount = ib;
  i >> iw;
  p.Address = iw;
  i >> ib;  
  p.LineType = (enum PICProgramLine::e_DataType)ib;

  p.DataBuffer = new unsigned char[p.ByteCount];
  
  if (p.DataBuffer != NULL)
  {
    /* Reading the data bytes from input stream. */
    for (int i = 0; i < p.ByteCount; i++)
    {
      i >> p.DataBuffer[i];
    }
  }
  
  
  
  return i;
}