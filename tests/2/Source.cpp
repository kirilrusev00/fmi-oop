#include "Storage.h"
#include "OnlineService.h"
#include "OnlineStorage.h"
#include <iostream>

int main()
{
	OnlineStorage a(5, 3.5, 8, 5.5, "3u487yyd12gad21efadf", "OOP-Exams-Dont-Steal", 80, 3);
	a.upload_file(1300);
	double price = a.get_price();
	std::cout << price << "\n";

	system("pause");

}