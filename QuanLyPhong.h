#pragma once
#include "PhongKS.h"
#include "PhongBT.h"
#include "PhongVIP.h"
#include <iostream>
#include <string>
using namespace std;

template <class T = PhongKS>
class QuanLyPhong
{
private:
	T **data;
	int size;

public:
	QuanLyPhong();
	~QuanLyPhong();
	T *operator[](const int &);
	const QuanLyPhong<T> &operator=(const QuanLyPhong<T> &);
	template <class U>
	friend ostream &operator<<(ostream &, const QuanLyPhong<U> &);
	template <class U>
	friend istream &operator>>(istream &, QuanLyPhong<U> &);
	void Add(T *, const int &);
	void Add(T *);
	int IndexOf(const string &);
	void RemoveAt(const int &);
	void Search(const string &);
	void Update(const string &);
	void Input();
	void Sort();
};