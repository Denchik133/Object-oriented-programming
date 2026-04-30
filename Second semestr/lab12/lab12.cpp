#include <iostream>
#include <stdexcept>
#include <iomanip>

using namespace std;

void printArray(int* arr, int n) {
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << "\n";
}

void printMatrix(int** m, int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cout << setw(4) << m[i][j];
        }
        cout << "\n";
    }
}

void task4() {
    try {
        int n;
        cout << "Введіть розмір масиву: ";
        cin >> n;
        if (cin.fail() || n <= 0) {
            throw invalid_argument("Некоректний розмір");
        }
        int* arr = new int[n];
        cout << "Введіть елементи:\n";
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
            if (cin.fail()) {
                throw invalid_argument("Помилка введення");
            }
        }
        int* doubled = new int[n];
        for (int i = 0; i < n; i++) {
            doubled[i] = arr[i] * 2;
        }
        cout << "\nПодвоєні значення:\n";
        printArray(doubled, n);
        delete[] arr;
        delete[] doubled;
    }
    catch (exception& e) {
        cout << "Помилка: " << e.what() << "\n";
        cin.clear();
        cin.ignore(10000, '\n');
    }
}

void task8() {
    try {
        int n;
        cout << "Введіть розмір масиву: ";
        cin >> n;
        if (cin.fail() || n <= 0) {
            throw invalid_argument("Некоректний розмір");
        }
        int* arr = new int[n];
        cout << "Введіть елементи:\n";
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
            if (cin.fail()) {
                throw invalid_argument("Помилка введення");
            }
        }
        int minIndex = 0;
        for (int i = 1; i < n; i++) {
            if (arr[i] < arr[minIndex]) {
                minIndex = i;
            }
        }
        swap(arr[minIndex], arr[n - 1]);
        cout << "\nРезультат:\n";
        printArray(arr, n);
        delete[] arr;
    }
    catch (exception& e) {
        cout << "Помилка: " << e.what() << "\n";
        cin.clear();
        cin.ignore(10000, '\n');
    }
}

void task14() {
    try {
        int rows, cols;
        cout << "Введіть розміри матриці: ";
        cin >> rows >> cols;
        if (cin.fail() || rows <= 0 || cols <= 0) {
            throw invalid_argument("Некоректні розміри");
        }
        int** matrix = new int* [rows];
        for (int i = 0; i < rows; i++) {
            matrix[i] = new int[cols];
        }
        cout << "Введіть елементи:\n";
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                cin >> matrix[i][j];
                if (cin.fail()) {
                    throw invalid_argument("Помилка введення");
                }
            }
        }
        cout << "\nМатриця:\n";
        printMatrix(matrix, rows, cols);
        int maxVal = matrix[0][0];
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (matrix[i][j] > maxVal) {
                    maxVal = matrix[i][j];
                }
            }
        }
        cout << "\nМаксимум: " << maxVal << "\n";
        cout << "\nТранспонована:\n";
        for (int j = 0; j < cols; j++) {
            for (int i = 0; i < rows; i++) {
                cout << setw(4) << matrix[i][j];
            }
            cout << "\n";
        }
        cout << "\nПоворот 90:\n";
        for (int j = 0; j < cols; j++) {
            for (int i = rows - 1; i >= 0; i--) {
                cout << setw(4) << matrix[i][j];
            }
            cout << "\n";
        }
        cout << "\nЯк 1D:\n";
        int* flat = new int[rows * cols];
        int k = 0;
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                flat[k++] = matrix[i][j];
            }
        }
        printArray(flat, rows * cols);
        delete[] flat;
        for (int i = 0; i < rows; i++) {
            delete[] matrix[i];
        }
        delete[] matrix;
    }
    catch (exception& e) {
        cout << "Помилка: " << e.what() << "\n";
        cin.clear();
        cin.ignore(10000, '\n');
    }
}

int main() {
    int choice;
    do {
        cout << "\n----- МЕНЮ -----\n";
        cout << "1 - Завдання 4 (подвоєння)\n";
        cout << "2 - Завдання 8 (мінімальний ↔ останній)\n";
        cout << "3 - Завдання 14 (матриця)\n";
        cout << "0 - Вихід\n";
        cout << "Ваш вибір: ";
        cin >> choice;
        if (cin.fail()) {
            cin.clear();
            cin.ignore(10000, '\n');
            cout << "Некоректний вибір\n";
            continue;
        }
        switch (choice) {
        case 1: task4(); break;
        case 2: task8(); break;
        case 3: task14(); break;
        case 0: cout << "Вихід...\n"; break;
        default: cout << "Невірний пункт меню\n";
        }
    } while (choice != 0);
    return 0;
}