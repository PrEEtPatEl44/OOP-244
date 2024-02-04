/*/////////////////////////////////////////////////////////////////////////
//						  Milestone: 3
//Full Name  : Preet Bhagyesh Patel
//Student ID#: 132603226
//Email      : pbpatel48@myseneca.ca
//Date       : 26 ovember 2023
//
//Authenticity Declaration:
//I have done all the coding by myself and only copied the code that my
//professor provided to complete my workshops and assignments.
///////////////////////////////////////////////////////////////////////////*/
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "iProduct.h"

using namespace std;
namespace sdds
{
	
	int iProduct::readSku(std::istream& istr)
	{
		cout << "readSku" << endl;
		return 0;
	}
	
	int iProduct::operator-=(int qty)
	{
		cout << "operator-=" << endl;
		return 0;
	}
	
	int iProduct::operator+=(int qty)
	{
		cout << "operator+=" << endl;
		return 0;
	}
	
	iProduct::operator double()const
	{
		cout << "operator double" << endl;
		return 0.;
	}
	
	iProduct::operator bool()const
	{
		cout << "operator bool" << endl;
		return false;
	}
	
	int iProduct::qtyNeeded()const
	{
		cout << "qtyNeeded" << endl;
		return 0;
	}
	
	int iProduct::qty()const
	{
		cout << "qty" << endl;
		return 0;
	}
	
	void iProduct::linear(bool isLinear)
	{
		cout << "Linear" << endl;
	}
	
	std::ofstream& iProduct::save(std::ofstream& ofstr)const
	{
		cout << "save" << endl;
		return ofstr;
	}
	
	std::ifstream& iProduct::load(std::ifstream& ifstr)
	{
		cout << "load" << endl;
		return ifstr;
	}
	
	std::ostream& iProduct::display(std::ostream& ostr)const
	{
		operator bool();
		operator double();
		qtyNeeded();
		qty();
		operator==("");
		operator== (2);
		return ostr;
	}
	
	std::istream& iProduct::read(std::istream& istr)
	{
		operator+=(1);
		operator-=(1);
		readSku(istr);
		linear(true);
		test = new char[2345];
		return istr;
	}
	
	bool iProduct::operator==(int sku)const
	{
		cout << "operator==" << endl;
		return false;
	}
	
	bool iProduct::operator==(const char* description)const
	{
		cout << "operator==(cosnt char*)" << endl;
		return false;
	}
	iProduct::~iProduct()
	{
		delete[] test;
	}
	std::ostream& operator<< (std::ostream& ostr, const iProduct& product)
	{
		return product.display(ostr);
	}
	std::istream& operator>> (std::istream& istr, iProduct& product)
	{
		return product.read(istr);
	}
}