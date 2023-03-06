#include "Menu.h"
#include "Calculator.h"
#include <iostream>
#include <string>
#include <iomanip>
#include <vector>
#include <sstream>
#include <memory>
#include <malloc.h>

//#define _WIN32_WINNT 0x601, used for drawing to console later

#include <windows.h>
#include <stdio.h>


using namespace std;

/*int Menu::getConsoleHandle()
{
	HWND console_handle = GetConsoleWindow();
	HDC device_context = GetDC(console_handle);


}*/


void Menu::onOpen()
{
	cout << "Welcome to the multi-use calculator. Please select a menu option below, or type the menu option and \"help\" to get more information.\n\n";

	for (auto const& itr : menu_options)
	{
		cout << left << setw(5) << itr.first << left << setw(20) << itr.second << "\n\n";
	}
	cout << "\nPlease enter your response here: ";


	try
	{
		cin >> menuResponse;
	}
	catch (...)
	{
		cout << "There was an error. If you would like to enter a different response, you can do so here, or type 0 to exit the program. ";
	}


	switch(menuResponse)
	{
	case 0:
		;
	case 1:
		//recursive?
		break;
	case 2:
	{
		BasicCalcMenu basic_menu;
		basic_menu.onOpen();
		break;
	}
	case 3:
		//will go to a statistical calculator
		break;
	case 4:
		//will go to a conversion calculator
		break;
	default:
		;
	}
}




//Methods of derived class Basic Calculator Menu

void BasicCalcMenu::onOpen()
{

	cout << "This calculator can perform these calculations using the provided syntax:\n\tAddition: x + y + ...\n\tSubtraction: x - y - ...\n\tMultiplication: x * y * ...\n\tDivision: x/y/z\n\tExponentiation:x^y\n\tRoot: x[y], where x is the number and y is the root)\n\n\n";
	cout << "You can use parentheses to group calculations as you would in normal arithmetic, and you can provide multiple numbers and perform multiple types of calculations using the provided syntax. If at anytime you need help, you can type \"help\" into the console or type \"exit\" to return to the main menu.\n\n\n";
	cout << "Please enter your calculation here: ";

	//This needs a lot of work. Currently, if there are parentheses, the tmpvec is filled with the innards by using a while loop. I have tried to make
	//all Calculator methods static, so I do not need to create a Calculator object. I will create one if needed, but I don't think it is the best way to do that
	//I have to figure out how to use the template a bit more efficiently so that it can adjust based on the user's input
	string response;
	vector <char> tmpvec;
	int x;
	int y;
	

	getline(cin, response);
	
	if (response == "Help" || response == "help")
	{
		help();
	}
	else if (response == "exit" || response == "EXIT" || response == "Exit")
	{
		;
	}
	else
	{
		for (auto const& itr : response)
		{
			if (itr == '(')
			{
				while (itr != ')')
				{
					tmpvec.push_back(itr);
				}
				for (auto const& itr1 : tmpvec)
				{
					switch (itr)
					{
					case '+': 
						x = static_cast<int> (itr - 1);
						y = static_cast<int> (itr + 1);
						return Calculator::sum(x, y);
					}
				}
			}

		}
	



}

void BasicCalcMenu::help()
{

	char response;
	cout << "This calculator can perform these calculations using the provided syntax:\n\tAddition: x + y + ...\n\tSubtraction: x - y - ...\n\tMultiplication: x * y * ...\n\tDivision: x/y/z\n\tExponentiation:x^y\n\t Root: x[y], where x is the number and y is the root)\n\n\n";
	cout << "You can use parentheses to group calculations as you would in normal arithmetic, and you can provide multiple numbers and perform multiple types of calculations using the provided syntax. If at anytime you need help, you can type \"help\" into the console.\n\n\n";
	cout << "Would you like examples of how to use this calculator? Type Y or N: ";

	cin >> response;

	if (response == 'Y' || response == 'y')
	{
		cout << "If you would like to solve the problem (3+3)/6, simple type that calculation below. You can also perform a calculation such as (3+7)^2/5. This system will understand relatively standard mathematical expressions.\n";
	}
}


void BasicCalcMenu::performCalculation()
{
	string result;

	do
	{
		cout << "Please enter your calculation, type exit to go back to the main menu, or type help: ";
		getline(cin, result);


	} while (result != "exit" && result != "Exit" && result != "EXIT");


}





