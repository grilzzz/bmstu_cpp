#include "declaration.h"
#include "implementation.cpp"
#include <iostream>

void testMatrix(Matrix m) {
    std::cout << "Testing matrix in function:\n";
    std::cout << m.elementAt(0, 0) << std::endl;
}

int main() {
    Matrix m(3); // Создание матрицы 3x3
    m.elementAt(0, 0) = 1;
    m.elementAt(0, 1) = 2;
    m.elementAt(0, 2) = 3;
    m.elementAt(1, 0) = 4;
    m.elementAt(1, 1) = 5;
    m.elementAt(1, 2) = 6;
    m.elementAt(2, 0) = 7;
    m.elementAt(2, 1) = 8;
    m.elementAt(2, 2) = 9;

    std::cout << "Original matrix:\n";
    for (int i = 0; i < m.getSize(); ++i) {
        for (int j = 0; j < m.getSize(); ++j) {
            std::cout << m.elementAt(i, j) << " ";
            if (m.isSaddlePoint(i, j)) {
                std::cout << "seddle element";
            }
        }
        std::cout << std::endl;
    }

    testMatrix(m);
    
    Matrix n = m; 


    std::cout << n.elementAt(0, 0) << std::endl;

    Matrix o(3);


    o = m; // Тестирование оператора присваивания

    std::cout << o.elementAt(0, 0) << std::endl;

    return 0;
}
