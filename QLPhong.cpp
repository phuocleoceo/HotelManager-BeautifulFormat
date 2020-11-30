#include "QLPhong.h"
QLPhong::QLPhong()
{
	this->size = 0;
	this->data = NULL;
}
QLPhong::~QLPhong()
{
	delete[] this->data;
}
ostream &operator<<(ostream &o, const QLPhong &ql)
{
	o << "Danh sach Phong : " << endl;
	for (int i = 0; i < ql.size; i++)
	{
		o << *(ql.data + i);
	}
	return o;
}
PhongKS &QLPhong::operator[](const int &i)
{
}