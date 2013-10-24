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
#define DEFAULT_BYTE_SIZE 8
#define DEFAULT_BAUD_RATE 9600
#define SLEEP_TIME 200  // msec between request, and read packets.

#include <string>
#include <iostream>
#if defined (_WIN32)
#include <windows.h>
#define FILE_HANDLE HANDLE
#endif
#if defined (_UNIX)
#define FILE_HANDLE int
#endif

using namespace std;

class serial : public iostream {
public:
    serial();
    serial(string aPortName, DWORD = DEFAULT_BAUD_RATE, int = DEFAULT_BYTE_SIZE,
            DWORD = DEFAULT_IN_BUFFER_SIZE, DWORD = DEFAULT_OUT_BUFFER_SIZE);

    serial(const serial& orig);

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

    bool WriteData(char c);
    bool WriteData(int data);
    bool WriteBuffer(unsigned char*, int);

    bool ReadBuffer(unsigned char*, int&);

    bool OpenPort() throw();
    void ClosePort();
    
    
    
    /* Destructor with file close. */
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
    int ByteSize;
    DWORD InBufferSize;
    DWORD OutBufferSize;
};

#endif	/* SERIAL_H */

