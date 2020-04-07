#ifndef MAGICBOX_H
#define MAGICBOX_H

#include <iostream>
#include <cstdlib>

template <class T>
class MagicBox
{
private:
	T* values;
	int size;
	int maxSize;

	bool is_empty() const;
	bool is_full() const;
	void resize();

	void remove(int);

	void copyMagicBox(const MagicBox<T>&);
public:
	MagicBox();
	MagicBox(const MagicBox<T>&);
	MagicBox<T>& operator=(const MagicBox<T>&);

	T& operator[](const int&);

	void insert(const T&);
	void pop();
	void list() const;

	~MagicBox();
};

template <class T>
MagicBox<T>::MagicBox() :size(0),maxSize(10)
{
	values = new T[maxSize];
	//values[0] = '\0';
}

template <class T>
bool MagicBox<T>::is_empty() const
{
	return size == 0;
}

template <class T>
bool MagicBox<T>::is_full() const
{
	return size == maxSize;
}

template <class T>
void MagicBox<T>::resize()
{
	T* newValues = new T[maxSize * 2];
	for (int i = 0; i < maxSize; i++)
	{
		newValues[i] = values[i];
	}
	delete[] values;
	values = newValues;
	maxSize *= 2;
}

template <class T>
void MagicBox<T>::copyMagicBox(const MagicBox<T>& rhs)
{
	size = rhs.size;
	maxSize = rhs.maxSize;
	values = new T[maxSize];
	for (int i = 0; i < maxSize; i++)
	{
		values[i] = rhs.values[i];
	}
}

template <class T>
MagicBox<T>::MagicBox(const MagicBox<T>& rhs)
{
	copyMagicBox(rhs);
}

template <class T>
MagicBox<T>& MagicBox<T>::operator=(const MagicBox<T>& rhs)
{
	if (this != &rhs)
	{
		delete[] values;
		copyMagicBox(rhs);
	}
	return *this;
}

template <class T>
T& MagicBox<T>::operator[](const int& ind)
{
	return values[ind];
}

template <class T>
void MagicBox<T>::insert(const T& newElement)
{
	if (is_full())
	{
		resize();
	}
	values[size++] = newElement;
}

template <class T>
void MagicBox<T>::remove(int ind)
{
	for (int i = ind; i < size; i++)
	{
		values[i] = values[i + 1];
	}
	size--;
}

template <class T>
void MagicBox<T>::pop()
{
	if (!is_empty())
	{
		int ind = std::rand() % (size - 1);
		std::cout << ind << std::endl;
		remove(ind);
	}
	else
	{
		std::cout << "The MagicBox is empty!\n";
	}
}

template <class T>
void MagicBox<T>::list() const
{
	for (int i = 0; i < size-1; i++)
	{
		std::cout << values[i] << " ";
	}
	std::cout << values[size-1] << std::endl;
}

template <class T>
MagicBox<T>::~MagicBox()
{
	delete[] values;
}

#endif