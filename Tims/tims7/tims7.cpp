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
            double p;
            int maxK;
            cout << "Введіть ймовірність знання відповіді (0 < p < 1): ";
            cin >> p;
            cout << "Введіть max k: ";
            cin >> maxK;
            if (cin.fail() || p <= 0 || p >= 1 || maxK <= 0) {
                throw invalid_argument("Некоректні дані");
            }
            double q = 1 - p;
            cout << "\nГеометричний розподіл:\n";
            cout << "k\tP(X=k)\n";
            double M_geo = 0, D_geo = 0;
            for (int k = 1; k <= maxK; k++) {
                double prob = pow(p, k - 1) * q;
                cout << k << "\t" << prob << "\n";
                M_geo += k * prob;
                D_geo += k * k * prob;
            }
            D_geo = D_geo - M_geo * M_geo;
            cout << "\nM = " << M_geo;
            cout << "\nD = " << D_geo;
            cout << "\nσ = " << sqrt(D_geo) << "\n";
            int n;
            cout << "\nВведіть n для біноміального розподілу: ";
            cin >> n;
            if (cin.fail() || n <= 0) {
                throw invalid_argument("Некоректне n");
            }
            cout << "\nБіноміальний розподіл:\n";
            cout << "k\tP(X=k)\n";
            double M_bin = 0, D_bin = 0;
            for (int k = 0; k <= n; k++) {
                double prob = binomial(n, k, p);
                cout << k << "\t" << prob << "\n";
                M_bin += k * prob;
                D_bin += k * k * prob;
            }
            D_bin = D_bin - M_bin * M_bin;
            cout << "\nM = " << M_bin;
            cout << "\nD = " << D_bin;
            cout << "\nσ = " << sqrt(D_bin) << "\n";
            cout << "\nПеревірка формул:\n";
            cout << "Геометричний: M = " << 1 / q << " D = " << p / (q * q) << "\n";
            cout << "Біноміальний: M = " << n * p << " D = " << n * p * q << "\n";
            break;
        }
        catch (exception& e) {
            cout << "\033[31mПомилка: " << e.what() << "\033[0m\n";
            cin.clear();
            cin.ignore(10000, '\n');
        }
    }
    return 0;
}
