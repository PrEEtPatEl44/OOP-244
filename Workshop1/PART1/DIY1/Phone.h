/*/////////////////////////////////////////////////////////////////////////
                          Workshop - #6 (P1)
Full Name  : Preet Bhagyesh Patel
Student ID#: 132603226
Email      : pbpatel48@myseneca.ca
Date       : 16 september 2023

Authenticity Declaration:
I have done all the coding by myself and only copied the code that my
professor provided to complete my workshops and assignments.
/////////////////////////////////////////////////////////////////////////*/

#ifndef SDDS_PHONE_H
#define SDDS_PHONE_H
namespace sdds {
    struct  Person {
        char name[51];
        char area[5];
        char num1[5];
        char num2[5];
    };
    
    void phoneDir(const char* nameDir, const char* filename);

   
}
#endif 