#include <iostream>
using namespace std;

template <typename T1, typename T2>
class Pair {
    T1 first;
    T2 second;
public:
    Pair(T1 a, T2 b) : first(a), second(b) {}
    void print() const {
        cout << "Пара: " << first << " , " << second << "\n";
    }
};

int main() {
    int a;
    double b;
    cout << "Введіть ціле число: ";
    cin >> a;
    cout << "Введіть дійсне число: ";
    cin >> b;
    Pair<int, double> p(a, b);
    p.print();
    return 0;
}