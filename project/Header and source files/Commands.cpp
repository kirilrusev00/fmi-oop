#include "Commands.h"
#include "XMLFileParser.h"

std::vector<std::string> Commands::enter_command()
{
	std::string input;
	std::vector<std::string> words;
	std::getline(std::cin, input);
	size_t temp = 0;
	size_t i = 0;
	std::string current_word;
	for (temp; temp <= input.length(); temp++)
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
	return words;
}

void Commands::help()
{
	std::string help("\
open: Open a file. (enter a file path or name) \n\
close: Close the currently opened file. \n\
save: Save the changes to the currently opened file.\n\
saveas: Save the changes to a new file. (enter the file path or name of the new file) \n\
exit: Exit the program. (if there is an opened file it will be closed)\n\
print: Print all figures. (circles, rectangles and lines) \n\
create: Create a new figure. (circle, rectangle or line)\n\
\t for a circle: enter cx, cy, r (and fill)\n\
\t for a rectangle: enter x, y , width, height (and fill)\n\
\t for a line: enter x1, y1, x2, y2 (and fill)\n\
erase: Erase a figure. (enter its number) \n\
translate: Translate one or all figures. \n\
\t for one figure: enter its number, vertical= and horizontal= \n\
\t for all figures: enter vertical= and horizontal= \n\
within: Prints all the figures within a circle or a rectangle \n\
\t for a circle: enter cx, cy, r\n\
\t for a rectangle: enter x, y , width, height\n");
	std::cout << help;
}

bool Commands::create(Group& shape_group, std::vector<std::string> input)
{
	input.erase(input.begin());
	if (input[0] == "circle" && input.size() > 3)
	{
		Circle* newCircle = new Circle;
		if (isdigit(input[1][0]) && isdigit(input[2][0]) && isdigit(input[3][0]))
		{
			newCircle->setXPoint(std::stoi(input[1]));
			newCircle->setYPoint(std::stoi(input[2]));
			newCircle->setRadius(std::stoi(input[3]));
		}
		else return false;
		if (input.size() > 4)
		{
			newCircle->setFill(input[4]);
		}
		shape_group.push_back(dynamic_cast<Figure*>(newCircle));
		std::cout << "Successfully created circle (" << shape_group.size() << ")\n";
		return true;
	}
	else if (input[0] == "rectangle" && input.size() > 4)
	{
		Rectangle* newRectangle = new Rectangle;
		if (isdigit(input[1][0]) && isdigit(input[2][0]) && isdigit(input[3][0]) && isdigit(input[4][0]))
		{
			newRectangle->setXPoint(std::stoi(input[1]));
			newRectangle->setYPoint(std::stoi(input[2]));
			newRectangle->setWidth(std::stoi(input[3]));
			newRectangle->setHeight(std::stoi(input[4]));
		}
		else return false;
		if (input.size() > 5)
		{
			newRectangle->setFill(input[5]);
		}
		shape_group.push_back(dynamic_cast<Figure*>(newRectangle));
		std::cout << "Successfully created rectangle (" << shape_group.size() << ")\n";
		return true;
	}
	else if (input[0] == "line" && input.size() > 4)
	{
		Line* newLine = new Line;
		if (isdigit(input[1][0]) && isdigit(input[2][0]) && isdigit(input[3][0]) && isdigit(input[4][0]))
		{
			newLine->setXPoint(std::stoi(input[1]));
			newLine->setYPoint(std::stoi(input[2]));
			newLine->setXEnd(std::stoi(input[3]));
			newLine->setYEnd(std::stoi(input[4]));
		}
		else return false;
		if (input.size() > 5)
		{
			newLine->setFill(input[5]);
		}
		shape_group.push_back(dynamic_cast<Figure*>(newLine));
		std::cout << "Successfully created line (" << shape_group.size() << ")\n";
		return true;
	}
	else return false;
}

void Commands::erase(Group& shape_group, std::vector<std::string> input)
{
	int ind;
	if (isdigit(input[1][0]))
	{
		ind = std::stoi(input[1]);
	}
	else
	{
		std::cout << "Wrong input! Try again.\n";
		return;
	}
	ind--;//input number is bigger with 1 than its index in the vector
	Figure::shape fig_type;
	if (ind >= 0 && ind < shape_group.size())
	{
		fig_type = shape_group[ind]->getType();
	}
	if (shape_group.remove(ind))//if there is a figure with index ind in the group
	{
		std::cout << "Erased a " << fig_type << " (" << ind + 1 << ")\n";
	}
	else//if there is not such a figure
	{
		std::cout << "There is no figure number " << ind + 1 << "!\n";
	}
}

void Commands::translate(Group& shape_group, std::vector<std::string> input)
{
	int vert = 0, hor = 0;
	bool is_wrong_input = false;
	if (isdigit(input[1][0]))
	{
		int index = std::stoi(input[1]);
		index--;//input number is bigger with 1 than its index in the vector
		if (index >= 0 && index < shape_group.size())
		{
			if (input[2].find("vertical=") != std::string::npos)
			{
				size_t ind = input[2].find('=');
				//convert the characters after "=" from char to int
				if (ind + 1 != input[2].length())
				{
					vert = std::stoi(input[2].substr(ind + 1));
				}
				else is_wrong_input = true;
			}
			else is_wrong_input = true;
			if (input[3].find("horizontal=") != std::string::npos)
			{
				size_t ind = input[3].find('=');
				//convert the characters after "=" from char to int
				if (ind + 1 != input[3].length())
				{
					hor = std::stoi(input[3].substr(ind + 1));
				}
				else is_wrong_input = true;
			}
			else is_wrong_input = true;
		}
		else is_wrong_input = true;
		if (is_wrong_input == true)
		{
			std::cout << "Wrong input! Try again.\n";
		}
		else
		{
			shape_group[index]->translate(hor, vert);
			std::cout << "Translated " << shape_group[index]->getType() << "(" << index + 1 << ")\n";
		}
	}
	else
	{
		if (input[1].find("vertical=") != std::string::npos)
		{
			size_t ind = input[1].find('=');
			//convert the characters after "=" from char to int
			if (ind + 1 != input[1].length())
			{
				vert = std::stoi(input[1].substr(ind + 1));
			}
			else is_wrong_input = true;
		}
		else is_wrong_input = true;
		if (input[2].find("horizontal=") != std::string::npos)
		{
			size_t ind = input[2].find('=');
			//convert the characters after "=" from char to int
			if (ind + 1 != input[2].length())
			{
				hor = std::stoi(input[2].substr(ind + 1));
			}
			else is_wrong_input = true;
		}
		else is_wrong_input = true;
		if (is_wrong_input == true)
		{
			std::cout << "Wrong input! Try again.\n";
		}
		else
		{
			for (int i = 0; i < shape_group.size(); i++)
			{
				shape_group[i]->translate(hor, vert);
			}
			std::cout << "Translated all figures\n";
		}
	}
}

void Commands::within(Group& shape_group, std::vector<std::string> input)
{
	Figure* new_fig = new Figure;
	bool is_wrong_input = false;
	if (input[0] == "circle" && input.size() >= 4)
	{
		Circle* newCircle = new Circle;
		if (isdigit(input[1][0]) && isdigit(input[2][0]) && isdigit(input[3][0]))
		{
			newCircle->setXPoint(std::stoi(input[1]));
			newCircle->setYPoint(std::stoi(input[2]));
			newCircle->setRadius(std::stoi(input[3]));
		}
		else is_wrong_input = true;
		if (input.size() > 4)
		{
			newCircle->setFill(input[4]);
		}
		new_fig = dynamic_cast<Figure*>(newCircle);
	}
	if (input[0] == "rectangle" && input.size() >= 5)
	{
		Rectangle* newRectangle = new Rectangle;
		if (isdigit(input[1][0]) && isdigit(input[2][0]) && isdigit(input[3][0]) && isdigit(input[4][0]))
		{
			newRectangle->setXPoint(std::stoi(input[1]));
			newRectangle->setYPoint(std::stoi(input[2]));
			newRectangle->setWidth(std::stoi(input[3]));
			newRectangle->setHeight(std::stoi(input[4]));
		}
		else is_wrong_input = true;
		if (input.size() > 5)
		{
			newRectangle->setFill(input[5]);
		}
		new_fig = dynamic_cast<Figure*>(newRectangle);
	}
	if (is_wrong_input == true)
	{
		std::cout << "Wrong input! Try again.\n";
		return;
	}
	int count = 0;
	count = shape_group.within(*new_fig);
	if (count == 0)// there are no figures within
	{
		std::cout << "No figures are located within " << *new_fig;
	}
	if (count == -1)// the figure is not a rectangle or a circle
	{
		std::cout << "Input a rectangle or a circle!\n";
	}

	delete new_fig;
}

void Commands::save(Group& shape_group, std::string& file_path, std::string& file_name)
{
	if (XMLFileParser::write_to_file(file_path, XMLFileParser::convert_group_to_svgString(shape_group)) == true)
	{
		std::cout << "Successfully saved " << file_name << "\n";
	}
	else std::cout << "Could not save " << file_name << "\n";
}

void Commands::saveas(Group& shape_group, std::string& file_path)
{
	std::string file_name = XMLFileParser::getFileNameFromInput(file_path);
	//check if a file with this name already exists
	std::ifstream inputFile(file_path, std::ios_base::binary);
	while (!inputFile.fail()) {
		std::cout << "A file with this name already exists. Enter a new name:\n";
		std::cin >> file_path;
	}
	//save to a new file
	save(shape_group, file_path, file_name);
}

bool Commands::open(Group& shape_group, std::string& file_path, std::string& file_name)
{
	std::vector<std::string> input;
	if (XMLFileParser::read_from_file(file_path, input) == true)
	{
		std::cout << "Successfully opened " << file_name << "\n";
		XMLFileParser::convert_svgVector_to_group(shape_group, input);
		return true;//the file exists
	}
	else
	{
		std::cout << "Could not open " << file_name << "\n";
		file_name = "new.svg";
		std::cout << "Instead, created a new file " << file_name << "\n";
		return false;//the file is new
	}
}

void Commands::close(Group& shape_group, std::string& file_name)
{
	shape_group.destroyShapes();
	std::cout << "Successfully closed " << file_name << "\n";
}

void Commands::menu(Group& shape_group)
{
	std::vector<std::string> command;
	std::string file_path;
	std::string file_name;
	bool is_opened_file = false;//say if there is an opened file
	bool is_opened_file_new = false;//say if the opened file is new or exists
	std::cout << "Enter help for more information.\n";
	do {
		std::cout << "\n> ";
		command = enter_command();
		size_t num_words_in_command = command.size();
		//the command should be "help ..."
		if (command[0] == "help" && num_words_in_command >= 1)
		{
			help();
			continue;
		}
		//the command should be "open <file_path> ..."
		if (command[0] == "open" && num_words_in_command >= 2)
		{
			file_path = command[1];
			file_name = XMLFileParser::getFileNameFromInput(file_path);
			if (is_opened_file == true)
			{
				std::cout << "There is already an opened file! Choose another command\n";
			}
			else
			{
				if (open(shape_group, file_path, file_name) == false)
				{
					is_opened_file_new = true;
				}
				is_opened_file = true;
			}
			continue;
		}
		//the command should be "exit ..."
		if (command[0] == "exit" && num_words_in_command >= 1)
		{
			//close the currently opened file before exit
			if (is_opened_file == true)
			{
				close(shape_group, file_name);
				is_opened_file = false;
			}
			std::cout << "Exit\n";
			continue;
		}
		if (is_opened_file == true)
		{
			//the command should be "print ..."
			if (command[0] == "print" && num_words_in_command >= 1)
			{
				std::cout << shape_group;
				continue;
			}
			//the command should be "create <information about the new figure> ..."
			if (command[0] == "create" && num_words_in_command >= 2)
			{
				if (create(shape_group, command) == false)
				{
					std::cout << "Wrong input of figure! Try again.\n";
				}
				continue;
			}
			//the command should be "erase <number of a figure> ..."
			if (command[0] == "erase" && num_words_in_command >= 2)
			{
				erase(shape_group, command);
				continue;
			}
			//the command should be "translate <number of a figure> vertical=<int> horizontal=<int> ..."
			//or "translate vertical=<int> horizontal=<int> ..."
			if (command[0] == "translate" && num_words_in_command >= 4)
			{
				translate(shape_group, command);
				continue;
			}
			//the command should be "within <information about a figure> ..."
			if (command[0] == "within"  && num_words_in_command >= 2)
			{
				command.erase(command.begin());//erase the word "within" from command
				within(shape_group, command);
				continue;
			}
			//the command should be "save ..."
			if (command[0] == "save"  && num_words_in_command >= 1)
			{
				if (is_opened_file_new == true)
				{
					std::cout << "The current file is new. Enter a directory to save it in and the file name:\n";
					std::cin >> file_path;
					saveas(shape_group, file_path);
					is_opened_file_new = false;
				}
				else
				{
					save(shape_group, file_path, file_name);
				}
				continue;
			}
			//the command should be "saveas <file_path> ..."
			if (command[0] == "saveas" && num_words_in_command >= 2)
			{
				if (is_opened_file_new == true)
				{
					is_opened_file_new = false;
				}
				saveas(shape_group, command[1]);
				continue;
			}
			//the command should be "close ..."
			if (command[0] == "close" && num_words_in_command >= 1)
			{
				close(shape_group, file_name);
				is_opened_file = false;
				continue;
			}
		}
		else
		{
			std::cout << "There is no opened file! First open a file or create a new one.\n";
			continue;
		}
		std::cout << "Wrong command! Try help\n";
	} while (command[0] != "exit");

}