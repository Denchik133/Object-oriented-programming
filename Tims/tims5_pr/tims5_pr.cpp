#include <iostream>
#include <cmath>
#include <stdexcept>

using namespace std;

int main() {
    while (true) {
        try {
            double p;
            int desiredMode;
            cout << "Введіть ймовірність проростання (0 < p < 1): ";
            cin >> p;
            cout << "Введіть бажане найімовірніше число зерен, що НЕ зійшли: ";
            cin >> desiredMode;
            bool validInput = !cin.fail() && p > 0 && p < 1 && desiredMode >= 0;
            if (!validInput) {
                throw invalid_argument("Некоректні дані.");
            }
            double q = 1 - p;
            double left = desiredMode / q;
            double right = (desiredMode + 1) / q;
            int n_min = ceil(left - 1);
            int n_max = floor(right - 1);
            if (n_min > n_max) {
                throw runtime_error("Розв'язку не існує для введених даних.");
            }
            cout << "\nМожливі значення n від " << n_min << " до " << n_max << endl;
            cout << "Найменше можливе n = " << n_min << endl;
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