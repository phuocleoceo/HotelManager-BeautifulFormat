#include <iostream>
#include "UI.h"
using namespace std;
int main()
{
	int FLAG;
	do
	{
		PrintMenu();
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