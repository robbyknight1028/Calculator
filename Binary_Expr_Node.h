#ifndef _BINARY_EXPR_NODE_H_
#define _BINARY_EXPR_NODE_H_

#include "Expr_Node.h"
#include <exception>
class Binary_Expr_Node : public Expr_Node { 
public: 
    Binary_Expr_Node (void); 
    virtual ~Binary_Expr_Node (void);
    virtual void setChild(Expr_Node * child);
    virtual Expr_Node * getLeft(void);
    virtual Expr_Node * getRight(void);   
    virtual int eval (void) = 0;
protected:
    Expr_Node * right_;   
    Expr_Node * left_;
};
#include "Binary_Expr_Node.cpp"
#endif 