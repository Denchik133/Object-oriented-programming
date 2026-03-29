#include <iostream>
#include <vector>
#include <cmath>
#include <stdexcept>
#include <iomanip>

using namespace std;

int main() {
    while (true) {
        try {
            int n, m;
            cout << "Введіть кількість значень X: ";
            cin >> n;
            cout << "Введіть кількість значень Y: ";
            cin >> m;
            bool valid = !cin.fail() && n > 0 && m > 0;
            if (!valid) {
                throw invalid_argument("Некоректні розміри");
            }
            vector<double> X(n), Y(m);
            vector<vector<double>> P(n, vector<double>(m));
            cout << "\nВведіть значення X:\n";
            for (int i = 0; i < n; i++) {
                cin >> X[i];
                if (cin.fail()) {
                    throw invalid_argument("Помилка введення X");
                }
            }
            cout << "\nВведіть значення Y:\n";
            for (int j = 0; j < m; j++) {
                cin >> Y[j];
                if (cin.fail()) {
                    throw invalid_argument("Помилка введення Y");
                }
            }
            cout << "\nВведіть матрицю ймовірностей P(X,Y):\n";
            double sum = 0;
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < m; j++) {
                    cin >> P[i][j];
                    if (cin.fail() || P[i][j] < 0) {
                        throw invalid_argument("Некоректна ймовірність");
                    }
                    sum += P[i][j];
                }
            }
            if (fabs(sum - 1.0) > 0.001) {
                cout << "\nСума ймовірностей != 1, виконується нормалізація\n";
                for (int i = 0; i < n; i++) {
                    for (int j = 0; j < m; j++) {
                        P[i][j] /= sum;
                    }
                }
            }
            vector<double> Px(n, 0), Py(m, 0);
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < m; j++) {
                    Px[i] += P[i][j];
                    Py[j] += P[i][j];
                }
            }
            cout << "\nРозподіл X:\n";
            for (int i = 0; i < n; i++) {
                cout << "P(X=" << X[i] << ") = " << Px[i] << "\n";
            }
            cout << "\nРозподіл Y:\n";
            for (int j = 0; j < m; j++) {
                cout << "P(Y=" << Y[j] << ") = " << Py[j] << "\n";
            }
            double EX = 0, EY = 0;
            for (int i = 0; i < n; i++) {
                EX += X[i] * Px[i];
            }
            for (int j = 0; j < m; j++) {
                EY += Y[j] * Py[j];
            }
            double DX = 0, DY = 0;
            for (int i = 0; i < n; i++) {
                DX += (X[i] - EX) * (X[i] - EX) * Px[i];
            }
            for (int j = 0; j < m; j++) {
                DY += (Y[j] - EY) * (Y[j] - EY) * Py[j];
            }
            double EXY = 0;
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < m; j++) {
                    EXY += X[i] * Y[j] * P[i][j];
                }
            }
            double cov = EXY - EX * EY;
            double corr = cov / (sqrt(DX) * sqrt(DY));
            cout << "\nM(X) = " << EX << ", D(X) = " << DX << "\n";
            cout << "M(Y) = " << EY << ", D(Y) = " << DY << "\n";
            cout << "Коефіцієнт кореляції = " << corr << "\n";
            double a, b;
            cout << "\nВведіть a (для X|Y=a): ";
            cin >> a;
            cout << "Введіть b (для Y|X=b): ";
            cin >> b;
            if (cin.fail()) {
                throw invalid_argument("Помилка введення a або b");
            }
            int idxY = -1, idxX = -1;
            for (int j = 0; j < m; j++) {
                if (Y[j] == a) {
                    idxY = j;
                }
            }
            for (int i = 0; i < n; i++) {
                if (X[i] == b) {
                    idxX = i;
                }
            }
            if (idxY == -1 || idxX == -1) {
                throw invalid_argument("a або b не знайдені");
            }
            cout << "\nP(X | Y=" << a << "):\n";
            for (int i = 0; i < n; i++) {
                double val = P[i][idxY] / Py[idxY];
                cout << "P(X=" << X[i] << ") = " << val << "\n";
            }
            cout << "\nP(Y | X=" << b << "):\n";
            for (int j = 0; j < m; j++) {
                double val = P[idxX][j] / Px[idxX];
                cout << "P(Y=" << Y[j] << ") = " << val << "\n";
            }
            double EX_cond = 0, EY_cond = 0;
            for (int i = 0; i < n; i++) {
                EX_cond += X[i] * (P[i][idxY] / Py[idxY]);
            }
            for (int j = 0; j < m; j++) {
                EY_cond += Y[j] * (P[idxX][j] / Px[idxX]);
            }
            cout << "\nM(X | Y=" << a << ") = " << EX_cond << "\n";
            cout << "M(Y | X=" << b << ") = " << EY_cond << "\n";
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