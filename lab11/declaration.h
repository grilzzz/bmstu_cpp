#ifndef TICTACTOE_H
#define TICTACTOE_H

class TicTacToe {
public:
    TicTacToe(int n);
    TicTacToe(const TicTacToe& other);
    virtual ~TicTacToe();
    TicTacToe& operator=(const TicTacToe& other);
    
    int getSize() const;
    char& operator()(int x, int y); 
    const char& operator()(int x, int y) const;
    
    bool isFinalState() const;

private:
    int size;
    char** board;
    void clearBoard();
    bool checkWin(char player) const;
};

#endif // TICTACTOE_H