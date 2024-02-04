
#ifndef SDDS_STATUS_H
#define SDDS_STATUS_H
#include<iostream>

namespace sdds {
	class Status {
		char* m_desc;
		int m_code;
		void setEmpty();
	public:
		Status();
		Status(const char* desc);
		Status(const Status& other);
		Status& operator=(const Status& other);
		~Status();
		Status& operator=(int code);
		Status& operator=(const char* desc);
		operator int()const;
		operator const char* ()const;
		operator bool()const;
		void clear();
		std::ostream& display(std::ostream& ostr)const;
	};
		std::ostream& operator<<(std::ostream& ostr, const Status& st);
}
#endif // !SDDS_STATUS_H
