#ifndef UTILITIES_H
#define UTILITIES_H

#include "includeHeaders.h"
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

	//bool background functions used for determining the type of any non-digit operators

	static bool isParanethesis(char&);
	static bool isExponent(char&);
	static bool isMultiplication(char&);
	static bool isDivision(char&);
	static bool isAddition(char&);
	static bool isSubstraction(char&);
	static bool isRoot(char&);

	//bool background function that will employ the above subfunctions to determine if the character passed as an argument is an operator or operand
	static bool isOperator(char&);

	//bool background functions that will 

	static bool isDouble(std::string&); 
	static bool isFloat(std::string&);
	static bool isInt(std::string&);

	//ptrinit is designed to take a char pointer in and instantiating another ptr at that address

	static char* ptrinit(char*);

	//

	static std::vector <std::string> pemdas(std::string& numstring)
	{
		int location{ 0 };
		std::string tmpstring;
		std::vector <std::string> resultvec;

		if(numstring.find('^') != std::string::npos || numstring.find('[') != std::string::npos)
		{
			while (numstring.find('^') != std::string::npos)
			{
				location = numstring.find('^');
				char* ptr{&numstring[location]}
				char* rangeendPtr{ptr};
				while (!isOperator(*ptr))
				{
					ptr--;
					
				}

				char* rangestartPtr{ ptr };

				while (!isOperator(*rangeendPtr)) //increment rangeendPtr until another operator is encountered.
				{
					rangeendPtr++;

				}
				tmpstring = numstring.substr(static_cast <size_t> (static_cast <int> (*rangestartPtr)), (rangeendPtr - rangestartPtr)); //tmpstring is set to a substring that starts at the location of rangestartPtr and count is set to rangeendPtr - rangestartPtr
				

			}
		}
		//std::array<char, 9> operators{'(', ')', '^', '[', ']', '*', '/', '+', '-'};
	}
		


	template <typename T> static T determineType(std::string& numstring)
	{

		if (isInt(numstring))
		{
			//method that will progressively cast to int to place into tuple
		}

		else if (isFloat(numstring))
		{
			//method to cast to float for placement into tuple
		}

		else if (!isFloat(numstring))
		{
			//method to cast to double
		}

	}

	static std::tuple <char, int, int> changeToInt(std::string&);
	static std::tuple <char, float, float> changeToFloat(std::string&);
	static std::tuple <char, double, double > changeToDouble(std::string&);


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

	/*template <typename C> static std::pair<C,C> functionIterator(std::string& numstr)
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
*/




	/*bool isTypeSafe()
	{
		
	}*/


	
};







#endif

