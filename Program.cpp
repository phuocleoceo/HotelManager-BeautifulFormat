#include <iostream>
#include "QLPhong.cpp"
#include "PhongVIP.h"
#include "PhongBT.h"
using namespace std;
int main()
{
	QLPhong<PhongKS> *qlp = new QLPhong<PhongKS>;
	string MSP;
	int FLAG;
	do
	{
		cout << "*========================Moi ban chon:=================================*" << endl;
		cout << "+-----------------------------+------------------------------+---------+" << endl;
		cout << "|      1. Them Phong          |      2. Sua Phong            |         |" << endl;
		cout << "|-----------------------------|------------------------------|         |" << endl;
		cout << "|      3. Xoa Phong           |      4. Hien Thi DS Phong    | 0.Thoat |" << endl;
		cout << "|-----------------------------|------------------------------|         |" << endl;
		cout << "|      5. Tim Kiem Phong      |      6. Sap Xep              |         |" << endl;
		cout << "+-----------------------------+------------------------------+---------+" << endl;

		cout << "\nLua chon cua ban la : ";
		cin >> FLAG;
		system("cls");
		cout << "------------------------------------------------------------------------" << endl;
		switch (FLAG)
		{
		case 1:
			qlp->Input();
			break;
		case 2:
			cout<<"Nhap ma so phong can sua : ";
			cin.ignore();
			getline(cin,MSP);
			qlp->Update(MSP);
			break;
		case 3:
			break;
		case 4:
			cout << *qlp;
			break;
		case 5:
			break;
		case 6:
			break;
		}
		cout << "------------------------------------------------------------------------" << endl;
	} while (FLAG != 0);

	return 0;
}