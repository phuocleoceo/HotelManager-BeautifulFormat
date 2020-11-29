#ifndef  PKS
#define  PKS

#include <string>
#include "Date.h"
using namespace std;
class PhongKS
{
protected:
	string MaPhong;
	int SoNguoiToiDa;
	bool TinhTrang;
	Date NgayNhanPhong;
	Date NgayTraPhong;
	double GiaPhong;
public:
	PhongKS(string,int,bool,Date,Date,double);
	~PhongKS();
};

#endif