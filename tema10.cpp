#include <iostream>
#include <vector>

using namespace std;

double fact(int n) {
    double f = 1;
    for (int i = 1; i <= n; i++) {
        f *= i;
    }
    return f;
}

double mySin(double x) {
    return x - (x * x * x) / fact(3) + (x * x * x * x * x) / fact(5) - (x * x * x * x * x * x * x) / fact(7);
}

double myCos(double x) {
    return 1 - (x * x) / fact(2) + (x * x * x * x) / fact(4) - (x * x * x * x * x * x) / fact(6);
}

double myExp(double x) {
    return 1 + x + (x * x) / fact(2) + (x * x * x) / fact(3) + (x * x * x * x) / fact(4);
}

double f(int id, double x) {
    switch (id) {
    case 1: return mySin(x);
    case 2: return myCos(x);
    case 3: return myExp(x);
    default: return 0;
    }
}

void tabulate(int functionId, double a, double b, double d, vector<double>& xs, vector<double>& ys) {
    xs.clear();
    ys.clear();
    for (double x = a; x <= b; x += d) {
        double y = f(functionId, x);
        xs.push_back(x);
        ys.push_back(y);
    }
}

double simpsonIntegral(int functionId, double a, double b, int n = 200) {
    double d = (b - a) / n;
    vector<double> xs, ys;
    tabulate(functionId, a, b, d, xs, ys);
    double s, s2 = 0, s4 = 0;
    s = ys.front() + ys.back();
    for (int i = 1; i < n; i++) {
        if (i % 2 == 1) {
            s4 += ys[i];
        }
        else {
            s2 += ys[i];
        }
    }
    return (d / 3) * (s + 4 * s4 + 2 * s2);
}

int main() {
    int menuChoice = 0;
    int funcChoice = 0;
    double a = 0, b = 0, d = 0, x, y;
    vector<double> xs, ys;
    while (menuChoice != 5) {
        cout << "\n1 - Вибрати функцію\n";
        cout << "2 - Ввести межі та крок\n";
        cout << "3 - Табулювати\n";
        cout << "4 - Обчислення інтегралів\n";
        cout << "5 - Вихід\n";
        cout << "Ваш вибір: ";
        cin >> menuChoice;

        if (menuChoice == 1) {
            cout << "\nОберіть функцію:\n";
            cout << "1. y = sin(x)\n";
            cout << "2. y = cos(x)\n";
            cout << "3. y = exp(x)\n";
            cout << "Ваш вибір: ";
            cin >> funcChoice;
            if (funcChoice > 3) {
            cout << "Такого варіанту немає\n";
            }
        }
        else if (menuChoice == 2) {
            cout << "\nВведіть початок відрізка a: ";
            cin >> a;
            cout << "Введіть кінець відрізка b: ";
            cin >> b;
            cout << "Введіть крок d: ";
            cin >> d;
            if (a >= b || d <= 0) {
                cout << "Помилка у введенні даних\n";
            }
        }
        else if (menuChoice == 3) {
            if (funcChoice == 0) {
                cout << "Спочатку виберіть функцію\n";
            }
            else if (a == 0 && b == 0 && d == 0) {
                cout << "Спочатку введіть межі\n";
            }
            else {
                tabulate(funcChoice, a, b, d, xs, ys);
                cout << "\nТаблиця значень:\n";
                cout << "------------------------\n";
                cout << "|   x\t|\ty\t|\n";
                cout << "------------------------\n";
                for (size_t i = 0; i < xs.size(); i++) {
                    cout << "| " << xs[i] << "\t|\t" << ys[i] << " |\n";
                }
                cout << "------------------------\n";
            }
        }
        else if (menuChoice == 4) {
            if (funcChoice == 0 || a == 0 && b == 0) {
                cout << "Спочатку виберіть функцію і введіть межі\n";
            }
            else {
                double integral = simpsonIntegral(funcChoice, a, b);
                cout << "Приблизне значення інтегралу = " << integral << endl;
            }
        }
        else if (menuChoice == 5) {
            cout << "Завершення програми\n";
        }
        else {
            cout << "Невірний вибір\n";
        }
    }

    return 0;
}