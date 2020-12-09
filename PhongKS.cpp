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
bool CheckMSP(string MSP)
{
	if (MSP.length() != 5)
		return false;
	int CheckValue = 0;
	for (int i = 0; i < MSP.length(); i++)
	{
		//Lay chu so nay nhan 10 cong chu so sau ( trong ASCII thi 1=49)
		CheckValue = CheckValue * 10 + ((int)MSP[i] - 48);
	}
	if (CheckValue >= 10000 && CheckValue <= 59999)
		return true;
	else
		return false;
}
void PhongKS::Input()
{
	while (true)
	{
		try
		{
			cout << "Nhap ma phong ( 10000 -> 59999 ) : ";
			getline(cin, MaPhong);
			if (!CheckMSP(MaPhong))
				throw string(">> Ma phong khong hop le ! <<");
			else
				break;
		}
		catch (string &e)
		{
			cout << e << endl;
		}
	}

	while (true)
	{
		try
		{
			cout << "Nhap so nguoi toi da ( 1 -> 4 ): ";
			cin >> SoNguoiToiDa;
			if (SoNguoiToiDa < 1 || SoNguoiToiDa > 4)
				throw string(">> So nguoi toi da phai tu 1 -> 4 ! <<");
			else
				break;
		}
		catch (string &e)
		{
			cout << e << endl;
		}
	}

	while (true)
	{
		try
		{
			cout << "Nhap tinh trang (1: Trong ; 0: Da co khach) : ";
			int Status;
			cin >> Status;
			if (Status != 0 && Status != 1)
				throw string(">>Tinh trang khong hop le ! <<");
			else
			{
				(Status == 0) ? TinhTrang = false : TinhTrang = true;
				break;
			}
		}
		catch (string &e)
		{
			cout << e << endl;
		}
	}

	if (TinhTrang == true)
	{
		NgayNhanPhong = NULL;
		NgayTraPhong = NULL;
	}
	else
	{
		while (true)
		{
			try
			{
				cout << "Nhap ngay nhan phong : ";
				cin >> *NgayNhanPhong;
				if (NgayNhanPhong->checkRealTime(true) == false)
					throw string(">> Ngay nhan phong phai tinh tu ngay hom nay tro ve truoc ! <<");
				else
					break;
			}
			catch (string &e)
			{
				cout << e << endl;
			}
		}

		while (true)
		{
			try
			{
				cout << "Nhap ngay tra phong : ";
				cin >> *NgayTraPhong;
				if (NgayTraPhong->checkRealTime(false) == false)
					throw string(">> Ngay tra phong phai tinh tu ngay hom nay tro ve sau ! <<");
				else
					break;
			}
			catch (string &e)
			{
				cout << e << endl;
			}
		}
	}
}
void PhongKS::Output()
{
	cout << "| " << setw(8) << MaPhong << " | " << setw(15) << SoNguoiToiDa << " | " << setw(10) << TinhTrang
		 << " | " << *NgayNhanPhong << " | " << *NgayTraPhong << " | ";
}
