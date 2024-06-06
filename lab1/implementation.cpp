#include "declaration.h"
#include <algorithm>
#include <stdexcept>

Matrix::Matrix(int size) : size(size), data(new int*[size]) {
    for (int i = 0; i < size; ++i) {
        data[i] = new int[size];
        std::fill(data[i], data[i] + size, 0);
    }
}

Matrix::Matrix(const Matrix& other) : size(other.size), data(new int*[size]) {
    for (int i = 0; i < size; ++i) {
        data[i] = new int[size];
        std::copy(other.data[i], other.data[i] + size, data[i]);
    }
}

Matrix::~Matrix() {
    for (int i = 0; i < size; ++i) {
        delete[] data[i];
    }
    delete[] data;
}

Matrix& Matrix::operator=(const Matrix& rhs) {
    if (this != &rhs) {
        Matrix tmp(rhs);
        std::swap(size, tmp.size);
        std::swap(data, tmp.data);
    }
    return *this;
}

int Matrix::getSize() const {
    return size;
}

int& Matrix::elementAt(int row, int col) {
    if (row < 0 || row >= size || col < 0 || col >= size) {
        throw std::out_of_range("erorre");
    }
    return data[row][col];
}

bool Matrix::isSaddlePoint(int row, int col) const {
    // if (row < 0 || row >= size || col < 0 || col >= size) {
    //     throw std::out_of_range("erorre");
    // }
    int elem = data[row][col];
    for (int i = 0; i < size; ++i) {
        if (data[row][i] < elem || data[i][col] > elem) {
            return false;
        }
    }
    return true;
}
