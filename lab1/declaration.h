#ifndef DECLARATION_H
#define DECLARATION_H

class Matrix {
private:
    int **data;
    int size; 

public:
    Matrix(int size); 
    Matrix(const Matrix& other);  
    virtual ~Matrix(); 
    Matrix& operator=(const Matrix& rhs);

    int getSize() const;       
    int& elementAt(int row, int col);   
    bool isSaddlePoint(int row, int col) const; 
};

#endif
