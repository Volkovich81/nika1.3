#include <iostream>
#include <string>
#include <clocale>
#include "Matrix.h"

int inputPositiveInt(const std::string& prompt) {
    int value;
    while (true) {
        std::cout << prompt;
        if (std::cin >> value && value > 0) {
            return value;
        }
        std::cout << "Пожалуйста, введите положительное целое число.\n";
        std::cin.clear();
        std::cin.ignore(32767, '\n');
    }
}

int main() {
    setlocale(LC_ALL, "Russian");

    int rows = inputPositiveInt("Введите количество строк: ");
    int cols = inputPositiveInt("Введите количество столбцов: ");
    Matrix matrix(rows, cols);

    bool running = true;
    while (running) {
        std::cout << "\nМеню:\n";
        std::cout << "1. Ввести элементы матрицы\n";
        std::cout << "2. Вывести матрицу\n";
        std::cout << "3. Умножить матрицу на число\n";
        std::cout << "4. Выход\n";
        std::cout << "Выберите действие: ";

        int choice;
        std::cin >> choice;

        switch (choice) {
        case 1:
            matrix.inputData();
            break;
        case 2:
            matrix.print();
            break;
        case 3: {
            int multiplier = inputPositiveInt("Введите число для умножения: ");
            matrix.multiplyBy(multiplier);
            std::cout << "Результат умножения:\n";
            matrix.print();
            break;
        }
        case 4:
            running = false;
            break;
        default:
            std::cout << "Неверный выбор. Попробуйте снова.\n";
        }
    }

    return 0;
}
