#include "PhongBT.h"
enum DonGiaPhongBT{
	

};
PhongBT::
	PhongBT(string MaPhong, int SoNguoiToiDa, bool TinhTrang, Date NgayNhanPhong, Date NgayTraPhong, double GiaPhong, double DonGia)
	: PhongKS(MaPhong, SoNguoiToiDa, TinhTrang, NgayNhanPhong, NgayTraPhong, GiaPhong)
{
	this->DonGia = DonGia;
}
PhongBT::~PhongBT() {}