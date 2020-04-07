#ifndef XMLFILEPARSER_H
#define XMLFILEPARSER_H

#include "Group.h"
#include <iostream>
#include <fstream>
#include <string>
#include <vector>

class XMLFileParser
{
public:
	//extract the name of a file from its path
	static std::string getFileNameFromInput(std::string& input);
	//get input from file_name 
	static bool read_from_file(const std::string& file_name, std::vector<std::string>& input);

	//add the figures in input to shape_group
	static void convert_svgVector_to_group(Group& shape_group, std::vector<std::string>& input);
	//create a new figure in shape_group with the information in input
	static void convert_svgString_to_figure(Group& shape_group, std::string input);
	//convert the symbols between " " from char to int
	static int extract_int_from_string(std::string&);
	//create a circle, a rectangle or a line in shape_group with the information ininput from input[begin] to input[end] 
	static void convert_svgString_to_circle(Group& shape_group, std::vector<std::string> input);
	static void convert_svgString_to_rect(Group& shape_group, std::vector<std::string> input);
	static void convert_svgString_to_line(Group& shape_group, std::vector<std::string> input);
	
	//create the text of a svg file containing a shape_group
	static std::string convert_group_to_svgString(const Group& shape_group);

	//write output in file_name
	static bool write_to_file(const std::string& file_name, const std::string& output);
};

#endif