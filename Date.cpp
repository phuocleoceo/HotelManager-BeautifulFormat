#include "Date.h"
#include <iostream>
using namespace std;
Date::Date() {}
Date::~Date() {}
ostream &operator<<(ostream &o, const Date &d)
{
	o << d.day << "/" << d.month << "/" << d.year;
}
istream &operator>>(istream &i, Date &d)
{
	cout << "Nhap ngay : ";
	i >> d.day;
	cout << "Nhap thang : ";
	i >> d.month;
	cout << "Nhap nam : ";
	i >> d.year;
	return i;
}