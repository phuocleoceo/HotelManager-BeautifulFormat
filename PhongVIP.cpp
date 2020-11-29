#include "PhongVIP.h"
PhongVip::PhongVip(string MaPhong, int SoNguoiToiDa, bool TinhTrang, Date NgayNhanPhong, Date NgayTraPhong, double GiaPhong, double DonGia)
	: PhongKS(MaPhong, SoNguoiToiDa, TinhTrang, NgayNhanPhong, NgayTraPhong, GiaPhong)
{
	this->DonGia = DonGia;
	this->PhuThuVIP = this->SoNguoiToiDa / 10;
}
PhongVip::~PhongVip() {}