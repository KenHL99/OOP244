// Final Project Milestone 1
//
// Version 1.0
// Date
// Author
// Description
//
//
//
//
// Revision History
// -----------------------------------------------------------
// Name               Date                 Reason
/////////////////////////////////////////////////////////////////
#include <iostream>
#include<iomanip>
#include "Date.h"
namespace AMA {
	Date::Date(){
		m_year = 0;
		m_month = 0;
		m_day = 0;
		checkError = NO_ERROR;
	}
	Date::Date(int year, int month, int day){
		bool yearTF = (year >= min_year || year <= max_year) && year > 0;
		int daysofMonth = mdays(month, year);
		bool dayofMonthTF = daysofMonth != 13 && day <= daysofMonth;
		if (yearTF && dayofMonthTF){
			m_year = year;
			m_month = month;
			m_day = day;
			checkError = NO_ERROR;
		}
		else{
			*this = Date();
			checkError = NO_ERROR;
		}
	}
	void Date::errCode(int errorCode){
		checkError = errorCode;
	}
	int Date::errCode() const{
		return checkError;
	}
	bool Date::bad() const{
		return checkError == NO_ERROR;
	}
	bool Date::operator==(const Date& rhs) const{
		bool day = this->m_day == rhs.m_day;
		bool month = this->m_month == rhs.m_month;
		bool year = this->m_year == rhs.m_year;

		return (day && month && year);
	}
	bool Date::operator!=(const Date& rhs) const{
		return !(*this == rhs);
	}
	bool Date::operator<(const Date& rhs) const{
		bool lessYear = this->m_year < rhs.m_year;
		bool lessMonth = this->m_month < rhs.m_month;
		bool lessDay = this->m_day < rhs.m_day;

		if (lessYear){
			return true;
		}
		else if (lessMonth){
			return true;
		}
		else if (lessDay){
			return true;
		}
		else{
			return false;
		}
	}
	bool Date::operator>(const Date& rhs) const{
		return !(*this < rhs);
	}
	bool Date::operator<=(const Date& rhs) const{
		return *this < rhs || *this == rhs;
	}
	bool Date::operator>=(const Date& rhs) const{
		return *this > rhs || *this == rhs;
	}
	std::istream& Date::read(std::istream& istr){
		char datas;
		istr.clear();
		istr >> m_year >> datas >> m_month >> datas >> m_day;

		if (istr.fail())
		{
			*this = Date();
			errCode(CIN_FAILED);
		}
		else if (min_year > m_year || m_year > max_year)
		{
			*this = Date();
			errCode(YEAR_ERROR);
		}
		else if (1 > m_month || m_month > 12)
		{
			*this = Date();
			errCode(MON_ERROR);
		}
		else if (m_day > mdays(m_month, m_year))
		{
			*this = Date();
			errCode(DAY_ERROR);
		}

		//istr.clear();
		return istr;
	}

	std::ostream& Date::write(std::ostream& ostr) const
	{
		ostr << m_year << "/";
		if (m_month <= 10)
		{
			ostr << "0" << m_month << "/";
			if (m_day <= 10) {
				ostr << "0" << m_day;
			}
			else {
				ostr << m_day;
			}
		}
		else {
			ostr << m_day << "/";
			if (m_day <= 10) {
				ostr << "0" << m_day;
			}
			else {
				ostr << m_day;
			}
		}
		return ostr;
	}

	std::istream& operator>>(std::istream& istr, Date& overO)
	{
		return overO.read(istr);
	}

	std::ostream& operator<<(std::ostream& ostr, Date& overI)
	{
		return overI.write(ostr);
	}




	  // number of days in month mon_ and year year_
	  //
	  int Date::mdays(int mon, int year)const {
		int days[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31, -1 };
		int month = mon >= 1 && mon <= 12 ? mon : 13;
		month--;
		return days[month] + int((month == 1)*((year % 4 == 0) && (year % 100 != 0)) || (year % 400 == 0));
	}



}
