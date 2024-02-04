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

#ifndef SDDS_IPRODUCT_H
#define SDDS_IPRODUCT_H

namespace sdds
{
	class iProduct
	{
	private:
		char* test{};
	public:
		// to read the Stock-Keeping Unit from the console before
	// main data entry
		virtual int readSku(std::istream& istr);
		// to reduce the quantity on hand
		virtual int operator-=(int qty);
		// to increase the quantity on hand
		virtual int operator+=(int qty);
		// returns the price of the produce
		virtual operator double()const;
		// returns if the iProduct is in a good state
		virtual operator bool()const;
		// returns the number of products needed
		virtual int qtyNeeded()const;
		// returns the quantity on hand
		virtual int qty()const;
		// determines if the iProduct is displayed in a linear format or 
		// descriptive format
		virtual void linear(bool isLinear);
		// saves the iProduct into a file
		virtual std::ofstream& save(std::ofstream& ofstr)const=0;
		// loads an iProduct from a file
		virtual std::ifstream& load(std::ifstream& ifstr)=0;
		// displays the iProduct on the screen
		virtual std::ostream& display(std::ostream& ostr)const=0;
		// reads the iProduct from the console
		virtual std::istream& read(std::istream& istr)=0;
		// return true if the SKU is a match to the iProduct's SKU
		virtual bool operator==(int sku)const;
		// returns true if the description is found in the iPorduct's description
		virtual bool operator==(const char* description)const;

		virtual ~iProduct();
	};
	std::ostream& operator<< (std::ostream& ostr, const iProduct& product);
	std::istream& operator>> (std::istream& istr, iProduct& product);
}
#endif//IPRODUCT_H