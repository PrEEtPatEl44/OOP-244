
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstdlib>
#include <ctime>
#include "Date.h"
#include "Utils.h"

using namespace std;
namespace sdds
{
    bool Date::validate(){
        bool isvalid = false;
        int year;
        ut.getSystemDate(&year);
        status.clear();
        if (m_year < year || m_year > MAXIMUM_YEAR_VALUE)
        {
            status = "Invalid year in date";
            status = 1;
        }
        else if (m_month < 1 || m_month > 12)
        {
            status = "Invalid month in date";
            status = 2;
        }
        else if (m_day< 1 || m_day > ut.daysOfMon(m_month, m_year))
        {
            status = "Invalid day in date";
            status = 3;
        }
        else if (m_invalid == true)
        {
            status = 0;
            status = "Invalid date value";
        }
        else
        {
            isvalid = true;
        }
        return isvalid;
    }
    const Status& Date::state(){
        return status;
    }
    int Date::uinqiueDateValue() const{
        return m_year * 372 + m_month * 31 + m_day;
    }
    Date::Date(){
        m_invalid = false;
        m_format= true;
        ut.getSystemDate(&m_year, &m_month, &m_day);
    }
    Date::operator bool() const{
        return status;
    }
    Date::Date(int year, int month, int day){
        m_invalid = false;
        m_format = true;
        m_year = year;
        m_month = month;
        m_day = day;
        validate();
    }
    Date& Date::formatted(bool slash){
        if (slash == false)
        {
            m_format = false;
        }
        return *this;
    }
    bool Date::operator==(const Date& ROp) const{
        return this->uinqiueDateValue() == ROp.uinqiueDateValue();
    }
    bool Date::operator!=(const Date& ROp) const{
        return this->uinqiueDateValue() != ROp.uinqiueDateValue();
    }
    bool Date::operator>=(const Date& ROp) const{
        return this->uinqiueDateValue() >= ROp.uinqiueDateValue();
    }
    bool Date::operator<=(const Date& ROp) const{
        return this->uinqiueDateValue() <= ROp.uinqiueDateValue();
    }
    bool Date::operator<(const Date& ROp) const{
        return this->uinqiueDateValue() < ROp.uinqiueDateValue();
    }
    bool Date::operator>(const Date& ROp) const{
        return this->uinqiueDateValue() > ROp.uinqiueDateValue();
    }
    bool notint(bool c){
        return c == true;
    }
    std::istream& Date::read(std::istream& istr){
        int num;
        int day1;
        int day2;
        int month1;
        int month2;
        int year1;
        int year2;
        istr >> num;
        if (istr)
        {
            if (num <= 9999)
            {
                day2 = num % 10;
                day1 = num / 10 % 10;
                month2 = num / 100 % 10;
                month1 = num / 1000 % 10;
                if (month1 == 0)
                {
                    m_month = month2;
                }
                else
                {
                    m_month = (month1 * 10) + month2;
                }
                if (day1 == 0)
                {
                    m_day = day2;
                }
                else
                {
                    m_day = (day1 * 10) + day2;
                }
                ut.getSystemDate(&m_year);
            }
            else if (num >= 100000 && num <= 999999)
            {
                day2 = num % 10;
                day1 = num / 10 % 10;
                month2 = num / 100 % 10;
                month1 = num / 1000 % 10;
                year2 = num / 10000 % 10;
                year1 = num / 100000 % 10;
                if (year1 == 0)
                {
                    m_year = 2000 + year2;
                }
                else
                {
                    m_year = 2000 + ((year1 * 10) + year2);
                }
                if (month1 == 0)
                {
                    m_month = month2;
                }
                else
                {
                    m_month = (month1 * 10) + month2;
                }
                if (day1 == 0)
                {
                    m_day = day2;
                }
                else
                {
                    m_day = (day1 * 10) + day2;
                }
            }
        }
        else
        {
            m_invalid = true;
        }
        if (!validate())
        {
            istr.setstate(ios::badbit);
        }
        return istr;
    }
    std::ostream& Date::print(std::ostream& ostr) const
    {
        if (m_format == true)
        {
            ostr << m_year;
            ostr<< '/';
            ostr.fill('0');
            ostr.width(2);
            ostr<< m_month;
            ostr<< '/';
            ostr.width(2);
            ostr<< m_day;
            ostr.fill(' ');
        }
        else if (m_format == false)
        {
            int year = m_year - 2000;
            ostr<< year;
            ostr.fill('0');
            ostr.width(2);
            ostr<< m_month;
            ostr.width(2);
            ostr<< m_day;
            ostr.fill(' ');
        }
        return ostr;
    }
    std::ostream& operator<<(std::ostream& ostr, const Date& date)
    {
        return date.print(ostr);
    }
    std::istream& operator>>(std::istream& istr, Date& date)
    {
        return date.read(istr);
    }
}