#include "PhongBT.h"
enum DonGiaPhongBT
{
	Tang1 = 500000,
	Tang2 = 450000,
	Tang3 = 400000,
	Tang4 = 350000,
	Tang5 = 300000
};
PhongBT::
	PhongBT(string MaPhong, int SoNguoiToiDa, bool TinhTrang, Date NgayNhanPhong, Date NgayTraPhong)
	: PhongKS(MaPhong, SoNguoiToiDa, TinhTrang, NgayNhanPhong, NgayTraPhong)
{
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
PhongBT::~PhongBT() {}