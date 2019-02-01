using namespace std;

#include <iostream>
#include "conio.h"
#include "Calculator.h"


int main()
{
	double fval = 0;	//First Value
	double sval;		//Second value
	char op;			//Operator
	double result;
	double mem_val;
	while (true)
	{
		std::cout << ">";
		cin >> fval >> op >> sval;


		switch (op)
		{
		case'+':
		{
			result = Calculator::add(fval, sval);
			break;
		}
		case'-':
		{
			result = Calculator::subtract(fval, sval);
			break;
		}
		case'*':
		{
			result = Calculator::multiply(fval, sval);
			break;
		}
		case'/':
		{
			result = Calculator::divide(fval, sval);
			break;
		}

		}

		std::cout << result << endl;
		mem_val = result;			//Probably will remove later, just testing

	}
	return 0;
}