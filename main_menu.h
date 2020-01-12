#ifndef MAIN_MENU_H
#define MAIN_MENU_H

#include <map>
#include <string>

class main_menu
{
private:
	std::map<std::string, bool(main_menu::*)()> commands;
public:
	bool init_map();
	bool take_input();
	bool display_commands();
	bool start();
	bool load();
	bool exit();
};

#endif // !MAIN_MENU_H


