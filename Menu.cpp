#include "Menu.h"
#include <iostream>
#include <string>
#include <iomanip>


using namespace std;

int Menu::onOpen()
{
	cout << "Welcome to the multi-use calculator. Please select a menu option below, or type the menu option and \"help\" to get more information.\n\n";

	for (auto const& itr : menu_options)
	{
		cout << left << setw(5) << itr.first << left << setw(20) << itr.second << "\n\n";
	}
	cout << "\nPlease enter your response here: ";

	do {
		try
		{
			cin >> menuResponse;
		}
		catch (...)
		{
			cout << "There was an error. If you would like to enter a different response, you can do so here, or type 0 to exit the program. ";
		}
	} while (menuResponse != 0);

	switch(menuResponse)
	{
	case 0:
		return 0;
	case 1:
		//recursive?
		break;
	case 2:
		//should go to a basic calculator interface
		break;
	case 3:
		//will go to a statistical calculator
		break;
	case 4:
		//will go to a conversion calculator
		break;
	default:
		return 1;
	}
}








