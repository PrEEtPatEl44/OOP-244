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
#define _CRT_SECURE_NO_WARNINGS
#include <cstring>
#include "Flight.h"

using namespace std;
namespace sdds {

    void Flight::emptyPlane() {
        m_passengers = 0;
        m_fuel = 0;
        strcpy(m_title , "EmptyPlane");
    }

    // New Flight
    Flight::Flight() {
        emptyPlane();
    }
    Flight::Flight(int passengers, double fuel, const char* title) {
        emptyPlane();
        if (passengers > 0 && passengers <= Boen747Capacity && fuel >= 0 &&
            fuel <= FuelTankCapacity) {
            m_passengers = passengers;
            m_fuel = fuel;
            strcpy(m_title,title);
        }
    }
    std::ostream& Flight::display() const {

        if (*this) {
            cout << " Flight  |  Ready to Depart";
            cout << " ";
            cout.width(10);
            cout << std::string(*this);
            cout << " | ";
            cout << "Pass: ";
            cout.width(10);
            cout << int(*this);
            cout << " | ";
            cout.width(12);
            cout.precision(2);
            cout.setf(ios::right);
            cout.setf(ios::fixed);
            cout << double(*this);
            cout.unsetf(ios::right);
            cout << " Liters";
        }
        else if (~*this) {
            cout << " Flight  |  Empty Plane    ";
        }
        else {
            cout << " Flight  |  Low Fuel       ";
            cout << " ";
            cout.width(10);
            cout << (const char *)(*this);
            cout << " | ";
            cout << "Pass: ";
            cout.width(10);
            cout << int(*this);
            cout << " | ";
            cout.width(12);
            cout.precision(2);
            cout.setf(ios::right);
            cout.setf(ios::fixed);
            cout << double(*this);
            cout.unsetf(ios::right);
            cout << " Liters";
        }
        return cout;
    }

    Flight::operator bool() const{
        return ((m_passengers > 0) && (m_fuel >= 600 * m_passengers));
    }

    Flight::operator int() const{
        return m_passengers;
    }
    Flight::operator double()const {
        return m_fuel;
    }
    Flight::operator const char* ()const {
        return m_title;
    }
    bool Flight::operator ~()const{
        return m_passengers == 0;
    }
    Flight& Flight::operator=(Flight& ROp){
        m_passengers = ROp.m_passengers;
        m_fuel = ROp.m_fuel;
        strcpy(m_title, ROp.m_title);
        ROp.emptyPlane();
        return *this;
    }
    Flight& Flight::operator=(int ROp) {
        if (ROp > 0 && ROp <= Boen747Capacity) {
            m_passengers = ROp;
        }
        return *this;
    }
    Flight& Flight::operator=(double ROp) {
        if (ROp > 0 && ROp < FuelTankCapacity) {
            m_fuel = ROp;
        }
        return *this;
    }
    Flight& Flight::operator+=(double ROp) {
        if(ROp>0 && m_fuel<FuelTankCapacity){
            m_fuel += ROp;
        }
        return *this;   
    }
    Flight& Flight::operator+=(int ROp) {
        if (ROp > 0 && m_passengers < Boen747Capacity) {
            m_passengers += ROp;
        }
        return *this;
    }
    Flight& Flight::operator-=(double ROp) {
        if (ROp > 0 && m_fuel > 0) {
            m_fuel -= ROp;
        }
        return *this;
    }
    Flight& Flight::operator-=(int ROp) {
        if (ROp > 0 && m_passengers > 0) {
            m_passengers -= ROp;
        }
        return *this;
    }
    Flight& Flight::operator<<(Flight& ROp) {
        if (*this && ROp) {///// !=0
            int totalPassengers = m_passengers + ROp.m_passengers;
            if (totalPassengers <= Boen747Capacity) {
                m_passengers = totalPassengers;
                ROp.m_passengers = 0;
            }
            else if(totalPassengers>Boen747Capacity){
                m_passengers = Boen747Capacity;
                ROp.m_passengers = totalPassengers - Boen747Capacity;
            }
        }
        return *this;
    }
    Flight& Flight::operator>>(Flight& ROp) {
        ROp << *this;
        return *this;
    }

    int Flight::operator+( const Flight& ROp){
        if (*this && ROp) {
            return (int)*this + (int)ROp;
        }
        return 0;
    }
    int operator+=(int& a, const Flight& ROp) {
        a+=(int)ROp;
        return a;
    }

}   