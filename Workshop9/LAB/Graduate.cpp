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
#include "Graduate.h"

namespace sdds {

    Graduate::Graduate() : Student(), m_title(nullptr), m_Sname(nullptr) {}

    Graduate::Graduate(const char* name, int age, const char* title, const char* supervisor) : Student(name, age) {
        m_title = new char[strlen(title) + 1];
        strcpy(m_title, title);

        m_Sname = new char[strlen(supervisor) + 1];
        strcpy(m_Sname, supervisor);
    }

    Graduate::Graduate(const Graduate& other) : Student(other) {
        m_title = new char[strlen(other.m_title) + 1];
        strcpy(m_title, other.m_title);

        m_Sname = new char[strlen(other.m_Sname) + 1];
        strcpy(m_Sname, other.m_Sname);
    }

    Graduate& Graduate::operator=(const Graduate& other) {
        if (this != &other) {
            Student::operator=(other);

            delete[] m_title;
            m_title = new char[strlen(other.m_title) + 1];
            strcpy(m_title, other.m_title);

            delete[] m_Sname;
            m_Sname = new char[strlen(other.m_Sname) + 1];
            strcpy(m_Sname, other.m_Sname);
        }
        return *this;
    }

    Graduate::~Graduate() {
        delete[] m_title;
        delete[] m_Sname;
    }

    void Graduate::display() const {
        Student::display();
        std::cout << "Thesis Title: " << (m_title ? m_title : "N/A")
            << "\nSupervisor: " << (m_Sname ? m_Sname : "N/A")
            << "\n---------------------------------------------" << std::endl;
    }
}
