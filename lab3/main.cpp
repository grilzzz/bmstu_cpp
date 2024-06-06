#include "PtrStack.h"
#include <iostream>

struct Point {
    int x, y;
};

int main() {
    PtrStack<Point> stack;
    Point p = {1, 2};
    Point p1 = {10, 20};

    stack << &p;
    Point* top;
    stack >> top;

    std::cout << top->x << ", " << top->y << std::endl; 

    stack << &p;

    std::cout << stack->x << ", " << stack->y << std::endl; 


    stack << &p1;

    std::cout << stack->x << ", " << stack->y << std::endl; 

    return 0;
}