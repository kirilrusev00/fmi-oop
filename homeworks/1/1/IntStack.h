#ifndef STACK_H
#define STACK_H

class IntStack
{
private:
	int *arr;
	int size;//The size of arr
	int top;//The index of the last element in arr

	bool is_full() const;

	void resize();
public:
	IntStack();
	IntStack(const IntStack&);
	IntStack& operator= (const IntStack&);

	int operator[] (unsigned int ind) const;//access arr[ind]
	int& operator[] (unsigned int ind);//change arr[ind]

	void push_back(int);

	void input();//add an element in the stack

	void print() const;

	friend IntStack sortStack(const IntStack&);

	~IntStack();
};

#endif