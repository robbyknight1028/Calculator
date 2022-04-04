#include "Binary_Expr_Node.h"
Binary_Expr_Node::Binary_Expr_Node (): Expr_Node(), left_(nullptr), right_(nullptr)
{

}
Binary_Expr_Node::~Binary_Expr_Node ()
{
    delete this->left_;
    delete this->right_;
} 
void Binary_Expr_Node::setChild(Expr_Node *  child) 
{
    if ( this->right_ != nullptr)
    {
        this->left_= child;
    }
    else
    {
        this->right_= child;
    }
}

Expr_Node * Binary_Expr_Node::getLeft()
{
    return this->left_;
}
Expr_Node * Binary_Expr_Node::getRight()
{
    return this->right_;
}