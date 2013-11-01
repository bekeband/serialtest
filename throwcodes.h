/* 
 * File:   throwcode.h
 * Author: user
 *
 * Created on 2013. november 1., 16:38
 */

#ifndef THROWCODE_H
#define	THROWCODE_H

#ifdef	__cplusplus
extern "C" {
#endif
  
#if defined (_WIN32)
  /* COMSTREAM THROW CODE GROUP 70 - 79 */
  #define COMSTREAM_BASE 70
  #define WRITEFILE_ERROR (COMSTREAM_BASE + 0)
  #define SETUPCOMM_ERROR (COMSTREAM_BASE + 1)
  #define SETCOMMSTATE_ERROR (COMSTREAM_BASE + 2)
  #define SERIAL_CREATEFILE_ERROR (COMSTREAM_BASE + 3)

  #define CONVERSION_ERROR 76
  #define E_NO_START_CHARACTER 34
#endif
  
#ifdef	__cplusplus
}
#endif

#endif	/* THROWCODE_H */

