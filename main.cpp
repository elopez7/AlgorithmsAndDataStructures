#include <map>
#include <iostream>
#include <string>
#include <functional>


class P
{
public:
	P(int, int, float);
	P(std::initializer_list<int>, std::initializer_list<float>);
};

P::P(int,int,float)
{

}

P::P(std::initializer_list<int>, std::initializer_list<float>)
{

}

class Menu
{
private:
	std::map<std::string, void(Menu::*)()> menu;
public:
	Menu();
	~Menu();

	void init_map();
	void take_input();
	void display_commands();
	void start();
	void load();
	void exit();
};

Menu::Menu()
{

}

Menu::~Menu()
{

}

void Menu::init_map()
{
	menu["start"] = &Menu::start;
	menu["load"] = &Menu::load;
	menu["exit"] = &Menu::exit;
	menu["help"] = &Menu::display_commands;
}

void Menu::take_input()
{
	std::cout << "Enter a command:\nType \"help\" a list of available commands: ";
	std::string usrinput;
	std::getline(std::cin, usrinput);

	auto it{ menu.find(usrinput) };

	if (it != menu.end())
	{
		auto calling{ it->second };
		(this->*calling)();
	}
	else
	{
		std::cout << "Nothing could be called\n";
		std::cout << "Nothing could be called\n";
		std::cout << "Nothing could be called\n";
		std::cout << "Nothing could be called\n";
		std::cout << "Nothing could be called\n";
	}
}

void Menu::display_commands()
{
	std::cout << "Available commands\n";
	auto it = menu.begin();
	for (it; it != menu.end(); ++it)
	{
		std::cout << it->first << '\n';
	}
}

void Menu::start()
{
	std::cout << "Game Start\n";
}

void Menu::load()
{
	std::cout << "Game Load\n";
}

void Menu::exit()
{
	std::cout << "Game Exit\n";
}

int main()
{

	Menu menu;
	menu.init_map();
	menu.take_input();

	P pp{ {1,2,3,4,5,6, }, {2.2, 2.3, 5.6} };

	//std::string usrinput;
	//std::getline(std::cin, usrinput);
	
	//Creating arrays on the stack
	int A[5];
	int B[5]{ 1,2,3,4,5 };
	int C[10]{ 2,4,6 };
	int D[5]{ 0 };
	int E[]{ 1,2,3,4,5,6 };

	std::cout << "Array on the stack: \n";

	//Accessing array elements using pointer arithmetic
	for (int i = 0; i < 5; ++i)
	{
		std::cout << *(E + i) << '\n';
	}

	//Creating array on the heap
	int arrSize{ 5 };
	int* p = new int[arrSize];
	int* q = new int[arrSize * 2];
	//Initializing elements individually
	p[0] = 3;
	p[1] = 5;
	p[2] = 7;
	p[3] = 9;
	p[4] = 11;

	std::cout << "Array P on the heap: \n";

	//accessing elements of p
	for (int i = 0; i < arrSize; i++)
	{
		std::cout << p[i] << "\n";
	}

	std::cout << "Array Q on the heap: \n";
	//accessing elements of q
	for (int i = 0; i < (arrSize*2); i++)
	{
		std::cout << q[i] << "\n";
	}

	/***Increasing size of an array***/
	//Copying contents of p into q
	for (int i = 0; i < arrSize; i++)
	{
		q[i] = p[i];
	}

	//Freeing P's memory;
	delete[]p;

	//make p point to new array
	p = q;
	//make q point to nothing
	q = nullptr;

	std::cout << "P now points to Q\n";
	//print p now
	for (int i = 0; i < (arrSize * 2); i++)
	{
		std::cout << p[i] << "\n";
	}

	return 0;
}