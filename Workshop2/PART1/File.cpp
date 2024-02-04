/*/////////////////////////////////////////////////////////////////////////
                          Workshop - #2 (P1)
Full Name  : Preet Bhagyesh Patel
Student ID#: 132603226
Email      : pbpatel48@myseneca.ca
Date       : 21 september 2023

Authenticity Declaration:
I have done all the coding by myself and only copied the code that my
professor provided to complete my workshops and assignments.
/////////////////////////////////////////////////////////////////////////*/
#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <cstring>
#include "File.h"

namespace sdds {
   FILE* fptr;
   bool openFile(const char filename[]) {
      fptr = fopen(filename, "r");
      return fptr != NULL;
   }
   int noOfRecords() {
      int noOfRecs = 0;
      char ch;
      while (fscanf(fptr, "%c", &ch) == 1) {
         noOfRecs += (ch == '\n');
      }
      rewind(fptr);
      return noOfRecs;
   }
   void closeFile() {
      if (fptr) fclose(fptr);
   }
   // TODO: read functions go here    
   bool read(char*& name) {

       char tempName[128];

       //Storing the name to a temperory variable

       if (fscanf(fptr, "%127[^\n]\n", tempName) == 1) {

           //dynamically allocating the name by adjusting the size for the null terminator

           name = new char[strlen(tempName) + 1];
           
           strcpy(name, tempName);
           
           return true;
       }
       
       return false;
   
   }
   bool read(int& empNum) {
       
       return fscanf(fptr, "%d,", &empNum) == 1;
   
   }
   bool read(double& empSal) {
      
       return fscanf(fptr, "%lf,", &empSal) == 1;
   
   }
   
}