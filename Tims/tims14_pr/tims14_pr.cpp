#include <iostream>
#include <cmath>
#include <stdexcept>
#include <boost/math/distributions/chi_squared.hpp>

using namespace std;
using namespace boost::math;

int main() {
    while (true) {
        try {
            double s, gamma;
            int n;
            cout << "Введіть s (виправлене σ): ";
            cin >> s;
            cout << "Введіть n: ";
            cin >> n;
            cout << "Введіть γ (надійність): ";
            cin >> gamma;
            if (cin.fail() || s <= 0 || n <= 1 || gamma <= 0 || gamma >= 1) {
                throw invalid_argument("Некоректні дані");
            }
            int v = n - 1;
            chi_squared dist(v);
            double chi2_low = quantile(dist, (1 + gamma) / 2);
            double chi2_high = quantile(dist, (1 - gamma) / 2);
            double left = sqrt((v * s * s) / chi2_low);
            double right = sqrt((v * s * s) / chi2_high);
            cout << "\nДовірчий інтервал для σ:\n";
            cout << "[" << left << " ; " << right << "]\n";
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