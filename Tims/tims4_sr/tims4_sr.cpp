#include <iostream>
#include <cmath>
#include <stdexcept>

using namespace std;

double factorial(int k) {
    double result = 1;
    for (int i = 1; i <= k; i++) {
        result *= i;
    }
    return result;
}

double puasson(int k, double lambda)
{
    return pow(lambda, k) * exp(-lambda) / factorial(k);
}

int main() {
    while (true) {
        try {
            int n;
            double p;
            cout << "Введіть кількість абонентів: ";
            cin >> n;
            cout << "Введіть ймовірність дзвінка одного абонента: ";
            cin >> p;
            bool validInput = !cin.fail() && n > 0 && p >= 0 && p <= 1;
            if (!validInput) {
                throw invalid_argument("Некоректні дані.");
            }
            double lambda = n * p;
            double exactly3 = puasson(3, lambda);
            double less3 = puasson(0, lambda) + puasson(1, lambda) + puasson(2, lambda);
            double more3 = 1 - (less3 + exactly3);
            double atLeastOne = 1 - puasson(0, lambda);
            cout << "\nλ = " << lambda << endl;
            cout << "\nРезультати (розподіл Пуассона):\n";
            cout << "а) Рівно 3: " << exactly3 << endl;
            cout << "б) Менше 3: " << less3 << endl;
            cout << "в) Більше 3: " << more3 << endl;
            cout << "г) Хоча б один: " << atLeastOne << endl;
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