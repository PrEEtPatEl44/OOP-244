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

#define _CRT_SECURE_NO_WARNINGS
#include "Student.h"
namespace sdds {
    void Student::copyFrom(const Student& other) {
        
        if (other.m_name != nullptr) {
            m_name = new char[strlen(other.m_name) + 1];
            strcpy(m_name, other.m_name);
        }
        else {
            m_name = nullptr;
        }
        m_age = other.m_age;
    }

    
    Student::Student() : m_name(nullptr), m_age(0) {}

    Student::Student(const char* studentName, int studentAge) {
        m_name = new char[strlen(studentName) + 1];
        strcpy(m_name, studentName);
        m_age = studentAge;
    }

    Student::Student(const Student& other) {
        copyFrom(other);
    }

    Student& Student::operator=(const Student& other) {
        if (this != &other) {
            delete[] m_name;
            
            copyFrom(other);
        }
        return *this;
    }

    Student::~Student() {
        delete[] m_name;
    }

    void Student::display() const {
        std::cout << "Name: " << (m_name ? m_name : "N/A") << "\nAge: " << m_age << std::endl;
    }
}
