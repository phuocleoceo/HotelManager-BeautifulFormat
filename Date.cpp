#include "Date.h"
#include <iostream>
using namespace std;
Date::Date() {}
Date::~Date() {}
ostream &operator<<(ostream &o, const Date &d)
{
	if (&d != NULL)
		o << d.day << "/" << d.month << "/" << d.year;
	else
		o << "    NULL  ";
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