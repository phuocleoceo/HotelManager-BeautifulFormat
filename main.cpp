#include <iostream>
#include "QLPhong.h"
using namespace std;
int main()
{
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
		cout << "------------------------------------------------------------------------" << endl;
		switch (FLAG)
		{
		case 1:
			break;
		case 2:
			break;
		case 3:
			break;
		case 4:
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