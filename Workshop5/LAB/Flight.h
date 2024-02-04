/*/////////////////////////////////////////////////////////////////////////
                          Workshop - #5 (P1)
Full Name  : Preet Bhagyesh Patel
Student ID#: 132603226
Email      : pbpatel48@myseneca.ca
Date       : 14 october 2023

Authenticity Declaration:
I have done all the coding by myself and only copied the code that my
professor provided to complete my workshops and assignments.
/////////////////////////////////////////////////////////////////////////*/
#ifndef SDDS_FLIGHT_H
#define SDDS_FLIGHT_H
#include <iostream>

namespace sdds {

   const int Boen747Capacity = 388;
   const int FuelTankCapacity = 238840;

   class Flight {

      int m_passengers = 0;
      double m_fuel = 0;
      char m_title[16];
      void emptyPlane();

   public:
      Flight();
      Flight(int passengers, double fuel, const char* title);
      std::ostream& display()const;
      operator bool() const;
      operator int()const;
      operator double()const;
      operator const char*()const;
      bool operator ~()const;
      Flight& operator =( Flight& ROp);
      Flight& operator=(int ROp);
      Flight& operator=(double ROp);
      Flight& operator+=(double ROp);
      Flight& operator+=(int ROp);
      Flight& operator-=(double ROp);
      Flight& operator-=(int ROp);
      Flight& operator<<(Flight& ROp);
      Flight& operator>>(Flight& ROp);
      int operator+(const Flight& ROp);
   };
      int operator+=(int& a, const Flight& ROp);

}
#endif // SDDS_FLIGHT_H