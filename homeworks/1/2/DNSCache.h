#ifndef DNSCACHE_H
#define DNSCACHE_H
#include "DNSRecord.h"

const int MAX_SIZE = 10;//The default size of dynamic array when it is initialised 

class DNSCache {
private:
	DNSRecord* cache;
	int size;//the number of DNS records in the array
	int maxSize;//the size of the dynamic array cache

	bool is_full() const;//check if the cache is full

	void resize();//enlarge the cache
public:
	DNSCache();//default constructor
	DNSCache(const DNSCache&);//copy constructor
	DNSCache& operator= (const DNSCache&);

	void add(const DNSRecord&);

	char* lookup(const char*) const;

	void flush();

	void print() const;

	~DNSCache();//destructor
};

#endif