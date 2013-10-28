/* 
 * File:   serial.cpp
 * Author: user 
 * Created on 2013. október 20., 11:45
 */

#include "serial.h"
#include <iostream>

serial::serial() {
  comHandle = 0;
}

serial::serial(string aPortName, DWORD aBaudRate, int aByteSize, DWORD aInBufferSize,
        DWORD aOutBufferSize) 
{
  serial(); /* reset comHandle... */
  PortName = aPortName;
  BaudRate = aBaudRate;
  ByteSize = aByteSize;
  InBufferSize = aInBufferSize;
  OutBufferSize = aOutBufferSize;
}

bool serial::OpenPort() throw()
{  int g = 0;

#if defined (_WIN32)    /* TODO Must parameterize !!! */

/* Createfile with PortName filename. */
  comHandle = CreateFile( PortName.c_str(), GENERIC_READ | GENERIC_WRITE, 0, NULL, 
      OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, NULL );
  if (comHandle == NULL) { return false;}
  
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
    }
  }
#endif        
  
  return false;
}

void serial::ClosePort()
{
#if defined (_WIN32)
    if (comHandle)
        CloseHandle(comHandle);
#endif
}

bool serial::WriteData(char c)
{ 
#if defined (_WIN32)
  DWORD dwBytesWritten;
  return WriteFile(comHandle, &c, 1, &dwBytesWritten, NULL );    
#endif
}
    
bool serial::WriteData(int data)
{
#if defined (_WIN32)
  DWORD dwBytesWritten;
  return WriteFile(comHandle, &data, 1, &dwBytesWritten, NULL );    
#endif    
}

bool serial::WriteBuffer(unsigned char* buffer, int size)
{
#if defined (_WIN32)
  for (int i = 0; i < size; i++)
  {
    if (!WriteData(buffer[i]))
    {
      return false;     
    }
  }
  return true;
#endif
}
bool serial::ReadBuffer(unsigned char* buffer, int &size)
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

serial::serial(const serial& orig) {
}

serial::~serial()
{
    ClosePort();
}

ostream& serial::PrintFeatures(ostream& o)
{
    o << "Com port: " << GetPortName() << endl;
    o << "Baud rate: " << BaudRate << endl;
    o << "Byte size: " << ByteSize << endl;
    o << "Inbuffer size: " << InBufferSize << endl;
    o << "Outbuffer size: " << OutBufferSize << endl;

  return o;    
}

ostream& operator <<(ostream &out, const serial &s) {
    out << s.GetPortName();
    return out;
}
