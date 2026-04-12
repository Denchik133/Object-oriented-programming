#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <iomanip>
#include <stdexcept>

using namespace std;

void drawPolygonFull(map<double, double>& relFreq) {
    cout << "\nПолігон відносних частот (таблиця):\n";
    cout << "x\tp_i\n";
    for (auto& p : relFreq) {
        cout << p.first << "\t" << fixed << setprecision(3) << p.second << "\n";
    }
    const int H = 20;
    const int W = 50;
    vector<vector<char>> grid(H, vector<char>(W, ' '));
    int i = 0;
    int size = relFreq.size();
    for (auto& p : relFreq) {
        int x = i * W / size;
        int y = (int)(p.second * (H - 1));
        grid[H - 1 - y][x] = '*';
        i++;
    }
    cout << "\nГрафік (p_i):\n";
    for (int r = 0; r < H; r++) {
        cout << setw(5) << fixed << setprecision(2)
            << (double)(H - 1 - r) / (H - 1) << " | ";
        for (int c = 0; c < W; c++) {
            cout << grid[r][c];
        }
        cout << "\n";
    }
    cout << "      +";
    for (int i = 0; i < W; i++) {
        cout << "-";
    }
    cout << "\n       ";
    for (auto& p : relFreq) {
        cout << setw(5) << p.first;
    }
    cout << "\n       x\n";
}

void drawEmpiricalFull(map<double, int>& freq, int n) {
    cout << "\nЕмпірична функція (таблиця):\n";
    int cumulative = 0;
    cout << "x\tF(x)\n";
    map<double, double> Fx;
    for (auto& p : freq) {
        cumulative += p.second;
        double F = (double)cumulative / n;
        Fx[p.first] = F;
        cout << p.first << "\t" << fixed << setprecision(3) << F << "\n";
    }
    const int H = 20;
    const int W = 50;
    vector<vector<char>> grid(H, vector<char>(W, ' '));
    int i = 0;
    int size = Fx.size();
    for (auto& p : Fx) {
        int x = i * W / size;
        int y = (int)(p.second * (H - 1));
        for (int j = x; j < W; j++) {
            grid[H - 1 - y][j] = '#';
        }
        i++;
    }
    cout << "\nГрафік (F(x)):\n";
    for (int r = 0; r < H; r++) {
        cout << setw(5) << fixed << setprecision(2)
            << (double)(H - 1 - r) / (H - 1) << " | ";
        for (int c = 0; c < W; c++) {
            cout << grid[r][c];
        }
        cout << "\n";
    }
    cout << "      +";
    for (int i = 0; i < W; i++) {
        cout << "-";
    }
    cout << "\n       ";
    for (auto& p : Fx) {
        cout << setw(5) << p.first;
    }
    cout << "\n       x\n";
}

int main() {
    while (true) {
        try {
            int n;
            cout << "Введіть кількість елементів вибірки: ";
            cin >> n;
            if (cin.fail() || n <= 0) {
                throw invalid_argument("Некоректна кількість");
            }
            vector<double> data(n);
            cout << "Введіть елементи вибірки:\n";
            for (int i = 0; i < n; i++) {
                cin >> data[i];
                if (cin.fail()) {
                    throw invalid_argument("Помилка введення");
                }
            }
            sort(data.begin(), data.end());
            cout << "\nВаріаційний ряд:\n";
            for (double x : data) cout << x << " ";
            cout << "\n";
            map<double, int> freq;
            for (double x : data) {
                freq[x]++;
            }
            cout << "\nСтатистичний розподіл:\n";
            cout << "x\tni\tpi\n";
            map<double, double> relFreq;
            for (auto& p : freq) {
                double pi = (double)p.second / n;
                relFreq[p.first] = pi;
                cout << p.first << "\t" << p.second << "\t" << fixed << setprecision(3) << pi << "\n";
            }
            drawPolygonFull(relFreq);
            drawEmpiricalFull(freq, n);
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