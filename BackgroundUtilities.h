#ifndef UTILITIES_H
#define UTILITIES_H

#include <cctype>
#include <iostream>
#include <vector>
#include "Calculator.h"

#define IS_PARA true
#define IS_EXP true
#define IS_ROOT true
#define IS_ADD true
#define IS_SUBT true
#define IS_PROD true
#define IS_DIV true
#define TYPE_IS checkType(n)

class BackgroundUtility
{

private:

	static char* modptr = nullptr;

public:

	static bool isParanethesis(char&);
	static bool isExponent(char&);
	static bool isMultiplication(char&);
	static bool isDivision(char&);
	static bool isAddition(char&);
	static bool isSubstraction(char&);
	static char checkType(char&);

	template <typename T> static T determineType(std::string& numstring)
	{

		T return_value;

		if(!numstring.find('.')) //if no dot is found in the numstring, return int
		{
			return_value = int();
		}
		else if (numstring.size() > 0)
		{
			for (auto const& itr : numstring)
			{
				if (itr == '.' && isdigit(static_cast<int>(itr + 2)))
				{
					return_value = double();
				}
			}
		}

		else
		{
				return_value = float();
		}

		try
		{
			return return_value;
		}
		catch(...)
		{
			std::cout << "There was an error in identifying the type of data.\n";
		}

	}

	static std::vector<int> changeToInt(std::string&);
	char* ptrinit(char* c);
	static std::vector<float> changeToFloat(std::string&);
	static double changeToDouble(std::string&);


	template <typename A> static A function_solver(std::pair<A,A>& bits, char& operation)
	{

		switch(operation)
		{
		case 1:			//behavior determined by the integer value returned by the determine operator function (this one is add
			return (bits.first + bits.second);
		case 2:			//case 2 == subtraction
			return (bits.first - bits.second);
		case 3:			//case 3 == multiplication
			return (bits.first * bits.second);
		case 4:			//case 4 == division
			return(bits.first / bits.second);
		case 5:			//case 5 == exponent
			return(Calculator<A>::exponent(bits.first, bits.second));
		case 6:			//case 6 == root
			return(Calculator<A>::root(bits.first, bits.second));
		default:
			break;
		}
	}

	template <typename C> static std::pair<C,C> functionIterator(std::string& numstr)
	{
		C result;
		std::pair <C,C> returnpair;
		char* startitr;
		char* enditr;

		for (auto& itr : numstr)
		{

			if (BackgroundUtility::isParanethesis(itr))
			{
				while(itr == '(')
				{
					startitr = &itr;
				}
				while(itr != ')')
				{
					enditr = &itr;

					if (checkType(itr) == 'e')
					{
						C x = static_cast<C>(itr - 1);
						C y = static_cast<C>(itr + 1);
						returnpair.first = x;
						returnpair.second = y;
						return returnpair;
					}
				}

				auto const& func_itr = startitr;
				//I am not sure what to do with this - I might need to create a function that returns a pointer to the operator;

				while (func_itr != enditr)
				{
					if (!isdigit(static_cast<int>(*func_itr)))
					{
						if (checkType(*func_itr) == 'e')
						{
							returnpair.first = *(func_itr - 1);
							returnpair.second = *(func_itr + 1);
							return returnpair;
						}
						else
						{
							continue;
						}
					}
					
					//i think a nested while loop may work here. i need something that progresses through PEMDAS in order. each character should be checked for the type then it will call the solve function in order
				}
			}
		}
	}





	/*bool isTypeSafe()
	{
		
	}*/


	
};







#endif

