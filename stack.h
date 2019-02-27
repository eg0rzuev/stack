//
// Created by egor on 2/26/19.
//

#ifndef STACK_STACK_H
#define STACK_STACK_H
// Все константы в enum

#include <iostream>
#include <cstdlib>
#define MULTIPLIER 2
#define DEFAULT_SIZE 10
#define OUT_OF_MEMORY -100
#define STACK_OVERFLOW -101
#define STACK_UNDERFLOW -102
#define SMALL_DIFFERENCE 3
// сократить название типа stkElemT
typedef int stackElementT;
using namespace std; // удалить строку

class Stack
{
    public:
        Stack();
        ~Stack();

        void                    push(stackElementT element);
        void                    resize();

        bool                    isStackFull();
        bool                    isStackEmpty();
        bool                    needResizing();

    stackElementT           peek();
        stackElementT           pop();

        int                     getMaxSize();
        int                     getTop();

    private:
        stackElementT*          data_;
        int                     top_;
        int                     maxSize_;       // capacity
};
#endif //STACK_STACK_H
