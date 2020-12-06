#include "PhongVIP.h"
enum DonGiaPhongVIP
{
	Tang1 = 700000,
	Tang2 = 650000,
	Tang3 = 600000,
	Tang4 = 550000,
	Tang5 = 500000
};

PhongVIP::PhongVIP() {}
PhongVIP::~PhongVIP() {}
void PhongVIP::Input()
{
	PhongKS::Input();
	switch (MaPhong[0])
	{
	case '1':
		this->DonGia = Tang1;
		break;
	case '2':
		this->DonGia = Tang2;
		break;
	case '3':
		this->DonGia = Tang3;
		break;
	case '4':
		this->DonGia = Tang4;
		break;
	case '5':
		this->DonGia = Tang5;
		break;
	}
	this->PhuThuVIP = (double)(this->SoNguoiToiDa) / 10;
	this->GiaPhong = (this->DonGia * this->SoNguoiToiDa) + (this->PhuThuVIP * this->DonGia);
}
void PhongVIP::Output()
{
	PhongKS::Output();
	cout << setw(7) << DonGia << " | " << setw(11) << PhuThuVIP << " | ";
	cout << setw(15) << fixed << setprecision(0) << GiaPhong << " | " << endl;
	cout << "+----------+-----------------+------------+-----------------+-----------------+---------+-------------+-----------------+" << endl;
}