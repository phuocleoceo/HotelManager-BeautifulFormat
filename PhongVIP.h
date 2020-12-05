#pragma once
#include "PhongKS.h"
class PhongVIP : public PhongKS
{
private:
	double DonGia;
	double PhuThuVIP;
public:
	PhongVIP();
	~PhongVIP();
	void Input();
	void Output();
};
