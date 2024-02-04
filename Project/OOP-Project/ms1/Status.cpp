#include"Status.h"
#include"Utils.h"
#include<iostream>
using namespace std;
namespace sdds {
	void Status::setEmpty() {
		m_desc = nullptr;
		m_code = 0;
	}
	Status::Status() {
		setEmpty();
	}
	Status::Status(const char* desc) {

		ut.alocpy(m_desc, desc);
		m_code = 0;
	}
	Status::Status(const Status& other){
		setEmpty();
		if (other.m_desc != nullptr) {
			ut.alocpy(m_desc, other.m_desc);
			m_code = other.m_code;
		}
		else {
			setEmpty();
		}
	}

	Status& Status::operator=(const Status& other){
		if (this != &other) {
			ut.alocpy(m_desc, other.m_desc);
			m_code = other.m_code;
		}
		return*this;
	}

	Status::~Status(){
		clear();
	}

	Status& Status::operator=(int code){
		m_code = code;
		return *this;
	}

	Status& Status::operator=(const char* desc) {
		ut.alocpy(m_desc, desc);
		return *this;
	}

	Status::operator int()const{
		return m_code;
	}

	Status::operator const char* ()const {
		return m_desc;
	}

	Status::operator bool()const {
		return m_desc==nullptr;
	}

	void Status::clear(){
		if (m_desc != nullptr) {
			delete[] m_desc;
			m_desc = nullptr;
		}
		m_code = 0;
	}

	ostream& Status::display(ostream& ostr)const {

		if (m_code == 0)
		{
			ostr << m_desc;
		}
		else
		{
			ostr << "ERR#" << m_code << ": ";
			ostr << m_desc;
		}
		return ostr;
	}
	ostream& operator<<(ostream& ostr, const Status& st){
		st.display(ostr);
		return ostr;
	}

	
}