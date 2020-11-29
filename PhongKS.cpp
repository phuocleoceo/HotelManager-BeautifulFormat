#include "PhongKS.h"
PhongKS::PhongKS(string MaPhong, int SoNguoiToiDa, bool TinhTrang, Date NgayNhanPhong, Date NgayTraPhong, double GiaPhong)
{
	this->MaPhong = MaPhong;
	this->SoNguoiToiDa = SoNguoiToiDa;
	this->TinhTrang = TinhTrang;
	this->NgayNhanPhong = NgayNhanPhong;
	this->NgayTraPhong = NgayTraPhong;
	this->GiaPhong = GiaPhong;
}

PhongKS::~PhongKS()
{
}
