#include <iostream>
#include <vector>
#include <cmath>
#include <stdexcept>

using namespace std;

double normalPDF(double x, double mean, double stddev) {
    return (1.0 / (stddev * sqrt(2 * 3.14))) *
        exp(-pow(x - mean, 2) / (2 * stddev * stddev));
}

void linearRegression(vector<double>& x, vector<double>& y) {
    int n = x.size();

    double sumX = 0, sumY = 0, sumXY = 0, sumX2 = 0;

    for (int i = 0; i < n; i++) {
        sumX += x[i];
        sumY += y[i];
        sumXY += x[i] * y[i];
        sumX2 += x[i] * x[i];
    }

    double a = (n * sumXY - sumX * sumY) / (n * sumX2 - sumX * sumX);
    double b = (sumY - a * sumX) / n;

    cout << "\nЛінійна регресія:\n";
    cout << "y = " << a << " * x + " << b << endl;
}

void polynomialRegression(vector<double>& x, vector<double>& y) {
    int n = x.size();

    double Sx = 0, Sx2 = 0, Sx3 = 0, Sx4 = 0;
    double Sy = 0, Sxy = 0, Sx2y = 0;

    for (int i = 0; i < n; i++) {
        double xi = x[i];
        double yi = y[i];
        Sx += xi;
        Sx2 += xi * xi;
        Sx3 += xi * xi * xi;
        Sx4 += xi * xi * xi * xi;
        Sy += yi;
        Sxy += xi * yi;
        Sx2y += xi * xi * yi;
    }
    double D = n * (Sx2 * Sx4 - Sx3 * Sx3) - Sx * (Sx * Sx4 - Sx2 * Sx3) + Sx2 * (Sx * Sx3 - Sx2 * Sx2);
    double Da = Sy * (Sx2 * Sx4 - Sx3 * Sx3) - Sx * (Sxy * Sx4 - Sx3 * Sx2y) + Sx2 * (Sxy * Sx3 - Sx2 * Sx2y);
    double Db = n * (Sxy * Sx4 - Sx3 * Sx2y) - Sy * (Sx * Sx4 - Sx2 * Sx3) + Sx2 * (Sx * Sx2y - Sxy * Sx2);
    double Dc = n * (Sx2 * Sx2y - Sxy * Sx3) - Sx * (Sx * Sx2y - Sxy * Sx2) + Sy * (Sx * Sx3 - Sx2 * Sx2);
    double a = Dc / D;
    double b = Db / D;
    double c = Da / D;
    cout << "\nПоліноміальна регресія:\n";
    cout << "y = " << a << " * x^2 + " << b << " * x + " << c << "\n";
}

int main() {
    while (true) {
        try {
            double x_bar, sigma;
            int n;
            cout << "Введіть x̄: ";
            cin >> x_bar;
            cout << "Введіть n: ";
            cin >> n;
            cout << "Введіть σ: ";
            cin >> sigma;
            if (cin.fail() || n <= 0 || sigma <= 0) {
                throw invalid_argument("Некоректні дані");
            }
            double z = 1.96;
            double std_error = sigma / sqrt(n);
            double error = z * std_error;
            double left = x_bar - error;
            double right = x_bar + error;
            cout << "\nДовірчий інтервал:\n";
            cout << "[" << left << " ; " << right << "]\n";
            cout << "\nГрафік нормального розподілу:\n\n";
            int width = 60;
            int height = 20;
            double minX = x_bar - 4 * std_error;
            double maxX = x_bar + 4 * std_error;
            vector<double> Xvals, Yvals;
            for (int j = 0; j <= width; j++) {
                double x = minX + (maxX - minX) * j / width;
                double y = normalPDF(x, x_bar, std_error);
                Xvals.push_back(x);
                Yvals.push_back(y);
            }
            for (int i = height; i >= 0; i--) {
                for (int j = 0; j <= width; j++) {
                    double normalized = Yvals[j] / normalPDF(x_bar, x_bar, std_error);
                    int level = normalized * height;
                    double x = Xvals[j];
                    if (fabs(x - x_bar) < (maxX - minX) / width) {
                        cout << "|";
                    }
                    else if (fabs(x - left) < (maxX - minX) / width || fabs(x - right) < (maxX - minX) / width) {
                        cout << "!";
                    }
                    else if (level == i) {
                        cout << "*";
                    }
                    else {
                        cout << " ";
                    }
                }
                cout << "\n";
            }
            cout << "\n| - середнє\n! - довірчий інтервал\n";
            linearRegression(Xvals, Yvals);
            polynomialRegression(Xvals, Yvals);
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
