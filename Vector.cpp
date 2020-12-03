#include "Vector.h"
template <class T>
Vector<T>::Vector()
{
	this->size = 0;
	this->data = nullptr;
}
template <class T>
Vector<T>::~Vector()
{
	delete[] this->data;
}
template <class T>
T &Vector<T>::operator[](const int &index)
{
	if (index >= 0 && index < this->size)
	{
		return *(this->data + index);
	}
	else
		return NULL;
}
template <class T>
int Vector<T>::length() const
{
	return this->size;
}
template <class T>
ostream &operator<<(ostream &o, const Vector<T> &v)
{
	for (int i = 0; i < v.size; i++)
	{
		o << *(v.data + i);
	}
	return o;
}
template <class T>
void Vector<T>::Add(const T &element, const int &k)
{
	if (this->size == 0)
	{
		this->data = new T[this->size + 1];
		this->data[this->size] = element;
	}
	else
	{
		T *temp = new T[this->size];
		for (int i = 0; i < this->size; i++)
		{
			*(temp + i) = *(this->data + i);
		}
		delete[] this->data;
		this->data = new T[this->size + 1];
		this->data[k] = element;
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
void Vector<T>::Add(const T &element)
{
	Add(element, this->size);
}
template <class T>
void Vector<T>::Remove(const int &k)
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
		T *temp = new T[this->size];
		for (int i = 0; i < this->size - 1; i++)
		{
			*(temp + i) = *(this->data + i);
		}
		delete[] this->data;
		this->data = new T[this->size - 1];
		for (int i = 0; i < this->size - 1; i++)
		{
			*(this->data + i) = *(temp + i);
		}
	}
	this->size--;
}