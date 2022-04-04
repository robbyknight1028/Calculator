#include "Addition_Expr_Node.h"

#include "Expr_Node_Visitor.h"

Addition_Expr_Node::Addition_Expr_Node (): Binary_Expr_Node()
{

}
Addition_Expr_Node::~Addition_Expr_Node ()
{
}
int Addition_Expr_Node::eval ()
{
    int n2 = this->left_->eval();
    int n1 = this->right_->eval();
    int result = n1 + n2;
    return result;
}
void Addition_Expr_Node::accept (Expr_Node_Visitor * v)
{
    v->Visit_Addition_Node(this);

}
