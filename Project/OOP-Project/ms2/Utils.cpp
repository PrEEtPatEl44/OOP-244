/*/////////////////////////////////////////////////////////////////////////
                          Milestone: 2
Full Name  : Preet Bhagyesh Patel
Student ID#: 132603226
Email      : pbpatel48@myseneca.ca
Date       : 15 November 2023

Authenticity Declaration:
I have done all the coding by myself and only copied the code that my
professor provided to complete my workshops and assignments.
/////////////////////////////////////////////////////////////////////////*/
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
       if (destination) {
           delete[] destination;
           destination = nullptr;
       }

       if (source != nullptr) {
           destination = new char[strlen(source) + 1];
           strcpy(destination, source);
       }
   }

 int Utils::getint(const char* prompt ) {
     int value;
     bool isValid = false;
     if (prompt) {
         cout << prompt;
     }
     do {
         if (!(cin >> value)) {
             cin.clear();
             cin.ignore(1000, '\n');
             cout << "Invalid Integer, retry: ";
         }
         else {
             isValid = true;
         }
     } while (!isValid);
     return value;
   }

   int Utils::getint(int min, int max, const char* prompt , const char* errMes ) {
       int value;
       bool displayPrompt = true;  // Flag to control whether to display the prompt

       do {
           if (displayPrompt) {
               value = getint(prompt);
               displayPrompt = false; // Do not display prompt on subsequent attempts
           }
           else {
               value = getint(nullptr); // Do not display prompt
           }

           if (value < min || value > max) {
               if (errMes)
                   cout << errMes << ", retry: ";
               else
                   cout << "Value out of range [" << min << "<=val<=" << max << "]: ";
           }
       } while (value < min || value > max);

       return value;
   }
};







   
   
