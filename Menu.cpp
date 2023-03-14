#include "Menu.h"
#include "Calculator.h"
#include "BackgroundUtilities.h"
#include <iostream>
#include <string>
#include <iomanip>
#include <vector>
#include <sstream>
#include <memory>
#include <malloc.h>


#include <windows.h>
#include <stdio.h>


using namespace std;



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
	string result;

	do
	{
		cout << "Please enter your calculation, type exit to go back to the main menu, or type help: ";
		getline(cin, result);
		this->userInput = result;


	} while (result != "exit" && result != "Exit" && result != "EXIT");
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


void BasicCalcMenu::setInput(std::string& user_input)
{
	this->userInput = user_input;
}

string BasicCalcMenu::getInput()
{
	return this->userInput;
}





