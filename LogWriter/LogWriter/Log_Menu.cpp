#include"Log_Menu.h"

void Log_Menu::printMenu(std::string title, std::string end, std::string options[])
{
	int optionsamount = 1;
	int i = 0;
	std::cout << "\n\n" << title << "\n\n";
	for (i; i < optionsamount; i++)
	{
		if (options[i] != "")
		{
			std::cout << i << ") " << options[i] << "\n";
			optionsamount++;
		}
	}
	std::cout << i - 1<<") "<<end;
}

