#ifndef PRODUCT_H
#define PRODUCT_H

class Product //GSM
{
private:
	char* SKU;
	char* brand;
	char* model;
	char* colour;
	double price;
	double display_size;
	int count;

public:
	Product();
	Product(const Product&);
	Product& operator=(const Product&);

	char* getSKU() const;
	void setSKU(const char* newSKU);

	char* getBrand() const;
	void setBrand(const char* newBrand);

	char* getModel() const;
	void setModel(const char* newModel);

	char* getColour() const;
	void setColour(const char* newColour);

	double getPrice() const;
	void setPrice(const double newPrice);

	double getDisplaySize() const;
	void setDisplaySize(const double newDisplaySize);

	int getCount() const;
	void setCount(const int newCount);

	void input();
	friend class Store;

	~Product();
};

#endif
