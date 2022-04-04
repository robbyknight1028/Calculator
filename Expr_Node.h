#ifndef _EXPR_NODE_H_
#define _EXPR_NODE_H_


class Expr_Node_Visitor;

class Expr_Node {
public:
    Expr_Node (void);   
    virtual ~Expr_Node (void);
    // Used to traverse the tree   
    virtual int eval (void) = 0;
    virtual void accept (Expr_Node_Visitor * v) = 0;
    //virtual void print_preorder (ostream &) = 0;   
    //virtual void print_inorder (ostream &) = 0;
};
#include "Expr_Node.cpp"
#endif 