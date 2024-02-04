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
#ifndef SDDS_STUDENT_H
#define SDDS_STUDENT_H

#include <iostream>
#include <cstring>

namespace sdds {
    class Student {
        char* m_name;
        int m_age;
        void copyFrom(const Student& other);
    public:        
        Student();
        Student(const char* studentName, int studentAge);
        Student(const Student& other);
        Student& operator=(const Student& other);
        virtual ~Student(); 
        virtual void display() const; 
    };
}

#endif
