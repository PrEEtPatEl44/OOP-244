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
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include<cstring>
#include "Container.h"
using namespace std;

using namespace sdds;
namespace sdds {
	void Container::setEmpty() {
		m_con[0] = '\0';
		m_cap = 0;
		m_vol = 0;
	}

	int Container::capacity() const {
		return m_cap;
	}

	int Container::volume() const {
		return m_vol;
	}

	Container::Container(const char* con, int cap, int vol) : m_cap(cap), m_vol(vol) {
		if (con != nullptr) {
			strncpy(m_con, con, MAXSIZE);
			m_con[MAXSIZE - 1] = '\0';
		}
		else setEmpty();

		if (vol > cap) setEmpty();
	}

	int Container::operator+=(int value) {
		if (operator bool()) {
			int space = m_cap - m_vol;
			int to_add = (value <= space) ? value : space;
			m_vol += to_add;

			return to_add;
		}

		else return 0;
	}

	int Container::operator-=(int value) {
		if (operator bool()) {
			int to_remove = (value <= m_vol) ? value : m_vol;
			m_vol -= to_remove;
			return to_remove;
		}

		else return 0;
	}

	Container::operator bool() const {
		return m_con[0] != '\0' && m_vol <= m_cap;
	}

	void Container::clear(int cap, const char* con) {
		if (cap && con && strlen(con) > 0) {
			setEmpty();
			new (this) Container(con, cap);
		}
		else setEmpty();
	}

	ostream& Container::print(ostream& ostr) const {
		if (*this) {
			ostr << m_con << ": (" << m_vol << "cc/" << m_cap << ")";
		}
		else {
			ostr << "****: (**cc/***)";
		}

		return ostr;
	}

	istream& Container::read(istream& istr) {
		if (!(*this)) {
			cout << "Broken Container, adding aborted! Press <ENTER> to continue...." << endl;
			istr.ignore(1000, '\n');
			return istr;
		}
		cout << "Add to ";
		print(cout);
		cout << "\n> ";

		int amt;
		while (!(istr >> amt) || amt < 1) {
			istr.clear();
			istr.ignore(1000, '\n');
			cout << "Invalid amount, retry: ";
		}

		int addedAmt = *this += amt;
		cout << "Added " << addedAmt << " CCs" << endl;

		return istr;
	}


	ostream& operator<<(ostream& ostr, const Container& container) {
		return container.print(ostr);
	}

	istream& operator>>(istream& istr, Container& container) {
		return container.read(istr);
	}
	
}