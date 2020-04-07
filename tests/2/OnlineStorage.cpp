#include "OnlineStorage.h"
/*
OnlineStorage::OnlineStorage(const int max_number, const double set_price_gb) :
	OnlineService(max_number), price_gb(set_price_gb)
{

}
*/
OnlineStorage::OnlineStorage(const int max_number, const double set_price_gb, double set_max_capacity, double set_taken_capacity, 
	const char* set_hash_code, const char* set_name, int set_port, int set_number_connected_devices) :
	Storage(set_max_capacity, set_taken_capacity, set_hash_code, set_name), OnlineService(set_port, set_number_connected_devices, max_number), price_gb(set_price_gb)
{

}


void OnlineStorage::upload_file(const double& file_size_in_mb)
{
	connect_device();
	double file_size_in_gb = file_size_in_mb / 1024;
	double capacity = getTakenCapacity() + file_size_in_gb;
	setTakenCapacity(capacity);
}
const double OnlineStorage::get_price() const
{
	int capacity = (int)getTakenCapacity() + 1;
	
	return price_gb * capacity;
}
