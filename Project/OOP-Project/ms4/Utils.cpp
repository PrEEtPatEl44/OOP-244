/*/////////////////////////////////////////////////////////////////////////
                          Milestone: 4
Full Name  : Preet Bhagyesh Patel
Student ID#: 132603226
Email      : pbpatel48@myseneca.ca
Date       : 29 November 2023

Authenticity Declaration:
I have done all the coding by myself and only copied the code that my
professor provided to complete my workshops and assignments.
/////////////////////////////////////////////////////////////////////////*/
#define _CRT_SECURE_NO_WARNINGS



#include <iostream>
#include <ctime>
#include <cstring>
#include <iomanip>
#include <fstream>

#include "Utils.h"

using namespace std;
namespace sdds {
   Utils ut;
   void Utils::testMode(bool testmode) {
      m_testMode = testmode;
   }
   void Utils::alocpy(char*& destination, const char* source) {
       destination = nullptr;

       if (source != nullptr) {
           destination = new char[strlen(source) + 1];
           strcpy(destination, source);
       }
       else {
           destination = nullptr;
       }
   }

   int Utils::getint(const char* prompt) {
       if (prompt != nullptr) {
           std::cout << prompt;
       }

       int userInput;
       while (!(std::cin >> userInput)) {
           std::cin.clear();
           std::cin.ignore(1000, '\n');
           std::cout << "Invalid Integer, retry: ";
       }

       return userInput;
   }

   int Utils::getint(int min, int max, const char* prompt, const char* errMes) {
       if (prompt != nullptr) {
           std::cout << prompt;
       }

       int userInput = getint();
       while (userInput < min || userInput > max) {
           if (errMes != nullptr) {
               std::cout << errMes << ", retry: ";
           }
           else {
               std::cout << "Value out of range [" << min << "<=val<=" << max << "]: ";
           }
           userInput = getint();
       }

       return userInput;
   }

   double Utils::getdouble(const char* prompt) {
       if (prompt != nullptr) {
           std::cout << prompt;
       }

       double userInput;
       while (!(std::cin >> userInput)) {
           std::cin.clear();
           std::cin.ignore(1000, '\n');
           std::cout << "Invalid number, retry: ";
       }

       return userInput;
   }

   double Utils::getdouble(double min, double max, const char* prompt, const char* errMes) {
       if (prompt != nullptr) {
           std::cout << prompt;
       }

       double userInput = getdouble();
       while (userInput < min || userInput > max) {
           if (errMes != nullptr) {
               std::cout << errMes << ", retry: ";
           }
           else {
               std::cout << "Value out of range [" << std::fixed << std::setprecision(2) << min << "<=val<=" << max << "]: ";
           }
           userInput = getdouble();
       }

       return userInput;
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
   
}