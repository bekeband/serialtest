/*
 * File:   serial.h
 * Author: user
 *
 * Created on 2013. október 20., 11:45
 */

#ifndef SERIAL_H
#define	SERIAL_H

#define DEFAULT_IN_BUFFER_SIZE 2000
#define DEFAULT_OUT_BUFFER_SIZE 1600

#include <string>
#if defined (_WIN32)
#include <windows.h>
#define FILE_HANDLE HANDLE
#endif
#if defined (_UNIX)
#define FILE_HANDLE int
#endif

using namespace std;

class serial {
public:
    serial();
    serial(string aPortName, DWORD, BYTE, DWORD, DWORD);
    serial(string aPortName);
    serial(const serial& orig);
    /* GetPortName */
    inline const string& GetPortName() const {return PortName;}; 
    inline const BYTE& GetByteSize() const {return ByteSize;};
    inline const DWORD& GetBaudRate() const {return BaudRate;};
    inline const FILE_HANDLE GetFileHandle() const {return comHandle;};  
    
    bool WriteChar(char c);
    bool WriteBuffer(unsigned char* buffer, int size);
    
    bool ReadBuffer(unsigned char* buffer, int size);
    
    bool OpenPort();
    virtual ~serial();
    
    friend ostream& operator<<(ostream &, const serial &);
    
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
#if defined (_UNIX)
    
#endif
    /* Globa communication features. */
    DWORD BaudRate;
    BYTE ByteSize;
    DWORD InBufferSize;
    DWORD OutBufferSize;
};

#endif	/* SERIAL_H */

