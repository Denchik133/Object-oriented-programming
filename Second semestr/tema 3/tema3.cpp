#include <iostream>

using namespace std;

class InputValidator {
public:

    static bool isInteger(double x) {
        return x == static_cast<int>(x);
    }

    static int readInt(const string& text) {
        while (true) {
            cout << text;
            double temp;
            cin >> temp;
            bool ok = !cin.fail() && isInteger(temp);
            if (!ok) {
                cout << "\033[31mПотрібно вводити ціле число.\033[0m\n";
                cin.clear();
                cin.ignore(10000, '\n');
                continue;
            }
            return static_cast<int>(temp);
        }
    }

    static int readPower(double n) {
        while (true) {
            double temp;
            cin >> temp;
            bool valid = !cin.fail() && isInteger(temp) && !(n == 0 && temp < 0);
            if (!valid) {
                cout << "\033[31mНекоректний степінь. Спробуйте ще раз.\033[0m\n";
                cin.clear();
                cin.ignore(10000, '\n');
                continue;
            }
            return static_cast<int>(temp);
        }
    }

    static void readDistance(int& feet, double& inches, const string& text) {
        while (true) {
            cout << text;
            cout << "\n feet: ";
            cin >> feet;
            cout << " inches: ";
            cin >> inches;
            bool ok = !cin.fail() && inches >= 0 && inches < 12;
            if (!ok) {
                cout << "\033[31mНекоректні дані.\033[0m\n";
                cin.clear();
                cin.ignore(10000, '\n');
                continue;
            }
            break;
        }
    }
};

struct Distance {
    int feet;
    double inches;
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
        char choice;
        cout << "Введіть число n: ";
        cin >> n;
        cout << "Вводити степінь? (y/n): ";
        cin >> choice;
        if (choice == 'y' || choice == 'Y') {
            cout << "Введіть степінь p: ";
            int p = InputValidator::readPower(n);
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
        if (a < b) a = 0;
        else if (b < a) b = 0;
    }

    static void run() {
        cout << "\n\nЗавдання 2: функція zeroSmaller()\n";
        int a = InputValidator::readInt("Введіть a: ");
        int b = InputValidator::readInt("Введіть b: ");
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
        return (total1 > total2) ? d1 : d2;
    }

    static void run() {
        cout << "\n\nЗавдання 3: найбільша дистанція\n";
        Distance d1, d2;
        InputValidator::readDistance(d1.feet, d1.inches, "Введіть першу відстань:");
        InputValidator::readDistance(d2.feet, d2.inches, "Введіть другу відстань:");
        Distance result = largestDistance(d1, d2);
        cout << "\nНайбільша відстань: " << result.feet << " футів " << result.inches << " дюймів";
    }
};

int main() {
    PowerTask::run();
    ZeroSmallerTask::run();
    DistanceTask::run();
    return 0;
}
