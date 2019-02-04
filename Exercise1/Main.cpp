//This program is rough for me and I still have a lot to learn. For the most part, it hits most of the rules we were supposed to follow, with the exception of Memory Recall, Enter and "Any number" functions.
//Which I have an slight idea of doing, but I think it would be almost completely different from how I'm doing it now. There are also a lot of things that break the program. At best you could call this "rough around the edges."
//For example, starting the expression with something like " *3" completely breaks it, and seemingly causes the program to completely skip the op switch. It's probably the whitespace and my inabilty to tell the program how to deal with them.
//I hate to leave it in such an unfinished state, but because of the lack of time and my poor time management this is all I can get out.

using namespace std;

#include <iostream>
#include <string>
#include "conio.h"
#include "Calculator.h"
#include "windows.h"



int main()
{
	double fval = 0;		//First Value
	double sval = 0;		//Second value
	char curr_key;
	char op = ' ';			//Operator
	double result = 0.0;
	double mem_val = 0.0;
	//This felt so jank while I was programming it, so I decided to give it a fitting name.
	SetConsoleTitle("The MacGyvered Calculator");
	while (true)
	{
		cout << ">";
		curr_key = _getch();		//This is used to tell the program which fork to go down, it creates an odd and jarring need to press a key before you can start an expression, but it gets the program functioning.
		
		
		//This conditional has two paths, operators or letter functions, depending on what "curr_key" gets set to.
		if (curr_key != 'X' && curr_key != 'x' && curr_key != 'C' && curr_key != 'c' && curr_key != 'S' && curr_key != 's' && curr_key != 'R' && curr_key != 'r' && curr_key != 'M' && curr_key != 'm' && curr_key != 'I' && curr_key != 'i')
		{
			cin >> fval >> op >> sval;
			switch (op)
			//Switch for the operators. If the op is read as + it adds, - is subtracts so on so forth. This was the easy part until I needed the program to be able to check if fval was a certain character. Which a double can't do.
			{
			
			case'+':
			{
				result += Calculator::add(fval, sval);
				cout << result << endl;
				break;
			}
			case'-':
			{
				result -= Calculator::subtract(fval, sval);
				cout << result << endl;
				break;
			}
			case'*':
			{
					result = Calculator::multiply(fval, sval);
					cout << result << endl;
					break;
			}
			case'/':
			{
				result = Calculator::divide(fval, sval);
				cout << result << endl;
				break;
			}
			case'^':
			{
				result = Calculator::power(fval, sval);
				cout << result << endl;
				break;
			}

			}
		}
		else
		//The switch for the letter functions. Also calls functions from "Calculator.cpp." Mostly works.
		{
			switch (curr_key)
			{
			case 's': 
			case 'S':
			{
				Calculator::save_mem(result);
				cout << "Value saved!" << endl;
				break;
			}
			case 'x':
			case'X':
			{
				return 0;
				break;
			}
			case 'M':
			case 'm':
			{
				Calculator::clear_mem;
				cout << "Memory cleared.";
				break;
			}
			case 'I':
			case 'i':
			{
				result = Calculator::invert(result);
				cout << "Value inverted." << endl;
				break;
			}
			case 'C':
			case 'c':
			{
				cout << "Value cleared." << endl;
				result = 0.0;
				break;
			}

			//Couldn't figure this one out. It was supposed to set the double "mem_val" in this file to hold the funtion in Calculator.cpp's value, but I kept getting the error "a value of type 'double (*)()' cannot be assigned to an entity of type 'double.'"	
			//For now I'm going to comment it out, and come back to it later once I've learned more.

			//case 'R':
			//case 'r':
			//{
				//mem_val = Calculator::call_mem;
			//}
			}

		}
	}





	
}