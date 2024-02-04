/*/////////////////////////////////////////////////////////////////////////
						  Workshop - #4 (P2)
Full Name  : Preet Bhagyesh Patel
Student ID#: 132603226
Email      : pbpatel48@myseneca.ca
Date       : 6 october 2023

Authenticity Declaration:
I have done all the coding by myself and only copied the code that my
professor provided to complete my workshops and assignments.
/////////////////////////////////////////////////////////////////////////*/

#define _CRT_SECURE_NO_WARNINGS

#include<iostream>
#include<cstring>
#include<iomanip>

#include "Label.h"

using namespace std;
namespace sdds {
	
	 const char defaultFrame[9] = "+-+|+-+|";

	Label::Label() {

		//copy the frame to default frame if frame not given
		strcpy(m_frame, defaultFrame);
		m_content = nullptr;
	}

	Label::Label(const char* frameArg) {

		//if frame is not null then copy the given frame
		if (frameArg != nullptr) {
			strcpy(m_frame, frameArg);
		}
		else {
			strcpy(m_frame, defaultFrame);
		}
		
		m_content = nullptr;
	}

	Label::Label(const char* frameArg, const char* content) {
		//if frame is not null then copy the given frame
		if (frameArg != nullptr) {
			strcpy(m_frame, frameArg);
		}
		else {
			strcpy(m_frame, defaultFrame);
		}
		m_content = new char[71];
		strncpy(m_content, content, 70);
	}

	Label::~Label() {
		if (m_content) {
			delete[] m_content;
			m_content = nullptr;
		}
	}
	
	istream& Label::readLabel(std::istream& ist ) {
		
		char content[71];
		 ist.get(content, 71);
		 ist.ignore(10000, '\n');
		 text(content);
		 
		 
		 return ist;
	}

	ostream& Label::printLabel(std::ostream& ostr) const{
		if (m_content != nullptr) {
			

			ostr << m_frame[0] << setw((strlen(m_content) + 3)) << setfill(m_frame[1]) << m_frame[2] << endl;
			ostr << m_frame[7] << setw((strlen(m_content) + 3)) << setfill(' ') << m_frame[3] << endl;
			ostr << m_frame[7] << " " << m_content << " " <<m_frame[3]<< endl;
			ostr << m_frame[7] << setw((strlen(m_content) + 3)) << setfill(' ') << m_frame[3] << endl;
			ostr << m_frame[6] << setw((strlen(m_content) + 3)) << setfill(m_frame[5]) << m_frame[4] ;
		}
		return ostr;
	}

	Label& Label::text(const char* content){
		if (m_content != nullptr) {
			delete[] m_content;
			m_content = nullptr;
		}

		//dynamically allocating m_content
		m_content = new char[71];
		strncpy(m_content, content, 71);
		return *this;
	}


}
