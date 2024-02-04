/*/////////////////////////////////////////////////////////////////////////
                          Workshop - #9 (P1)
Full Name  : Preet Bhagyesh Patel
Student ID#: 132603226
Email      : pbpatel48@myseneca.ca
Date       : 26 November 2023

Authenticity Declaration:
I have done all the coding by myself and only copied the code that my
professor provided to complete my workshops and assignments.
/////////////////////////////////////////////////////////////////////////*/
#ifndef SDDS_GRADUATE_H
#define SDDS_GRADUATE_H

#include "Student.h"

namespace sdds {
    class Graduate : public Student {
        char* m_title;
        char* m_Sname;
        

    public:
        
        Graduate();
        Graduate(const char* name, int age, const char* title = nullptr, const char* supervisor = nullptr);
        Graduate(const Graduate& other);
        Graduate& operator=(const Graduate& other);
        ~Graduate() override;
        void display() const override;
    };
}

#endif
