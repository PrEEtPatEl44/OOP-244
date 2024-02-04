/*/////////////////////////////////////////////////////////////////////////
                          Workshop - #6 (P1)
Full Name  : Preet Bhagyesh Patel
Student ID#: 132603226
Email      : pbpatel48@myseneca.ca
Date       : 4 November 2023

Authenticity Declaration:
I have done all the coding by myself and only copied the code that my
professor provided to complete my workshops and assignments.
/////////////////////////////////////////////////////////////////////////*/


#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string.h>
#include "HealthCard.h"
using namespace std;
namespace sdds
{
    // function to check if the HealthCard ID is valid
    bool HealthCard::validID(const char* name, long long number, const char vCode[], const char sNumber[]) const
    {
        return name && name[0] && number > 999999999 && number < 9999999999 && strlen(vCode) == 2 && strlen(sNumber) == 9;
    }

    // function to set the object to an empty state
    void HealthCard::setEmpty()
    {
        delete[] m_name;
        m_name = nullptr;
    }

    // function to allocate memory for the name and copy the provided name
    void HealthCard::allocateAndCopy(const char* name)
    {
        delete[] m_name;
        m_name = new char[strlen(name) + 1];
        strcpy(m_name, name);
    }

    // function to extract a character from the input stream
    void HealthCard::extractChar(istream& istr, char ch) const
    {
        if (istr.peek() == ch)
            istr.ignore();
        else
        {
            istr.ignore(1000, ch);
            istr.setstate(ios::failbit);
        }
    }

    // function to print the ID information of the HealthCard
    ostream& HealthCard::printIDInfo(ostream& ostr) const
    {
        return ostr << m_number << "-" << m_vCode << ", " << m_sNumber;
    }

    // function to set the HealthCard object with provided data
    void HealthCard::set(const char* name, long long number, const char vCode[], const char sNumber[])
    {
        delete[] m_name;
        m_name = nullptr;
        setEmpty();
        if (validID(name, number, vCode, sNumber))
        {
            allocateAndCopy(name);
            m_number = number;
            strcpy(m_vCode, vCode);
            strcpy(m_sNumber, sNumber);
        }
    }

    // constructor to create a HealthCard object
    HealthCard::HealthCard(const char* name, long long number, const char vCode[], const char sNumber[])
    {
        set(name, number, vCode, sNumber);
    }

    // copy constructor to create a HealthCard object from an existing one
    HealthCard::HealthCard(const HealthCard& hc)
    {
        *this = hc;
    }

    // assignment operator to copy data from one HealthCard object to another
    HealthCard& HealthCard::operator=(const HealthCard& hc)
    {
        if (this != &hc)
        {
            set(hc.m_name, hc.m_number, hc.m_vCode, hc.m_sNumber);
        }
        return *this;
    }

    // destructor to release dynamically allocated memory
    HealthCard::~HealthCard()
    {
        delete[] m_name;
    }

    // conversion operator to check if the HealthCard object is valid
    HealthCard::operator bool() const
    {
        return m_name != nullptr;
    }

    // function to print the HealthCard information
    ostream& HealthCard::print(ostream& ostr, bool toFile) const
    {
        if (*this)
        {
            if (toFile)
            {
                ostr << m_name;
                ostr << ',';
                printIDInfo(ostr);
                ostr << endl;
            }
            else
            {
                ostr.width(50);
                ostr.fill('.');
                ostr.setf(ios::left);
                ostr << m_name;
                printIDInfo(ostr);
            }
        }
        return ostr;
    }

    // function to read HealthCard information from an input stream
    istream& HealthCard::read(istream& istr)
    {
        char name[MaxNameLength]{ '\0' };
        long long number{ 0 };
        char vCode[3]{ 0 };
        char sNumber[10]{ 0 };
        istr.get(name, MaxNameLength, ',');
        extractChar(istr, ',');
        istr >> number;
        extractChar(istr, '-');
        istr.get(vCode, 3, ',');
        extractChar(istr, ',');
        istr.get(sNumber, 10, '\n');
        extractChar(istr, '\n');
        if (istr)
        {
            set(name, number, vCode, sNumber);
        }
        else
        {
            istr.clear();
            istr.ignore(1000, '\n');
        }
        return istr;
    }

    // overloaded insertion operator to print HealthCard information
    ostream& operator<<(ostream& ostr, const HealthCard& hc)
    {
        if (hc)
        {
            hc.print(ostr, false);
        }
        else
        {
            ostr << "Invalid Health Card Record";
        }
        return ostr;
    }

    // overloaded extraction operator to read HealthCard information from an input stream
    istream& operator>>(istream& istr, HealthCard& hc)
    {
        return hc.read(istr);
    }

} 
