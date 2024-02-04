/*/////////////////////////////////////////////////////////////////////////
						  Workshop - #7 (P1)
Full Name  : Preet Bhagyesh Patel
Student ID#: 132603226
Email      : pbpatel48@myseneca.ca
Date       : 12 November 2023

Authenticity Declaration:
I have done all the coding by myself and only copied the code that my
professor provided to complete my workshops and assignments.
/////////////////////////////////////////////////////////////////////////*/
#ifndef SDDS_PACK_H
#define SDDS_PACK_H
#include <iostream>
#include "Container.h"

namespace sdds {
	class Pack : public Container {
		int m_unit_size;
	public:
		Pack(const char* content = "", int size = 0, int unit_size = 330, int num_of_units = 0);

		int operator+=(int units_to_add);
		int operator-=(int units_to_remove);
		int unit() const;
		int no_of_units() const;
		int size() const;

		void clear(int size, int unit_size, const char* content);

		std::ostream& print(std::ostream& ostr) const;
		std::istream& read(std::istream& istr);
			
	};
	std::ostream& operator<<(std::ostream& ostr, const Pack& pack);
	std::istream& operator>>(std::istream& istr, Pack& pack);
}
#endif
