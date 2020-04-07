#ifndef COMMANDS_H
#define COMMANDS_H

#include "Group.h"
#include <string>
#include <vector>

class Commands
{
public:
	//enter a command and convert it to vector of strings containing all words in the command
	static std::vector<std::string> enter_command();

	//print instruction for the commands
	static void help();
	//create a new figure and add it to the group of figures
	static bool create(Group& shape_group, std::vector<std::string> input);
	//erase a figure from the group
	static void erase(Group& shape_group, std::vector<std::string> input);
	//translate all figures in the group
	static void translate(Group& shape_group, std::vector<std::string> input);
	//print the figures within a rectangle or a circle
	static void within(Group& shape_group, std::vector<std::string> input);
	//saves the changes to the currently opened file
	static void save(Group& shape_group, std::string& file_path, std::string& file_name);
	//and save the changes to a new file 
	static void saveas(Group& shape_group, std::string& file_path);
	//open an existing file and read the information in it or create a new file
	static bool open(Group& shape_group, std::string& file_path, std::string& file_name);
	//close the document and delete all information about the figures
	static void close(Group& shape_group, std::string& file_name);

	//menu for the commands
	static void menu(Group& shape_group);
};

#endif