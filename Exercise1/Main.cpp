//This program was rough for me and I still have a lot to learn. It was alse a good learning experience for me for problem solving my code.
//Thanks to some helpful classmates like Sibani, Vasilije and Jeremy, as well as the snow day, I was able to finish this.

using namespace std;

#include <iostream>
#include <string>
#include "conio.h"
#include "Calculator.h"
#include "windows.h"



int main()
{
	double fval;				//First Value
	double sval;				//Second value
	string fval_str = "";
	string sval_str = "";
	char curr_key;
	char op = ' ';				//Operator
	double result = 0.0;
	int which_num = 1;			// Indicator for which number is being entered.
	//This felt so jank while I was programming it, so I decided to give it a fitting name.

	SetConsoleTitle("The MacGyvered Calculator");


	cout << ">";

	do
	{
		//At the start of the loop, each character is read individually, which limits the kind of inputs that can be entered, unlike cin.
		curr_key = char(_getch());

		switch (curr_key)
		{
			//Saves current result when S is pressed.
		case 's':
		case 'S':
		{
			Calculator::save_mem(result);
			cout << "Value saved!" << endl;
			break;
		}
		//Clears saved memory value when M is pressed.
		case 'M':
		case 'm':
		{
			Calculator::clear_mem;
			cout << "Memory cleared.";
			break;
		}
		//Inverts the sign of the current result when I is pressed.
		case 'I':
		case 'i':
		{
			result = Calculator::invert(result);
			fval_str = to_string(result);
			cout << "Value inverted: " << result << endl;
			break;
		}
		//Clears all values and resets the number indicator to 1 when C is pressed.
		case 'C':
		case 'c':
		{
			cout << "Value cleared." << endl;
			fval = 0.0;
			sval = 0.0;
			fval_str = "";
			sval_str = "";
			which_num = 1;
			result = 0.0;
			break;
		}
		//Calls the value saved to memory when R is pressed.
		case 'R':
		case 'r':
		{
			result = Calculator::call_mem();
			fval_str = to_string(result);
			cout << "Stored value is " << result << "." << endl;
			break;
		}

		case '1':
		case '2':
		case '3':
		case '4':
		case '5':
		case '6':
		case '7':
		case '8':
		case '9':
		case '0':
		case '.':
		{
			cout << curr_key;

			if (which_num == 1)
			{
				fval_str += curr_key;		//Adds each digit to a string to create a number.
			}

			else
			{
				sval_str += curr_key;
			}
			break;
		}
		case '+':
		case '-':
		case '/':
		case '*':
		case '^':
		{
			if (which_num == 1)
			{
				fval = stod(fval_str);		//When an operator is pressed and the indicator is on the first number, then assign the double "fval" the converted string -> double "fval_str" and set the indicator the the second number. 
				which_num = 2;				//Reset string values and set the op char to the key pressed.
				fval_str = "";
				sval_str = "";
			}
			op = curr_key;
			cout << curr_key;
			break;
		}
		case char(13) :
		{
			//Determine which funtion to call whenever enter is pressed and if there is something in the string "sval_str"
			cout << endl;
			if (sval_str != "")
			{
				sval = stod(sval_str);
				switch (op)
				{
				case '+':
				{
					result = Calculator::add(fval, sval);
					break;
				}
				case'-':
				{
					result = Calculator::subtract(fval, sval);
					break;
				}
				case '/':
				{
					result = Calculator::divide(fval, sval);
					break;
				}
				case '*':
				{
					result = Calculator::multiply(fval, sval);
					break;
				}
				case '^':
				{
					result = Calculator::power(fval, sval);
					break;
				}

				}

			}
			cout << result << endl;
			cout << ">";
			fval_str = to_string(result);
			sval_str = "";
			which_num = 1;
			break;
		}


		}


	}
	//Exit the main function when X is pressed.
	while (curr_key != 'x' && curr_key != 'X');
	return 0;
}






	
}