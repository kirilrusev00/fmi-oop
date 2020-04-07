#include "DNSCache.h"
#include <iostream>
#include <iomanip>
#include <cstring>

DNSCache::DNSCache():size(0),maxSize(MAX_SIZE)
{
	cache = new DNSRecord[maxSize];
}

DNSCache::DNSCache(const DNSCache& rhs):size(rhs.size),maxSize(rhs.maxSize)
{
	int i = 0;
	cache = new DNSRecord[maxSize];
	for (i = 0; i < size; i++)
	{
		cache[i] = rhs.cache[i];
	}
}

DNSCache& DNSCache::operator= (const DNSCache& rhs)
{
	if (this != &rhs)
	{
		delete[] cache;
		size = rhs.size;
		maxSize = rhs.maxSize;
		cache = new DNSRecord[maxSize];
		for (int i = 0; i < size; i++)
		{
			cache[i] = rhs.cache[i];
		}
	}
	return *this;
}

bool DNSCache::is_full() const
{
	return size == maxSize;
}

void DNSCache::resize()
{
	maxSize *= 2;
	DNSRecord* newCache = new DNSRecord[maxSize];
	for (int i = 0; i < size; i++)
	{
		newCache[i] = cache[i];
	}
	delete[] cache;
	cache = newCache;
}

void DNSCache::add(const DNSRecord& rhs)
{
	if (is_full())
	{
		resize();
	}
	cache[size++] = rhs;
}

char* DNSCache::lookup(const char* name) const
{
	for (int i = 0; i < size; i++)
	{
		if (std::strcmp(cache[i].domainName, name) == 0)
		{
			return cache[i].ipAddress;
		}
	}
	return NULL;
}

void DNSCache::flush()
{
	for (int i = 0; i < size; i++)
	{
		cache[i].domainName = NULL;
		cache[i].ipAddress = NULL;
	}
	size = 0;
}

void DNSCache::print() const
{
	if (size != 0)
	{
		std::cout << std::endl;
		std::cout << "|"
			<< std::setw(3) << std::left << "No." << "|"
			<< std::setw(19) << std::left << "Domain name" << "|"
			<< std::setw(19) << std::left << "IP address" << "|" << std::endl;
		for (int i = 0; i < 45; i++)
		{
			std::cout << "-";
		}
		std::cout << std::endl;
		for (int i = 0; i < size; i++)
		{
			std::cout << "|"
				<< std::setw(3) << std::left << i << "|"
				<< std::setw(19) << std::left << cache[i].domainName << "|"
				<< std::setw(19) << std::left << cache[i].ipAddress << "|" << std::endl;
		}
		std::cout << std::endl;
	}
	else std::cout << "The cache is empty." << std::endl;
}

DNSCache::~DNSCache()
{
	if (cache != nullptr)
	{
		delete[] cache;
	}
}