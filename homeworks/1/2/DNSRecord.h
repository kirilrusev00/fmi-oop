#ifndef DNSRECORD_H
#define DNSRECORD_H

class DNSRecord {
private:
	//Pointers to dynamic array containing the domain name and the IP address
	char* domainName;
	char* ipAddress;
	
	//The number of chars in the domain name and the IP address
	int size_domainName;
	int size_ipAddress;
public:
	DNSRecord();//default constructor
	DNSRecord(const char*, const char*);//constructor with parameters (the domain name and the IP address)
	DNSRecord(const DNSRecord&);//copy constructor
	DNSRecord& operator= (const DNSRecord&);
	~DNSRecord();//destructor

	friend class DNSCache;
};

#endif
