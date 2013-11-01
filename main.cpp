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

#include "serialstream.h"
#include "bootloader.h"
#include "PICProgramLine.h"
#include "HexClass.h"
#include "throwcodes.h"
#include "cmd.h"

using namespace std;

int main(int argc, char** argv) 
{

 cmd_cCmd ProgCommand(argv, "i:b:p:e:");    
 serialstream comstream(string("COM8"), 19200);
 try 
 {
   comstream.OpenPort();
 } catch (int error_code)
 {
   if ((error_code > COMSTREAM_BASE) && (error_code < COMSTREAM_BASE + 9))
   {
    cerr << "ComStream class error. Error code = " << error_code << endl;
    cerr << "" << endl;
    return -1;
   };
 } catch(exception e)
 {
   cerr << "catch(exception e) = " << e.what() << endl;
 } catch (...)
 {
   cerr << "catch (...)" << endl;
 };
 
 string o("test.hex");
 ifstream ifile;
 /* failbit, badbit exceptions */
 ifile.exceptions (ifstream::failbit);
 
 fstream ofile("out.bin", ios::binary | ios::out);

// vector< HexClass<BYTE> > HCVector;
 
 try
 {
  ifile.open(o.c_str());
  int n = 0;  
  while (!ifile.eof())
  {
    PICProgramLine Line;
//    ifile >> nextline;
//      cout << Line;
//    ifile >> Line;
//      ifile >> c;
    ifile >> Line;
 
    ofile << Line;
    comstream << Line;
    
  };
  ofile.close();
  ifile.close();
  comstream.ClosePort();
 } catch (ifstream::failure e)
 {
   if (!ifile.eof())
     cout << "Exception opening/reading/closing file code = " << e.what() << endl;
   else
   {
       /* Phantom exception TODO I must do it anithing. 
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

