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
#include "Shape.h"

using namespace std;
namespace sdds {

	//overloaded insertion operator
	ostream& operator<<(ostream& ostr, const Shape& shape) {
		shape.draw(ostr);
		return ostr;
	};

	//overloaded extraction 
	istream& operator>>(istream& istr, Shape& shape) {
		shape.getSpecs(istr);
		return istr;
	};

	//destructor
	Shape::~Shape() {
		/*this guarantees that any dynamically allocated derived class
		from the shape interface pointed by a base class pointer will be 
		removed properly from memory when deleted.*/
	};
}