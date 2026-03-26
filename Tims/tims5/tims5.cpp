#include <iostream>
#include <vector>
#include <stdexcept>
#include <iomanip>
#include <algorithm>

using namespace std;

int main() {
    while (true) {
        try {
            int k;
            cout << "Введіть кількість різних значень xi: ";
            cin >> k;
            if (cin.fail() || k <= 0) {
                throw invalid_argument("Некоректне значення k");
            }
            vector<double> x(k);
            vector<int> n(k);
            cout << "\nВведіть значення xi:\n";
            for (int i = 0; i < k; i++) {
                cin >> x[i];
                if (cin.fail()) {
                    throw invalid_argument("Помилка введення xi");
                }
            }
            cout << "\nВведіть відповідні частоти ni:\n";
            int total = 0;
            for (int i = 0; i < k; i++) {
                cin >> n[i];
                if (cin.fail() || n[i] <= 0) {
                    throw invalid_argument("Помилка введення ni");
                }
                total += n[i];
            }
            vector<pair<double, int>> data;
            for (int i = 0; i < k; i++) {
                data.push_back({ x[i], n[i] });
            }
            sort(data.begin(), data.end());
            for (int i = 0; i < k; i++) {
                x[i] = data[i].first;
                n[i] = data[i].second;
            }
            double mean = 0;
            for (int i = 0; i < k; i++) {
                mean += x[i] * n[i];
            }
            mean /= total;
            double variance = 0;
            for (int i = 0; i < k; i++) {
                variance += n[i] * (x[i] - mean) * (x[i] - mean);
            }
            variance /= (total - 1);
            cout << "\nЕмпірична функція розподілу:\n";
            int cumulative = 0;
            cout << fixed << setprecision(3);
            for (int i = 0; i < k; i++) {
                cumulative += n[i];
                double F = (double)cumulative / total;
                cout << "F(x <= " << x[i] << ") = " << F << "\n";
            }
            cout << "\nВибіркове середнє = " << mean << "\n";
            cout << "Незміщена дисперсія = " << variance << "\n";
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
