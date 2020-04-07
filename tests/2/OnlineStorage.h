#ifndef ONLINESTORAGE_H
#define ONLINESTORAGE_H
#include "Storage.h"
#include "OnlineService.h"

class OnlineStorage :public Storage, public OnlineService
{
private:
	const double price_gb;
public:
	//OnlineStorage(const int max_number = 0, const double set_price_gb = 0);
	OnlineStorage(const int max_number = 0, const double set_price_gb = 0, double set_max_capacity = 0, double set_taken_capacity = 0, const char* set_hash_code = "\0", const char* set_name = "\0",
		int set_port = 0, int set_number_connected_devices = 0);

	void upload_file(const double&);
	const double get_price() const;
};

#endif