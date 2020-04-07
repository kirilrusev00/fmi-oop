#ifndef STORAGE_H
#define STORAGE_H

class Storage
{
private:
	char* hash_code;
	char* name;
	double max_capacity;
	double taken_capacity;
public:
	//Storage();
	Storage(double set_max_capacity = 0, double set_taken_capacity = 0, const char* set_hash_code = "\0", const char* set_name = "\0");
	Storage(const Storage&);
	Storage& operator=(const Storage&);

	const char* getHashCode() const;
	const char* getName() const;
	const double getMaxCapacity() const;
	const double getTakenCapacity() const;

	void setHashCode(const char*);
	void setName(const char*);
	void setMaxCapacity(const double&);
	void setTakenCapacity(const double&);

	~Storage();
};

#endif
