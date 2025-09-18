#ifndef MATRIX_H
#define MATRIX_H

#include <iostream>
#include <stdexcept>

class Matrix {
private:
    
    int rows = 0;
    int cols = 0;
    int** data = nullptr;

    void freeMemory();

public:
    Matrix(int rows, int cols);
    ~Matrix();

    Matrix(const Matrix&) = delete;
    Matrix& operator=(const Matrix&) = delete;

    void inputData() const;              
    void print() const;             
    void multiplyBy(int multiplier) const; 
};

#endif  