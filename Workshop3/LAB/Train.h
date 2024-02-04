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



#ifndef SDDS_TRAIN_H
#define SDDS_TRAIN_H

#define MIN_TIME   700
#define MAX_TIME  2300
#define MAX_NO_OF_PASSENGERS 1000
namespace sdds {
	class Train{
	private:
		char* m_name;
		int m_people;
		int m_time;
	public:
		void initialize();
		bool validTime(int value)const;
		bool validNoOfPassengers(int value)const;
		void set(const char* name);
		void set(int noOfPassengers, int departure);
		void set(const char* name, int noOfPassengers, int departure);
		void finalize();
		bool isInvalid()const;
		int noOfPassengers() const;
		const char* getName() const;
		int getDepartureTime() const;
		void display() const;

	};
}

#endif // !SDDS_TRAIN_H
