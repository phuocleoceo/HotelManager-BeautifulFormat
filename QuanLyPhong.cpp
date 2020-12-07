#include "QuanLyPhong.h"

template <class T>
QuanLyPhong<T>::QuanLyPhong()
{
	this->data = nullptr;
	this->size = 0;
}

template <class T>
QuanLyPhong<T>::~QuanLyPhong()
{
	delete[] this->data;
}

template <class T>
T *QuanLyPhong<T>::operator[](const int &index)
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

template <class T>
const QuanLyPhong<T> &QuanLyPhong<T>::operator=(const QuanLyPhong<T> &p)
{
	this->size = p.size;
	this->data = new T *[this->size];
	for (int i = 0; i < p.size; i++)
	{
		*(this->data + i) = *(p.data + i);
	}
	return (*this);
}

template <class T>
void QuanLyPhong<T>::Add(T *p, const int &k)
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
void QuanLyPhong<T>::Add(T *p)
{
	Add(p, this->size);
}

template <class T>
int QuanLyPhong<T>::IndexOf(const string &MSP)
{
	for (int i = 0; i < this->size; i++)
	{
		if ((*this)[i]->getMSP().compare(MSP) == 0)
			return i;
	}
	return -1;
}

template <class T>
void QuanLyPhong<T>::RemoveAt(const int &k)
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
void QuanLyPhong<T>::Remove(T *p)
{
	int k = IndexOf(p->getMSP());
	if (k == -1)
		cout << "Khong co phong nay, khong the xoa !" << endl;
	else
		RemoveAt(k);
}

template <class T>
void QuanLyPhong<T>::Update(const string &MSP)
{
	int k = IndexOf(MSP);
	if (k == -1)
		cout << "Khong co phong nay, khong the sua !" << endl;
	else
	{
		//Tao phong moi o cuoi Danh sach, Swap no voi phong can sua roi xoa Phong can sua(o cuoi danh sach)
		Input(); //Tao phong moi va them no vao cuoi Mang, luc nay this->size da tang them 1
		*(this->data + k) = *(this->data + (this->size - 1));
		*(this->data + (this->size - 1)) = nullptr;
		RemoveAt(this->size - 1);
	}
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
void QuanLyPhong<T>::Sort()
{
	bool (*CompareChoice)(string, string);
	int flag;
	while (true)
	{
		cout << "*==============Moi ban chon phuong thuc sap xep :=============*" << endl;
		cout << "+----------------------+-------------------------------------+" << endl;
		cout << "|   1. SX tang dan     |   2. SX giam dan    |   0. Thoat    |" << endl;
		cout << "+----------------------+-------------------------------------+" << endl;
		cout << "Nhap lua chon : ";
		cin >> flag;
		if (flag == 1)
		{
			CompareChoice = Ascending;
			break;
		}
		else if (flag == 2)
		{
			CompareChoice = Descending;
			break;
		}
		else if (flag == 0)
			break;
		else
			cout << "> Lua chon khong hop le ! <" << endl;
	}
	T *temp = new T;
	for (int i = 0; i < this->size - 1; i++)
	{
		int flag = i;
		for (int j = i + 1; j < this->size; j++)
		{
			if (CompareChoice((*(this->data + flag))->getMSP(), (*(this->data + j))->getMSP()))
				flag = j;
		}
		//Trao doi dia chi chung tro toi , trao doi gia tri se gay sai sot o PhuThuVIP
		temp = *(this->data + i);
		*(this->data + i) = *(this->data + flag);
		*(this->data + flag) = temp;
	}
}

template <class T>
void QuanLyPhong<T>::Input()
{
	int flag;
	while (true)
	{
		cout << "*===================Moi ban chon loai phong :=================*" << endl;
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
			break;
		}
		else if (flag == 2)
		{
			PhongMoi = new PhongVIP;
			PhongMoi->Input();
			Add(PhongMoi);
			break;
		}
		else if (flag == 0)
			break;
		else
			cout << "Lua chon khong hop le ! " << endl;
	}
}

template <class T>
ostream &operator<<(ostream &o, const QuanLyPhong<T> &ql)
{
	o << "Danh sach phong : " << endl;
	o << "+----------+-----------------+------------+-----------------+-----------------+---------+-------------+-----------------+" << endl;
	o << "| Ma phong "
	  << "| So nguoi toi da "
	  << "| Tinh trang "
	  << "| Ngay nhan phong "
	  << "| Ngay tra phong  "
	  << "| Don gia "
	  << "| Phu thu VIP "
	  << "|    Gia phong    |" << endl;
	o << "+----------+-----------------+------------+-----------------+-----------------+---------+-------------+-----------------+" << endl;
	for (int i = 0; i < ql.size; i++)
	{
		ql.data[i]->Output();
	}
}
