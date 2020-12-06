#include "PhongKS.h"
PhongKS::PhongKS()
{
	NgayNhanPhong = new Date;
	NgayTraPhong = new Date;
}
PhongKS::~PhongKS()
{
	delete NgayNhanPhong;
	delete NgayTraPhong;
}
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
	cout << "Nhap tinh trang (1: Trong ; 0: Da co khach) : ";
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
		do
		{
			cout << "Nhap ngay tra phong : ";
			cin >> *NgayTraPhong;
			if (NgayTraPhong->checkRealTime() == false)
				cout << "<<Ngay tra phong phai tinh tu ngay hom nay tro di ! " << endl;
		} while (NgayTraPhong->checkRealTime() == false);
	}
}
void PhongKS::Output()
{
	cout << "| " << setw(8) << MaPhong << " | " << setw(15) << SoNguoiToiDa << " | " << setw(10) << TinhTrang
		 << " | " << *NgayNhanPhong << " | " << *NgayTraPhong << " | ";
}