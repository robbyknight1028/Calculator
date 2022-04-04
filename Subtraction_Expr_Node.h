#ifndef _SUBTRACTION_EXPR_NODE_H_
#define _SUBTRACTION_EXPR_NODE_H_

#include "Binary_Expr_Node.h"


class Subtraction_Expr_Node : public Binary_Expr_Node { 
public:  
    Subtraction_Expr_Node (); 
    virtual ~Subtraction_Expr_Node (void); 
    virtual int eval (void);
    virtual void accept (Expr_Node_Visitor * v);
};
#include "Subtraction_Expr_Node.cpp"
#endif 