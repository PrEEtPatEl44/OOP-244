/*/////////////////////////////////////////////////////////////////////////
						  Workshop - #3 (P1)
Full Name  : Preet Bhagyesh Patel
Student ID#: 132603226
Email      : pbpatel48@myseneca.ca
Date       : 29 september 2023

Authenticity Declaration:
I have done all the coding by myself and only copied the code that my
professor provided to complete my workshops and assignments.
/////////////////////////////////////////////////////////////////////////*/

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include "Train.h"
using namespace std;
namespace sdds {

	void Train::initialize() {
		m_name = nullptr;
		m_people = -1;
		m_time = -1;
	}


	bool Train::validTime(int value)const {
		
		int min = value % 100;
		return ((value >= MIN_TIME && value <= MAX_TIME) && min <= 59);
	}


	bool Train::validNoOfPassengers(int value)const {
		return (value <= MAX_NO_OF_PASSENGERS && value>0);
	}


	void Train::set(const char* name) {
		finalize();
		initialize();
		if (name != nullptr && name[0]!='\0') {
			m_name = new char[strlen(name) + 1];
			strcpy(m_name, name);

		}
	}


	void Train::set(int noOfPassengers, int departure) {
		if (validTime(departure) && validNoOfPassengers(noOfPassengers)) {
			m_people = noOfPassengers;
			m_time = departure;
		}
		else {
			m_people = -1;
			m_time = -1;
		}

	}


	void Train::set(const char* name, int noOfPassengers, int departure) {
		set(name);
		set(noOfPassengers, departure);

	}


	void Train::finalize() {
		delete[] m_name;

	}


	bool Train::isInvalid()const {
		return (!validTime(m_time) || !validNoOfPassengers(m_people)||m_name==nullptr||m_name[0]=='\0');
	}


	int Train::noOfPassengers() const {
		return m_people;

	}

	const char* Train::getName() const {
		return m_name;
	}


	int Train::getDepartureTime() const {
		return m_time;
	}

	
	void Train::display() const {
		if (isInvalid()) {
			cout << "Train in an invalid State!" << endl;
		}
		else {
			cout << "NAME OF THE TRAIN:    " << getName()<<endl;
			cout << "NUMBER OF PASSENGERS: " << noOfPassengers()<<endl;
			cout << "DEPARTURE TIME:       " << getDepartureTime() << endl;
		}
	}
}
