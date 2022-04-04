#ifndef _EXPR_TREE_BUILDER_H_
#define _EXPR_TREE_BUILDER_H_

#include "Expr_Builder.h"
#include "Stack.h"
#include <typeinfo>

class Expr_Tree_Builder : public Expr_Builder { 
public:
    Expr_Tree_Builder (void);
    virtual ~Expr_Tree_Builder (void);
    virtual void start_expression (void); 
    virtual void build_number (int n); 
    virtual void build_add_operator (void);   
    virtual void build_subtract_operator (void);
    virtual void build_multiplication_operator (void);
    virtual void build_division_operator (void);
    virtual void build_mod_operator (void); 
    virtual void build_open_parenthesis (void);   
    virtual void build_close_parenthesis (void);
    virtual Eval_Expr_Tree * get_expression (void);
private:
    Eval_Expr_Tree * tree_;
    Stack<Number_Expr_Node *> * node_;
    Stack<Binary_Expr_Node *> * op_;
    Binary_Expr_Node * top_;
    Expr_Tree_Builder * builder_;
    bool parentheses_;
    bool prec(Expr_Node * n1);
    void operator_compare(void);

};
#include "Expr_Tree_Builder.cpp"
#endif 