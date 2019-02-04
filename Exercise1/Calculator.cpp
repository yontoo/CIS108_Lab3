using namespace std;


#include "Calculator.h"
#include <cmath>

double current_mem = 0.0;

//Basic arithmetic funtions. Simple enough to create.
double Calculator::add(double n1, double n2)
{
	return n1 + n2;
}

double Calculator::subtract(double n1, double n2)
{
	return n1 - n2;
}

double Calculator::multiply(double n1, double n2)
{
	return n1 * n2;
}

double Calculator::divide(double n1, double n2)
{
	return n1 / n2;
}

//cmath.h makes this one easy.
double Calculator::power(double n1, double n2)
{
	return pow(n1, n2);
}

//The way I inversed the sign of the result is by just subtracting 0 from it. 
double Calculator::invert(double n1)
{
	return 0.0 - n1;
}

//This is probably the reason why I couldn't get the memory recall to work. Not entirely sure. 
double Calculator::call_mem()
{
	return current_mem;
}

//Write the result of an expression to current_mem
void Calculator::save_mem(double n1)
{
	current_mem = n1;
}

//Set the memory value back to 0
void Calculator::clear_mem()
{
	current_mem = 0.0;
}