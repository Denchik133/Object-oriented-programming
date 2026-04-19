#include <iostream>
#include <cmath>
#include <stdexcept>

using namespace std;

int main() {
    while (true) {
        try {
            double p;
            int maxK;
            cout << "Введіть ймовірність знання відповіді (0 < p < 1): ";
            cin >> p;
            cout << "Введіть максимальну кількість питань для виводу: ";
            cin >> maxK;
            if (cin.fail() || p <= 0 || p >= 1 || maxK <= 0) {
                throw invalid_argument("Некоректні дані");
            }
            double q = 1 - p;
            cout << "\nЗакон розподілу (геометричний):\n";
            cout << "k\tP(X = k)\n";
            double sum = 0;
            for (int k = 1; k <= maxK; k++) {
                double prob = pow(p, k - 1) * q;
                cout << k << "\t" << prob << "\n";
                sum += prob;
            }
            cout << "\nСума ймовірностей (наближено): " << sum << endl;
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