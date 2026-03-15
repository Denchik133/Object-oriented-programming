#include <iostream>
#include <cmath>
#include <stdexcept>

using namespace std;

double F(double x) {
    if (x <= 0) {
        return 0;
    }
    if (x > 0 && x <= 1) {
        return (x * x + x) / 2;
    }
    return 1;
}

double density(double x) {
    if (x > 0 && x <= 1) {
        return x + 0.5;
    }
    return 0;
}

int main() {
    try {
        double alpha, beta;
        cout << "Введіть alpha: ";
        cin >> alpha;
        cout << "Введіть beta: ";
        cin >> beta;
        if (cin.fail()) {
            throw invalid_argument("Помилка введення");
        }
        if (alpha > beta) {
            throw invalid_argument("alpha повинно бути <= beta");
        }
        double probability = F(beta) - F(alpha);
        cout << "\nЙмовірність P(alpha ≤ X ≤ beta) = " << probability << "\n";
        double EX = 0;
        double EX2 = 0;
        int steps = 1000;
        double a = 0;
        double b = 1;
        double h = (b - a) / steps;
        for (int i = 0; i <= steps; i++) {
            double x = a + i * h;
            double f = density(x);
            EX += x * f * h;
            EX2 += x * x * f * h;
        }
        double D = EX2 - EX * EX;
        double sigma = sqrt(D);
        cout << "Математичне сподівання M(X) = " << EX << "\n";
        cout << "Дисперсія D(X) = " << D << "\n";
        cout << "Середнє квадратичне відхилення σ(X) = " << sigma << "\n";
        cout << "\nТаблиця значень для графіків:\n";
        cout << "x\tF(x)\tf(x)\n";
        for (double x = -0.2; x <= 1.2; x += 0.1) {
            cout << x << "\t" << F(x) << "\t" << density(x) << "\n";
        }
    }
    catch (const exception& e) {
        cout << "Помилка: " << e.what() << "\n";
    }
    return 0;
}