#include "PhongKS.h"
#include <iostream>
#include <string>
using namespace std;

// template<class T>
class QLPhong
{
private:
	PhongKS *data;
	int size;

public:
	QLPhong();
	~QLPhong();
	PhongKS &operator[](const int &);
	friend ostream &operator<<(ostream &, const QLPhong &);
	void Add(const PhongKS &);
	int IndexOf(const PhongKS &);
	void Remove(const PhongKS &);
	void Update(const string &);
	void Sort();
};
