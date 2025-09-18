#include "Matrix.h"
#include <stdexcept>

void Matrix::freeMemory() {
    if (data) {
        for (int i = 0; i < rows; ++i) {
            delete[] data[i];
        }
        delete[] data;
        data = nullptr;
    }
}

Matrix::Matrix(int rows, int cols) : rows(rows), cols(cols), data(nullptr) {
    if (rows <= 0 || cols <= 0) {
        throw std::invalid_argument("������� ������� ������ ���� ��������������");
    }

    data = new int* [rows];
    for (int i = 0; i < rows; ++i) {
        data[i] = new int[cols] {0}; 
    }
}

Matrix::~Matrix() {
    freeMemory();
}

void Matrix::inputData() {
    std::cout << "������� �������� ������� (" << rows << "x" << cols << "):\n";
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            std::cout << "������� [" << i << "][" << j << "]: ";
            if (!(std::cin >> data[i][j])) {
                throw std::runtime_error("������ ����� ��������");
            }
        }
    }
}

void Matrix::print() const {
    std::cout << "������� (" << rows << "x" << cols << "):\n";
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            std::cout << data[i][j] << '\t';
        }
        std::cout << '\n';
    }
}

void Matrix::multiplyBy(int multiplier) {
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            data[i][j] *= multiplier;
        }
    }
}