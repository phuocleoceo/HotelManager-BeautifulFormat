#include "Date.h"
#include <iostream>
using namespace std;
Date::Date() {}
Date::~Date() {}
ostream &operator<<(ostream &o, const Date &d)
{
	if (&d != NULL)
		o << "     " << setw(2) << d.day << "/" << setw(2) << d.month << "/" << setw(4) << d.year;
	else
		o << setw(15) << "NULL";
}
istream &operator>>(istream &i, Date &d)
{
	cout << "\n>> Nhap ngay : ";
	i >> d.day;
	cout << ">> Nhap thang : ";
	i >> d.month;
	cout << ">> Nhap nam : ";
	i >> d.year;
	return i;
}
bool Date::checkLeapYear()
{
	time_t now = time(0);
	tm *ltm = localtime(&now);
	int checkDay = ltm->tm_mday;
	int checkMonth = 1 + ltm->tm_mon;
	int checkYear = 1900 + ltm->tm_year;
	return true;
}