using namespace std;
#include <iostream>
#include "clsMyStackArr.h"
#include <vector>
#include <string>


int main()
{    
  
    clsMyStackArr<int> myStack;

    myStack.push(10);
    myStack.push(20);
    myStack.push(30);

    std::cout << "Size: " << myStack.Size() << std::endl;
    std::cout << "Top: " << myStack.Top() << std::endl;
    std::cout << "Bottom: " << myStack.Bottom() << std::endl;

    myStack.pop();
    std::cout << "After pop, Top: " << myStack.Top() << std::endl;

    myStack.Print();


    return 0;
}

