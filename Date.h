#include <iostream>
#include <ctime>
#include <iomanip>
using namespace std;
class Date
{
private:
	int day;
	int month;
	int year;

public:
	Date();
	~Date();
	bool checkLeapYear();
	bool checkDate();
	friend ostream &operator<<(ostream &, const Date &);
	friend istream &operator>>(istream &, Date &);
};