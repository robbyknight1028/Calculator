// $Id: Array.cpp 827 2011-02-07 14:20:53Z hillj $

// Honor Pledge:
//
// I pledge that I have neither given nor received any help
// on this assignment.

#include "Array.h"
#include <stdexcept>         // for std::out_of_bounds exception

//
// Array
//
template <typename T>
Array <T>::Array (void): Base_Array<T>()
{

}

//
// Array (size_t)
//
template <typename T>
Array <T>::Array (size_t length): Base_Array<T>(length)
{
    
    

}

//
// Array (size_t, char)
//
template <typename T>
Array <T>::Array (size_t length, T fill):Base_Array<T>(length, fill)
{
    
}

//
// Array (const Array &)
//
template <typename T>
Array <T>::Array (const Array & array):Base_Array<T>(array)
{
    
}

//
// ~Array
//
template <typename T>
Array <T>::~Array (void)
{
    
}

//
// operator =
//
template <typename T>
const Array <T> & Array <T>::operator = (const Array & rhs)
{
    if(*this != rhs){
        delete [] this->data_;
        this->data_ = nullptr;
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
// resize
//
template <typename T>
void Array <T>::resize (size_t new_size)
{   
    if(new_size != 0){
		size_t finish = 0;
        //find where to stop for loop
        if((this->size()) > new_size)
        {
            finish = new_size;
        }
        else if((this->size()) <= new_size)
        {
            finish = this->size();
        }
        if((this->size()) != 0){
            
            //Copy Array
            T * new_Arr   = nullptr;
            new_Arr = new T[new_size];

            //copy old array to new array
            for(size_t i = 0; i < finish; i++)
            {
                new_Arr[i]=this->data_[i]; 
            }
            
            //remove old array
            delete [] this->data_;
            
            //resize
            this->data_= nullptr;
            this->data_= new T[new_size];

            //restore values to resized arr
            for(size_t r = 0; r < finish ; r++)
            {
                this->data_[r] = new_Arr[r];
            }
            //remove old array copy
            delete [] new_Arr;
        }
        else if((this->size()) == 0)
        {
            delete [] this->data_;
            this->data_= nullptr;
            this->data_= new T[new_size];
        }
        
    }
    else if(new_size == 0)
    {
        delete []this->data_;
        this->data_ = nullptr;
    }
        //set new size info
        this->cur_size_= new_size;
        this->max_size_= this->cur_size_;
}

//
// operator ==
//
template <typename T>
bool Array <T>::operator == (const Array & rhs) const
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
bool Array <T>::operator != (const Array & rhs) const
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

