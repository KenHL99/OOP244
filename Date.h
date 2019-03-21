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
#ifndef AMA_DATE_H
#define AMA_DATE_H

#define NO_ERROR 0
#define CIN_FAILED 1
#define YEAR_ERROR 2
#define MON_ERROR 3
#define DAY_ERROR 4

namespace AMA {
	const int min_year = 2000;
	const int max_year = 2030;
  class Date {
	  
  public:
	  int m_year;
	  int m_month;
	  int m_day;
	  int m_comparator;
	  int checkError;
	  void errCode(int errorCode);
	  int mdays(int, int)const;
	  Date();
	  Date(int year, int month, int day);
	  int errCode() const;
	  bool bad() const;
	  bool operator==(const Date& rhs) const;
	  bool operator!=(const Date& rhs) const;
	  bool operator<(const Date& rhs) const;
	  bool operator>(const Date& rhs) const;
	  bool operator<=(const Date& rhs) const;
	  bool operator>=(const Date& rhs) const;
	  std::istream& read(std::istream& istr);
	  std::ostream& write(std::ostream& ostr) const;
  };
  std::ostream& operator<<(std::ostream& ostr, Date&);
  std::istream& operator>>(std::istream& istr, Date&);




}
#endif