#ifndef _EVAL_EXPR_TREE_H_
#define _EVAL_EXPR_TREE_H_

#include "Expr_Node_Visitor.h"

class Eval_Expr_Tree : public Expr_Node_Visitor { 
public:
    Eval_Expr_Tree  (void); 
    virtual ~Eval_Expr_Tree (void);
    virtual void Visit_Addition_Node (Addition_Expr_Node * node);   
    virtual void Visit_Subtraction_Node (Subtraction_Expr_Node * node);
    virtual void Visit_Multiplication_Node (Multiplication_Expr_Node * node);
    virtual void Visit_Division_Node (Division_Expr_Node * node);
    virtual void Visit_Mod_Node (Mod_Expr_Node * node);     
    virtual void Visit_Number_Node (Number_Expr_Node * node);
    //virtual void Visit_Unary_Node (const Unary_Expr_Node & node);
    void reset(void);
    int result (void) const; 
private:
    int result_;

};
#include "Eval_Expr_Tree.cpp"
#endif 