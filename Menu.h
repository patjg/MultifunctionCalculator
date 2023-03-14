#ifndef ONOPEN_H
#define ONOPEN_H


#include <string>
#include <vector>
#include "BackgroundUtilities.h"

class Menu
{
protected:
	int menuResponse{10};
	std::string userInput;

private:
	const std::vector <std::pair <int, std::string> > menu_options{ {0, "Exit"}, {1, "Main Menu" }, {2, "Basic"}, {3, "Statistical"}, {4, "Converter"}};

public:

	//constructor and desctructor

	//member functions
	void onOpen();
	//int getConsoleHandle();
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

template <typename T>
class BasicCalcMenu : protected Menu
{



public:

	BasicCalcMenu();
	void onOpen();
	void help();
	std::string getInput();
	void setInput(std::string&);


	template <typename T>
	void performCalculation(std::string& numstring)
	{
		std::vector <std::string>  stringvec;

		std::vector <std::pair <T, char> > solution_vec;

		switch (BackgroundUtility::determineType(numstring))
		{
		case 'i':
			stringvec = BackgroundUtility::pemdas<int>(numstring);
			break;

		case 'f':
			stringvec = BackgroundUtility::pemdas<float>(numstring);
			break;

		case 'd':
			stringvec = BackgroundUtility::pemdas<double>(numstring);
			BackgroundUtility::make_solution_vec<double>(stringvec);
		}


	}

};




#endif




