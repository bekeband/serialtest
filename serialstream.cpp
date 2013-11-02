/* 
 * File:   serial.cpp
 * Author: user 
 * Created on 2013. október 20., 11:45
 */

#include <iostream>
#include <string>

#include "HexClass.h"
#include "serialstream.h"
#include "throwcodes.h"
//#include "PICProgramLine.h"

serialstream::serialstream() {
  comHandle = INVALID_HANDLE_VALUE;
}

serialstream::serialstream(string aPortName, DWORD aBaudRate, int aByteSize, DWORD aInBufferSize,
        DWORD aOutBufferSize) 
{
  serialstream(); /* reset comHandle... */
  PortName = aPortName;
  BaudRate = aBaudRate;
  ByteSize = aByteSize;
  InBufferSize = aInBufferSize;
  OutBufferSize = aOutBufferSize;
}

bool serialstream::OpenPort()
{

#if defined (_WIN32)    /* TODO Must parameterize !!! */

/* Createfile with PortName filename. */
#if defined (DEBUG)
cerr << "CreateFile " << PortName << endl;
#endif
comHandle = CreateFile( PortName.c_str(), GENERIC_READ | GENERIC_WRITE, 0, NULL, 
      OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, NULL );
if (comHandle == INVALID_HANDLE_VALUE) { throw SERIAL_CREATEFILE_ERROR;};
  
  /* Setting the commtimeouts structure. */

  dcb.DCBlength = sizeof( DCB );
  GetCommState(comHandle, &dcb );
  dcb.BaudRate = BaudRate;
  dcb.ByteSize = ByteSize;
  if (SetCommState(comHandle, &dcb))
  {
    if (SetupComm(comHandle, InBufferSize, OutBufferSize))
    {
      CommTimeOuts.ReadIntervalTimeout = 0xFFFFFFFF;
      CommTimeOuts.ReadTotalTimeoutMultiplier = 0;
      CommTimeOuts.ReadTotalTimeoutConstant = 0;
      CommTimeOuts.WriteTotalTimeoutMultiplier = 0;
      CommTimeOuts.WriteTotalTimeoutConstant = 5000;
      if (SetCommTimeouts(comHandle, &CommTimeOuts ))
      {
          return true;
      }
    } else {throw SETUPCOMM_ERROR;};
  } else {throw SETCOMMSTATE_ERROR;};
#endif        
  
  return false;
}

void serialstream::ClosePort()
{
#if defined (_WIN32)
    if (comHandle)
        CloseHandle(comHandle);
#endif
}

bool serialstream::WriteBuffer(unsigned char* buffer, int size)
{
#if defined (_WIN32)
  for (int i = 0; i < size; i++)
  {
    if (!WriteData<BYTE>(buffer[i]))
    {
      return false;     
    }
  }
  return true;
#endif
}
bool serialstream::ReadBuffer(unsigned char* buffer, int &size)
{
#if defined (_WIN32)
  DWORD dwBytesRead, dwErrorFlags;
  COMSTAT ComStat;
  ClearCommError(comHandle, &dwErrorFlags, &ComStat );
  /* If there are'nt input character. */
  if(!ComStat.cbInQue) return(false);
  /* If reading character. .. */
  dwBytesRead = (DWORD) ComStat.cbInQue;
  if (ReadFile(comHandle, buffer, dwBytesRead, &dwBytesRead, NULL))
  {
      size = dwBytesRead;
    return true;    
  };
  return false;
#endif
}

serialstream::serialstream(const serialstream& orig) {
}

serialstream::~serialstream()
{
  ClosePort();
}

ostream& serialstream::PrintFeatures(ostream& o)
{
  o << "Com port: " << GetPortName() << endl;
  o << "Baud rate: " << BaudRate << endl;
  o << "Byte size: " << ByteSize << endl;
  o << "Inbuffer size: " << InBufferSize << endl;
  o << "Outbuffer size: " << OutBufferSize << endl;

  return o;    
}

/* Serial stream features output. Only write portname now. */
ostream& operator <<(ostream &out, const serialstream &s) {
    out << s.GetPortName();
    return out;
}

/* PICProgramLine to serialstream transfer. */
serialstream& operator<<(serialstream& sstream, PICProgramLine& p)
{ stringstream os; BYTE inbyte;
  p.ByteCount.PrintBin(os);
  p.Address.PrintBin(os);
  p.LineType.PrintBin(os);
  
  vector< HexClass<BYTE> >::iterator it;
  
  for (it = p.DataLine.begin(); it != p.DataLine.end(); ++it)
  {
    it->PrintBin(os);
  }
  
  p.CrcByte.PrintBin(os);
  
  while (!os.eof())
  {
    os >> inbyte; 
    sstream.WriteData<BYTE>(inbyte);
  }
  return sstream;
}
/* String to serialstream. */
serialstream& operator<<(serialstream& sstream, string& instr)
{ 
  string::iterator it; 
  for (it = instr.begin(); it != instr.end(); ++it)
  {
    sstream.WriteData<char>(*it);
  };
  return sstream;
}

serialstream& operator<<(serialstream& sstream, char c)
{
  
}

serialstream& operator<<(serialstream&, MyString& p)
{
  
}

/* */
serialstream& operator>>(serialstream& sstream, PICProgramLine& p)
{
  return sstream;
}