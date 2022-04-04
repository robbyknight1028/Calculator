#include "Multiplication_Expr_Node.h"

#include "Expr_Node_Visitor.h"

Multiplication_Expr_Node::Multiplication_Expr_Node (): Binary_Expr_Node()
{

}
Multiplication_Expr_Node::~Multiplication_Expr_Node ()
{

}
int Multiplication_Expr_Node::eval ()
{
    int n2 = this->left_->eval();
    int n1 = this->right_->eval();
    int result =  n1 * n2;
    return result;
}
void Multiplication_Expr_Node::accept (Expr_Node_Visitor * v)
{
    v->Visit_Multiplication_Node(this);
}
