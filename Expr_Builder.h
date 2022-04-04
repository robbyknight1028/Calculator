#ifndef _EXPR_BUILDER_H_
#define _EXPR_BUILDER_H_

#include "Eval_Expr_Tree.h"

class Expr_Builder { 
public:
    Expr_Builder (void);
    virtual ~Expr_Builder (void);
    virtual void start_expression (void) = 0; 
    virtual void build_number (int n) = 0; 
    virtual void build_add_operator (void) = 0;   
    virtual void build_subtract_operator (void) = 0;
    virtual void build_multiplication_operator (void) = 0;
    virtual void build_division_operator (void) = 0;
    virtual void build_mod_operator (void) = 0; 
    virtual void build_open_parenthesis (void) = 0;   
    virtual void build_close_parenthesis (void) = 0;
    virtual Eval_Expr_Tree * get_expression (void) = 0;
};
#include "Expr_Builder.cpp"
#endif 