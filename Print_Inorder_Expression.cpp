#include "Print_Inorder_Expression.h"
Print_Inorder_Expression::Print_Inorder_Expression (std::ostream & out): out_(out)
{

}
Print_Inorder_Expression::~Print_Inorder_Expression (void); 
void Print_Inorder_Expression::Visit_Addition_Node (const Addition_Expr_Node & node)
{
    this->out_=node.eval();

}   
void Print_Inorder_Expression::Visit_Subtraction_Node (const Subtraction_Expr_Node & node)
{
    this->out_=node.eval();
}
void Print_Inorder_Expression::Visit_Multiplication_Node (const Multiplication_Expr_Node & node)
{
    this->out_=node.eval();
}
void Print_Inorder_Expression::Visit_Division_Node (const Division_Expr_Node & node)
{
    this->out_=node.eval();
} 
void Print_Inorder_Expression::Visit_Mod_Node (const Mod_Expr_Node & node)
{
    this->out_=node.eval();
}     
void Print_Inorder_Expression::Visit_Number_Node (const Number_Expr_Node & node)
{
    this->out_=node.eval();
}
void Print_Inorder_Expression::Visit_Unary_Node (const Unary_Expr_Node & node)
{
    //this->out_=node.eval();
}
