#include "declaration.h"
#include "implementation.cpp"
#include <iostream>

void printBoard(const TicTacToe& game) {
    for (int i = 0; i < game.getSize(); ++i) {
        for (int j = 0; j < game.getSize(); ++j) {
            std::cout << game(i, j) << ' ';
        }
        std::cout << std::endl;
    }
}

int main() {
    int boardSize = 3; 
    TicTacToe game(boardSize);

    std::cout << "size: " << game.getSize() << std::endl << std::endl;

    game(0,0) = 'X';
    game(1,1) = 'O';
    game(2,2) = 'X';
    printBoard(game);
    std::cout << std::endl;

    std::cout << "is end " << (game.isFinalState() ? "yes" : "no") << std::endl;


    char& cell = game(1, 1);
    std::cout << "on (1, 1): " << cell << std::endl;
    cell = 'X';
    std::cout << "new on (1, 1):" << cell << std::endl;
    printBoard(game);
    std::cout << std::endl;

    std::cout << "is end " << (game.isFinalState() ? "yes" : "no") << std::endl;

    return 0;
}

