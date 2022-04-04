#ifndef _UNARY_EXPR_NODE_H_
#define _UNARY_EXPR_NODE_H_

#include "Expr_Node.h"

class Unary_Expr_Node : public Expr_Node { 
public: 
    Unary_Expr_Node (Expr_Node child); 
    virtual ~Unary_Expr_Node (void); 
    virtual int eval (void);
protected:
    Expr_Node * child_;
};
#include "Unary_Expr_Node.cpp"
#endif 