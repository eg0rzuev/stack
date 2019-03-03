/*!
 * \file
 * \brief fuction descriptions
 * \author eg0rzuev
 * \version 1.0
 * \date March 2019 year
 * \warning sorry for creepy code
 *
 * This file contains functions(methods) descriptions used in class Stack
 * God save Vadim ^_^
 */

#include "stack.h"

/*!
 * \brief Stack constructor
 * When created it has size of 10 elemets (DEFAULT_SIZE)
 * \
 * top -1 means it has no elements
 * \
 * Some space for array of elements is allocated by calloc to data_
 * \
 * If something goes wrong program shuts down
 */

Stack :: Stack():
        capacity_(DEFAULT_SIZE),
        top_(-1)
{
    this -> data_ = (stkElemT *) calloc(DEFAULT_SIZE * this -> capacity_, sizeof(stkElemT));
    if(this -> data_ == NULL)
    {
        exit(OUT_OF_MEMORY);
    }
}

/*!
 * \brief Stack destructor
 * \
 * When gone all the of the memory used frees
 * \
 * data_ pointer is set to NULL, top_ is -1 ('cause Stack is empty now)
 * \
 */

Stack :: ~Stack() //destructor
{
    free(this -> data_);
    this -> data_ = NULL;
    this -> capacity_ = 0;
    this -> top_ = -1;
}

/*!
 * \brief increases capasity_
 * resize allows to put more elements into the Stack
 * \
 * realloc doubles size of data_ (MULTIPLIER == 2)
 * \
 * capacity_ is brand new now
 * \
 * \return error_ or 0
 */

int Stack :: resize() // change size of stack
{
    this -> data_ = (stkElemT *) realloc(this -> data_, capacity_ * MULTIPLIER * sizeof(stkElemT));

    if (this -> data_ == NULL)
    {
        this -> error_ = OUT_OF_MEMORY;
        this -> dump();
        return this -> error_;
    }
    //cout << "RESISE WORKS!" << endl;
    this -> capacity_ *= MULTIPLIER;
    return 0;
}

/*!
 * \brief decides whether Stack needs resizing or not
 * \return true or false
 */

bool Stack :: needResizing()
{
    return (this -> capacity_ - this -> top_) < SMALL_DIFFERENCE;
}

/*!
 * Checks whether Stack is Ok
 * \return last element put in Stack or error_ code
 */

stkElemT Stack ::peek()
{
    if(this -> StackOk() == STACK_UNDERFLOW)
    {
        this -> dump();
        return this -> error_;
    }
    return this -> data_[top_];
}

/*!
 * \return top_ (number of elements in Stack minus one)
 */

int Stack ::getTop()
{
    return this -> top_;
}

/*!
 * \return capacity_ of Stack
 */

int Stack :: getMaxSize()
{
    return this -> capacity_;
}

/*!
 * \brief push element on Stack top
 * firstly is checks whether Stack needResizing, if it does resizes it
 * \
 * if stack is full and you push smth then program shuts down
 * \
 * top_ is incremented and element is pushed into Stack
 * \param element nothing special
 * \return
 */
int Stack :: push(stkElemT element) //
{
    if(this -> needResizing())
    {
        this -> resize();
    }

    /*if(this -> isStackFull())
    {
        exit(STACK_OVERFLOW);
    }*/

    if(this -> StackOk() == STACK_OVERFLOW)
    {
        this -> dump();
        return this -> error_;
    }
    this -> data_[++this -> top_] = element;
    return 0;
}

/*!
 * \brief pops element from stack
 * \
 * if it is empty program is shut down
 * \
 * top_ is decremented
 * \return value of the element popped
 */

stkElemT Stack :: pop() //pop element from stack top
{
    if(this -> StackOk() == STACK_UNDERFLOW)
    {
        this -> dump();
        return this -> error_;
    }

    return this -> data_[this -> top_--];
}

/*!
 * \brief checks whether stack is ok or not
 * can say if Stacjk is empty or full
 * @return error_ code or 1 (not quite sure about the last one)
 */

int Stack::StackOk()
{
    if(this -> top_ < 0)
    {
        this -> error_ = STACK_UNDERFLOW;
        return STACK_UNDERFLOW;
    }

    if((this -> top_ + 1) >= (this -> capacity_))
    {
        this -> error_ = STACK_OVERFLOW;
        return STACK_OVERFLOW;
    }
    return 1;
}

/*!
 * \brief Stack dump() functions
 * \warning :)
 * writes everything about Stack
 * \
 * State, error_, top_, capacity_, all of the elements inside it
 * \return error_ code
 */

int Stack::dump()
{
    std::cout << std::endl;
    std::cout << "*_* ''''''_____STACK_DUMP_____'''''' *_*" << std::endl;
    std::cout << std::endl;

    std::cout << "  STATE = ";
    if(!this -> StackOk())
    {
        std::cout << "INVALID" << std::endl;
    }
    else
    {
        std::cout <<   "OK!"    << std::endl;
    }

    std::cout << "  ERROR:      " << this -> error_ << std::endl;
    std::cout << "  top_      = " << this -> top_ << std::endl;
    std::cout << "  capacity_ = " << this -> capacity_ << std::endl;
    std::cout << std::endl;

    for (int i = 0; i <= this -> top_; i++)
    {
        std::cout <<  "  data_[" << i << "] = " << "data_[" << &data_[i] << "] = " << this -> data_[i] << std::endl;
    }

    std::cout << "........................................" << std::endl;
    std::cout << std::endl;
    return this -> error_;
}





