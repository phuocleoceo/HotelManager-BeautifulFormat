#pragma once
#include "PhongKS.h"
class PhongBT : public PhongKS
{
private:
	double DonGia;
public:
	PhongBT();
	~PhongBT();
	void Input();
	void Output();
};
