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
#include <cstring>
#include "Rectangle.h"
using namespace std;
namespace sdds {

    //default constructor 
    Rectangle::Rectangle() : LblShape(), m_width(0), m_height(0) {}


    //Three argument constructor
    //    Receives a Cstring for the label, and two values for the width and height 
    //    of the Rectangle from the argument list.
    Rectangle::Rectangle(const char* label, const int width, const int height)
        : LblShape(label), m_width(width >= 0 ? width : 0), m_height(height >= 3 ? height : 0) {}



    void Rectangle::getSpecs(istream& istr) {
        //calling base class getSpec function
        LblShape::getSpecs(istr);
        istr >> m_width;
        istr.ignore();
        istr >> m_height;
        istr.ignore();
    }

    //overrided draw of lblshape
    void Rectangle::draw(ostream& ostr) const {
        if (m_width > 0 && m_height > 0) {
            ostr << '+' << std::string(m_width - 2, '-') << '+' << std::endl;
            ostr << '|';
                        
            int padLength = m_width - 2 - strlen(label());
            ostr << label();
            for (int i = 0; i < padLength; i++) {
                ostr << ' ';
            }

            ostr << '|' << std::endl;

            for (int i = 0; i < m_height - 3; i++) {
                ostr << '|' << std::string(m_width - 2, ' ') << '|' << std::endl;
            }
            ostr << '+' << std::string(m_width - 2, '-') << '+';
        }
    }

} 
