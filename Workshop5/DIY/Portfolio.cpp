/*/////////////////////////////////////////////////////////////////////////
                          Workshop - #5 (P2)
Full Name  : Preet Bhagyesh Patel
Student ID#: 132603226
Email      : pbpatel48@myseneca.ca
Date       : 15 october 2023

Authenticity Declaration:
I have done all the coding by myself and only copied the code that my
professor provided to complete my workshops and assignments.
/////////////////////////////////////////////////////////////////////////*/
#define _CRT_SECURE_NO_WARNINGS

#include "Portfolio.h"
#include<iostream>
#include<cstring>

using namespace std;
namespace sdds {


    Portfolio::Portfolio() {
       emptyPortfolio();
    }

    void Portfolio::emptyPortfolio()
    {
        m_value = 0;
        m_stock[0] = 0;
        m_type = 'E';
    }
    Portfolio::Portfolio(double value, const char* stock, char type) {
        emptyPortfolio();
        if (value >= 0 && ( type == 'V' || type == 'G' || type == 'I') ) {
            m_value = value;
            m_type = type;
            strcpy(m_stock, stock);
        }
    }

    void Portfolio::dispPortfolio() const{
            cout << " ";
            cout.width(10);
            cout << (const char*)(*this);
            cout << " | ";
            cout << "Value: ";
            cout.width(10);
            cout << double(*this);
            cout << " | ";
            cout << " Type: ";
            cout << char(*this);
    }
    std::ostream& Portfolio::display() const {

        if (~*this) {
            cout << " Portfolio  |  Bad-NG |";
            dispPortfolio();
        }
        else if (*this) {
            cout << " Portfolio  |  Active |";
            dispPortfolio();

        }
        else {
            cout << " Portfolio  |  EMPTY  |";
            dispPortfolio();
        }
        return cout;
    }
    Portfolio::operator double()const {
        return m_value;
    }
    Portfolio::operator const char* ()const {
        return m_stock;
    }
    Portfolio::operator char()const {
        return m_type;
    }
    Portfolio::operator bool()const {
        return m_type == 'G' || m_type == 'V' || m_type == 'I';
    }

    Portfolio& Portfolio::operator+=(double ROp){
        if (ROp>0 && *this) {
            m_value += ROp;
        }
            return *this;
    }
    Portfolio& Portfolio::operator -= (double ROp) {
        if (*this && ROp > 0) {
            m_value -= ROp;
        }
        return*this;
    }
    bool Portfolio::operator~()const {
        return m_value < 0;
    }
    Portfolio& Portfolio::operator<<(Portfolio& ROp) {
        if (*this && ROp) {
            m_value += ROp.m_value;
            ROp.emptyPortfolio();
        }
        return *this;
    }
    Portfolio& Portfolio::operator>>(Portfolio& ROp) {
         
            ROp << *this;
            return *this;
    }
    double operator+(const Portfolio& LOp,  Portfolio& ROp){
        double value = 0;
        if (LOp && ROp) {
            value = (double)LOp+(double)ROp;
        }
        return value;
    }
    double operator +=(double& value, const Portfolio& ROp)
    {
        value += double(ROp);
        return value;
    }

}