#include "QLPhong.h"

template <class T>
QLPhong<T>::QLPhong()
{
	this->data = nullptr;
	this->size = 0;
}

template <class T>
QLPhong<T>::~QLPhong()
{
	delete[] this->data;
}

template <class T>
T *QLPhong<T>::operator[](const int &index)
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
void QLPhong<T>::Add(T *p, const int &k)
{
	if (this->size == 0)
	{
		this->data = new T *[this->size + 1];
		this->data[this->size] = p;
	}
	else
	{
		T **temp = new T *[this->size];
		for (int i = 0; i < this->size; i++)
		{
			*(temp + i) = *(this->data + i);
		}
		delete[] this->data;
		this->data = new T *[this->size + 1];
		this->data[k] = p;
		for (int i = 0; i < k; i++)
		{
			*(this->data + i) = *(temp + i);
		}
		for (int i = k + 1; i <= this->size; i++)
		{
			*(this->data + i) = *(temp + i - 1);
		}
	}
	this->size++;
}

template <class T>
void QLPhong<T>::Add(T *p)
{
	Add(p, this->size);
}

template <class T>
int QLPhong<T>::IndexOf(const string &MSP)
{
	for (int i = 0; i < this->size; i++)
	{
		if ((*this)[i]->getMSP().compare(MSP) == 0)
			return i;
	}
	return -1;
}

template <class T>
void QLPhong<T>::RemoveAt(const int &k)
{
	if (k == 0 && this->size == 1)
	{
		delete[] this->data;
		this->data = nullptr;
		this->size = 0;
	}
	else if (k >= this->size)
	{
		return;
	}
	else
	{
		for (int i = k; i < this->size - 1; i++)
		{
			this->data[i] = this->data[i + 1];
		}
		T **temp = new T *[this->size];
		for (int i = 0; i < this->size - 1; i++)
		{
			*(temp + i) = *(this->data + i);
		}
		delete[] this->data;
		this->data = new T *[this->size - 1];
		for (int i = 0; i < this->size - 1; i++)
		{
			*(this->data + i) = *(temp + i);
		}
	}
	this->size--;
}

template <class T>
void QLPhong<T>::Remove(T *p)
{
	int k = IndexOf(p->getMSP());
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
		RemoveAt(k);
		cout << "Nhap thong tin moi cho phong nay : " << endl;
		Input();
		// Swap((*this)[k], (*this)[this->size - 1]);
		// Remove((*this)[this->size - 1]);
	}
}

template <class T>
void QLPhong<T>::Swap(T *p1, T *p2)
{
	T *temp = p1;
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
void QLPhong<T>::Sort()
{
	bool (*CompareChoice)(string, string);
	int flag;
	while (true)
	{
		cout << "*========================Moi ban chon:=======================*" << endl;
		cout << "+----------------------+-------------------------------------+" << endl;
		cout << "|   1. SX tang dan     |   2. SX giam dan    |   0. Thoat    |" << endl;
		cout << "+----------------------+-------------------------------------+" << endl;
		cout << "Nhap lua chon : ";
		cin >> flag;
		if (flag == 1)
		{
			CompareChoice = Ascending;
		}
		else if (flag == 2)
		{
			CompareChoice = Descending;
		}
		else if (flag == 0)
			return;
		else
			cout << "Lua chon khong hop le ! " << endl;
	}
	for (int i = 0; i < this->size - 1; i++)
	{
		int min = i;
		for (int j = i + 1; j < this->size; j++)
		{
			if (CompareChoice((*this)[j]->getMSP(), (*this)[min]->getMSP()))
				min = j;
		}
		Swap((*this)[i], (*this)[min]);
	}
}

template <class T>
void QLPhong<T>::Input()
{
	int flag;
	while (true)
	{
		cout << "*========================Moi ban chon:=======================*" << endl;
		cout << "+----------------------+-------------------------------------+" << endl;
		cout << "|   1. Phong Thuong    |    2. Phong VIP     |   0. Thoat    |" << endl;
		cout << "+----------------------+-------------------------------------+" << endl;
		cout << "Nhap lua chon : ";
		cin >> flag;
		T *PhongMoi;
		if (flag == 1)
		{
			PhongMoi = new PhongBT;
			PhongMoi->Input();
			Add(PhongMoi);
		}
		else if (flag == 2)
		{
			PhongMoi = new PhongVip;
			PhongMoi->Input();
			Add(PhongMoi);
		}
		else if (flag == 0)
			break;
		else
			cout << "Lua chon khong hop le ! " << endl;
	}
}

template <class T>
ostream &operator<<(ostream &o, const QLPhong<T> &ql)
{
	o << "Danh sach phong : " << endl;
	o << "Ma phong\t"
	  << "So nguoi toi da\t"
	  << "Tinh trang\t"
	  << "Ngay nhan phong\t"
	  << "Ngay tra phong\t"
	  << "Don gia\t"
	  << "Phu thu VIP\t"
	  << "Gia phong" << endl;
	for (int i = 0; i < ql.size; i++)
	{
		ql.data[i]->Output();
	}
}