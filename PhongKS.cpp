#include "PhongKS.h"
PhongKS::PhongKS(string MaPhong, int SoNguoiToiDa, bool TinhTrang, Date NgayNhanPhong, Date NgayTraPhong)
{
	this->MaPhong = MaPhong;
	this->SoNguoiToiDa = SoNguoiToiDa;
	this->TinhTrang = TinhTrang;
	this->NgayNhanPhong = NgayNhanPhong;
	this->NgayTraPhong = NgayTraPhong;
}

PhongKS::~PhongKS()
{
}
