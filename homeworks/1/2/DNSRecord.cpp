#include "DNSRecord.h"
#include <cstring>

DNSRecord::DNSRecord():size_domainName(0),size_ipAddress(0)
{
	domainName = new char[size_domainName];
	ipAddress = new char[size_ipAddress];
}

DNSRecord::DNSRecord(const char* name,const char* address)
{
	size_domainName = strlen(name) + 1;
	size_ipAddress = strlen(address) + 1;
	int i = 0;
	domainName = new char[size_domainName];
	for (i = 0; i < size_domainName; i++)
	{
		domainName[i] = name[i];
	}

	ipAddress = new char[size_ipAddress];
	for (i = 0; i < size_ipAddress; i++)
	{
		ipAddress[i] = address[i];
	}
}

DNSRecord::DNSRecord(const DNSRecord& rhs):size_domainName(rhs.size_domainName), size_ipAddress(rhs.size_ipAddress)
{
	int i = 0;
	domainName = new char[size_domainName];
	for (i = 0; i < size_domainName; i++)
	{
		domainName[i] = rhs.domainName[i];
	}

	ipAddress = new char[size_ipAddress];
	for (i = 0; i < size_ipAddress; i++)
	{
		ipAddress[i] = rhs.ipAddress[i];
	}
}

DNSRecord& DNSRecord::operator= (const DNSRecord& rhs) 
{
	if (this != &rhs)
	{
		delete[] domainName;
		delete[] ipAddress;

		size_domainName = rhs.size_domainName;
		size_ipAddress = rhs.size_ipAddress;

		int i;
		domainName = new char[size_domainName];
		for (i = 0; i < size_domainName; i++)
		{
			domainName[i] = rhs.domainName[i];
		}

		ipAddress = new char[size_ipAddress];
		for (i = 0; i < size_ipAddress; i++)
		{
			ipAddress[i] = rhs.ipAddress[i];
		}
	}
	return *this;
}

DNSRecord::~DNSRecord()
{
	delete[] domainName;
	delete[] ipAddress;
}