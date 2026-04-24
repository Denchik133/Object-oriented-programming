#include <iostream>
#include <vector>
#include <cmath>
#include <iomanip>
#include <stdexcept>

using namespace std;

struct Interval {
    double left;
    double right;
    int freq;
};

void drawHistogram(vector<double>& relFreq, vector<double>& mid) {
    const int H = 20;
    const int W = 60;
    vector<vector<char>> grid(H, vector<char>(W, ' '));
    int k = relFreq.size();
    for (int i = 0; i < k; i++) {
        int x = i * W / k;
        int height = relFreq[i] * (H - 1);
        for (int h = 0; h <= height; h++) {
            grid[H - 1 - h][x] = '#';
        }
    }
    cout << "\nГістограма (p_i):\n";
    for (int r = 0; r < H; r++) {
        cout << setw(5) << fixed << setprecision(2) << (double)(H - 1 - r) / (H - 1) << " | ";
        for (int c = 0; c < W; c++) {
            cout << grid[r][c];
        }
        cout << "\n";
    }
    cout << "      +";
    for (int i = 0; i < W; i++) cout << "-";
    cout << "\n       ";
    for (int i = 0; i < k; i++) {
        cout << setw(5) << mid[i];
    }
    cout << "\n       x\n";
}

int main() {
    while (true) {
        try {
            int k;
            cout << "Введіть кількість інтервалів: ";
            cin >> k;
            if (cin.fail() || k <= 0) {
                throw invalid_argument("Некоректна кількість інтервалів");
            }
            vector<Interval> data(k);
            int N = 0;
            cout << "\nВведіть інтервали та частоти (left right ni):\n";
            for (int i = 0; i < k; i++) {
                cin >> data[i].left >> data[i].right >> data[i].freq;
                if (cin.fail() || data[i].freq <= 0 || data[i].left >= data[i].right) {
                    throw invalid_argument("Помилка введення інтервалу");
                }
                N += data[i].freq;
            }
            vector<double> mid(k);
            for (int i = 0; i < k; i++) {
                mid[i] = (data[i].left + data[i].right) / 2.0;
            }
            double mean = 0;
            for (int i = 0; i < k; i++) {
                mean += mid[i] * data[i].freq;
            }
            mean /= N;
            double var = 0;
            for (int i = 0; i < k; i++) {
                var += data[i].freq * pow(mid[i] - mean, 2);
            }
            var /= N;
            double correctedVar = var * N / (N - 1);
            double sigma = sqrt(var);
            vector<double> relFreq(k);
            for (int i = 0; i < k; i++) {
                relFreq[i] = (double)data[i].freq / N;
            }
            cout << fixed << setprecision(3);
            cout << "\nВибіркове середнє = " << mean << "\n";
            cout << "Вибіркова дисперсія = " << var << "\n";
            cout << "Виправлена дисперсія = " << correctedVar << "\n";
            cout << "Середнє квадратичне відхилення = " << sigma << "\n";
            drawHistogram(relFreq, mid);
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