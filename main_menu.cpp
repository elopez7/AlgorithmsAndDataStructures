#include "main_menu.h"

#include <iostream>

bool main_menu::init_map()
{
	commands["start"] = &main_menu::start;
	commands["load"] = &main_menu::load;
	commands["exit"] = &main_menu::exit;

	return true;
}

bool main_menu::take_input()
{
	display_commands();

	std::string usrinput;
	std::getline(std::cin, usrinput);

	auto it{ commands.find(usrinput) };

	if (it != commands.end())
	{
		auto command{ it->second };
		(this->*command)();
		return true;
	}

	std::cout << "Invalid command, try again";
	return false;
}

bool main_menu::display_commands()
{
	std::cout << "MAIN MENU\n"
		<< "Available commands\n";

	auto it = commands.begin();
	for (it; it != commands.end(); ++it)
	{
		std::cout << it->first << '\n';
	}
	return true;
}

bool main_menu::start()
{
	std::cout << "Game Start\n";
	return true;
}

bool main_menu::load()
{
	std::cout << "Game Load\n";
	return true;
}

bool main_menu::exit()
{
	std::cout << "Game Exit\n";
	return true;
}
