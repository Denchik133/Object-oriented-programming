#include <iostream>

using namespace std;

long long comb(int n, int k) {
    if (k < 0 || k > n) {
        return 0;
    }
    if (k == 0 || k == n) {
        return 1;
    }
    long long res = 1;
    for (int i = 1; i <= k; i++) {
        res = res * (n - i + 1) / i;
    }
    return res;
}

int main() {
    int rm, tl;
    int bqtSize;
    int maxTl;
    cout << "Введіть кількість ромашок: ";
    cin >> rm;
    cout << "Введіть кількість тюльпанів: ";
    cin >> tl;
    cout << "Введіть розмір букету: ";
    cin >> bqtSize;
    cout << "Введіть максимальну кількість тюльпанів у букеті: ";
    cin >> maxTl;
    long long ways = 0;
    for (int t = 0; t <= maxTl; t++) {
        int d = bqtSize - t;
        if (t <= tl && d <= rm && d >= 0) {
            ways += comb(tl, t) * comb(rm, d);
        }
    }
    cout << "\nКількість способів скласти букет: " << ways << endl;
    return 0;
}
