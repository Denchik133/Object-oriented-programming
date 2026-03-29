#include <iostream>
#include <cmath>
#include <stdexcept>

using namespace std;

int main() {
    while (true) {
        try {
            double x_bar, sigma;
            int n;
            cout << "Введіть вибіркове середнє x̄: ";
            cin >> x_bar;
            cout << "Введіть обсяг вибірки n: ";
            cin >> n;
            cout << "Введіть стандартне відхилення σ: ";
            cin >> sigma;
            bool valid = !cin.fail() && n > 0 && sigma > 0;
            if (!valid) {
                throw invalid_argument("Некоректні дані");
            }
            double z = 1.96;
            double error = z * sigma / sqrt(n);
            double left = x_bar - error;
            double right = x_bar + error;
            cout << "\nДовірчий інтервал:\n";
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