#include "QLPhong.h"

template <class T>
QLPhong<T>::QLPhong() {}
template <class T>
QLPhong<T>::~QLPhong() {}

template <class T>
T &QLPhong<T>::operator[](const int &index)
{
	try
	{
		if (index >= 0 && index < this->size)
			return this->data[index];
		else
			throw NULL;
	}
	catch (...)
	{
		cout << "Chi so khong hop le !" << endl;
	};
}
template <class T>
const T &QLPhong<T>::operator=(const T &p)
{
}
template <class T>
void QLPhong<T>::Add(T *p)
{
	data.Add(p);
}
template <class T>
int QLPhong<T>::IndexOf(const string &MSP)
{
	for (int i = 0; i < data.length(); i++)
	{
		if (MSP.compare((data[i]->getMSP())) == 0)
			return i;
	}
	return -1;
}
template <class T>
void QLPhong<T>::RemoveAt(const int &k)
{
	data.Remove(k);
}
template <class T>
void QLPhong<T>::Remove(T *p)
{
	int k = IndexOf(p.getMSP());
	if (k == -1)
		cout << "Khong co phong nay, khong the xoa !" << endl;
	else
		RemoveAt(k);
}
template <class T>
void QLPhong<T>::Update(const string &MSP)
{
	int k = IndexOf(MSP);
	if (k == -1)
		cout << "Khong co phong nay, khong the sua !" << endl;
	else
	{
		Remove((*this)[k]);
		//Tao ham NewRoom de tao phong moi roi Add no vao mang hoac gan no bang newPhong
	}
}
template <class T>
void Swap(T &p1, T &p2)
{
	T temp = p1;
	p1 = p2;
	p2 = temp;
}
bool Ascending(string a, string b)
{
	return a.compare(b) > 0;
}
bool Descending(string a, string b)
{
	return a.compare(b) < 0;
}
template <class T>
void QLPhong<T>::Sort(bool (*CompareChoice)(string, string))
{
	for (int i = 0; i < this->size - 1; i++)
	{
		int min = i;
		for (int j = i + 1; j < this->size; j++)
		{
			// if ((*this)[j].getMSP().compare((*this)[min].getMSP()) < 0)
			if (CompareChoice((*this)[j].getMSP(), (*this)[min].getMSP()))
				min = j;
		}
		Swap((*this)[i], (*this)[min]);
	}
}
template <class T>
void QLPhong<T>::Input()
{
	int flag;
	do
	{
		cout << "*========================Moi ban chon:=======================*" << endl;
		cout << "+----------------------+-------------------------------------+" << endl;
		cout << "|   1. Phong Thuong    |    2. Phong VIP     |   0. Thoat    |" << endl;
		cout << "+----------------------+-------------------------------------+" << endl;
		cout << "Nhap lua chon : ";
		cin >> flag;
		if (flag == 1)
		{
			PhongBT *newPhongBT = new PhongBT;
			newPhongBT->Input();
			Add(newPhongBT);
		}
		else if (flag == 2)
		{
			PhongVip *newPhongVIP = new PhongVip;
			newPhongVIP->Input();
			Add(newPhongVIP);
		}
	} while (flag != 0);
}
template <class T>
ostream &operator<<(ostream &o, const QLPhong<T> &ql)
{
	o << "Danh sach Phong : " << endl;
	for (int i = 0; i < ql.size; i++)
	{
		o << *(ql.data + i);
	}
	return o;
}