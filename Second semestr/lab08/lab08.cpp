#include <iostream>
#include <stdexcept>

using namespace std;

class Vect {
public:
    Vect(char n) {
        try {
            if (n < 0) {
                throw invalid_argument("Від’ємний розмір масиву");
            }
            size = n;
            p = new int[size];
            if (!p) {
                throw runtime_error("Помилка виділення пам’яті");
            }
            for (int i = 0; i < size; ++i) {
                p[i] = 0;
            }
        }
        catch (exception& e) {
            cerr << "Помилка в конструкторі: " << e.what() << "\n";
            p = nullptr;
            size = 0;
        }
    }

    ~Vect() {
        try {
            destroy();
        }
        catch (...) {
            cerr << "Помилка в деструкторі\n";
        }
    }

    int& operator[](int i) {
        if (i < 0 || i >= size) {
            throw out_of_range("Індекс поза межами");
        }
        return p[i];
    }

    void Print() {
        for (int i = 0; i < size; ++i) {
            cout << p[i] << " ";
        }
        cout << endl;
    }

private:
    int* p;
    char size;
    void destroy() {
        if (p) {
            delete[] p;
            p = nullptr;
        }
    }
};

int main() {
    while (true) {
        try {
            char size;
            cout << "Введіть розмір масиву (0-127): ";
            int temp;
            cin >> temp;
            if (cin.fail() || temp < 0 || temp > 127) {
                throw invalid_argument("Некоректний розмір");
            }
            size = static_cast<char>(temp);
            Vect a(size);
            cout << "Введіть індекс і значення: ";
            int index, value;
            cin >> index >> value;
            if (cin.fail()) {
                throw invalid_argument("Помилка введення");
            }
            a[index] = value;
            a.Print();
            break;
        }
        catch (exception& e) {
            cout << "\033[31mПомилка: " << e.what() << "\033[0m\n";
            cin.clear();
            cin.ignore(10000, '\n');
            cout << "Спробуйте ще раз...\n\n";
        }
    }
    return 0;
}