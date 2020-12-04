#include "PhongKS.h"
#include "PhongBT.h"
#include "PhongVIP.h"
#include <iostream>
#include <string>
using namespace std;

template <class T>
class QLPhong
{
private:
	T **data;
	int size;

public:
	QLPhong();
	~QLPhong();
	T* operator[](const int &);
	const T &operator=(const T &);
	template <class U>
	friend ostream &operator<<(ostream &, const QLPhong<U> &);
	void Add(T *, const int &);
	void Add(T *);
	int IndexOf(const string &);
	void RemoveAt(const int &);
	void Remove(T *);
	void Update(const string &);	
	void Input();
	void Sort();
};