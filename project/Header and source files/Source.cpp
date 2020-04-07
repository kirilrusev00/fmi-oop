#include "Group.h"
#include "Commands.h"
#include <iostream>
#include <fstream>

int main()
{
	Group* shapes = &Group::instance();
	Commands::menu(*shapes);
	
	system("pause");

	return 0;
}