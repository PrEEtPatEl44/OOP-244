/***********************************************************************
// Final project Milestone 1
// Module: Utils
// File: Utils.h
// Version 1.0
// Author  Fardad Soleimanloo
// Description
//
// Revision History
// -----------------------------------------------------------
// Name                 Date            Reason
***********************************************************************/
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <ctime>
#include <cstring>
#include "Utils.h"
using namespace std;
namespace sdds {
   Utils ut;
   void Utils::testMode(bool testmode) {
      m_testMode = testmode;
   }
   
   void Utils::getSystemDate(int* year, int* mon, int* day) {
      if (m_testMode) {
         if(day) *day = sdds_testDay;
         if(mon) *mon = sdds_testMon;
         if(year) *year = sdds_testYear;
      }
      else {
         time_t t = std::time(NULL);
         tm lt = *localtime(&t);
         if (day) *day = lt.tm_mday;
         if (mon) *mon = lt.tm_mon + 1;
         if (year) *year = lt.tm_year + 1900;
      }
   }
   int Utils::daysOfMon(int month, int year)const {
      int days[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31, -1 };
      int mon = (month >= 1 && month <= 12 ? month : 13)-1;
      return days[mon] + int((mon == 1) * ((year % 4 == 0) && (year % 100 != 0)) || (year % 400 == 0));
   }

   void Utils::alocpy(char*& destination, const char* source)
   {

       delete[] destination;
       destination = nullptr;

       if (source != nullptr) {
           destination = new char[strlen(source) + 1];
           strcpy(destination, source);
       }
   }

   int Utils::getint(const char* prompt)
   {
       int input = 0;
       if (prompt != nullptr)
       {
           cout << prompt;
           bool valid = true;
           while (valid)
           {
               cin >> input;
               if (cin.fail())
               {
                   valid = false;
                   cout << "Invalid Integer, retry: ";
                   cin.clear();
                   cin.ignore(1000, '\n');
               }
           }
       }
       return input;
   }
   int Utils::getint(int min, int max, const char* prompt, const char* errMes)
   {
       int temp = 0;
       if (prompt != nullptr)
       {
           bool valid = true;

           cout << prompt;
           while (valid)
           {
               cin >> temp;
               if (cin.fail() || temp < min || temp > max)
               {
                   valid = false;
                   if (errMes == nullptr)
                   {
                       cout << "Value out of rnage [" << min << "<= val <=" << max << "]: ";
                   }
                   else
                   {
                       cout << errMes << ", retry: ";
                   }
                   cin.clear();
                   cin.ignore(1000, '\n');
                   
               }
           }
       }
       return temp;
   }
   
}