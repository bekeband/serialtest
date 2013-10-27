/* 
 * File:   main.cpp
 * Author: user
 *
 * Created on 2013. október 20., 11:44
 */


#include <stdio.h>

#include <stdexcept>
#include <vector>
#include <istream>
#include <fstream>

#include "serial.h"
#include "bootloader.h"
#include "PICProgramLine.h"

using namespace std;

int main(int argc, char** argv) 
{
 unsigned char c;
 PICProgramLine PLine;
 
 string o("test.hex");
 string nextline;
 
 ifstream ifile;
 /* failbit, badbit exceptions */
 ifile.exceptions (ifstream::failbit);
 
 PICProgramLine Line;
 
 try
 {
  ifile.open(o.c_str());
  
  int n = 0;  
  while (!ifile.eof())
  {
//    ifile >> nextline;
//      cout << Line;
    ifile >> Line;  
    
    cout << "N : " << n++ << ", F = " << "\"" << nextline << "\"" << endl;
  };
  
 } catch (ifstream::failure e)
 {
   if (!ifile.eof())
     cout << "Exception opening/reading/closing file code = " << e.what() << endl;
   else
   {
       /* Phanton exception TODO I must do it anithing. 
       cout << "Phantom exception occurs." << endl;*/       
   }
 } catch (int e)
 {
     if (e == E_NO_START_CHARACTER)
     {
       cout << "There are no start character. " << endl;
       return -1;
     }
 }

 return 0;

};
/*
 * 
 
int main(int argc, char** argv) 
{   unsigned char InBuffer[20];
    int readedbytes;
    
    serial s(string("COM9"), 19200);
    if (s.OpenPort())
    {
      cout << "Succesfully opened the " << s << " port." << endl;
      if (s.WriteData('\x9'))
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
}*/

