/* 
 * File:   packets.h
 * Author: user
 * This is a simple class for hand on kind of request - response communication for PIC download. 
 * request - response
 */

#ifndef PACKETS_H
#define	PACKETS_H

#include <iostream>

class packets {
public:
    
  packets(const class iostream*);
  
  /* This is generally procedure for request - response communication. */
  bool RequestResponse();
  
  /* Specially request -response*/
  bool GetID();
  bool GetEEpromContent();
  bool GetProgramContent();
  bool SetEEpromContent();
  bool SetProgramContent();
  bool GetCM();
  bool SetCM();
  bool Reset();
  
  inline int GetResponseDelay() {return ResponseDelay; };
  inline void SetResponseDelay(int newDelay) {ResponseDelay = newDelay;};
  
//  packets(const packets& orig);
  virtual ~packets();
private:
    int ResponseDelay;
    const class iostream* packetstream;
};

#endif	/* PACKETS_H */

