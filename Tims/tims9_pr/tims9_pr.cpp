#include <iostream>
#include <cmath>
#include <stdexcept>

using namespace std;

long long factorial(int n) {
    long long res = 1;
    for (int i = 1; i <= n; i++) {
        res *= i;
    }
    return res;
}

double poisson(int k, double lambda) {
    return (pow(lambda, k) * exp(-lambda)) / factorial(k);
}

int main() {
    while (true) {
        try {
            double lambda_per_minute;
            int time;
            cout << "Введіть середню кількість викликів за хвилину: ";
            cin >> lambda_per_minute;
            cout << "Введіть кількість хвилин: ";
            cin >> time;
            bool valid = !cin.fail() && lambda_per_minute > 0 && time > 0;
            if (!valid) {
                throw invalid_argument("Некоректні дані");
            }
            double lambda = lambda_per_minute * time;
            double p0 = poisson(0, lambda);
            double p4 = poisson(4, lambda);
            double p_less3 = poisson(0, lambda) + poisson(1, lambda) + poisson(2, lambda);
            cout << "\nλ = " << lambda << "\n";
            cout << "а) P(0 викликів) = " << p0 << "\n";
            cout << "б) P(4 виклики) = " << p4 << "\n";
            cout << "в) P(менше 3 викликів) = " << p_less3 << "\n";
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