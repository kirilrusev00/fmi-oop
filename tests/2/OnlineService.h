#ifndef ONLINESERVICE_H
#define ONLINESERVICE_H

class OnlineService
{
private:
	int port;
	int number_connected_devices;
	const int max_number_connected_devices;

	bool is_full() const;
	bool is_empty() const;
public:
	OnlineService(const int max_number = 0);
	OnlineService(int set_port = 0, int set_number_connected_devices = 0, const int max_number = 0);

	void setPort(const int&);

	const int getPort() const;

	void connect_device();
	void disconnect_device();
};

#endif

