#include "PhongKS.h"
#include <iostream>
#include <string>
using namespace std;

class QLPhong
{
private:
	PhongKS **data;
	int size;

public:
	QLPhong();
	~QLPhong();
	PhongKS &operator[](const int &);
	const PhongKS &operator=(const PhongKS &);
	friend ostream &operator<<(ostream &, const QLPhong &);
	friend istream &operator>>(istream &, QLPhong &);
	void Add(const PhongKS &);
	int IndexOf(const string &);
	void Remove(const PhongKS &);
	void Update(const string &);
	void Swap(PhongKS &, PhongKS &);
	void Sort();
};
