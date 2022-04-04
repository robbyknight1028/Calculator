#ifndef _CALCULATOR_H_
#define _CALCULATOR_H_

#include "Expr_Tree_Builder.h"
#include <iostream>
#include <sstream>      // std::istringstream
#include <map> 
#include <cstdio>
#include <cstdlib>
#include <exception>
#include <string>
#include <cctype>

class Calculator {
public:
    Calculator(void);  
    ~Calculator (void);
    void menu(void);
    int evalulate(void);
    bool parse_expr ();
private:
    std::string entry_;
    Expr_Tree_Builder * builder_;
};
#include "Calculator.cpp"
#endif 