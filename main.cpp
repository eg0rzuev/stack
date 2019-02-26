#include <iostream>
#include <cstdlib>
#include "stack.h"


int main()
{
    Stack X;
   // cout << X.getMaxSize() << endl
        X.push(100);
        X.push(200);
        X.push(111);
       // X.~Stack();

    cout <<X.pop() << endl;
    cout <<X.pop() << endl;
    cout <<X.pop() << endl;
   // cout <<X.pop() << endl;



    return 0;
}