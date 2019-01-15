#pragma once
#include "stdafx.h"
#include <iostream>
#include <cstring>

template <typename T>
class Vector
{
public:
	Vector<T>();							//default constructor
	Vector<T>(const Vector<T>& other);		//copy constructor
	Vector<T>& operator= (const Vector<T>& other);		//operator =
	~Vector<T>();										//destructor
	void push_front(T element);							//push front element
	void push_back(T element);							//push back element
	void push(size_t index, T element);					//push element at any position
	void pop_back();									//pop back element
	void pop_front();									//pop front element
	void pop(size_t index);								//pop element at any position
	Vector<T>& operator+=(const Vector<T>& other);			//operator +=
	T operator[](size_t index) const;				// return elem from index
	int operator[](T element) const;				// return index from elem
	void print();									//print function
	size_t size() const;							//get current size
	size_t maxsize() const;							//get capacity
	friend std::ostream &operator<< (std::ostream& output, Vector<T>& other);	//operator<< for ostream

private:
	T * value;
	size_t count;
	size_t capacity;

	void copy(const Vector<T>& other);			//helper copy function
	void destroy();								//helper destruct function
	void resize();								//resize function
};

template <typename T>
Vector<T>::Vector<T>()							//default constructor
{
	this->capacity = 8;
	this->count = 0;
	this->value = new T[this->capacity];
}

template <typename T>
Vector<T>::Vector<T>(const Vector<T>& other)		//copy constructor
{
	this->copy(other);
}

template <typename T>
Vector<T>& Vector<T>::operator= (const Vector<T>& other)	//operator =
{
	if (this != &other)
	{
		this->destroy();
		this->copy(other);
	}
	return *this;
}

template <typename T>
Vector<T>::~Vector<T>()								//destructor
{
	this->destroy();
}

template <typename T>
void Vector<T>::push_front(T element)				//push front element
{
	if (++this->count > this->capacity)
	{
		this->resize();
	}
	for (size_t i = this->count; i > 0; i--)
	{
		this->value[i] = this->value[i - 1];
	}
	this->value[0] = element;
}

template <typename T>
void Vector<T>::push_back(T element)					//push back element
{
	if (this->count >= this->capacity)
	{
		this->resize();
	}
	this->value[this->count++] = element;
}


template <typename T>
void Vector<T>::push(size_t index, T element)				//push element at any position
{
	if (this->count >= this->capacity)
	{
		this->resize();
	}
	this->count++;

	for (size_t i = this->count; i >= index; i--)
	{
		this->value[i] = this->value[i - 1];
	}
	this->value[index] = element;
}

template <typename T>
void Vector<T>::pop_back()									//pop back element
{
	this->count--;
}


template <typename T>
void Vector<T>::pop_front()									//pop front element
{
	T temp = value[1];
	for (size_t i = 0; i < this->count - 1; i++)
	{
		this->value[i] = temp;
		temp = this->value[i + 2];
	}
	this->count--;
}

template <typename T>
void Vector<T>::pop(size_t index)							//pop element at any position
{
	if (index > this->count) { return; }
	for (size_t i = index; i < this->count - 1; i++)
	{
		this->value[i] = this->value[i + 1];
	}
	this->pop_back();
}

template <typename T>
Vector<T>& Vector<T>::operator+=(const Vector<T>& other)			//operator +=
{
	T* temp = new T[this->count + other.count];
	for (size_t i = 0; i < this->count; i++)
	{
		temp[i] = this->value[i];
	}
	for (size_t i = this->count, j = 0; i < this->count + other.count; i++, j++)
	{
		temp[i] = other.value[j];
	}
	this->destroy();

	this->count += other.count;
	this->capacity += other.capacity;
	this->value = new T[this->capacity];
	this->value = temp;

	return *this;
}


template <typename T>
T Vector<T>::operator[](size_t index) const // return elem from index
{
	return this->value[index];
}

template <typename T>
int Vector<T>::operator[](T element) const  // return index from elem
{
	for (size_t i = 0; i < this->count; i++)
	{
		if (element == this->value[i])
		{
			return i;
		}
	}

	return -1;
}

template <typename T>
void Vector<T>::print()										//print function
{
	for (size_t i = 0; i < count; i++)
	{
		std::cout << this->value[i] << " ";
	}
}

template <typename T>
size_t Vector<T>::size() const								//get current size
{
	return this->count;
}

template <typename T>
size_t Vector<T>::maxsize() const							//get capacity
{
	return this->capacity;
}

template <typename T>
std::ostream &operator <<(std::ostream &output, Vector<T>&  other)   //operator<< for ostream
{
	for (size_t i = 0; i < other.size(); i++)
		output << other[i] << " ";
	return output;
}

template <typename T>
void Vector<T>::copy(const Vector<T>& other)			//helper copy function
{
	this->count = other.count;
	this->capacity = other.capacity;
	this->value = new T[other.capacity];
	for (size_t i = 0; i < this->count; i++)
	{
		this->value[i] = other.value[i];
	}

}

template <typename T>
void Vector<T>::destroy()						//helper destruct function
{
	delete[] this->value;
}

template <typename T>
void Vector<T>::resize()						//resize function
{
	this->capacity = 2 * this->capacity + 1;
	T* temp = new T[this->capacity];
	for (size_t i = 0; i < this->count; i++)
	{
		temp[i] = this->value[i];
	}
	destroy();
	this->value = temp;
}