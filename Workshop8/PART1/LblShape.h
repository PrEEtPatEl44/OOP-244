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
#ifndef SDDS_LBL_SHAPE_H
#define SDDS_LBL_SHAPE_H

#include "Shape.h"

namespace sdds {
	class LblShape : public Shape {
	private:
		char* m_label = nullptr;

	protected:
		const char* label() const;

	public:
		LblShape();
		LblShape(const char* label);
		void getSpecs(std::istream& istr);
		~LblShape();
	};
}
#endif 