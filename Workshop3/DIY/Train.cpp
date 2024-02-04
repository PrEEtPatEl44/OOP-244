	/*/////////////////////////////////////////////////////////////////////////
						  Workshop - #3(P2)
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
		if (name != nullptr && name[0] != '\0') {
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
		return (!validTime(m_time) || !validNoOfPassengers(m_people) || m_name == nullptr || m_name[0] == '\0');
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
			cout << "NAME OF THE TRAIN:    " << getName() << endl;
			cout << "NUMBER OF PASSENGERS: " << noOfPassengers() << endl;
			cout << "DEPARTURE TIME:       " << getDepartureTime() << endl;
		}
	}

	//gets input for the number of passengers to be boarded
	bool Train::load(int& unboarded) {
		int noOfPassenger;
		bool ok=true;
		cout << "Enter number of passengers boarding:" << endl
			<< "> ";
		cin >> noOfPassenger;
		if (load(noOfPassenger, unboarded)) {
			return ok;
		}
		else {
			ok = false;
			return ok;
		}
		
	}

	//Update the number of passengers that can be boarded and calculates the number of unboarded passengers
	bool Train::load(const int& noOfPassenger, int& unboarded) {
		bool ok = true;

		if (validNoOfPassengers(noOfPassenger)) {
			if (m_people + noOfPassenger > MAX_NO_OF_PASSENGERS) {
				unboarded = ((m_people + noOfPassenger) - MAX_NO_OF_PASSENGERS);
				m_people = MAX_NO_OF_PASSENGERS;
				ok = false;
			}
			else {
				m_people += noOfPassenger;
			}

		}
		else {
			unboarded = noOfPassenger - MAX_NO_OF_PASSENGERS;
			m_people = MAX_NO_OF_PASSENGERS;
			ok = false;

		}
		return ok;
	}


	bool Train::updateDepartureTime() {
		int departTime;
		cout << "Enter new departure time:" << endl
			<< "> ";
		cin >> departTime;
		if (validTime(departTime)) {
			m_time=departTime;
			return true;
		}
		else {
			m_time = -1;
			return false;
		}

	}

	bool Train::transfer(const Train& tr) {
		int notBoarded;
		bool ok = true;
		if (isInvalid() || tr.isInvalid()) {
			ok =false;
		}
		else {
			int combinedNameLength = strlen(m_name) + strlen(tr.m_name) + 3; // 3 for ", " and null terminator

			
			char* combinename = new char[combinedNameLength];

			
			strcpy(combinename, m_name);
			strcat(combinename, ", ");
			strcat(combinename, tr.m_name);
			//deleting the previously allocated memory
			delete[] m_name;
			//setting the new memory
			m_name = new char[combinedNameLength];
			strcpy(m_name, combinename);
			
			if(load(tr.m_people, notBoarded)){
			//do nothing
				
			}
			else {
				cout << "Train is full; " << notBoarded << " passengers of " << tr.m_name << " could not be boarded!" << endl;
			}
			delete[] combinename;
		}
		return ok;
	}
}
