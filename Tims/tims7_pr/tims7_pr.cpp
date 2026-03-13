#include <iostream>
#include <vector>
#include <cmath>
#include <stdexcept>

using namespace std;

int main() {
    try {
        int n;
        cout << "Введіть кількість значень випадкової величини: ";
        while (!(cin >> n) || n <= 0) {
            cout << "Помилка. Введіть додатнє число: ";
            cin.clear();
            cin.ignore(10000, '\n');
        }
        vector<double> x(n);
        vector<double> p(n);
        cout << "\nВведіть значення xi:\n";
        for (int i = 0; i < n; i++) {
            cout << "x[" << i << "] = ";
            while (!(cin >> x[i])) {
                cout << "Помилка вводу. Повторіть: ";
                cin.clear();
                cin.ignore(10000, '\n');
            }
        }
        cout << "\nВведіть відповідні ймовірності pi:\n";
        double sumP = 0;
        for (int i = 0; i < n; i++) {
            cout << "p[" << i << "] = ";
            while (!(cin >> p[i]) || p[i] < 0) {
                cout << "Ймовірність повинна бути >=0. Повторіть: ";
                cin.clear();
                cin.ignore(10000, '\n');
            }
            sumP += p[i];
        }
        if (fabs(sumP - 1.0) > 0.001) {
            cout << "\nУвага: сума ймовірностей не дорівнює 1 (" << sumP << "). Виконується нормалізація.\n";
            for (int i = 0; i < n; i++) {
                p[i] /= sumP;
            }
        }
        double M = 0;
        for (int i = 0; i < n; i++) {
            M += x[i] * p[i];
        }
        double D = 0;
        for (int i = 0; i < n; i++) {
            D += pow(x[i] - M, 2) * p[i];
        }
        double sigma = sqrt(D);
        cout << "\nМатематичне сподівання M(X) = " << M << endl;
        cout << "Дисперсія D(X) = " << D << endl;
        cout << "Середнє квадратичне відхилення σ = " << sigma << endl;
    }
    catch (exception& e) {
        cout << "Помилка: " << e.what() << endl;
    }
    return 0;
}