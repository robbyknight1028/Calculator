// $Id: Array.cpp 827 2011-02-07 14:20:53Z hillj $

// Honor Pledge:
//
// I pledge that I have neither given nor received any help
// on this assignment.

#include "Base_Array.h"
#include <stdexcept>         // for std::out_of_bounds exception

//
// Array
//
template <typename T>
Base_Array <T>::Base_Array (void):data_(nullptr),cur_size_(0),max_size_(0)
{

}

//
// Array (size_t)
//
template <typename T>
Base_Array <T>::Base_Array (size_t length):data_(new T[length]), cur_size_(length),max_size_(length)
{

}

//
// Array (size_t, char)
//
template <typename T>
Base_Array <T>::Base_Array (size_t length, T fill):data_(new T[length]), cur_size_(length),max_size_(length)
{
    for(size_t i = 0; i < this->size(); i++)
    {
        this->set(i, fill);
    }
    
}

//
// Array (const Array &)
//
template <typename T>
Base_Array <T>::Base_Array (const Base_Array & array):data_(new T[array.size()]),cur_size_(array.size()),max_size_(array.max_size())
{
    for(size_t i = 0; i < this->size(); i++)
    {
        this->set(i, array.get(i));
    }
    
}

//
// ~Array
//
template <typename T>
Base_Array <T>::~Base_Array (void)
{
    delete [] this->data_;
    this-> data_= nullptr;
}

//
// operator =
//
template <typename T>
const Base_Array <T> & Base_Array <T>::operator = (const Base_Array & rhs)
{
    if(*this != rhs)
	{
        delete [] this->data_;
        this->data_= new T[rhs.size()];
        this->cur_size_= rhs.size();
        this->max_size_= rhs.max_size();
        for(size_t i = 0; i < rhs.size(); i++)
        {
            this->set(i, rhs.get(i));
        }
        
    }
    return *this;
}

//
// operator []
//
template <typename T>
T & Base_Array <T>::operator [] (size_t index)
{
    if((index >= this->size()) || (index < 0))
	{
		throw std::out_of_range("");
    }
    return this->data_[index];
}

//
// operator [] 
//
template <typename T>
const T & Base_Array <T>::operator [] (size_t index) const
{
    if((index >= this->size()) || (index < 0))
	{
        throw std::out_of_range("");
    }
    return this->get(index);
}

//
// get
//
template <typename T>
T Base_Array <T>::get (size_t index) const
{
    if(index >= (this->size()) || index < 0){
        throw std::out_of_range("");
    }
    return this->data_[index];
}

//
// set
//
template <typename T>
void Base_Array <T>::set (size_t index, T value)
{
   if(index >= (this->size()) || index < 0)
   {
        throw std::out_of_range("");
   }
    this->data_[index] = value;
}

//
// find (typename)
//
template  <typename T>
int Base_Array <T>::find (T value) const
{
    for(size_t i = 0; i < this->size(); i++)
    {
        if(this->get(i) == value)
        {
            return i;
        }
    }
    return -1;
    
}

//
// find (typename, size_t) 
//
template <typename T>
int Base_Array <T>::find (T val, size_t start) const
{
    if(start >= this->size() || start < 0)
    {
        throw std::out_of_range("");
    }
    for(size_t i = start; i < this->size(); i++)
    {
        if(this->get(i) == val)
        {
            return i;
        }
    }
    return -1;
}

//
// operator ==
//
template <typename T>
bool Base_Array <T>::operator == (const Base_Array & rhs) const
{
    if (this->size() == rhs.size())
	{
		for (size_t i = 0; i < this->size(); i++)
		{
			
			if (this->get(i) != rhs.get(i))
			{
				return false;
			}
		}
		return true;
	}
    return false;

}

//
// operator !=
//
template <typename T>
bool Base_Array <T>::operator != (const Base_Array & rhs) const
{
    size_t end = 0;
    if (this->size() != rhs.size())
	{
        if(this->size() > rhs.size())
        {
            end = rhs.size();
        }
        else
        {
            end = this->size();
        }
        
		for (size_t i = 0; i < end; i++)
		{
			
			if (this->get(i) != rhs.get(i))
			{
				return true;
			}
		}
	}
    return false;

}

//
// fill
//
template <typename T>
void Base_Array <T>::fill (T value)
{
    for(size_t i = 0; i < this->size(); i++)
    {
        this->set(i, value);
    }
    

}
