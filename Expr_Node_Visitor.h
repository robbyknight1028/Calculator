#ifndef _EXPR_NODE_VISITOR_H_
#define _EXPR_NODE_VISITOR_H_

class Addition_Expr_Node;
class Subtraction_Expr_Node;
class Division_Expr_Node;
class Multiplication_Expr_Node;
class Mod_Expr_Node;
class Number_Expr_Node;
//class Unary_Expr_Node;

class Expr_Node_Visitor {
public:
    virtual ~Expr_Node_Visitor (void); 
    virtual void Visit_Addition_Node (Addition_Expr_Node * node) = 0;   
    virtual void Visit_Subtraction_Node (Subtraction_Expr_Node * node) = 0;
    virtual void Visit_Multiplication_Node (Multiplication_Expr_Node * node) = 0;
    virtual void Visit_Division_Node (Division_Expr_Node * node) = 0;
    virtual void Visit_Mod_Node (Mod_Expr_Node * node) = 0;     
    virtual void Visit_Number_Node (Number_Expr_Node * node) = 0;
    //virtual void Visit_Unary_Node (const Unary_Expr_Node & node) = 0;  
};
#include "Expr_Node_Visitor.cpp"
#endif 