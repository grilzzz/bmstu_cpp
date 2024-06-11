#include "declaration.h"
#include <iostream>
#include <cstring>


TicTacToe::TicTacToe(int n) : size(n) {
    this->board = new char*[size];
    for (int i = 0; i < size; i++) {
        this->board[i] = new char[size];
        for (int j = 0; j < size; j++) {
            this->board[i][j] = (char)".";
        }
    }



    // board = new char*[size];
    // for (int i = 0; i < size; i++) {
    //     board[i] = new char[size];
    //     for (int j = 0; j < size; j++) {
    //         board[i][j] = (char)".";
    //     }
    // }

    // board = new char*[size];
    // for (int i = 0; i < size; ++i) {
    //     board[i] = new char[size];
    //     std::memset(board[i], '.', size); 
    // }
}


TicTacToe::TicTacToe(const TicTacToe& other) : size(other.size) {
    this->board = new char*[size];
    for (int i = 0; i < size; i++) {
        this->board[i] = new char[size];
        for (int j = 0; j < size; j++) {
            this->board[i][j] = other.board[i][j];
        }
    } 



    // board = new char*[size];
    // for (int i = 0; i < size; ++i) {
    //     board[i] = new char[size];
    //     std::memcpy(board[i], other.board[i], size);
    // }
}


TicTacToe::~TicTacToe() {
    for (int i = 0; i < size; ++i) {
        delete[] board[i];
    }
    delete[] board;
}


TicTacToe& TicTacToe::operator=(const TicTacToe& other) {
    if (this != &other) {
        // for (int i = 0; i < size; ++i) {
        //     delete[] board[i];
        // }
        // delete[] board;
        
        size = other.size;
        board = new char*[size];
        for (int i = 0; i < size; ++i) {
            board[i] = new char[size];
            std::memcpy(board[i], other.board[i], size);
        }
    }
    return *this;
}


char& TicTacToe::operator()(int x, int y) {
    return board[x][y];
}

const char& TicTacToe::operator()(int x, int y) const {
    return board[x][y];
}


int TicTacToe::getSize() const {
    return size;
}


bool TicTacToe::isFinalState() const {
    for (char player : {'X', 'O'}) {
        if (checkWin(player)) {
            return true;
        }
    }
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            if (board[i][j] == '.') {
                return false; 
            }
        }
    }
    return true; 
}


bool TicTacToe::checkWin(char player) const {
    bool win;
    for (int i = 0; i < size; ++i) {
        win = true;
        for (int j = 0; j < size; ++j) {
            if (board[i][j] != player) {
                win = false;
                break;
            }
        }
        if (win) return true;

        win = true;
        for (int j = 0; j < size; ++j) {
            if (board[j][i] != player) {
                win = false;
                break;
            }
        }
        if (win) return true;
    }

    win = true;
    for (int i = 0; i < size; ++i) {
        if (board[i][i] != player) {
            win = false;
            break;
        }
    }
    if (win) return true;

    win = true;
    for (int i = 0; i < size; ++i) {
        if (board[i][size - i - 1] != player) {
            win = false;
            break;
        }
    }
    return win;
}
