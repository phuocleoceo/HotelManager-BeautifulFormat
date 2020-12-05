#pragma once
#include "PhongKS.h"
class PhongBT : public PhongKS
{
private:
	double DonGia;
public:
	PhongBT();
	~PhongBT();
	virtual void Input();
	virtual void Output();
};
