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
	template <class U>
	friend ostream &operator<<(ostream &, const QLPhong<U> &);
	void Add(const T &);
	int IndexOf(const string &);
	void Remove(const T &);
	void Update(const string &);
	void Swap(T&,T&);
	void Sort();
};
