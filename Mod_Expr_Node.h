#ifndef _MOD_EXPR_NODE_H_
#define _MOD_EXPR_NODE_H_

#include "Binary_Expr_Node.h"



class Mod_Expr_Node : public Binary_Expr_Node { 
public:  
    Mod_Expr_Node (void); 
    virtual ~Mod_Expr_Node (void); 
    virtual int eval (void);
    virtual void accept (Expr_Node_Visitor * v);
};
#include "Mod_Expr_Node.cpp"
#endif 