#include <iostream>
#include "QuanLyPhong.cpp"
#include "PhongVIP.h"
#include "PhongBT.h"
using namespace std;
int main()
{
	QuanLyPhong<PhongKS> *qlp = new QuanLyPhong<PhongKS>;
	string MSP;
	int FLAG;
	while (true)
	{
		try
		{
			cout << "*========================Moi ban chon:=================================*" << endl;
			cout << "+-----------------------------+------------------------------+---------+" << endl;
			cout << "|      1. Them Phong          |      2. Sua Phong            |         |" << endl;
			cout << "|-----------------------------|------------------------------|         |" << endl;
			cout << "|      3. Xoa Phong           |      4. Hien Thi DS Phong    | 0.Thoat |" << endl;
			cout << "|-----------------------------|------------------------------|         |" << endl;
			cout << "|      5. Tim Kiem Phong      |      6. Sap Xep              |         |" << endl;
			cout << "+-----------------------------+------------------------------+---------+" << endl;

			cout << "\n>>Lua chon cua ban la : ";
			cin >> FLAG;
			cout << "--------------------------------------------------------------------------------------------------------------------------" << endl;
			switch (FLAG)
			{
			case 0:
				return 0;
				break;
			case 1:
				cin >> *qlp;
				break;
			case 2:
				cout << ">>Nhap ma so phong can sua : ";
				cin.ignore();
				getline(cin, MSP);
				qlp->Update(MSP);
				break;
			case 3:
				cout << ">>Nhap ma so phong can xoa : ";
				cin.ignore();
				getline(cin, MSP);
				qlp->RemoveAt(qlp->IndexOf(MSP));
				break;
			case 4:
				cout << *qlp;
				break;
			case 5:
				cout << ">>Nhap ma so phong can tim : ";
				cin.ignore();
				getline(cin, MSP);
				qlp->Search(MSP);
				break;
			case 6:
				qlp->Sort();
				break;
			default:
				throw string(">> Lua chon khong hop le ! <<");
				break;
			}
			cout << "--------------------------------------------------------------------------------------------------------------------------" << endl;
		}
		catch (string &e)
		{
			cout << e << endl;
		}
	}

	return 0;
}