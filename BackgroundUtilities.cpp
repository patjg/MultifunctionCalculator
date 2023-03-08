#include "BackgroundUtilities.h"
#include "includeHeaders.h"

//WIP

/*std::vector<int> BackgroundUtility::changeToInt(std::string& numstring) //function to change to int given a string. will find char that are digits and store in int vec
{
	std::vector<int> returnVec;

    for(auto& itr :numstring)
    {
	    if(isdigit(itr))
	    {
			returnVec.push_back(itr);
	    }
		else
		{
			determineOperator(itr);
		}
    }

    return returnVec;
}*/

char* BackgroundUtility::ptrinit(char* c) //function to initialize a new ptr to the location of the pointer that is passed as an argument, essentially saving a pointer location
{
	char* d = nullptr;
	d = c;

	return (d);
}


//method to change to a char, int, int tuple where char is the operator
std::tuple<char, int, int> BackgroundUtility::changeToInt(std::string& substring)
{
	char oper1;
	char bracket2;
	char bracket;
	int x;
	int y;
	int range{0};
	int range_begin{ 0 };
	char* ptr{ nullptr };
	std::string stringX;
	std::string stringY;
	std::tuple<char, int, int> returnval;

	for (auto& itr : substring)
	{
		if (isOperator(itr)) // this block will run if the function does not include the '[' operator, which indicates a root function, the code will be slightly different
		{
			if (!isRoot(itr))
			{
				stringX = substring.substr(substring[0], (itr - 1)); //stringX and stringY are both substrings of the argument. stringX is anything before the 
				stringY = substring.substr((itr + 1), *substring.end());
				oper1 = itr;
			}
			else if (isRoot(itr))
			{
				bracket = substring.find('[');
				bracket2 = substring.find(']');
				stringX = substring.substr(substring[0], substring[bracket - 1]);
				stringY = substring.substr(substring[bracket + 1], substring[bracket2 - 1]);

				oper1 = itr;
			}

			try 
			{
				x = std::stoi(stringX);
				y = std::stoi(stringY);
				return std::make_tuple(oper1, x, y);
			}catch (...)
			{
				std::cout << "There was an error.\n";
				std::cout << "The x substring is currently " << stringX << " and the y substring is " << stringY << '\n';
				break;
			}
		}

		else if (isOperator(itr))
		{

		}

		else
		{
			std::cout << "There was an error in the input substr: " << substr << std::endl;
		}
	}
	return std::make_tuple('e', -1, -1);
}

//These methods all check the type of character that is encountered by the iterator, not sure if this necessary


bool BackgroundUtility::isParanethesis(char& c) 
{
	if (c == '(' || c == ')')
	{
		return IS_PARA;
	}
	//otherwise return false
	return !IS_PARA;
	
}

bool BackgroundUtility::isExponent(char& c)
{
	if (c == '^')
	{
		return IS_EXP;
	}
	return !IS_EXP;
}

bool BackgroundUtility::isMultiplication(char& c)
{
	if(c == '*')
	{
		return IS_PROD;
	}
	return !IS_PROD;
}

bool BackgroundUtility::isDivision(char& c)
{
	if (c == '/')
	{
		return IS_DIV;
	}
	return !IS_DIV;
}

bool BackgroundUtility::isAddition(char& c)
{
	if (c == '+')
	{
		return IS_ADD;
	}
	return !IS_ADD;
}

bool BackgroundUtility::isSubstraction(char& c)
{
	if (c == '-')
	{
		return IS_SUBT;
	}
	return !IS_SUBT;
}

bool BackgroundUtility::isFloat(std::string& numstr)
{
	std::array<char, 9> operators{ '(', ')', '^', '[', ']', '*', '/', '+', '-' };
	size_t found = numstr.find('.');
	int counter{ 0 };
	if(found != std::string::npos)
	{
		 int dotspot = found;
		 for (auto const& itr = numstr[dotspot]; !isdigit(static_cast<int>(itr));)
		 {
			
			 counter++;
			if (counter > 1)
			{
				return false; //false, in this case, will indicate type double
			}
		 }//need to loop forward until hitting a non digit
	}
	return true; //indicating type float
}

bool BackgroundUtility::isInt(std::string& numstr)
{
	size_t found = numstr.find('.');

	if (found != std::string::npos)
	{
		return false; //if performing the find operation on numstr is not equal to npos (the char '.' is not found), return isInt -> true, if found == anything except npos, return false
	}

	return true;
}



bool BackgroundUtility::isOperator(char& c)
{
	if (isExponent(c) || isMultiplication(c) || isDivision(c) || isAddition(c) || isSubstraction(c))
	{
		return true;
	}

	return false;
}



//function to build functions - functions being actual operable statements - perhaps create a number of sub results to be later joined together

/*I need to have a function that does this (in pseudocode):
 * find any parentheses
 * if parentheses found, iterate forward and store for calculation
 * if additional left parentheses found, clear stored calculation and store new calculation
 * iterate until hitting a right parentheses, complete calculation
 * return to a stored iterator position next to ( just prior to the (that was just iterated through
 * and replace the completed parentheses with the calculated value
 * iterate from '(' to ')' in a similar fashion, store the values and operator, solve
 *
 *
 * if no more parenthesis, (and throughout each calculation iteration) find exponents first, then multiplication sign, then division, then addition, then subtraction (PEMDAS)
 * iterate until no more calculations are remaining and return the result in appropriate formate
 */


