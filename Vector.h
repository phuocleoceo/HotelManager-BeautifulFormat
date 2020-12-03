#pragma once
#include <iostream>
using namespace std;
template <class T>
class Vector
{
private:
	T *data;
	int size;

public:
	Vector();
	~Vector();
	T &operator[](const int &);
	int length() const;
	template <class U>
	friend ostream &operator<<(ostream &, const Vector<U> &);
	void Add(const T &, const int &);
	void Add(const T &);
	void Remove(const int &);
};