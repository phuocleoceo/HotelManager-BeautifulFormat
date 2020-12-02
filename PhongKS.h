#pragma once
#include <string>
#include "Date.h"
#include <iostream>
using namespace std;
class PhongKS
{
protected:
	string MaPhong;
	int SoNguoiToiDa;
	bool TinhTrang;
	Date *NgayNhanPhong;
	Date *NgayTraPhong;
	double GiaPhong;

public:
	PhongKS();
	~PhongKS();
	string getMSP() const;
	virtual void Input();
	virtual void Output();
};