#include "Subtraction_Expr_Node.h"

#include "Expr_Node_Visitor.h"

Subtraction_Expr_Node::Subtraction_Expr_Node (): Binary_Expr_Node()
{

}
Subtraction_Expr_Node::~Subtraction_Expr_Node ()
{
}
int Subtraction_Expr_Node::eval ()
{
    int n2 = this->left_->eval();
    int n1 = this->right_->eval();
    int result = n1 - n2;
    return result;
}
void Subtraction_Expr_Node::accept (Expr_Node_Visitor * v)
{
    v->Visit_Subtraction_Node(this);
}
