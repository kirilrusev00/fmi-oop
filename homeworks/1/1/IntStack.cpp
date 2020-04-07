#include "IntStack.h"
#include <iostream>

IntStack::IntStack():size(10),top(-1)
{
	arr = new int[size];
}

IntStack::IntStack(const IntStack& rhs) :size(rhs.size), top(rhs.top)
{
	arr = new int[size];
	for (int i = 0; i <= top; i++)
	{
		arr[i] = rhs.arr[i];
	}
}

bool IntStack::is_full() const
{
	return top == size-1;
}

void IntStack::resize()
{
	int* newArr = new int[size * 2];
	for (int i = 0; i <= top; i++)
	{
		newArr[i] = arr[i];
	}
	delete[] arr;
	arr = newArr;
	size *= 2;
}

IntStack& IntStack::operator= (const IntStack& rhs)
{
	if (this != &rhs)
	{
		delete[] arr;

		size = rhs.size;
		top = rhs.top;

		arr = new int[size];
		for (int i = 0; i <= top; i++)
		{
			arr[i] = rhs.arr[i];
		}
	}
	return *this;
}

int IntStack::operator[] (unsigned int ind) const
{
	if (ind <= top)
	{
		return arr[ind];
	}
	std::cout << "The stack does not have an element with index " << ind << "!\n";
	return -1;
}

int& IntStack::operator[] (unsigned int ind)
{
	if (ind <= top)
	{
		return arr[ind];
	}
	//if (ind < 0 || ind > top), return arr[top]
	std::cout << "The stack does not have an element with index " << ind << "!\n";
	return arr[top];
}

void IntStack::push_back(int val)
{
	if (is_full())
	{
		resize();
	}
	arr[++top] = val;
}

void IntStack::input()
{
	int n;
	std::cout << "Enter a number to push in the stack:";
	std::cin >> n;
	push_back(n);
}

void IntStack::print() const
{
	if (top == -1)
	{
		std::cout << "The stack is empty.\n";
		return;
	}
	for (int i = top; i >= 0; i--)
	{
		std::cout << arr[i];
		if (i > 0)
		{
			std::cout << " ";
		}
		else
		{
			std::cout << std::endl;
		}
	}
}

IntStack sortStack(const IntStack& s)
{
	IntStack sortedStack(s);
	for (int i = 0; i < sortedStack.top; i++)
	{
		for (int j = i+1; j <= sortedStack.top; j++)
		{
			if (sortedStack[i] > sortedStack[j])
			{
				int temp = sortedStack[i];
				sortedStack[i] = sortedStack[j];
				sortedStack[j] = temp;
			}
		}
	}
	return sortedStack;
}

IntStack::~IntStack()
{
	delete[] arr;
}