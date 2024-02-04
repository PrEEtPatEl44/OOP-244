#ifndef SDDS_DATE_H
#define SDDS_DATE_H
#include <iostream>
#include <cstring>
#include <sstream>
#include "Status.h"

namespace sdds
{
	const int MAXIMUM_YEAR_VALUE = 2030;
	class Date
	{
	private:
		Status status;
		int m_year;
		int m_month;
		int m_day;
		bool m_format;
		bool m_invalid;
		bool validate();
		int uinqiueDateValue() const;

	public:
		Date();
		bool notint(bool c = false);
		Date(int year, int month, int day);
		operator bool() const;
		const Status& state();
		Date& formatted(bool slash);
		bool operator==(const Date& ROp) const;
		bool operator!=(const Date& ROp) const;
		bool operator<(const Date& ROp) const;
		bool operator>(const Date& ROp) const;
		bool operator<=(const Date& ROp) const;
		bool operator>=(const Date& ROp) const;
		std::ostream& print(std::ostream& ostr) const;
		std::istream& read(std::istream& istr);
	};
	std::ostream& operator<<(std::ostream& os, const Date& dat);
	std::istream& operator>>(std::istream& is, Date& dat);
}

#endif // DATE_H