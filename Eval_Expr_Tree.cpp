#include "Eval_Expr_Tree.h"

#include "Addition_Expr_Node.h"
#include "Subtraction_Expr_Node.h"
#include "Division_Expr_Node.h"
#include "Multiplication_Expr_Node.h"
#include "Mod_Expr_Node.h"
#include "Number_Expr_Node.h"
//#include "Unary_Expr_Node.h"

Eval_Expr_Tree::Eval_Expr_Tree  (): result_(0)
{

}
Eval_Expr_Tree::~Eval_Expr_Tree ()
{

}
void Eval_Expr_Tree::Visit_Addition_Node (Addition_Expr_Node * node)
{
    this->result_=node->eval();
}   
void Eval_Expr_Tree::Visit_Subtraction_Node (Subtraction_Expr_Node * node)
{
    this->result_=node->eval();
}
void Eval_Expr_Tree::Visit_Multiplication_Node (Multiplication_Expr_Node * node)
{
    this->result_=node->eval();
}
void Eval_Expr_Tree::Visit_Division_Node (Division_Expr_Node * node)
{
    this->result_=node->eval();
} 
void Eval_Expr_Tree::Visit_Mod_Node (Mod_Expr_Node * node)
{
    this->result_=node->eval();
}     
void Eval_Expr_Tree::Visit_Number_Node (Number_Expr_Node * node)
{
    this->result_= node->eval();
}
/*
void Eval_Expr_Tree::Visit_Unary_Node (const Unary_Expr_Node * node)
{
    //this->result_=node->eval();
}
*/
void Eval_Expr_Tree::reset()
{
    this->result_ = 0;
}
int Eval_Expr_Tree::result () const
{
    return this->result_;
}  