#ifndef _NUMBER_EXPR_NODE_H_
#define _NUMBER_EXPR_NODE_H_

#include "Expr_Node.h"

class Number_Expr_Node : public Expr_Node { 
public: 
    Number_Expr_Node (int n); 
    virtual ~Number_Expr_Node (void); 
    virtual int eval (void);
    virtual void accept (Expr_Node_Visitor * v);
protected:
    int number_;
};
#include "Number_Expr_Node.cpp"
#endif 