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
#ifndef SDDS_ITEM_H
#define SDDS_ITEM_H
#include "iProduct.h"
#include "Status.h"

namespace sdds
{
	class Item : public iProduct
	{
	private:
		double m_price;
		int m_qty;
		int m_neededQty;
		char* m_desc;
	protected:
		bool m_flag;
		Status state;
		int unitNum;
		void linear(bool valid);
	public:
		Item();
		int readSku(std::istream& is);
		int qtyNeeded() const;
		int qty() const;
		operator double() const;
		operator bool() const;
		int operator-=(int value);
		int operator+=(int value);
		void linear();
		bool operator==(int sku)const;
		bool operator==(const char* description)const;
		std::ofstream& save(std::ofstream& ostr) const override;
		std::ifstream& load(std::ifstream& istr) override;
		std::ostream& display(std::ostream& ostr) const override;
		std::istream& read(std::istream& istr) override;
		void clear();
		virtual ~Item();
	};

	

}

#endif//ITEM_H