#ifndef _ADDITION_EXPR_NODE_H_
#define _ADDITION_EXPR_NODE_H_

#include "Binary_Expr_Node.h"


class Addition_Expr_Node : public Binary_Expr_Node { 
public:  
    Addition_Expr_Node (void); 
    virtual ~Addition_Expr_Node (void); 
    virtual int eval (void);
    virtual void accept (Expr_Node_Visitor * v);
};
#include "Addition_Expr_Node.cpp"
#endif 