#include "Date.h"
#include <iostream>
using namespace std;
Date::Date() {}
Date::~Date() {}
bool Date::checkLeapYear()
{
	if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0))
		return true;
	else
		return false;
}
bool Date::checkDate()
{
	//ctime : since 1/1/1970
	if (year < 1970 || year > 9999)
		return false;
	if (month < 1 || month > 12)
		return false;
	if (day < 1 || day > 31)
		return false;
	if (month == 4 || month == 6 || month == 9 || month == 11)
	{
		if (day > 30)
			return false;
	}
	if (month == 2)
	{
		if (checkLeapYear())
		{
			if (day > 29)
				return false;
		}
		else
		{
			if (day > 28)
				return false;
		}
	}
	return true;
}
bool Date::checkRealTime(bool DateType)
{
	//DateType la true thi dung cho NgayNhanPhong , false cho NgayTraPhong
	time_t now = time(0);
	tm *ltm = localtime(&now);
	int realDay = ltm->tm_mday;
	int realMonth = 1 + ltm->tm_mon;
	int realYear = 1900 + ltm->tm_year;
	int realDate = realYear * 10000 + realMonth * 100 + realDay;
	int thisDate = this->year * 10000 + this->month * 100 + this->day;
	if (DateType == true)
		return thisDate <= realDate ? true : false;
	else
		return thisDate >= realDate ? true : false;
}
ostream &operator<<(ostream &o, const Date &d)
{
	if (&d != NULL)
		o << setw(7) << d.day << "/" << setw(2) << d.month << "/" << setw(4) << d.year;
	else
		o << setw(15) << "NULL";
}
istream &operator>>(istream &i, Date &d)
{
	do
	{
		cout << "\n>> Nhap ngay : ";
		i >> d.day;
		cout << ">> Nhap thang : ";
		i >> d.month;
		cout << ">> Nhap nam : ";
		i >> d.year;
		if (!d.checkDate())
			cout << "Ngay thang nam khong hop le ! Nhap lai ! " << endl;
	} while (!d.checkDate());
	return i;
}