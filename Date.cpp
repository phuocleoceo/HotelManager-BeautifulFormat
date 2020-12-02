#include "Date.h"
#include <iostream>
using namespace std;
Date::Date()
{
	day = 1;
	month = 1;
	year = 1900;
}
Date::Date(int day, int month, int year)
{
	if (day >= 1 && day <= 31 && month >= 1 && month <= 12 && year >= 1900 && year <= 2020)
	{
		this->day = day;
		this->month = month;
		this->year = year;
	}
	else
		cout << "Ngay thang nam khong hop le !" << endl;
}
Date::~Date() {}
ostream &operator<<(ostream &o, const Date &d)
{
	o << d.day << " / " << d.month << " / " << d.year << endl;
}
istream &operator>>(istream &i, Date &d)
{
	cout << "Nhap ngay : ";
	i >> d.day;
	cout << "Nhap thang : ";
	i >> d.month;
	cout << "Nhap nam : ";
	i >> d.year;
}