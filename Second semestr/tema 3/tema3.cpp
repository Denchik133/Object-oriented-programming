#include <iostream>

using namespace std;

struct Distance {
    int feet;
    double inches;
    void input(const string& text) {
        while (true) {
            cout << text;
            cout << "\n feet: ";
            cin >> feet;
            cout << " inches: ";
            cin >> inches;
            if (cin.fail()) {
                cout << "\033[31mПомилка введення. Спробуйте ще раз.\033[0m";
                cin.clear();
                cin.ignore(10000, '\n');
                continue;
            }
            if (inches < 0) {
                cout << "\033[31mДюйми не можуть бути від'ємними. Спробуйте ще раз.\033[0m";
                continue;
            }
            if (inches >= 12) {
                cout << "\033[31mДюйми повинні бути менше 12. Спробуйте ще раз.\033[0m";
                continue;
            }
            break;
        }
    }
};

class PowerTask {
public:
    static double power(double n, int p = 2) {
        double result = 1;
        for (int i = 0; i < p; i++) {
            result *= n;
        }
        return result;
    }

    static void run() {
        cout << "\nЗавдання 1: функція power()\n";
        double n;
        int p;
        char choice;
        cout << "Введіть число n: ";
        cin >> n;
        cout << "Вводити степінь? (y/n): ";
        cin >> choice;
        if (choice == 'y' || choice == 'Y') {
            cout << "Введіть степінь p: ";
            while (true) {
                double temp;
                cin >> temp;
                if (cin.fail()) {
                    cout << "\033[31mПотрібно вводити ціле число. Спробуйте ще раз.\033[0m\n";
                    cin.clear();
                    cin.ignore(10000, '\n');
                    cout << "Введіть степінь p: ";
                    continue;
                }
                if (temp != static_cast<int>(temp)) {
                    cout << "\033[31mСтепінь має бути цілим числом. Спробуйте ще раз.\033[0m\n";
                    cout << "Введіть степінь p: ";
                    continue;
                }
                p = static_cast<int>(temp);
                if (n == 0 && p < 0) {
                    cout << "\033[31m0 не можна підносити у від'ємний степінь. Спробуйте ще раз.\033[0m\n";
                    cout << "Введіть степінь p: ";
                    continue;
                }
                break;
            }
            cout << "Результат: " << power(n, p);
        }
        else {
            cout << "Результат: " << power(n);
        }
    }
};

class ZeroSmallerTask {
public:
    static void zeroSmaller(int& a, int& b) {
        if (a < b) {
            a = 0;
        }
        else if (b < a) {
            b = 0;
        }
    }

    static void run() {
        cout << "\n\nЗавдання 2: функція zeroSmaller()\n";
        int a, b;
        cout << "Введіть два цілі числа: ";
        while (true) {
            double tempA, tempB;
            cin >> tempA >> tempB;
            if (cin.fail()) {
                cout << "\033[31mПомилка! Потрібно вводити тільки цілі числа. Спробуйте ще раз.\033[0m";
                cin.clear();
                cin.ignore(10000, '\n');
                cout << "Введіть два цілі числа: ";
                continue;
            }
            if (tempA != static_cast<int>(tempA) || tempB != static_cast<int>(tempB)) {
                cout << "\033[31mПотрібно вводити тільки цілі числа. Спробуйте ще раз.\033[0m\n";
                cout << "Введіть два цілі числа: ";
                continue;
            }
            a = static_cast<int>(tempA);
            b = static_cast<int>(tempB);
            break;
        }
        zeroSmaller(a, b);
        cout << "Результат після виклику функції:\n";
        cout << "a = " << a << ", b = " << b;
    }
};

class DistanceTask {
public:
    static Distance largestDistance(Distance d1, Distance d2) {
        double total1 = d1.feet * 12 + d1.inches;
        double total2 = d2.feet * 12 + d2.inches;
        if (total1 > total2) {
            return d1;
        }
        else {
            return d2;
        }
    }

    static void run() {
        cout << "\n\nЗавдання 3: найбільша дистанція\n";
        Distance d1, d2, result;
        d1.input("Введіть першу відстань (feet inches): ");
        d2.input("Введіть другу відстань (feet inches): ");
        result = largestDistance(d1, d2);
        cout << "\nНайбільша відстань: " << result.feet << " футів " << result.inches << " дюймів";
    }
};

int main() {
    PowerTask::run();
    ZeroSmallerTask::run();
    DistanceTask::run();
    return 0;
}
