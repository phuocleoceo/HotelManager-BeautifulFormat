#include "PhongKS.h"
#include <iostream>
#include <string>
using namespace std;

template <class T>
class QLPhong
{
private:
	PhongKS *data;
	int size;

public:
	QLPhong();
	~QLPhong();
	T &operator[](const int &);
	const T &operator=(const T &);
	friend ostream &operator<<(ostream &, const QLPhong &);
	void Add(const T &);
	int IndexOf(const string &);
	void Remove(const T &);
	void Update(const string &);
	void Sort();
};
