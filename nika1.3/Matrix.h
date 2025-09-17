#ifndef MATRIX_H
#define MATRIX_H

#include <iostream>
#include <stdexcept>

class Matrix {
private:
    int** data;
    int rows;
    int cols;

    void freeMemory();

public:
    Matrix(int rows, int cols);
    ~Matrix();

    Matrix(const Matrix&) = delete;
    Matrix& operator=(const Matrix&) = delete;

    void inputData();              
    void print() const;             
    void multiplyBy(int multiplier); 
};

#endif  