#include <iostream>
#include <cmath>

using namespace std;

class Equation {
public:
    virtual void roots() = 0;
    virtual ~Equation() {}
};

class LinearEquation : public Equation {
private:
    double a, b;
public:
    LinearEquation(double a, double b) : a(a), b(b) {}
    void roots() override {
        cout << "Лінійне рівняння: ";
        if (a == 0) {
            cout << "Немає коренів (a = 0)\n";
            return;
        }
        cout << "x = " << -b / a << endl;
    }
};

class QuadrEquation : public Equation {
private:
    double a, b, c;
public:
    QuadrEquation(double a, double b, double c) : a(a), b(b), c(c) {}
    void roots() override {
        cout << "Квадратне рівняння: ";
        if (a == 0) {
            cout << "Це не квадратне рівняння\n";
            return;
        }
        double D = b * b - 4 * a * c;
        if (D < 0) {
            cout << "Дійсних коренів немає\n";
            return;
        }
        if (D == 0) {
            cout << "x = " << -b / (2 * a) << endl;
            return;
        }
        double sqrtD = sqrt(D);
        cout << "x1 = " << (-b + sqrtD) / (2 * a)
            << ", x2 = " << (-b - sqrtD) / (2 * a) << endl;
    }
};

int main() {
    while (true) {
        try {
            double a1, b1, a2, b2, c2;
            cout << "Введіть коефіцієнти для лінійного рівняння ax+b=0\n";
            cout << "a: ";
            cin >> a1;
            cout << "b: ";
            cin >> b1;
            cout << "\nВведіть коефіцієнти для квадратного рівняння ax^2+bx+c=0\n";
            cout << "a: ";
            cin >> a2;
            cout << "b: ";
            cin >> b2;
            cout << "c: ";
            cin >> c2;
            bool validInput = !cin.fail();
            if (!validInput) {
                throw invalid_argument("Потрібно вводити тільки числа.");
            }
            LinearEquation linear(a1, b1);
            QuadrEquation quadratic(a2, b2, c2);
            Equation* equations[2] = { &linear, &quadratic };
            cout << "\n--- Обчислення коренів ---\n";
            for (int i = 0;i < 2;i++) {
                equations[i]->roots();
            }
            break;
        }
        catch (const exception& e) {
            cout << "\033[31mПомилка: " << e.what() << "\033[0m\n";
            cin.clear();
            cin.ignore(10000, '\n');
        }
    }
    return 0;
}