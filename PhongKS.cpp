#include "PhongKS.h"
PhongKS::PhongKS()
{
	NgayNhanPhong = new Date;
	NgayTraPhong = new Date;
}
PhongKS::~PhongKS() {}
string PhongKS::getMSP() const
{
	return this->MaPhong;
}
void PhongKS::Input()
{
	cout << "Nhap ma phong : ";
	cin.ignore();
	getline(cin, MaPhong);
	cout << "Nhap so nguoi toi da : ";
	cin >> SoNguoiToiDa;
	cout << "Nhap tinh trang (1 hoac 0) : ";
	cin >> TinhTrang;
	if (TinhTrang == true)
	{
		NgayNhanPhong = NULL;
		NgayTraPhong = NULL;
	}
	else
	{
		cout << "Nhap ngay nhan phong : ";
		cin >> *NgayNhanPhong;
		cout << "Nhap ngay tra phong : ";
		cin >> *NgayTraPhong;
	}
}
void PhongKS::Output()
{
	cout << "Ma phong\t"
		 << "So nguoi toi da\t"
		 << "Tinh trang\t"
		 << "Ngay nhan phong\t"
		 << "Ngay tra phong\t"
		 << "Don gia\t"
		 << "Phu thu VIP\t"
		 << "Gia phong" << endl;
	cout << MaPhong << "\t" << SoNguoiToiDa << "\t" << TinhTrang
		 << "\t" << *NgayNhanPhong << "\t" << *NgayTraPhong << "\t";
}