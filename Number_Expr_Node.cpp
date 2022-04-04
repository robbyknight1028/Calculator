
#include "Number_Expr_Node.h"

#include "Expr_Node_Visitor.h"

Number_Expr_Node::Number_Expr_Node (int n): Expr_Node(), number_(n)
{

}
Number_Expr_Node::~Number_Expr_Node () 
{

} 
int Number_Expr_Node::eval ()
{
    int number = this->number_;
    return number ;
}
void  Number_Expr_Node::accept (Expr_Node_Visitor * v)
{
    v->Visit_Number_Node(this);
}