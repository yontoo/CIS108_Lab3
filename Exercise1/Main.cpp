using namespace std;

#include <iostream>
#include "Calculator.h"

double Calculator::add(double n1, double n2);

int main()
{
	double fval;	//First Value
	double sval;	//Second value
	char op;		//Operator
	double result;
	cout << ">";
	cin >> fval >> op >> sval;

	if (op == '+') {
		Calculator::add(fval, sval);
	}
	
	else if (op == '-')
	{
		Calculator::subtract(fval, sval);
	}


}