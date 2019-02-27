//Methods used in Stack
//**************************
// Created by egor on 2/26/19.
//**************************

#include "stack.h"

//****************************************************

// ! God save Vadim ^_^
// прочитай мануал для doxygen
// http://www.doxygen.nl/manual/index.html


//****************************************************

// ! Here I create a quite nice Stack (constructor)

// ! When created it has size of 10 elemets (DEFAULT_SIZE)

// ! top -1 means it has no elements

// ! Some space for array of elements is allocated by malloc to data_

// ! If something goes wrong program shuts down

//****************************************************

Stack :: Stack():
        maxSize_(DEFAULT_SIZE),
        top_(-1)
{
    this -> data_ = (stackElementT *) malloc(DEFAULT_SIZE * sizeof(stackElementT)); // calloc вместо malloc
    if(this -> data_ == NULL)
    {
        exit(OUT_OF_MEMORY);
    }
}

//****************************************************

// ! Here is what happens when stack dies (destructor)

// ! When gone all the of the memory used frees

// ! data_ pointer is set to NULL, top_ is -1 ('cause Stack is empty now)

//****************************************************

Stack :: ~Stack() //destructor
{
    free(this -> data_);
    this -> data_ = NULL;
    this -> maxSize_ = 0;
    this -> top_ = -1;
}

//****************************************************

// ! resize allows to put more elements into the Stack

// ! realloc doubles size of data_ (MULTIPLIER == 2)

// ! maxSize_ is brand new now

// ! If something goes wrong program shuts down

//****************************************************

void Stack :: resize() // change size of stack
{
    this -> data_ = (stackElementT *) realloc(this -> data_, maxSize_ * MULTIPLIER * sizeof(stackElementT));
        // проверить возвращаемое значение
    //cout << "RESISE WORKS!" << endl;
    this -> maxSize_ *= MULTIPLIER;
    if(this -> data_ == NULL)
    {
        exit(OUT_OF_MEMORY);
    }
}

//****************************************************

// ! needResising desides whether resize() is needed

// ! if there is SMALL_DIFFERENCE == 3 betweem maxSize_ and top_

// ! then resize() is needed

//****************************************************


bool Stack :: needResizing()
{
    return (this -> maxSize_ - this -> top_) < SMALL_DIFFERENCE;
}


//****************************************************

// ! Returns the last element put in stack

//****************************************************

// проверки в getter-functions

stackElementT Stack ::peek()
{
    return this -> data_[top_];
}


//****************************************************

// ! Returns number of elements in Stack minus one

//****************************************************


int Stack ::getTop()
{
    return this -> top_;
}


//****************************************************

// ! Returns current maxSize_ ( capability ) of Stack

//****************************************************

int Stack :: getMaxSize()
{
    return this -> maxSize_;
}


//****************************************************

// ! Pushes an element on top of a Stack

// ! firstly is checks whether Stack needResizing

// ! if it does resizes it

// ! if stack is full and you push smth then program shuts down

// ! top_ is incremented and element is pushed into Stack

//****************************************************


void Stack :: push(stackElementT element) //push element on Stack top
{
    if(this -> needResizing())
    {
        //cout << "IT DOES NEED RESIZING" << endl;
        this -> resize();
    }

    if(this -> isStackFull())
    {
        cout << "top is " << this -> getTop() << "maxSize is " << this -> getMaxSize() << endl;
        cout << "so fcking strange" << endl;
        exit(STACK_OVERFLOW);
    }
    this -> data_[++this -> top_] = element;
}


//****************************************************

// ! pops element from stack

// ! if it is empty program is shut down

// ! top_ is decremented

// ! returns value of the element popped

//****************************************************


stackElementT Stack :: pop() //pop element from stack top
{
    if(this -> isStackEmpty())
    {
        //cout << "STACK IS EMPTY" << endl;
        exit(STACK_UNDERFLOW);
    }
    return this -> data_[this -> top_--];
}


//****************************************************

// ! checks whether stack is empty or not

//****************************************************


bool Stack :: isStackEmpty()
{
    return this -> top_ < 0;
}


//****************************************************

// ! checks whether stack is full or not

//****************************************************


bool Stack :: isStackFull()
{
    return (this -> top_ + 1) >= (this -> maxSize_);
}
