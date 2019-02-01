using namespace std;

#include <iostream>
#include "conio.h"
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
		result = Calculator::add(fval, sval);
	}
	
	else if (op == '-')
	{
		result = Calculator::subtract(fval, sval);
	}

	cout << result << endl;
	_getch();
}