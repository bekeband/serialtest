/* 
 * File:   MyString.h
 * Author: user
 *
 * Created on 2013. november 2., 13:10
 */

#ifndef MYSTRING_H
#define	MYSTRING_H

#include <string>

using namespace std;

class MyString : public string {
public:
  MyString();
  inline MyString(const char* c) : string(c) {};
  MyString(const MyString& orig);
  virtual ~MyString();
private:

};

#endif	/* MYSTRING_H */

