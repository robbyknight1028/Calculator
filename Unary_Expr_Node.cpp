#include "Unary_Expr_Node.cpp"

#include "Expr_Node_Visitor.h"
Unary_Expr_Node::Unary_Expr_Node (Expr_Node child): Expr_Node(), child_(child)
{
    
}
Unary_Expr_Node::~Unary_Expr_Node ()
{

} 
int Unary_Expr_Node::eval ()
{
    if (this->child_) 
    {
         return this->child_->eval ();
    }
}