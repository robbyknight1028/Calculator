#include "Division_Expr_Node.h"

#include "Expr_Node_Visitor.h"

Division_Expr_Node::Division_Expr_Node (): Binary_Expr_Node()
{

}
Division_Expr_Node::~Division_Expr_Node ()
{
}
int Division_Expr_Node::eval ()
{
    int n2 = this->left_->eval();
    int n1 = this->right_->eval();
    if( n2 != 0)
    {
        int result = n1 / n2;
        return result;
    }
    else
    {
        throw 0;
    }

}
void Division_Expr_Node::accept (Expr_Node_Visitor * v)
{
     v->Visit_Division_Node(this);
}
