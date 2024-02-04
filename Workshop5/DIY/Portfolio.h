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
#ifndef SDDS_Portfolio_H_
#define SDDS_Portfolio_H_
#include<iostream>

namespace sdds {

   class Portfolio {
      double m_value = 0;
      char m_stock[16];
      char m_type;

   public:
       Portfolio();
       void emptyPortfolio();
       Portfolio(double value, const char* stock, char type);
       void dispPortfolio() const;
       std::ostream& display() const;
       operator double()const;
       operator const char* ()const;
       operator char()const;
       operator bool()const;
       Portfolio& operator += (double ROp);
       Portfolio& operator -= (double ROp);
       double getvalue() const;
       bool operator~()const;
       Portfolio& operator<<(Portfolio& ROp);
       Portfolio& operator>>(Portfolio& ROp);

   };
       double operator + (const Portfolio& LOp,  Portfolio & ROp);
       double operator +=(double& value, const Portfolio& ROp);
}
#endif // SDDS_Portfolio_H_