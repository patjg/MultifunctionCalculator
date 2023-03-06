#ifndef MENU_H
#define MENU_H

#include <iostream>
#include <memory>
#include <malloc.h>

//Includes basic calculator functionality on which other, more complex tasks will be built within classes that inherit Calculator
//Only one result will occur at a time, which has its benefits although it includes using a lot of pointers.

template <typename T>

class Calculator
{
	T result;
	T* calcptr = &result;


public:
	//Need to work on the data members for this classj

	Calculator(){}

	~Calculator(){}

	T getResult()
	{
		return this -> result;
	}

	void add(T& num1, T& num2)
	{
		*calcptr = num1 + num2;
	}

	void subtract(T& num1, T& num2)
	{
		*calcptr = num1 - num2;
	}

	void multiply(T& num1, T& num2)
	{
		*calcptr = num1 * num2;
	}

	void exponent(int& num1, int& exponent)
	{
		result = 1;

		{
			if (exponent > 0)
			{
				for (int i = 1; i <= exponent; i++)
				{
					*calcptr *= num1;
				}
			}
			else if (exponent == 0)
			{
				*calcptr = 1;
			}

			//eventually would like to add square root function that can be used if the user inputs a negative num
		}
	}

	void root(int& num, int& root)
	{
		/*if number is greater than 0, test tmp by multiplying tmp by itself by for loop until either the solution/num == 1 (meaning the nums are the same), or until solution is > num, in
		 which case "Result is not an integer" is output to console
		 */


		//THERE IS AN INFINITE LOOP HERE SOMEWHERE


		if (num > 0 || (num < 0 && root % 2 == 1)) //check if root is a positive integer or, if a negative integer and root is odd, performs calculation
		{
			int count{ 1 }; //declare counter and solution
			int solution{ 1 };

			for (int i{	1 }; solution < num; i++) //will initiate a loop that terminates once solution is at num, i will serve as possible solution, this will attempt 1 * 1 * 1, then 2 * 2 * 2 IF the root is 3
			{


			//actually performs iterative multiplication to check each possible solution (i.e. if root is 3, this will multiply i by itself 3 times)
				do
				{
					solution = i * i;
					count++;

				} while (count < root);

				if (solution / num == 1) //if solution is equal to num, then dividing the 2 will equal 1. I chose this over solution == num because it looks cooler and like I know what I am doing
				{
					*calcptr = count; //set private data member result equal to count
					break;
				}
				solution = 1; //resets
				count = 1; //reset counter
			}
		}

		//if the number input by user == 0, let result = 0
		else if (num == 0)
		{
			result = 0;
		}

		//Puts out explanation for why the even root of a negative value cannot be evaluated.
		else
		{ 
			char response;

			std::cout << "You have entered a negative number (" << num << ") with an even root (" << root << ")\n"
				<< "Would you like further explanation of this error? Type Y or N" << std::endl;

			std::cin >> response;

			if (response == 'Y' || response == 'y')
			{
				std::cout << "If you have an even root such as 2, 4, 6, or 8, then you cannot find the root of a negative number(without using imaginary numbers).\n"
					<< "This is because a negative number multiplied by a negative number is a positive number.So, for example, if you try to take the square root\n of - 4, you would logically try - 2 * -2, but this would equal 4, not - 4." << std::endl;
			}
		}
	}

};





#endif

