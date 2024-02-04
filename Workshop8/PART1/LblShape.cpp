/*/////////////////////////////////////////////////////////////////////////
                          Workshop - #8 (P1)
Full Name  : Preet Bhagyesh Patel
Student ID#: 132603226
Email      : pbpatel48@myseneca.ca
Date       : 19 November 2023

Authenticity Declaration:
I have done all the coding by myself and only copied the code that my
professor provided to complete my workshops and assignments.
/////////////////////////////////////////////////////////////////////////*/
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include "LblShape.h"

namespace sdds {

    //Default constructor

    LblShape::LblShape() : m_label(nullptr) {}

    //Constructor with label paremeter to copy it o member label

    LblShape::LblShape(const char* label) : m_label(nullptr) {
        if (label) {
            m_label = new char[strlen(label) + 1];
            strcpy(m_label, label);
        }
    }

    //getter for label function

    const char* LblShape::label() const {
        return m_label;
    }



    void LblShape::getSpecs(std::istream& istr) {
        char label[100];
        istr.get(label, 100, ',');
        istr.ignore();

        delete[] m_label;
        m_label = new char[strlen(label) + 1];
        strcpy(m_label, label);
    }

    LblShape::~LblShape() {
        delete[] m_label;
    }

} 
