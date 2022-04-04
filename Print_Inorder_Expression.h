#ifndef _PRINT_INORDER_EXPRESSION_H_
#define _PRINT_INORDER_EXPRESSION_H_

#include "Expr_Node_Visitor.h"

class Print_Inorder_Expression : public Expr_Node_Visitor 
{ 
public: 
Print_Inorder_Expression (std::ostream & out);
virtual ~Print_Inorder_Expression (void); 
virtual void Visit_Addition_Node (const Addition_Expr_Node & node);   
virtual void Visit_Subtraction_Node (const Subtraction_Expr_Node & node);
virtual void Visit_Multiplication_Node (const Multiplication_Expr_Node & node);
virtual void Visit_Division_Node (const Division_Expr_Node & node);
virtual void Visit_Mod_Node (const Mod_Expr_Node & node);     
virtual void Visit_Number_Node (const Number_Expr_Node & node);
virtual void Visit_Unary_Node (const Unary_Expr_Node & node);
private:
    // output stream   
    std::ostream out_;
};
#include "Print_Inorder_Expression.cpp"
#endif 