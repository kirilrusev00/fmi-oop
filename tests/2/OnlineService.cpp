#include "OnlineService.h"
#include <iostream>

OnlineService::OnlineService(const int max_number) :
	port(0), number_connected_devices(0), max_number_connected_devices(max_number)
{
}

OnlineService::OnlineService(int set_port, int set_number_connected_devices, const int max_number) :
	port(set_port), number_connected_devices(set_number_connected_devices), max_number_connected_devices(max_number)
{
}

bool OnlineService::is_full() const
{
	return number_connected_devices == max_number_connected_devices;
}

bool OnlineService::is_empty() const
{
	return number_connected_devices == 0;
}

void OnlineService::setPort(const int& newPort)
{
	port = newPort;
}

const int OnlineService::getPort() const
{
	return port;
}

void OnlineService::connect_device()
{
	if (is_full())
	{
		std::cout << "Unsuccessful connection!\n";
	}
	else
	{
		number_connected_devices++;
		std::cout << "Successful connection!\n";
	}
}
void OnlineService::disconnect_device()
{
	if (is_empty())
	{
		std::cout << "There are no devices connected!\n";
	}
	else
	{
		number_connected_devices--;
	}
}