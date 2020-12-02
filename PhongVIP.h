#pragma once
#include "PhongKS.h"
class PhongVip : public PhongKS
{
private:
	double DonGia;
	double PhuThuVIP;
public:
	PhongVip();
	~PhongVip();
	void Input();
	void Output();
};
