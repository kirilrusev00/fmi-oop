#ifndef STORE_H
#define STORE_H
#include "Product.h"

class Store
{
private:
	Product* prod;
	int num;
public:
	Store();
	Store(const Store&);
	Store& operator=(const Store&);

	void add(Product);
	void remove(int pos);
	void change(int pos, Product val);
	void print() const;

	~Store();
};


#endif
