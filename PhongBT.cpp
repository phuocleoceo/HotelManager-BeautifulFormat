#include "PhongBT.h"
enum DonGiaPhongBT
{
	Tang1 = 500000,
	Tang2 = 450000,
	Tang3 = 400000,
	Tang4 = 350000,
	Tang5 = 300000
};
PhongBT::PhongBT() {}
PhongBT::~PhongBT() {}
void PhongBT::Input()
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
	this->GiaPhong = this->DonGia * this->SoNguoiToiDa;
}
void PhongBT::Output()
{
	PhongKS::Output();
	cout << setw(7) << DonGia << " | " << setw(11) << "0"
		 << " | " << setw(15) << GiaPhong << " | " << endl;
}