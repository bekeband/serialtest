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
    inline HexClass() {Value = 0; FieldWidth = 4;};
    inline HexClass(unsigned char aValue, int aFieldWidth) {Value = aValue; FieldWidth = aFieldWidth;};
    inline HexClass(const HexClass& orig) {Value = orig.Value; FieldWidth = orig.FieldWidth; };
    virtual ~HexClass();
    
    inline void const SetValue(const long aValue) {Value = aValue; };
    inline unsigned char GetValue() {return Value; };
    
    friend ostream& operator << (ostream &, const HexClass&);
    friend istream& operator >> (istream &, HexClass&);        
    istream& operator >> (istream &);        
    
//private:
    /* long value than max field width is 8 characters. */
    long Value;
    /* The width in characters of input value. */
    int FieldWidth;
};

#endif	/* BYTECLASS_H */

