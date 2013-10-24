/* 
 * File:   main.cpp
 * Author: user
 *
 * Created on 2013. október 20., 11:44
 */

#include <stdio.h>
#include <iostream>
#include "serial.h"
#include "bootloader.h"

using namespace std;

/*
 * 
 */
int main(int argc, char** argv) 
{   unsigned char InBuffer[20];
    int readedbytes;
    
    serial s(string("COM9"), 19200);
    if (s.OpenPort())
    {
      cout << "Succesfully opened the " << s << " port." << endl;
      if (s.WriteData('\x9' /*COMMAND_READ_ID */))
      {
        cout << "s.WriteChar('\x9') OK " << endl; 
        Sleep(SLEEP_TIME);
        if (s.ReadBuffer(InBuffer, readedbytes))
        {
          cout << "Readed bytes = " << readedbytes << "\nThe buffer = " << endl;
          for (int i = 0; i < readedbytes; i++)
          {
              int d = InBuffer[i];
            cout << i << " : " << hex << d << endl;  
          }
        }
      }
    }
    else 
        cout << "Can't opened the " << s << " port." << endl;
    
//    s.PrintFeatures(cout);
    
    return 0;
}

