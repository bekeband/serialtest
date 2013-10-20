/* 
 * File:   main.cpp
 * Author: user
 *
 * Created on 2013. október 20., 11:44
 */

//#include <cstdlib>
#include <iostream>
#include "serial.h"

using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {

    serial s(string("COM9"));
    cout << s.GetPortName() << endl;
    return 0;
}

