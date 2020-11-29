#include "PhongVIP.h"
enum DonGiaPhongBT
{
	Tang1 = 700000,
	Tang2 = 650000,
	Tang3 = 600000,
	Tang4 = 550000,
	Tang5 = 500000
};

PhongVip::PhongVip(string MaPhong, int SoNguoiToiDa, bool TinhTrang, Date NgayNhanPhong, Date NgayTraPhong)
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
	this->PhuThuVIP = this->SoNguoiToiDa / 10;
	this->GiaPhong = (this->DonGia * this->SoNguoiToiDa) + (this->PhuThuVIP * this->DonGia);
}
PhongVip::~PhongVip() {}