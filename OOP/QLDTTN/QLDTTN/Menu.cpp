#include "Menu.h"

void Menu::add_item(string item)
{
	menu.push_back(item);
}

void Menu::print_menu()
{
	for (int i = 0; i < menu.size(); i++)
	{
		cout << i  << "." << menu[i] << endl;
	}
}

int Menu::choose()
{	
	int yourchoose;
	do {
		print_menu();
		cout << "Your choose:";cin >> yourchoose;
		string tmp;
		getline(cin, tmp);
	} while (yourchoose > menu.size() || yourchoose < 0);
	return yourchoose;
}
