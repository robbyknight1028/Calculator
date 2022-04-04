#include "Expr_Tree_Builder.h"

Expr_Tree_Builder::Expr_Tree_Builder (): Expr_Builder(), parentheses_(false), tree_(nullptr), node_(nullptr), op_(nullptr), top_(nullptr), builder_(nullptr)
{

}

Expr_Tree_Builder::~Expr_Tree_Builder ()
{
    delete this->tree_;
    delete this->node_;
    delete this->op_;
}

void Expr_Tree_Builder::start_expression ()
{
    this->tree_ = new Eval_Expr_Tree ();
    this->node_ = new Stack<Number_Expr_Node *> ();
    this->op_ = new Stack<Binary_Expr_Node *> ();
}

void Expr_Tree_Builder::build_number (int n)
{
    if(!(this->parentheses_))
    {
        Number_Expr_Node * num = new Number_Expr_Node(n);
        this->node_->push(num);
        this->operator_compare();
    }
    else
    {
        this->builder_->build_number(n);
    }
    
} 

void Expr_Tree_Builder::build_add_operator ()
{
    if(!(this->parentheses_))
    {
        Addition_Expr_Node * add = new Addition_Expr_Node();
        this->op_->push(add);
        this->operator_compare();
    }
    else
    {
        this->builder_->build_add_operator();
    }
    
}

void Expr_Tree_Builder::build_subtract_operator ()
{
    if(!(this->parentheses_))
    {
        Subtraction_Expr_Node * sub = new Subtraction_Expr_Node();
        this->op_->push(sub);
        this->operator_compare();
    }
    else
    {
        this->builder_->build_subtract_operator();
    }
    
}

void Expr_Tree_Builder::build_multiplication_operator ()
{
    if(!(this->parentheses_))
    {
        Multiplication_Expr_Node * mult = new Multiplication_Expr_Node();
        this->op_->push(mult);
        this->operator_compare();
    }
    else
    {
        this->builder_->build_multiplication_operator();
    }
    
}

void Expr_Tree_Builder::build_division_operator ()
{
    if(!(this->parentheses_))
    {
        Division_Expr_Node * div = new Division_Expr_Node();
        this->op_->push(div);
        this->operator_compare();
    }
    else
    {
        this->builder_-> build_division_operator();
    }
    
}

void Expr_Tree_Builder::build_mod_operator ()
{
    if(!(this->parentheses_))
    {
        Mod_Expr_Node * mod = new Mod_Expr_Node();
        this->op_->push(mod);
        this->operator_compare();
    }
    else
    {
        this->builder_->build_mod_operator();
    }
    
} 

Eval_Expr_Tree * Expr_Tree_Builder::get_expression ()
{
    Binary_Expr_Node * top = nullptr;

    if (this->parentheses_)
    {
        throw 1;
    }

    if(!(this->op_->is_empty()))
    {
        top = this->op_->top();
        this->op_->pop();
    }

    while(!(this->node_->is_empty()) && !(this->op_->is_empty()) )
    {
        this->op_->top()->setChild(this->node_->top());
        this->node_->pop();
    }

    while(!(this->op_->is_empty()))
    {
        if(top != nullptr )
        {
            this->op_->top()->setChild(top);
            top= this->op_->top();
            this->op_->pop();
        }
        else
        {
            top = this->op_->top();
            this->op_->pop();
        }
    }

    if(!(this->node_->is_empty()))
    {
        Number_Expr_Node * number = nullptr;
        number = this->node_->top();
        this->node_->pop();
        number->accept(this->tree_);
        delete number;
    }
    else
    {
        top->accept(this->tree_);
        delete top;
    }

    return this->tree_;
}
void Expr_Tree_Builder::build_open_parenthesis ()
{
    this->builder_= new Expr_Tree_Builder();
    this->builder_->start_expression();
    this->parentheses_ = true;
}   
void Expr_Tree_Builder::build_close_parenthesis ()
{
    Eval_Expr_Tree * tree = nullptr;
    this->parentheses_ = false;
    tree = this->builder_->get_expression();
    Number_Expr_Node * num = new Number_Expr_Node(tree->result());
    this->node_->push(num);
    delete tree;
	delete this->builder_;
}
bool Expr_Tree_Builder::prec(Expr_Node * n1 ) 
{ 
    Addition_Expr_Node * add;
    Subtraction_Expr_Node * sub;
    Multiplication_Expr_Node * mult;
    Division_Expr_Node * div;
    Mod_Expr_Node * mod;

	if(typeid(n1) == typeid(mult) || typeid(n1) == typeid(div) || typeid(n1) == typeid(mod))
	{
        return 3;
    }
    else if(typeid(n1) == typeid(add) || typeid(n1) == typeid(sub))
    {
        return 2;
    }
	else
    {
        return -1;
    }

} 

void Expr_Tree_Builder::operator_compare ()
{
    Binary_Expr_Node * builder = nullptr;
    Binary_Expr_Node * top = nullptr;

    if(!(this->op_->is_empty()))
    {
        builder = this->op_->top();
        this->op_->pop();

        while(!(this->node_->is_empty()))
        {
            builder->setChild(this->node_->top());
            this->node_->pop();
        }

        if(!(this->op_->is_empty()))
        {
            top = this->op_->top();
            this->op_->pop();
        }

        while(!(this->op_->is_empty()) && !(this->parentheses_) && this->prec(this->op_->top()) >= this->prec(builder))
        {
            this->op_->top()->setChild(top);
            top = this->op_->top();
            this->op_->pop();
        }

        this->op_->push(builder);

        if(top != nullptr)
        {
            this->op_->push(top);
        }

    }
}
 