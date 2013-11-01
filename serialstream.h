/*
 * File:   serial.h
 * Author: user
 *
 * Created on 2013. október 20., 11:45
 */

#ifndef SERIALSTREAM_H
#define	SERIALSTREAM_H


#define DEFAULT_IN_BUFFER_SIZE 2000
#define DEFAULT_OUT_BUFFER_SIZE 1600
#define DEFAULT_BYTE_SIZE 8
#define DEFAULT_BAUD_RATE 9600
#define SLEEP_TIME 200  // msec between request, and read packets.

#include <string>
#include <iostream>

#include "opersys.h"
#include "PICProgramLine.h"
#include "throwcodes.h"

using namespace std;

class serialstream {
public:
    serialstream();
    serialstream(string aPortName, DWORD = DEFAULT_BAUD_RATE, int = DEFAULT_BYTE_SIZE,
            DWORD = DEFAULT_IN_BUFFER_SIZE, DWORD = DEFAULT_OUT_BUFFER_SIZE);

    serialstream(const serialstream& orig);

    /* GetPortName */
    inline const string& GetPortName() const {
        return PortName;
    };

    inline const int& GetByteSize() const {
        return ByteSize;
    };

    inline const DWORD& GetBaudRate() const {
        return BaudRate;
    };

    inline const FILE_HANDLE GetFileHandle() const {
        return comHandle;
    };

    ostream& PrintFeatures(ostream&);

    /* Writedata to serial port. */    
    template <typename TYPE> bool WriteData(TYPE data)
    {
    #if defined (_WIN32)
    DWORD dwBytesWritten; /* TODO Must observe the case of the dwBytesWritten not equal the 
                           BytesToWritten parameter. */
      if (!WriteFile(comHandle, &data, sizeof(data), &dwBytesWritten, NULL ))
      {
        throw WRITEFILE_ERROR;
      } return true;
    #endif 
    }
    
    bool WriteBuffer(unsigned char*, int);

    bool ReadBuffer(unsigned char*, int&);

    bool OpenPort();
    void ClosePort();
    
    /* Destructor with file close. */
    virtual ~serialstream();

    friend ostream& operator<<(ostream&, const serialstream&);
/*    friend istream& operator>>(istream&, serialstream&);*/
    
/*    inline friend serialstream& operator<<(serialstream& sstream, const PICProgramLine& p)
    {
      return sstream;
    }*/

    friend serialstream& operator<<(serialstream&, PICProgramLine& p);
    
private:
    string PortName;
    FILE_HANDLE comHandle;
    bool isOpened;
    
    
#if defined (_WIN32)
    COMMTIMEOUTS CommTimeOuts;
    DCB dcb;

    DWORD ReadIntervalTimeout;
    DWORD ReadTotalTimeoutMultiplier;
    DWORD ReadTotalTimeoutConstant;
    DWORD WriteTotalTimeoutMultiplier;
    DWORD WriteTotalTimeoutConstant;

#endif
    /* UNIX style com structure. */
#if defined (LINUX)

#endif
    /* Globa communication features. */
    DWORD BaudRate;
    int ByteSize;
    DWORD InBufferSize;
    DWORD OutBufferSize;
};

#endif	/* SERIALSTREAM_H */

