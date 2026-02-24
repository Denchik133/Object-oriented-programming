#include <iostream>
#include <stdexcept>

using namespace std;

int main() {
    while (true) {
        try {
            double p1, p2, p3;
            cout << "Введіть ймовірність для 1-го довідника: ";
            cin >> p1;
            cout << "Введіть ймовірність для 2-го довідника: ";
            cin >> p2;
            cout << "Введіть ймовірність для 3-го довідника: ";
            cin >> p3;
            bool validInput = !cin.fail() && p1 >= 0 && p1 <= 1 && p2 >= 0 && p2 <= 1 && p3 >= 0 && p3 <= 1;
            if (!validInput) {
                throw invalid_argument("Ймовірності мають бути в межах [0;1]");
            }
            double q1 = 1 - p1;
            double q2 = 1 - p2;
            double q3 = 1 - p3;
            double onlyOne = p1 * q2 * q3 + q1 * p2 * q3 + q1 * q2 * p3;
            double onlyTwo = p1 * p2 * q3 + p1 * q2 * p3 + q1 * p2 * p3;
            double allThree = p1 * p2 * p3;
            double atLeastOne = 1 - q1 * q2 * q3;
            cout << "\nРезультати:\n";
            cout << "а) лише в одному = " << onlyOne << "\n";
            cout << "б) лише в двох = " << onlyTwo << "\n";
            cout << "в) в усіх трьох = " << allThree << "\n";
            cout << "г) хоча б в одному = " << atLeastOne << "\n";
            break;
        }
        catch (const exception& e) {
            cout << "\033[31mПомилка: " << e.what() << "\033[0m\n";
            cin.clear();
            cin.ignore(10000, '\n');
        }
    }
    return 0;
}