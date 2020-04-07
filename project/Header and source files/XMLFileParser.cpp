#include "XMLFileParser.h"
#include "Figure.h"
#include "Rectangle.h"
#include "Circle.h"
#include "Line.h"
#include "Group.h"

std::string XMLFileParser::getFileNameFromInput(std::string& input)
{
	
	for (size_t i = 0; i < input.length(); i++)
	{
		if (input[i] == '\"')
		{
			input.erase(input.begin() + i);
		}
	}
	size_t found = input.find_last_of("/\\");
	std::string file_name = input.substr(found + 1);

	return file_name;
}

bool XMLFileParser::read_from_file(const std::string& file_name, std::vector<std::string>& input)
{
	std::ifstream inputFile(file_name, std::ios_base::binary);
	if (inputFile.fail()) {
		return false; // Failed to open file
	}

	if (inputFile.is_open()) {
		std::string line;
		while (getline(inputFile, line)) {
			input.push_back(line);
		}
	}

	inputFile.close();
	return true; // Successfully read file
}

void XMLFileParser::convert_svgVector_to_group(Group& shape_group, std::vector<std::string>& input)
{
	//if is_svg is true input[i] is part of the body of the svg file
	bool is_svg = false;
	for (size_t i = 0; i < input.size(); i++)
	{
		if (input[i].find("</svg>") != std::string::npos)
		{
			is_svg = false;
		}
		if (is_svg == true)
		{
			convert_svgString_to_figure(shape_group, input[i]);
		}
		if (input[i].find("<svg") != std::string::npos)
		{
			is_svg = true;
		}
	}

}

void XMLFileParser::convert_svgString_to_figure(Group& shape_group, std::string input)
{
	std::vector<std::string> words;
	size_t temp = 0;
	size_t i = 0;
	bool is_open = false;
	std::string current_word;
	for (temp; temp <= input.length(); temp++)
	{
		if (is_open == true)
		{
			if (input[temp] == ' ' || input[temp] == '\0')
			{
				words.push_back(current_word);
				current_word.clear();
			}
			else
			{
				current_word.push_back(input[temp]);
			}
		}
		if (input[temp] == '<')
		{
			is_open = true;
		}
		if (input[temp] == '/')
		{
			is_open = false;
		}
	}
	if (words[0] == "circle")
	{
		convert_svgString_to_circle(shape_group, words);
	}
	else if (words[0] == "rect")
	{
		convert_svgString_to_rect(shape_group, words);
	}
	else if (words[0] == "line")
	{
		convert_svgString_to_line(shape_group, words);
	}
	else
	{
		return;
	}
}

int XMLFileParser::extract_int_from_string(std::string& input)
{
	size_t ind1 = input.find_first_of('\"');
	size_t ind2 = input.find_last_of('\"');
	//convert the characters between " "(from ind1 + 1 to ind2 - ind1 - 1) from char to int
	int _number = std::stoi(input.substr(ind1 + 1, ind2 - ind1 - 1));
	return _number;
}

void XMLFileParser::convert_svgString_to_circle(Group& shape_group, std::vector<std::string> input)
{
	Circle* newCircle = new Circle;
	//get the information from all words in input
	//if word.find("cx=") == std::string::npos, word does not contain "cx="
	if (input[1].find("cx=") != std::string::npos)
	{
		newCircle->setXPoint(extract_int_from_string(input[1]));
	}
	if (input[2].find("cy=") != std::string::npos)
	{
		newCircle->setYPoint(extract_int_from_string(input[2]));
	}
	if (input[3].find("r=") != std::string::npos)
	{
		newCircle->setRadius(extract_int_from_string(input[3]));
	}
	if (input.size() > 4 && input[4].find("fill=") != std::string::npos)
	{
		size_t ind1 = input[4].find_first_of('\"');
		size_t ind2 = input[4].find_last_of('\"');
		std::string _fill = input[4].substr(ind1 + 1, ind2 - ind1 - 1);
		newCircle->setFill(_fill);
	}
	//add newCircle to shape_group
	shape_group.push_back(dynamic_cast<Figure*>(newCircle));
}
void XMLFileParser::convert_svgString_to_rect(Group& shape_group, std::vector<std::string> input)
{
	Rectangle* newRectangle = new Rectangle;
	//get the information from all words in input
	//if word.find("x=") == std::string::npos, word does not contain "x="
	if (input[1].find("x=") != std::string::npos)
	{
		newRectangle->setXPoint(extract_int_from_string(input[1]));
	}
	if (input[2].find("y=") != std::string::npos)
	{
		newRectangle->setYPoint(extract_int_from_string(input[2]));
	}
	if (input[3].find("width=") != std::string::npos)
	{
		newRectangle->setWidth(extract_int_from_string(input[3]));
	}
	if (input[4].find("height=") != std::string::npos)
	{
		newRectangle->setHeight(extract_int_from_string(input[4]));
	}
	if (input.size() > 5 && input[5].find("fill=") != std::string::npos)
	{
		size_t ind1 = input[5].find_first_of('\"');
		size_t ind2 = input[5].find_last_of('\"');
		std::string _fill = input[5].substr(ind1 + 1, ind2 - ind1 - 1);
		newRectangle->setFill(_fill);
	}
	//add newRectangle to shape_group
	shape_group.push_back(dynamic_cast<Figure*>(newRectangle));
}
void XMLFileParser::convert_svgString_to_line(Group& shape_group, std::vector<std::string> input)
{
	Line* newLine = new Line;
	//get the information from all words in input
	//if word.find("x1=") == std::string::npos, word does not contain "x1="
	if (input[1].find("x1=") != std::string::npos)
	{
		newLine->setXPoint(extract_int_from_string(input[1]));
	}
	if (input[2].find("y1=") != std::string::npos)
	{
		newLine->setYPoint(extract_int_from_string(input[2]));
	}
	if (input[3].find("x2=") != std::string::npos)
	{
		newLine->setXEnd(extract_int_from_string(input[3]));
	}
	if (input[4].find("y2=") != std::string::npos)
	{
		newLine->setYEnd(extract_int_from_string(input[4]));
	}
	if (input.size() > 5 && input[5].find("fill=") != std::string::npos)
	{
		size_t ind1 = input[5].find_first_of('\"');
		size_t ind2 = input[5].find_last_of('\"');
		std::string _fill = input[5].substr(ind1 + 1, ind2 - ind1 - 1);
		newLine->setFill(_fill);
	}
	//add newLine to shape_group
	shape_group.push_back(dynamic_cast<Figure*>(newLine));
}

std::string XMLFileParser::convert_group_to_svgString(const Group& shape_group)
{
	std::string output;
	std::string svg_begin = "<?xml version=\"1.0\" standalone=\"no\"?>\n<!DOCTYPE svg PUBLIC \"-//W3C//DTD SVG 1.1//EN\"\n\"http://www.w3.org/Graphics/SVG/1.1/DTD/svg11.dtd\">\n<svg>";
	std::string svg_end = "</svg>";

	//svg_body contains the information about the figures(rectangles, circles and lines) in shape_group
	std::vector<std::string> svg_body;
	for (int i = 0; i < shape_group.size(); i++)
	{
		//svg_figure contains the information about the current figure in shape_group
		std::string svg_figure;
		if (shape_group[i]->getType() == Figure::rectangle)
		{
			Rectangle* current_figure = static_cast<Rectangle*>(shape_group[i]);
			svg_figure.append("<rect x=\"");
			svg_figure = svg_figure + std::to_string(current_figure->getPoint().getX());
			svg_figure.append("\" y=\"");
			svg_figure = svg_figure + std::to_string(current_figure->getPoint().getY());
			svg_figure.append("\" width=\"");
			svg_figure = svg_figure + std::to_string(current_figure->getWidth());
			svg_figure.append("\" height=\"");
			svg_figure = svg_figure + std::to_string(current_figure->getHeight());
			//the figure may have no fill
			if (current_figure->getFill() != "\0")
			{
				svg_figure.append("\" fill=\"");
				svg_figure = svg_figure + current_figure->getFill();
			}
			svg_figure.append("\" />");
		}
		if (shape_group[i]->getType() == Figure::circle)
		{
			Circle* current_figure = static_cast<Circle*>(shape_group[i]);
			svg_figure.append("<circle cx=\"");
			svg_figure = svg_figure + std::to_string(current_figure->getPoint().getX());
			svg_figure.append("\" cy=\"");
			svg_figure = svg_figure + std::to_string(current_figure->getPoint().getY());
			svg_figure.append("\" r=\"");
			svg_figure = svg_figure + std::to_string(current_figure->getRadius());
			//the figure may have no fill
			if (current_figure->getFill() != "\0")
			{
				svg_figure.append("\" fill=\"");
				svg_figure = svg_figure + current_figure->getFill();
			}
			svg_figure.append("\" />");
		}
		if (shape_group[i]->getType() == Figure::line)
		{
			Line* current_figure = static_cast<Line*>(shape_group[i]);
			svg_figure.append("<line x1=\"");
			svg_figure = svg_figure + std::to_string(current_figure->getPoint().getX());
			svg_figure.append("\" y1=\"");
			svg_figure = svg_figure + std::to_string(current_figure->getPoint().getY());
			svg_figure.append("\" x2=\"");
			svg_figure = svg_figure + std::to_string(current_figure->getXEnd());
			svg_figure.append("\" y2=\"");
			svg_figure = svg_figure + std::to_string(current_figure->getYEnd());
			//the figure may have no fill
			if (current_figure->getFill() != "\0")
			{
				svg_figure.append("\" fill=\"");
				svg_figure = svg_figure + current_figure->getFill();
			}
			svg_figure.append("\" />");
		}
		svg_body.push_back(svg_figure);
	}

	output.append(svg_begin);
	output.append("\n");
	for (size_t i = 0; i < svg_body.size(); i++)
	{
		output.append(svg_body[i]);
		output.append("\n");
	}
	output.append(svg_end);

	return output;
}

bool XMLFileParser::write_to_file(const std::string& file_name, const std::string& output) 
{
	std::ofstream outputFile(file_name, std::ios_base::binary);
	if (outputFile.fail()) {
		return false; // Failed to open file
	}

	outputFile << output;

	outputFile.close();
	return true; // Successfully wrote to file
}