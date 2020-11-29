#include <iostream>
#include "QLPhong.h"
using namespace std;
int main()
{	
	
	int FLAG;
	do
	{
		cout << "*==========Moi ban chon:=======*" << endl;
		cout << "+------------------------------+" << endl;
		cout << "|       1. Them Phong          |" << endl;
		cout << "+------------------------------+" << endl;
		cout << "|       2. Sua Phong           |" << endl;
		cout << "+------------------------------+" << endl;
		cout << "|       3. Xoz Phong           |" << endl;
		cout << "+------------------------------+" << endl;
		cout << "|       4. Hien Thi DS Phong   |" << endl;
		cout << "+------------------------------+" << endl;
		cout << "|       5.Tim Kiem Phong       |" << endl;
		cout << "+------------------------------+" << endl;
		cout << "|       6.Sap Xep              |" << endl;
		cout << "+------------------------------+" << endl;
		cout << "|       0.Thoat                |" << endl;
		cout << "+------------------------------+" << endl;
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