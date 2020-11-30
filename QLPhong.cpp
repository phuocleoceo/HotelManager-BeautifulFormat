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
PhongKS &QLPhong::operator[](const int &index)
{
	try
	{
		if (index >= 0 && index < this->size)
			return *(this->data + index);
		else
			throw NULL;
	}
	catch (...)
	{
		cout << "Chi so khong hop le !" << endl;
	};
}
void QLPhong::Add(const PhongKS &p)
{
	if (this->size == 0)
	{
		this->data = new PhongKS[this->size + 1];
		this->data[0] = p;
	}
	else
	{
		PhongKS *temp = new PhongKS[this->size];
		for (int i = 0; i < this->size; i++)
		{
			*(temp + i) = *(this->data + i);
		}
		delete[] this->data;
		this->data = new PhongKS[this->size + 1];
		for (int i = 0; i < this->size; i++)
		{
			*(this->data + i) = *(temp + i);
		}
		this->data[this->size] = p;
	}
	this->size++;
}
int QLPhong::IndexOf(const PhongKS &p)
{
	for (int i = 0; i < this->size; i++)
		if (this->data[i] == p)
			return i;
	return -1;
}
void QLPhong::Remove(const PhongKS &p)
{
	int k = IndexOf(p);
	if (k == 1)
		cout << "Khong co phong nay, khong the xoa !" << endl;
	else
	{
		if (k == 0 && this->size == 1)
		{
			delete[] this->data;
		}
		else
		{
			for (int i = k; i < this->size - 1; i++)
			{
				this->data[i] = this->data[i + 1];
			}
			PhongKS *temp = new PhongKS[this->size];
			for (int i = 0; i < this->size - 1; i++)
			{
				*(temp + i) = *(this->data + i);
			}
			delete[] this->data;
			this->data = new PhongKS[this->size - 1];
			for (int i = 0; i < this->size - 1; i++)
			{
				*(this->data + i) = *(temp + i);
			}
		}
		this->size--;
	}
}