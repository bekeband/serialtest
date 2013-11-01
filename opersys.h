/* 
 * File:   opersys.h
 * Author: user
 *
 * Created on 2013. november 1., 18:12
 */

#ifndef OPERSYS_H
#define	OPERSYS_H

#ifdef	__cplusplus
extern "C" {
#endif

#if defined (LINUX)
#define BYTE unsigned char
#define WORD unsigned short 
#define DWORD unsigned int 
#define FILE_HANDLE int
#else
#include <windows.h>
#define FILE_HANDLE HANDLE
#endif

#ifdef	__cplusplus
}
#endif

#endif	/* OPERSYS_H */

