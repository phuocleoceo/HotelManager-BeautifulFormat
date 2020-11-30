#ifndef PKS
#define PKS

#include <string>
#include "Date.h"
#include<iostream>
using namespace std;
class PhongKS
{
protected:
	string MaPhong;
	int SoNguoiToiDa;
	bool TinhTrang;
	Date NgayNhanPhong;
	Date NgayTraPhong;
	double GiaPhong;

public:
	PhongKS();
	PhongKS(string, int, bool, Date, Date);
	~PhongKS();
	friend ostream &operator<<(ostream &, const PhongKS &);
	bool operator==(const PhongKS&);
};

#endif