/* 
 * File:   cexception.h
 * Author: user
 *
 * Created on 2013. október 21., 9:56
 */

#ifndef CEXCEPTION_H
#define	CEXCEPTION_H

#include <exception>

using namespace std;

class cexception : public exception 
{
public:
    cexception() throw();
    cexception(const cexception& orig);
    virtual ~cexception() throw();
private:

};

#endif	/* CEXCEPTION_H */

