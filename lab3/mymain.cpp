#include "myPtrStack.h"
#include <iostream>


int main() {
    Stack<int> lst;
    lst.append(1);
    lst.append(2);
    lst.append(3);
    std::cout << lst.pop() << std::endl;
    std::cout << lst.pop() << std::endl;
    std::cout << lst.length() << std:: endl;
}