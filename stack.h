
#ifndef STACK_STACK_H
#define STACK_STACK_H

/*!
 * \file
 * \brief header file
 * \author eg0rzuev
 * \version 1.0
 * \date March 2019 year
 * \warning sorry for creepy code
 *
 * This file contains libraries, constants and description of class Stack
 * ^_^ God save Vadim ^_^
 */


#include <iostream>
#include <cstdlib>

///errors that can occur
enum ERRORS
{
    OUT_OF_MEMORY  = 1;
    STACK_OVERFLOW = 1 << 2;
    STACK_OVERFLOW = 1 << 3;
    OUT_OF_MEMORY   = -100, ///something wrong happens with realloc(...)/calloc(...)
    STACK_OVERFLOW  = -101, ///stack is full and you try push(...) something
    STACK_UNDERFLOW = -102  ///stack is empty and you try to peek() or pop()
};

///important parametrs
enum PARAMS
{
    MULTIPLIER       = 2,  ///multiplier used to resize() Stack with calloc(...)
    DEFAULT_SIZE     = 10, ///deafult capacity of Stack
    SMALL_DIFFERENCE = 3   ///this const shows when it is time to resize() Stack
};

typedef int stkElemT;

/*!
 * \brief class Stack
 * \warning I'm not quite sure about it
 * My own super class Stack, it can do a lot of cool things :)
 * \
 * data_ contains information of array
 * \
 * Stack capacity_ is obvious
 * \
 * error_ field contains information about an error code that occured
 * \
 * methods descriptions are given in functions.cpp
 */

class Stack
{
    public:

        Stack();
        ~Stack();

        bool                    needResizing();

        stkElemT                peek();
        stkElemT                pop();

        int                     push(stkElemT element);
        int                     resize();
        int                     getMaxSize();
        int                     getTop();
        int                     StackOk(); // private
        int                     dump();    // 

    private:

        stkElemT*               data_;
        int                     top_;
        int                     capacity_;
        int                     error_;
};
#endif //STACK_STACK_H
