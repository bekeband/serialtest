/* 
 * File:   ByteClass.h
 * Author: user
 *
 * Created on 2013. október 26., 21:02
 */

#ifndef BYTECLASS_H
#define	BYTECLASS_H

#include <iostream>

#define CONVERSION_ERROR 76

using namespace std;

class HexClass {
public:
    inline HexClass(unsigned char aValue) {Value = aValue; FieldWidth = 4;};
    inline HexClass(const HexClass& orig) {Value = orig.Value; FieldWidth = orig.FieldWidth; };
    virtual ~HexClass();
    
    inline void SetValue(unsigned char aValue) {Value = aValue; };
    inline unsigned char GetValue() {return Value; };
    
    friend ostream& operator << (ostream &, const HexClass &);
    friend istream& operator >> (istream &, const HexClass);        
    
private:
    long Value;
    int FieldWidth;
};

#endif	/* BYTECLASS_H */

