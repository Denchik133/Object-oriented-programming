#include <iostream>
#include <stdexcept>
#include <random>

using namespace std;

long long C(int n, int k) {
    if (k > n || k < 0) {
        return 0;
    }
    long long res = 1;
    for (int i = 1; i <= k; i++) {
        res = res * (n - i + 1) / i;
    }
    return res;
}

int main() {
    while (true) {
        try {
            int k, n;
            cout << "Введіть кількість білих кульок (k): ";
            cin >> k;
            cout << "Введіть кількість чорних кульок (n): ";
            cin >> n;
            bool validInput = !cin.fail() && k >= 0 && n >= 0 && (k + n) >= 2;
            if (!validInput) {
                throw invalid_argument("Некоректні дані.");
            }
            int total = k + n;
            double p0 = (double)C(n, 2) / C(total, 2);
            double p1 = (double)(C(k, 1) * C(n, 1)) / C(total, 2);
            double p2 = (double)C(k, 2) / C(total, 2);
            cout << "\nЗакон розподілу випадкової величини X:\n";
            cout << "X = 0  P(X=0) = " << p0 << endl;
            cout << "X = 1  P(X=1) = " << p1 << endl;
            cout << "X = 2  P(X=2) = " << p2 << endl;
            cout << "\nПеревірка: сума ймовірностей = " << p0 + p1 + p2 << endl;
            random_device rd;
            mt19937 gen(rd());
            uniform_real_distribution<> uniformDist(0.0, 1.0);
            normal_distribution<> normalDist(0.0, 1.0);
            cout << "\nРівномірний розподіл (5 випадкових чисел):\n";
            for (int i = 0; i < 5; i++) {
                cout << uniformDist(gen) << endl;
            }
            cout << "\nНормальний розподіл (5 випадкових чисел):\n";
            for (int i = 0; i < 5; i++) {
                cout << normalDist(gen) << endl;
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