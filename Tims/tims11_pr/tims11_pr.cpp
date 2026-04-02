#include <iostream>
#include <cmath>
#include <stdexcept>

using namespace std;

double C(int n, int k) {
    if (k > n || k < 0) {
        return 0;
    }
    double res = 1;
    for (int i = 1; i <= k; i++) {
        res = res * (n - i + 1) / i;
    }
    return res;
}

double binomial(int n, int k, double p) {
    return C(n, k) * pow(p, k) * pow(1 - p, n - k);
}

int main() {
    while (true) {
        try {
            int n;
            double p, prize;
            cout << "Введіть кількість покупок (n): ";
            cin >> n;
            cout << "Введіть ймовірність виграшу (p): ";
            cin >> p;
            cout << "Введіть суму призу: ";
            cin >> prize;
            bool valid = !cin.fail() && n > 0 && p >= 0 && p <= 1 && prize > 0;
            if (!valid) {
                throw invalid_argument("Некоректні дані.");
            }
            cout << "\nРяд розподілу X:\n";
            double expected = 0;
            double variance = 0;
            for (int k = 0; k <= n; k++) {
                double prob = binomial(n, k, p);
                double value = k * prize;
                cout << "X = " << value << "  P = " << prob << "\n";
                expected += value * prob;
                variance += value * value * prob;
            }
            variance -= expected * expected;
            cout << "\nМатематичне сподівання: " << expected << "\n";
            cout << "Дисперсія: " << variance << "\n";
            cout << "Середнє квадратичне відхилення: " << sqrt(variance) << "\n";
            break;
        }
        catch (const exception& e) {
            cout << "\033[31mПомилка: " << e.what() << "\033[0m\n";
            cin.clear();
            cin.ignore(10000, '\n');
            cout << "Спробуйте ще раз...\n\n";
        }
    }
    return 0;
}