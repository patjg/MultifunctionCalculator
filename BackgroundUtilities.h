#ifndef UTILITIES_H
#define UTILITIES_H

#include "includeHeaders.h"
#include "Calculator.h"
#include <iterator>

#define IS_PARA true
#define IS_EXP true
#define IS_ROOT true
#define IS_ADD true
#define IS_SUBT true
#define IS_PROD true
#define IS_DIV true


class BackgroundUtility
{

public:

	//bool background functions used for determining the type of any non-digit operators

	static bool isParanetheses(char&);
	static bool isExponent(char&);
	static bool isMultiplication(char&);
	static bool isDivision(char&);
	static bool isAddition(char&);
	static bool isSubstraction(char&);
	static bool isRoot(char&);

	//bool background function that will employ the above subfunctions to determine if the character passed as an argument is an operator or operand
	static bool isOperator(char&);

	//bool background functions that will 

	static bool isFloat(std::string&);
	static bool isInt(std::string&);

	//ptrinit is designed to take a char pointer in and instantiating another ptr at that address

	static char* ptrinit(char*);

	//
	template <typename T> static std::vector <std::string > pemdas(std::string& numstring) //PEMDAS method
	{
		int L_para_index{ 0 }; //named because this will indicate the location of parentheses in the numstring, but, will also indicate the beginning and end of any given substring to be chunked and removed for calculation
		int R_para_index{ 0 };
		int oper_index{ 0 };
		std::vector <std::string> tmpvec;
		std::vector <std::string> returnvec;
		std::string micro_functionStr;

		while (numstring.size() > 0) //should loop until the entirety of string is cleared
		{
			if (numstring.find('(') != std::string::npos) //if there are parentheses, break up numstring into vector of strings
			{
				L_para_index = numstring.find_last_of('(');
				R_para_index = numstring.find(')');
				micro_functionStr = numstring.substr(numstring[L_para_index], (R_para_index - 1) - (L_para_index + 1));
				numstring.erase(numstring[L_para_index], R_para_index - L_para_index);
				tmpvec.push_back(micro_functionStr);

			}
			else
			{
				tmpvec.push_back(numstring); //if there are no parentheses (or no parentheses left), push back the whole numstring
			}
		}

		for (int z{ 0 }; z < tmpvec.size(); z++) // loop through the tmpvec to find instances of where strings need to be further broken down
		{

			while (tmpvec.at(z).find('^') != std::string::npos) //while loop to resolve all instances of exponents first
			{

				oper_index = tmpvec.at(z).find('^');

				for (int i{ oper_index - 1 }; !isOperator(tmpvec.at(z).at(i)); i--)
				{
					L_para_index = i;
				}

				for (int j{ oper_index + 1 }; !isOperator(tmpvec.at(z).at(j)); j++)
				{
					R_para_index = j;
				}
				micro_functionStr = tmpvec.at(z).substr(tmpvec.at(z)[L_para_index], (R_para_index - L_para_index));
				tmpvec.at(z).erase(tmpvec.at(z).at(L_para_index), (R_para_index + 1) - (L_para_index - 1));
				returnvec.push_back(micro_functionStr);
			}

			while (tmpvec.at(z).find('[') != std::string::npos)
			{
				oper_index = tmpvec.at(z).find('[');
				for (int i{ oper_index + 1}; tmpvec.at(z).at(i) != ']'; i++)
				{
					R_para_index = i;
				}

				for  (int j{oper_index - 1}; !isOperator(tmpvec.at(z).at(j)); j--)
				{
					L_para_index = j;
				}
				micro_functionStr = tmpvec.at(z).substr(tmpvec.at(z)[L_para_index], (R_para_index - L_para_index));
				tmpvec.at(z).erase(tmpvec.at(z).at(L_para_index), (R_para_index + 1) - (L_para_index - 1));
				returnvec.push_back(micro_functionStr);
			}

			while (tmpvec.at(z).find('*') != std::string::npos)
			{
				oper_index = tmpvec.at(z).find('*');
				for (int i{oper_index + 1}; !isOperator(tmpvec.at(z).at(i)); i++)
				{
					R_para_index = i;
				}

				for (int j{oper_index - 1}; !isOperator(tmpvec.at(z).at(j)); j--)
				{
					L_para_index = j;
				}
				micro_functionStr = tmpvec.at(z).substr(tmpvec.at(z)[L_para_index], (R_para_index - L_para_index));
				tmpvec.at(z).erase(tmpvec.at(z).at(L_para_index), (R_para_index + 1) - (L_para_index - 1));
				returnvec.push_back(micro_functionStr);
			}

			while (tmpvec.at(z).find('/') != std::string::npos)
			{
				oper_index = tmpvec.at(z).find('/');
				for (int i{oper_index + 1}; !isOperator(tmpvec.at(z).at(i)); i++)
				{
					R_para_index = i;
				}
				for (int j{oper_index - 1}; !isOperator(tmpvec.at(z).at(j)); j--)
				{
					L_para_index = j;
				}
				micro_functionStr = tmpvec.at(z).substr(tmpvec.at(z)[L_para_index], (R_para_index - L_para_index));
				tmpvec.at(z).erase(tmpvec.at(z).at(L_para_index), (R_para_index + 1) - (L_para_index - 1));
				returnvec.push_back(micro_functionStr);
			}

			while (tmpvec.at(z).find('+') != std::string::npos)
			{
				oper_index = tmpvec.at(z).find('+');
				for (int i{oper_index+1}; !isOperator(tmpvec.at(z).at(i)); i++)
				{
					R_para_index = i;
				}
				for (int j{oper_index - 1}; !isOperator(tmpvec.at(z).at(j)); j--)
				{
					L_para_index = j;
				}
				micro_functionStr = tmpvec.at(z).substr(tmpvec.at(z)[L_para_index], (R_para_index - L_para_index));
				tmpvec.at(z).erase(tmpvec.at(z).at(L_para_index), (R_para_index + 1) - (L_para_index - 1));
				returnvec.push_back(micro_functionStr);
			}

			while (tmpvec.at(z).find('-') != std::string::npos)
			{
				oper_index = tmpvec.at(z).find('-');
				for (int i{oper_index + 1}; !isOperator(tmpvec.at(z).at(i)); i++)
				{
					R_para_index = i;
				}
				for (int j{ oper_index - 1 }; !isOperator(tmpvec.at(z).at(j)); j--)
				{
					L_para_index = j;
				}
				micro_functionStr = tmpvec.at(z).substr(tmpvec.at(z)[L_para_index], (R_para_index - L_para_index));
				tmpvec.at(z).erase(tmpvec.at(z).at(L_para_index), (R_para_index + 1) - (L_para_index - 1));
				returnvec.push_back(micro_functionStr);
			}
		}
	}

	template <typename T> static std::vector <std::pair <T, char> > make_solution_vec(std::vector <std::string>& string_vec)
	{
		std::string tmpstring;
		std::string* operPtr{nullptr};
		int counter{ 0 };
		char type{'a'};
		std::pair <T, char> tmppair;
		std::vector <std::pair <T, char> > returnvec;

		for (int i{ 0 }; i < string_vec.size(); i++)
		{
			for (std::string::iterator stringItr{string_vec.at(i).begin()}; stringItr != string_vec.at(i).end(); ++stringItr)
			{
				counter++;

				if (isOperator(*stringItr))
				{

					tmppair.second = *stringItr;

					tmpstring = string_vec.at(i).substr(0, counter);
					if (type == 'a')
					{
						type = determineType(tmpstring);
					}

					switch (type)
					{
					case 'i':
						tmppair.first = std::stoi(tmpstring);
						break;
					case 'f':
						tmppair.first = std::stof(tmpstring);
						break;
					case 'd':
						tmppair.first = std::stod(tmpstring);
						break;
					default:
						std::cout << "There was an error in identifying the type of the digits provided.\n";
					}
					returnvec.push_back(tmppair);
					string_vec.at(i).erase(string_vec.at(i).begin(), stringItr);
					counter = 0;
				}
			}
		}

		return returnvec;
	}

	

	//if end of substring is not a number or beginning is not a number (that is, it is an operator), need to calculate only by doing that operation when evaluating the vector as a whole rather than internally




	/*template <typename A, typename B = A> A changeType(std::vector<std::string>& pemdasvec, char& type_indicator) //type_indicator SHOULD ALWAYS USE THE DETERMINE TYPE FUNCTION BELOW
	{
		std::vector <std::tuple <char, A...,A> > returnvec;

		std::tuple <char, A...,A, bool, bool> tmptup; //will accept 1 or 2 numerical values and a true or false - true or false and true or false which will indicate whether 2, 1, or none of the values should be trusted as not filler values
		//so, true and true will mean that both numerical values are valid, true and false will indicate that the first num is valid and second is not, false and true will indicate that the first num is not valid and second is
		//and, finally, false and false will mean neither num is valid - meaning that there is really only an operator available, which should mean that the operator should be performed on the result of the tuple before and the tuple
		//after it


		if (type_indicator == 'i' || type_indicator == 'f' || type_indicator == 'd')
		{

			//this is the character that will be placed into the tuple as an identifier for the operator type for later calculation
			char oper;

			//identifies the outer bounds of brackets to identify any root operations
			char bracket2;
			char bracket;

			bool trust_first_num{ true };
			bool trust_second_num{ true };

			//counter variable
			int i{ 0 };

			//these are the integers/double/float that will placed into the tuple
			A x;
			A y;

			std::string stringX;
			std::string stringY;


			for (auto& itr : pemdasvec)
			{
				for (int i{ 0 }; i < itr.size(); i++)
				{
					if (isOperator(itr.at(i))) //find where the operator is in the string within pemdasvec
					{
		
						if (i != 0)
						{
							stringX = itr.substr(0, i);
						}
						else if (i == 0)
						{
							trust_first_num = false;
						}
					

						try
						{
							stringY = itr.substr(i + 1);
						}
						catch (std::out_of_range)
						{
							trust_second_num = false;
						}
						oper = itr.at(i);
					}
				} //will need to build in protection so that error doesnt happen if the value one of the strings is empty. 

				try //try block will attempt to change the type after both substrings are identified
				{
					if (trust_first_num)
					{
						if (type_indicator == 'i')
						{
							x = std::stoi(stringX);
						}
						else if (type_indicator == 'f')
						{
							x = std::stof(stringX);
						}
						else if (type_indicator == 'd')
						{
							x = std::stod(stringX);
						}
					}
					else
					{
						if (type_indicator == 'i')
						{
							x = int();
						}
						else if (type_indicator == 'f')
						{
							x = float();
						}
						else if (type_indicator == 'd')
						{
							x = double();
						}

					}

					if (trust_second_num)
					{
						if (type_indicator == 'i')
						{
							y = std::stoi(stringY);
						}
						else if (type_indicator == 'f')
						{
							y = std::stof(stringY);
						}
						else if (type_indicator == 'd')
						{
							y = std::stod(stringY);
						}
					}
					else//makes a placeholder
					{
						if (type_indicator == 'i') //these types are different for the purposes of later clarification, as you cannot create an empty int, float, or double
						{
							y = float();
						}
						else if (type_indicator == 'f')
						{
							y = int();
						}
						else if (type_indicator == 'd')
						{
							y = int();
						}
					}
					returnvec.push_back(std::make_tuple(oper, x, y, trust_first_num, trust_second_num));
				}
				catch (...)
				{
					std::cout << "There was an error.\n";
					std::cout << "The x substring is currently " << stringX << " and the y substring is " << stringY << '\n';
				}
			}
		}
		return returnvec;
	}*/




			//method to solve vector


	static char determineType(std::string& numstring)
	{

		if (isInt(numstring))
		{
			return 'i';
		}

		else if (isFloat(numstring))
		{
			return 'f';
		}

		else if (!isFloat(numstring))
		{
			return 'd';
		}

		return 'e'; //e to indicate an error

	}


	/*template <typename A> static A solver(std::vector <std::tuple <char, A, A, bool, bool> > calculate)
	{
		std::vector <A> tmpvec;
		std::tuple <char, A> tmptup;
		std::tuple <char, A, A> calculation_tup;
		bool add_to_tup{ false };
		A result;

		for (int i {0}; i < calculate.size(); i++)
		{
			if (calculate.at(i).at(4) && calculate.at(i).at(5)) // if elements 4 and 5 are true, do the following block because both nums can be trusted
			{
				switch (calculate.at(i).at(0))
				{
				case '^':
					Calculator<A>::exponent(calculate.at(i).at(1), calculate.at(i).at(2));
					break;
				case '[':
					Calculator<A>::root(calculate.at(i).at(1), calculate.at(i).at(2));
					break;
				case '*':
					result = calculate.at(i).at(1) * calculate.at(i).at(2);
					break;
				case '/':
					result = calculate.at(i).at(1) / calculate.at(i).at(2);
					break;
				case '+':
					result = calculate.at(i).at(1) + calculate.at(i).at(2);
					break;
				case '-':
					result = calculate.at(i).at(1) - calculate.at(i).at(2);
					break;
				default:
					break;
				}


				if (add_to_tup) //check if there is a temporary tuple
				{
					switch (tmptup[0]) {
					case '^':
						result = Calculator<A>::exponent(tmptup[1], result);
						break;
					case '[':
						result = Calculator<A>::root(tmptup[1], result);
						break;
					case '*':
						result = tmptup[1] * result;
						break;
					case '/':
						result = tmptup[1] / result;
						break;
					case '+':
						result = tmptup[1] + result;
						break;
					case '-':
						result = tmptup[1] + result;
						break;
					default:
						break;
					}
					add_to_tup = false;
				}

				tmpvec.push_back(result);
			}

			else if (!calculate.at(i).at(4) && calculate.at(i).at(5))
			{
				switch (calculate.at(i).at(0))
				{
				case '^':
					Calculator<A>::exponent(tmpvec.back(), calculate.at(i).at(3));
					break;
				case '[':
					Calculator<A>::root(tmpvec.back(), calculate.at(i).at(3));
					break;
				case '*':
					result = tmpvec.back() * calculate.at(i).at(3);
					break;
				case '/':
					result = tmpvec.back() / calculate.at(i).at(3);
					break;
				case '+':
					result = tmpvec.back() + calculate.at(i).at(3);
					break;
				case '-':
					result = tmpvec.back() - calculate.at(i).at(3);
					break;
				default:
					break;
				}

				if (add_to_tup) //check if there is a temporary tuple
				{
					switch (tmptup[0]) {
					case '^':
						result = Calculator<A>::exponent(tmptup[1], result);
						break;
					case '[':
						result = Calculator<A>::root(tmptup[1], result);
						break;
					case '*':
						result = tmptup[1] * result;
						break;
					case '/':
						result = tmptup[1] / result;
						break;
					case '+':
						result = tmptup[1] + result;
						break;
					case '-':
						result = tmptup[1] + result;
						break;
					default:
						break;
					}
					add_to_tup = false;
				}

				tmpvec.push_back(result);

			}

			else if (calculate.at(i).at(4) && !calculate.at(i).at(5))
			{
				tmptup = std::make_tuple(calculate.at(i).at(0), calculate.at(i).at(1));
				add_to_tup = true;

			}

			else if (!calculate.at(i).at(4) && !calculate.at(i).at(5))
			{
				tmptup = std::make_tuple(calculate.at(i).at(0), tmpvec.back());
				add_to_tup = true;
			}
		}
	}*/
};

/*
 *         2 * 3 + 7 - 1 + 3 ^ 3 == 2 * 3 + 7 - 1 + 9 == 6 + 7 - 1 + 9 == 13 - 1 + 9 == 12 + 9 == 21
 * {{^, 3, 3}, {}}
 *
 *		   2*3+7-1 +
 *{{^, 3, 3}, {*, 2, 3}}
 *
 *		   +7-1+
 *{{^, 3, 3}, {*, 2, 3}, {+, 7}}
 *
 *		   -1+
 *{{^, 3, 3}, {*, 2, 3}, {+, 7}, {-, 1} {+}}
 *
 * == {{9}, {6}, (then will perform 6 + 7), see new vec below
 * == {{9}, {13}, (then will perform - 1), see new vec below
 * =={{9}, {12}, (result added togther due to outstanding + sign), see final answer below
 * =={21}
 *
 *
 *
 *
 *
 *
 *Another trial
 *
 *			2 - 3 - 2
 *{{- , 2, 3}, {}}
 *			-2
 *{{-, 2, 3}, {-, 2}}
 *
 *
 *== {-1, -2}
 *== {-3}
 *
 *
 *Another trial
 *
 * numstring = 2^(4[2]) (2 raised to the square root of 4)
 *
 * first, parentheses are found by using find (to find the FIRST instance of a right parentheses) and find_last_of (to find the LAST instance of a left parentheses)
 *
 * then these are pushed back as a STRING into a temporary vector and are deleted from original string of numbers and operators
 *
 * tmpvec = {4[2]} (numstring now == 2^)
 *
 * tmpvec = {4[2], 2^} HOW DO I TELL THE COMPUTER THAT IT IS 2 raised to the power before it rather than the first substring raised by 2
 *
 * what about adding an empty number of whatever type the provided number as a placeholder for the first element of the vector
 *
 * for example, the final vector of tuples would be, in this case,
 *
 * vector <tuple <char, int, int> > function = {{[, 4, 2}, {^, 2, int()}}... then the result of the virst calculation could be placed into the placeholder, so you would end up with {{^, 2, 2}}
 *
 *
 * (3 + 2) ^2    This could be a case where, since the power will be "floating", I could do this {{+, 3, 2}, {^, int(), 2}}
 *
 *
 *
 */







#endif

