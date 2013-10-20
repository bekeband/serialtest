/* 
 * File:   serial.cpp
 * Author: user
 * 
 * Created on 2013. október 20., 11:45
 */

#include "serial.h"

serial::serial() {
  comHandle = 0;
}

serial::serial(string aPortName, DWORD aBaudRate = 9600, BYTE aByteSize = 8, 
        DWORD aInBufferSize = DEFAULT_IN_BUFFER_SIZE,
        DWORD aOutBufferSize = DEFAULT_OUT_BUFFER_SIZE) {
  serial(); /* reset comHandle... */
  PortName = aPortName;
  BaudRate = aBaudRate;
  ByteSize = aByteSize;
  InBufferSize = aInBufferSize;
  OutBufferSize = aOutBufferSize;
}

serial::serial(string aPortName)
{
  serial(aPortName, 9600, 8, DEFAULT_IN_BUFFER_SIZE, DEFAULT_OUT_BUFFER_SIZE);
}
bool serial::OpenPort()
{
    /* Createfile with PortName filename. */
  comHandle = CreateFile( PortName.c_str(), GENERIC_READ | GENERIC_WRITE, 0, NULL, 
          OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, NULL );
  if (comHandle == NULL) { return false;}
  
  /* Setting the commtimeouts structure. */
#if defined (_WIN32)    /* TODO Must parameterize !!! */

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

bool serial::WriteChar(char c)
{ 
#if defined (_WIN32)
  DWORD dwBytesWritten;
  return WriteFile(comHandle, &c, 1, &dwBytesWritten, NULL );    
#endif
}
    
bool serial::WriteBuffer(unsigned char* buffer, int size)
{
#if defined (_WIN32)
  for (int i = 0; i < size; i++)
  {
    if (!WriteChar(buffer[i]))
    {
      return false;     
    }
  }
  return true;
#endif
}
bool serial::ReadBuffer(unsigned char* buffer, int size)
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
    return true;    
  };
  return false;
#endif
}

serial::serial(const serial& orig) {
}

serial::~serial() {
#if defined (_WIN32)
  if (comHandle != 0) CloseHandle(comHandle);
#endif
#if defined (_UNIX)
  /* TODO _UNIX File close procedure !!!*/
#endif
}

ostream& operator <<(ostream &out, const serial &s) {
    out << s.GetPortName();
    return out;
}
