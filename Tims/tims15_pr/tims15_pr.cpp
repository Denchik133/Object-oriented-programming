#include <iostream>
#include <vector>
#include <cmath>
#include <stdexcept>
#include <iomanip>

using namespace std;

int main() {
    while (true) {
        try {
            const int n = 5;
            vector<double> x(n), y(n);
            cout << "Введіть 5 значень x:\n";
            for (int i = 0; i < n; i++) {
                cin >> x[i];
                if (cin.fail()) throw invalid_argument("Помилка введення x");
            }
            cout << "Введіть 5 значень y:\n";
            for (int i = 0; i < n; i++) {
                cin >> y[i];
                if (cin.fail()) throw invalid_argument("Помилка введення y");
            }
            double sumX = 0, sumY = 0, sumXY = 0, sumX2 = 0;
            for (int i = 0; i < n; i++) {
                sumX += x[i];
                sumY += y[i];
                sumXY += x[i] * y[i];
                sumX2 += x[i] * x[i];
            }
            double denom = n * sumX2 - sumX * sumX;
            if (fabs(denom) < 1e-9) {
                throw runtime_error("Неможливо побудувати регресію (ділення на 0)");
            }
            double a = (n * sumXY - sumX * sumY) / denom;
            double b = (sumY - a * sumX) / n;
            cout << fixed << setprecision(3);
            cout << "\nРівняння регресії:\n";
            cout << "y = " << a << "x + " << b << "\n";
            const int H = 20;
            const int W = 60;
            vector<vector<char>> grid(H, vector<char>(W, ' '));
            double minX = x[0], maxX = x[0];
            double minY = y[0], maxY = y[0];
            for (int i = 0; i < n; i++) {
                if (x[i] < minX) minX = x[i];
                if (x[i] > maxX) maxX = x[i];
                if (y[i] < minY) minY = y[i];
                if (y[i] > maxY) maxY = y[i];
            }
            minY -= 1;
            maxY += 1;
            for (int i = 0; i < n; i++) {
                int px = (x[i] - minX) / (maxX - minX) * (W - 1);
                int py = (y[i] - minY) / (maxY - minY) * (H - 1);
                grid[H - 1 - py][px] = '*';
            }
            for (int i = 0; i < W; i++) {
                double xx = minX + (maxX - minX) * i / (W - 1);
                double yy = a * xx + b;
                int py = (yy - minY) / (maxY - minY) * (H - 1);
                if (py >= 0 && py < H) {
                    if (grid[H - 1 - py][i] == ' ') {
                        grid[H - 1 - py][i] = '#';
                    }
                }
            }
            cout << "\nГрафік:\n";
            for (int r = 0; r < H; r++) {
                cout << setw(6) << fixed << setprecision(2) << (maxY - (maxY - minY) * r / (H - 1)) << " | ";
                for (int c = 0; c < W; c++) {
                    cout << grid[r][c];
                }
                cout << "\n";
            }
            cout << "       +";
            for (int i = 0; i < W; i++) {
                cout << "-";
            }
            cout << "\n        ";
            for (int i = 0; i < 6; i++) {
                double val = minX + (maxX - minX) * i / 5;
                cout << setw(10) << val;
            }
            cout << "\n          x\n";
            cout << "* - точки\n";
            cout << "# - регресія\n";
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