#include "BackgroundUtilities.h"

std::vector<int> BackgroundUtility::changeToInt(std::string& numstring) //function to change to int given a string. will find char that are digits and store in int vec
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
}

char* BackgroundUtility::ptrinit(char* c)
{
	char* d = nullptr;
	d = c;

	return (d);
}


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

bool BackgroundUtility::isDivision(char&)
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

char BackgroundUtility::checkType(char& c)
{
	if (isExponent(c))
	{
		return 'e';
	}
	else if (isMultiplication(c))
	{
		return 'm';
	}
	else if (isDivision(c))
	{
		return 'd';
	}
	else if(isAddition(c))
	{
		return 'c';
	}
	else if (isSubstraction(c))
	{
		return 's';
	}
	else
	{
		return 'z';
	}
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


