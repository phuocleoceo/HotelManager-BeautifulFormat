#include "PhongKS.h"
PhongKS::PhongKS() {}
PhongKS::PhongKS(string MaPhong, int SoNguoiToiDa, bool TinhTrang, Date NgayNhanPhong, Date NgayTraPhong)
{
	this->MaPhong = MaPhong;
	this->SoNguoiToiDa = SoNguoiToiDa;
	this->TinhTrang = TinhTrang;
	this->NgayNhanPhong = NgayNhanPhong;
	this->NgayTraPhong = NgayTraPhong;
}
PhongKS::~PhongKS() {}
string PhongKS::getMSP() const
{
	return this->MaPhong;
}
ostream &operator<<(ostream &o, const PhongKS &p)
{
	o << p.MaPhong << "\t" << p.SoNguoiToiDa << "\t" << p.TinhTrang
	  << "\t" << p.NgayNhanPhong << "\t" << p.NgayTraPhong << "\t" << p.GiaPhong << endl;
}