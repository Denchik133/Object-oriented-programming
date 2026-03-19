#include <iostream>
#include <stdexcept>
#include <string>
#include <cmath>

using namespace std;

class Chislo {
protected:
    long n;
public:
    Chislo(long value = 0) {
        if (value < 0) {
            throw invalid_argument("Число повинно бути додатним");
        }
        n = value;
    }

    virtual ~Chislo() {}

    virtual long long factorial(long x) {
        if (x < 0) {
            throw invalid_argument("Факторіал від’ємного числа не існує");
        }
        long long result = 1;
        for (long i = 1; i <= x; i++) {
            result *= i;
        }
        return result;
    }
    long getSize() const {
        return n;
    }
};

class Matrix : public Chislo {
public:
    double array[100]{};
    Matrix(long size) : Chislo(size) {
        if (size > 100) {
            throw invalid_argument("Максимальний розмір масиву 100");
        }
    }
    ~Matrix() {}
};

string cesarEncryptDigits(string text, int shift) {
    for (char& c : text) {
        if (isdigit(c)) {
            c = '0' + (c - '0' + shift) % 10;
        }
    }
    return text;
}

void processArray(Chislo* obj, Matrix& m, int shift) {
    cout << "\nФакторіали елементів:\n";
    for (int i = 0; i < obj->getSize(); i++) {
        double value = m.array[i];
        if (floor(value) != value) {
            cout << "Число: " << value << " | Факторіал не визначений (число має бути цілим) | (шифровано): -\n";
            continue;
        }
        long intValue = (long)value;
        long long fact = obj->factorial(intValue);
        string normal = to_string(fact);
        string encrypted = cesarEncryptDigits(normal, shift);
        cout << "Число: " << value << " | Факторіал: " << normal << " | (шифровано): " << encrypted << endl;
    }
}

int main() {
    while (true) {
        try {
            long size;
            int shift;
            cout << "Введіть розмір масиву: ";
            cin >> size;
            if (cin.fail() || size <= 0) {
                throw invalid_argument("Некоректний розмір");
            }
            Matrix m(size);
            cout << "Введіть " << size << " чисел:\n";
            for (int i = 0; i < size; i++) {
                cin >> m.array[i];
                if (cin.fail() || m.array[i] < 0) {
                    throw invalid_argument("Некоректне значення елемента");
                }
            }
            cout << "Введіть зсув для шифру Цезаря: ";
            cin >> shift;
            if (cin.fail()) {
                throw invalid_argument("Некоректний зсув");
            }
            Chislo* ptr = &m;
            processArray(ptr, m, shift);
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
