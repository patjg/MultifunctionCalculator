#ifndef ONOPEN_H
#define ONOPEN_H


#include <string>
#include <vector>

class Menu
{
protected:
	int menuResponse{10};

private:
	const std::vector <std::pair <int, std::string> > menu_options{ {0, "Exit"}, {1, "Main Menu" }, {2, "Basic"}, {3, "Statistical"}, {4, "Converter"}};

public:

	//constructor and desctructor

	//member functions
	int onOpen();
	/*
	void onClose();
	void main_menu();
	void basic_calc();
	void stat_calc();
	void conversion_calc();
	void educational_calc(); //eventually I want this to be an add on to other calculators. If selected, calculators will provide educational information about the calculations performed
	*/


};


//derived BasicCalcMenu class


#include "Menu.h"


class BasicCalcMenu : protected Menu
{
public:
	void onOpen();

};




#endif




