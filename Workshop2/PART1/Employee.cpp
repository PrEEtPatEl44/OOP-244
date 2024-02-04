/*/////////////////////////////////////////////////////////////////////////
						  Workshop - #2 (P1)
Full Name  : Preet Bhagyesh Patel
Student ID#: 132603226
Email      : pbpatel48@myseneca.ca
Date       : 21 september 2023

Authenticity Declaration:
I have done all the coding by myself and only copied the code that my
professor provided to complete my workshops and assignments.
/////////////////////////////////////////////////////////////////////////*/
#include <iostream>
#include "Employee.h"
#include "File.h"
using namespace std;
namespace sdds {

	int noOfEmployees;
	Employee* employees;


	void sort() {
		int i, j;
		Employee temp;
		for (i = noOfEmployees - 1; i > 0; i--) {
			for (j = 0; j < i; j++) {
				if (employees[j].m_empNo > employees[j + 1].m_empNo) {
					temp = employees[j];
					employees[j] = employees[j + 1];
					employees[j + 1] = temp;
				}
			}
		}
	}

	// TODO: Finish the implementation of the 1 arg load function which
	// reads one employee record from the file and loads it into the employee reference
	// argument
	bool load(Employee& employee) {
		bool ok = false;
		
		//If all  overloaded read functions return true the the entire function return true 
		//This function loads/reads one row of the data file 
		if (read(employee.m_empNo) && read(employee.m_salary) && read(employee.m_name)) {
			ok = true;

		}
		return ok;
	}
	// TODO: Finish the implementation of the 0 arg load function 
	bool load() {
		int i = 0;
		
		bool ok = false;

		//opening the data file
		
		if (openFile("employees.csv")) {

			//count the number of records if file opened successfully

			noOfEmployees = noOfRecords();
			
			//dynamically allocate the size of the array of object to be the no of records in the data file
			
			employees = new Employee[noOfEmployees];
			
			//load all the records by iterating through the loop of the object 
			
			for (i = 0; i < noOfEmployees; i++) {
				if (load(employees[i])) {
					ok = true;
				}

				//show error if one of the record is not read correctly

				else {
					cout << "Error: incorrect number of records read; the data is possibly corrupted." << endl;
				}

			}
			closeFile();
		}
		
		//Error message if data file could not be opened

		else {
			cout << "Could not open data file: data_file_name" << endl;
		}

		return ok;
	}


	// TODO: Implementation for the display functions go here
	void display(const Employee& emp) {

		//displaying a single record in the data file

		cout << emp.m_empNo << ": " << emp.m_name<< ", $" << emp.m_salary << endl;
	}

	void display() {
		cout << "Employee Salary report, sorted by employee number" << endl
			<< "no- Empno, Name, Salary" << endl
			<< "------------------------------------------------" << endl;
		sort();

		//displaying all records in the data file using the display function with 1 argument

		for (int i = 0; i < noOfEmployees; i++) {
			cout << i + 1 << "- ";
			display(employees[i]);
		}
	}

	// TODO: Implementation for the deallocateMemory function goes here
	void deallocateMemory()
	{
		for (int i = 0; i < noOfEmployees; i++)
		{
			//first deleting the dynamically allocated names
			delete[] employees[i].m_name;
		}

		//Then deletine the entire object
		delete[] employees;
	}


}