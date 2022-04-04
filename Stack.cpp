// $Id: Stack.cpp 827 2011-02-07 14:20:53Z hillj $

// Honor Pledge:
//
// I pledge that I have neither given nor received any help
// on this assignment.



#include "Stack.h"

//
// Stack
//
template <typename T>
Stack <T>::Stack (void): Array<T>(),size_(0)
{

}

//
// Stack
//
template <typename T>
Stack <T>::Stack (const Stack<T> & stack): Array<T>(stack), size_(stack.size_)
{
    /**T * copy_data = new T[stack.size()];
    for(size_t i = 0; i < stack.size(); i++)
    {
        copy_data[i]=stack.top();
        stack.pop(); 
    }
    size_t r = stack.size()-1;
    for(size_t p = 0; p < stack.size(); p++)
    {
        this->push(copy_data[r]);
        r--;
    }
    delete [] copy_data;*/
}

//
// ~Stack
//
template <typename T>
Stack <T>::~Stack (void)
{
}

//
// push
//
template <typename T>
void Stack <T>::push (T element)
{
    this->resize((this->size()) + 1);
    this->size_++;
    this->set(((this->size()) - 1), element);
}

//
// pop
//
template <typename T>
void Stack <T>::pop (void)
{   
    if(!(this->is_empty()))
    {
        this->resize((this->size()) - 1);
        this->size_ --; 
    }
    else
    {
        throw empty_exception();
    }
}

//
// operator =
//
template <typename T>
const Stack <T> & Stack <T>::operator = (const Stack & rhs)
{
    if(*this != rhs)
    {
         T * copy_data = new T[rhs.size()];
        for(size_t i = 0; i < rhs.size(); i++)
        {
            copy_data[i]=rhs.top();
            rhs.pop(); 
        }
        size_t r = rhs.size()-1;
        for(size_t p = 0; p < rhs.size(); p++)
        {
            this->push(copy_data[r]);
            r--;
        }
        delete [] copy_data;
    }
    return *this;

}

//
// clear
//
template <typename T>
void Stack <T>::clear (void)
{
    if(!(this->is_empty()))
    {
        size_t length = this->size();
        for(size_t i = 0; i < length; i++)
        {
            this->pop();
        }
    }
    else
    {
        throw empty_exception();
    }
}

//
// top
//
template <typename T>
T Stack <T>::top (void) const
{
    if(!(this->is_empty()))
    {
        return (this->get(this->size() - 1));
    }
    else
    {
        throw empty_exception();
    }
    
}
