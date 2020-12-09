#include "QuanLyPhong.h"

template <class T>
QuanLyPhong<T>::QuanLyPhong()
{
	this->DanhSachPhong = nullptr;
	this->SoLuongPhong = 0;
}

template <class T>
QuanLyPhong<T>::~QuanLyPhong()
{
	delete[] this->DanhSachPhong;
}

template <class T>
T *QuanLyPhong<T>::operator[](const int &index)
{
	try
	{
		if (index >= 0 && index < this->SoLuongPhong)
			return *(this->DanhSachPhong + index);
		else
			throw string(">> Chi so khong hop le ! <<");
	}
	catch (string &e)
	{
		cout << e << endl;
	};
}

template <class T>
const QuanLyPhong<T> &QuanLyPhong<T>::operator=(const QuanLyPhong<T> &p)
{
	this->SoLuongPhong = p.SoLuongPhong;
	this->DanhSachPhong = new T *[this->SoLuongPhong];
	for (int i = 0; i < p.SoLuongPhong; i++)
	{
		*(this->DanhSachPhong + i) = *(p.DanhSachPhong + i);
	}
	return (*this);
}

template <class T>
void QuanLyPhong<T>::Add(T *p, const int &k)
{
	if (this->SoLuongPhong == 0)
	{
		this->DanhSachPhong = new T *[this->SoLuongPhong + 1];
		this->DanhSachPhong[this->SoLuongPhong] = p;
	}
	else
	{
		T **temp = new T *[this->SoLuongPhong];
		for (int i = 0; i < this->SoLuongPhong; i++)
		{
			*(temp + i) = *(this->DanhSachPhong + i);
		}
		delete[] this->DanhSachPhong;
		this->DanhSachPhong = new T *[this->SoLuongPhong + 1];
		this->DanhSachPhong[k] = p;
		for (int i = 0; i < k; i++)
		{
			*(this->DanhSachPhong + i) = *(temp + i);
		}
		for (int i = k + 1; i <= this->SoLuongPhong; i++)
		{
			*(this->DanhSachPhong + i) = *(temp + i - 1);
		}
	}
	this->SoLuongPhong++;
}

template <class T>
void QuanLyPhong<T>::Add(T *p)
{
	Add(p, this->SoLuongPhong);
}

template <class T>
int QuanLyPhong<T>::IndexOf(const string &MSP)
{
	for (int i = 0; i < this->SoLuongPhong; i++)
	{
		if ((*this)[i]->getMSP().compare(MSP) == 0)
			return i;
	}
	return -1;
}

template <class T>
void QuanLyPhong<T>::RemoveAt(const int &k)
{
	if (k < 0)
	{
		cout << ">> Khong ton tai phong nay de xoa ! <<" << endl;
		return;
	}
	if (k == 0 && this->SoLuongPhong == 1)
	{
		delete[] this->DanhSachPhong;
		this->DanhSachPhong = nullptr;
		this->SoLuongPhong = 0;
	}
	else if (k >= this->SoLuongPhong)
	{
		return;
	}
	else
	{
		for (int i = k; i < this->SoLuongPhong - 1; i++)
		{
			this->DanhSachPhong[i] = this->DanhSachPhong[i + 1];
		}
		T **temp = new T *[this->SoLuongPhong];
		for (int i = 0; i < this->SoLuongPhong - 1; i++)
		{
			*(temp + i) = *(this->DanhSachPhong + i);
		}
		delete[] this->DanhSachPhong;
		this->DanhSachPhong = new T *[this->SoLuongPhong - 1];
		for (int i = 0; i < this->SoLuongPhong - 1; i++)
		{
			*(this->DanhSachPhong + i) = *(temp + i);
		}
	}
	this->SoLuongPhong--;
	cout << ">> Xoa thanh cong ! <<" << endl;
}

template <class T>
void QuanLyPhong<T>::Search(const string &MSP)
{
	int Vitri = IndexOf(MSP);
	if (Vitri != -1)
	{
		cout << "Phong can tim co thong tin la : " << endl;
		cout << "+----------+-----------------+------------+-----------------+-----------------+---------+-------------+-----------------+" << endl;
		cout << "| Ma phong "
			 << "| So nguoi toi da "
			 << "| Tinh trang "
			 << "| Ngay nhan phong "
			 << "| Ngay tra phong  "
			 << "| Don gia "
			 << "| Phu thu VIP "
			 << "|    Gia phong    |" << endl;
		cout << "+----------+-----------------+------------+-----------------+-----------------+---------+-------------+-----------------+" << endl;
		(*this)[Vitri]->Output();
	}
	else
		cout << "Khong tim thay ! " << endl;
}

template <class T>
void QuanLyPhong<T>::Update(const string &MSP)
{
	int k = IndexOf(MSP);
	if (k == -1)
		cout << ">> Khong co phong nay, khong the sua ! <<" << endl;
	else
	{
		//Tao phong moi o cuoi Danh sach, Swap no voi phong can sua roi xoa Phong can sua(o cuoi danh sach)
		cin >> (*this); //Tao phong moi va them no vao cuoi Mang, luc nay this->SoLuongPhong da tang them 1
		*(this->DanhSachPhong + k) = *(this->DanhSachPhong + (this->SoLuongPhong - 1));
		*(this->DanhSachPhong + (this->SoLuongPhong - 1)) = nullptr; //Huy lien ket giua DanhSachPhong[SoLuongPhong-1] voi doi tuong PhongMoi
		RemoveAt(this->SoLuongPhong - 1);
		cout << ">> Sua thong tin phong thanh cong ! <<" << endl;
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
		try
		{
			cout << "*==============Moi ban chon phuong thuc sap xep :=============*" << endl;
			cout << "+----------------------+-------------------------------------+" << endl;
			cout << "|   1. SX tang dan     |   2. SX giam dan    |   0. Tro Lai  |" << endl;
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
				throw string(">> Lua chon khong hop le ! <<");
		}
		catch (string &e)
		{
			cout << e << endl;
		}
	}
	T *temp = new T;
	for (int i = 0; i < this->SoLuongPhong - 1; i++)
	{
		int flag = i;
		for (int j = i + 1; j < this->SoLuongPhong; j++)
		{
			if (CompareChoice((*(this->DanhSachPhong + flag))->getMSP(), (*(this->DanhSachPhong + j))->getMSP()))
				flag = j;
		}
		//Trao doi dia chi chung tro toi , trao doi gia tri se gay sai sot o PhuThuVIP
		temp = *(this->DanhSachPhong + i);
		*(this->DanhSachPhong + i) = *(this->DanhSachPhong + flag);
		*(this->DanhSachPhong + flag) = temp;
	}
	cout<<">> Sap xep thanh cong ! <<"<<endl;
}

template <class T>
istream &operator>>(istream &i, QuanLyPhong<T> &ql)
{
	int flag;
	while (true)
	{
		try
		{
			cout << "*===================Moi ban chon loai phong :=================*" << endl;
			cout << "+----------------------+-------------------------------------+" << endl;
			cout << "|   1. Phong Thuong    |    2. Phong VIP     |   0. Tro Lai  |" << endl;
			cout << "+----------------------+-------------------------------------+" << endl;
			cout << "Nhap lua chon : ";
			cin >> flag;
			T *PhongMoi;
			if (flag == 1)
			{
				PhongMoi = new PhongBT;
				cin.ignore();
				PhongMoi->Input();
				ql.Add(PhongMoi);
				break;
			}
			else if (flag == 2)
			{
				PhongMoi = new PhongVIP;
				cin.ignore();
				PhongMoi->Input();
				ql.Add(PhongMoi);
				break;
			}
			else if (flag == 0)
				break;
			else
				throw string(">> Lua chon khong hop le ! <<");
		}
		catch (string &e)
		{
			cout << e << endl;
		}
	}
	return i;
}
template <class T>
ostream &operator<<(ostream &o, const QuanLyPhong<T> &ql)
{
	o << "Danh sach phong ( Phong VIP thi co Phu Thu Vip > 0 ) :" << endl;
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
	for (int i = 0; i < ql.SoLuongPhong; i++)
	{
		ql.DanhSachPhong[i]->Output();
	}
}
