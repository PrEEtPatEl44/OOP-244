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
#include <iostream>
#include "Line.h"
using namespace std;
namespace sdds {
    

    //Default constructor 
    Line::Line() : LblShape(), m_length(0) {}

    /*Receives a Cstring and a value for the length of the line.
    Passes the Cstring to the constructor of the base class and 
    sets the m_length member variable to the value of the second argument.*/
    Line::Line(const char* label, const int length) : LblShape(label), m_length(length >= 0 ? length : 0) {}

    void Line::getSpecs(istream& istr) {
        LblShape::getSpecs(istr);
        istr >> m_length;
        istr.ignore();
    }

    void Line::draw(ostream& ostr) const {
        if (m_length > 0 && label()) {
            ostr << label() << std::endl;
            ostr << std::string(m_length, '=');
        }
    }

} 
