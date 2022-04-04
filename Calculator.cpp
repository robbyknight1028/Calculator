
#include "Calculator.h"
Calculator::Calculator (): builder_(nullptr)
{
} 
Calculator::~Calculator ()
{
}
void Calculator::menu()
{
	bool QUIT = false;
	while(!(QUIT))
	{
		while(this->entry_.empty())
		{
			std::cout << "Please ENTER a CALCULATION or TYPE QUIT :" << std::endl;
			std::cout << std::endl;
			std::cout << "~";
			std::getline (std::cin >> std::skipws , this->entry_);
			continue;
		}
		if((this->entry_.compare("QUIT"))==0 || this->entry_.compare("quit")==0)
		{
			this->entry_.clear();
			QUIT = true;
			break;
		}
		
		else if (!(this->entry_.empty()))
		{
			try
      {
				this->builder_ = new Expr_Tree_Builder();
				this->builder_->start_expression();
        // evaluate postfix
			  if(this->parse_expr())
			  {	
					std::cout << "Result:" << this->evalulate() << std::endl;
					std::cout << std::endl;
			  }
				delete this->builder_;
      }
      catch(...)
      {
				std::cout << "Syntax Error!(one)"  << std::endl;
      }	
	
		}
		this->entry_.clear();
		continue;
	}
}
int Calculator::evalulate()
{
	Eval_Expr_Tree * eval = nullptr;
	eval =this->builder_->get_expression();
	int result = eval->result();
	delete eval;
	return result;
}

bool Calculator::parse_expr ()
{
  std::istringstream input(this->entry_); // create a input stream parser std::string token;
	std::string  s_token;
	std::map<char,int>  variable;
	while (getline(input,s_token,' ' ))
	{
		try
		{
			if(s_token.empty())
			{
				continue;
			}
			int token = 0;
			char c_token = '\0';
			bool i_digit = false;
			bool i_alpha = false;
			try 
			{
				i_digit =isdigit(s_token.at(0));
				if(s_token.length() > 1)
				{
					i_digit =isdigit(s_token.at(1));	
				}
			}
			catch(...)
			{
				i_digit= false;
			}
			if(i_digit)
			{
				token= std::stoi(s_token);
			}
			else
			{
				c_token = s_token.at(0);
			}
			if(isalpha(c_token))
			{
				if(!(variable.find(s_token.at(0))->second))
				{
					std::cout << s_token.at(0) << ": ";
					std::cin >> token;
					std::cout << std::endl;
					i_digit = true;
					variable.insert({ s_token.at(0), token }); 
				}
				else
				{
					token = variable.find(s_token.at(0))->second;
				}
			}
			switch(c_token)
			{
				case '(': // code to be executed if token = (
					this->builder_->build_open_parenthesis();
					break;
				case '*': // code to be executed if token = *
					this->builder_->build_multiplication_operator();
					break;
				case '/': // code to be executed if token = /
					this->builder_->build_division_operator();
					break;
				case '+': // code to be executed if token = +
					this->builder_->build_add_operator();
					break;
				case '-': // code to be executed if token = -
					this->builder_->build_subtract_operator();
					break;
				case '%': // code to be executed if token = -
					this->builder_->build_mod_operator();
					break;
				case ')':
					this->builder_->build_open_parenthesis();
					break;
				default: // code to be executed if token is number
					if(i_digit)
					{
						this->builder_->build_number(token);	
					}
					break;
			}//end switch
			token = 0;
			c_token = '\0';
			s_token.clear();
		}
		catch(...)
		{
			return false;
			std::cout << "Syntax Error!(two)" << std::endl;
		}
		variable.clear();
	}//end while
	return true;
}
