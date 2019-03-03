#include <iostream>
#include <cstdlib>
#include "stack.h"


int main()
{
    Stack X;
   // cout << X.getMaxSize() << endl
   std::cout<< X.peek() << std::endl;
        X.push(100);
        X.push(200);
        X.push(111);
        X.dump();
       // X.~Stack();

    std::cout <<X.pop() << std::endl;
    std:: cout <<X.pop() << std::endl;
    std::cout <<X.pop() <<std:: endl;
   // cout <<X.pop() << endl;



    return 0;
}