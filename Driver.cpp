//wrapper
#include "Calculator.h"

//Required
#include <iostream>
#include <string>

int main(int argc, char* argv[])
{
    //Calculator goes here!
    //typedef Array <int> Array;
	Calculator* Calc = new Calculator();
	Calc->menu();
    delete Calc;
	 exit(1);
    return 0;
}