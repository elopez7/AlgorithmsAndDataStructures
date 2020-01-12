#ifndef MENU_H
#define MENU_H

#include <map>
#include <string>

class menu
{
protected:
	std::map<std::string, bool(menu::*)()> commands;
public:
	menu();
	~menu();

	//virtual bool init_map();
	//virtual bool take_input();
	//virtual bool display_commands();
};

#endif // !MENU_H