/*/////////////////////////////////////////////////////////////////////////
						  Milestone: 3
Full Name  : Preet Bhagyesh Patel
Student ID#: 132603226
Email      : pbpatel48@myseneca.ca
Date       : 26 ovember 2023

Authenticity Declaration:
I have done all the coding by myself and only copied the code that my
professor provided to complete my workshops and assignments.
/////////////////////////////////////////////////////////////////////////*/
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include <string>
#include <iomanip>
#include <fstream>
#include "Item.h"
#include "Utils.h"

using namespace std;
namespace sdds
{

	Item::Item() : iProduct()
	{
		m_price = 0;
		m_qty = 0;
		m_neededQty = 0;
		m_desc = nullptr;
		state = nullptr;
		m_flag = false;
	}
	int Item::readSku(std::istream& is)
	{
		unitNum = ut.getint(40000, 99999, "SKU: ");
		return unitNum;
	}
	void Item::linear(bool valid)
	{
		m_flag = valid;
	}
	int Item::qtyNeeded() const
	{
		return this->m_neededQty;
	}
	int Item::qty() const
	{
		return this->m_qty;
	}
	Item::operator double() const
	{
		return m_price;
	}
	Item::operator bool() const
	{
		bool valid = false;
		if (state == nullptr)
		{
			valid = true;
		}
		return valid;
	}
	int Item::operator-=(int value)
	{
		return this->m_qty -= value;
	}
	int Item::operator+=(int value)
	{
		return this->m_qty += value;
	}
	void Item::linear()
	{
		if (m_flag == false)
		{
			m_flag = true;
		}
		else
		{
			m_flag = false;
		}
		//m_flag = false;
	}
	bool Item::operator==(int sku)const
	{
		bool valid = false;
		if (unitNum == sku)
		{
			valid = true;
		}
		return valid;
	}
	bool Item::operator==(const char* description)const
	{
		bool valid = false;
		if (ut.strStr(m_desc, description) != nullptr)
		{
			valid = true;
		}
		return valid;
	}
	std::ofstream& Item::save(std::ofstream& ofstr)const
	{
		if ((int)state == 0)//state==nullpyr
		{
			ofstr << unitNum << "\t" << m_desc << "\t" << m_qty
				<< "\t" << m_neededQty << "\t" << m_price << endl;
		}
		ofstr.close();
		return ofstr;
	}
	std::ifstream& Item::load(std::ifstream& ifstr)
	{
		int sku;
		int qty;
		int qtyneeded;
		double price;
		//delete[] m_desc;
		char descr[400];
		if (ifstr.fail())
		{
			cout << "Input file stream read failed!" << endl;
		}
		else if (!ifstr.eof())
		{
			ifstr >> sku;
			ifstr.ignore(1000, '\t');
			ifstr.get(descr, 400, '\t');
			ifstr.ignore(1000, '\t');
			ifstr >> qty;
			ifstr.ignore(1000, '\t');
			ifstr >> qtyneeded;
			ifstr.ignore(1000, '\t');
			ifstr >> price;
			ifstr.ignore(1000, '\t'); \
					/*m_desc = new char[strlen(descr) + 1];
				strcpy(m_desc, descr);*/
				ut.alocpy(m_desc, descr);//alocpy first delets the m_desc
			unitNum = sku;
			m_neededQty = qtyneeded;
			m_qty = qty;
			m_price = price;
		}
		return ifstr;
	}
	std::ostream& Item::display(std::ostream& ostr)const
	{////////////////////////////////////////////////////////////////////////////////////////does not checks is state is good or not
		if (state == nullptr) {
			if (m_flag == true)
			{
				ostr << setw(5) << unitNum << " | " << left;
				if (strlen(m_desc) > 35)
				{
					for (int i = 0; i < 35; i++)
						ostr << left << m_desc[i];
				}
				else
				{
					ostr << left << setw(35) << m_desc;
				}
				ostr << " |"
					<< right << setw(5) << m_qty << " |" << setw(5) << m_neededQty << " |";
				ostr << setw(8) << fixed << setprecision(2) << m_price << " |";
			}
			else
			{
				ostr << "AMA Item:" << endl;
				ostr << unitNum << ": " << m_desc << endl;
				ostr << "Quantity Needed: " << m_neededQty << endl;
				ostr << "Quantity Available: " << m_qty << endl;
				ostr << "Unit Price: $" << m_price << endl;
				double needToBuy = m_price * (m_neededQty - m_qty);
				ostr << "Needed Purchase Fund: $" << fixed << setprecision(2) << needToBuy << endl;
			}
		}
		else {
			ostr<<m_desc;
		}
		return ostr;
	}
	std::istream& Item::read(std::istream& istr)
	{
		char descr[400];
		int m_flag = 1;
		double price;
		//delete[] m_desc;
		state.clear();
		cout << "AMA Item:" << endl;
		cout << "SKU: " << unitNum << endl;
		cout << "Description: ";
		istr >> descr;
		if (istr.fail())
		{
			cout << "Console entry failed!" << endl;
		}
		/*m_desc = new char[strlen(descr) + 1];
		strcpy(m_desc, descr);*/
		ut.alocpy(m_desc, descr);
		m_neededQty = ut.getint(1, 9999, "Quantity Needed: ");
		m_qty = ut.getint(0, m_neededQty, "Quantity On Hand: ");
		cout << "Unit Price: $";
		while (m_flag)
		{
			istr >> price;
			if (price > 9999.0 || price < 0.0)
			{
				cout << "Value out of range [0.00<=val<=9999.00]: ";
			}
			else if (istr.fail())
			{
				cout << "Invalid number, retry: ";
				istr.clear();
				istr.ignore(1000, '\n');
			}
			else if (price <= 9999.0 && price >= 0.0)
			{
				m_flag = 0;
				m_price = price;
			}
		}

		return istr;
	}
	void Item::clear()
	{
		m_price = 0;
		m_qty = 0;
		m_neededQty = 0;
		state = nullptr;
	}
	Item::~Item()
	{
		delete[] m_desc;
	}
}
