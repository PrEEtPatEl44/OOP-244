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
#ifndef SDDS_CONTAINER_H
#define SDDS_CONTAINER_H

#include <iostream>
#define MAXSIZE 50
namespace sdds {
	
	class Container {
		char m_con[MAXSIZE];
		int m_cap;
		int m_vol;

	protected:
		void setEmpty();
		int capacity() const;
		int volume() const;

	public:
		Container(const char* content = nullptr, int capacity = 0, int volume = 0);
		int operator+=(int value);
		int operator-=(int value);
		operator bool() const;
		void clear(int capacity, const char* content);

		std::ostream& print(std::ostream& ostr) const;
		std::istream& read(std::istream& istr);
				
	};

	std::ostream& operator<<(std::ostream& ostr, const Container& container);
	std::istream& operator>>(std::istream& istr, Container& container);

}
#endif