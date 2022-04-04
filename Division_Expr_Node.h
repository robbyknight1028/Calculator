#ifndef _DIVISION_EXPR_NODE_H_
#define _DIVISION_EXPR_NODE_H_

#include "Binary_Expr_Node.h"


class Division_Expr_Node : public Binary_Expr_Node { 
public:  
    Division_Expr_Node (void); 
    virtual ~Division_Expr_Node (void); 
    virtual int eval (void);
    virtual void accept (Expr_Node_Visitor * v);
};
#include "Division_Expr_Node.cpp"
#endif 