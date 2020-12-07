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
		do
		{
			cout << "Nhap ngay nhan phong : ";
			cin >> *NgayNhanPhong;
			if (NgayNhanPhong->checkRealTime(true) == false)
				cout << "<< Ngay nhan phong phai tinh tu ngay hom nay tro ve truoc ! >>";
		} while (NgayNhanPhong->checkRealTime(true) == false);

		do
		{
			cout << "Nhap ngay tra phong : ";
			cin >> *NgayTraPhong;
			if (NgayTraPhong->checkRealTime(false) == false)
				cout << "<< Ngay tra phong phai tinh tu ngay hom nay tro ve sau ! >>" << endl;
		} while (NgayTraPhong->checkRealTime(false) == false);
	}
}
void PhongKS::Output()
{
	cout << "| " << setw(8) << MaPhong << " | " << setw(15) << SoNguoiToiDa << " | " << setw(10) << TinhTrang
		 << " | " << *NgayNhanPhong << " | " << *NgayTraPhong << " | ";
}