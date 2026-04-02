#include <iostream>
#include <cmath>
#include <stdexcept>

using namespace std;

double normalPDF(double x, double mean, double stddev) {
    return (1.0 / (stddev * sqrt(2 * 3.14))) *
        exp(-pow(x - mean, 2) / (2 * stddev * stddev));
}

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
            for (int i = height; i >= 0; i--) {
                for (int j = 0; j <= width; j++) {
                    double x = minX + (maxX - minX) * j / width;
                    double y = normalPDF(x, x_bar, std_error);
                    double normalized = y / normalPDF(x_bar, x_bar, std_error);
                    int level = normalized * height;
                    if (fabs(x - x_bar) < (maxX - minX) / width) {
                        cout << "|";
                    }
                    else if (fabs(x - left) < (maxX - minX) / width ||
                        fabs(x - right) < (maxX - minX) / width) {
                        cout << "!";
                    }
                    else if (level == i) {
                        cout << "*";
                    }
                    else {
                        cout << " ";
                    }
                }
                cout << endl;
            }
            cout << "\n| - середнє (x̄)\n";
            cout << "! - довірчий інтервал\n";
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
