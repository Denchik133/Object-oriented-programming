#include <iostream>
#include <stdexcept>

using namespace std;

int main() {
    while(true) {
        try {
            double p1, p2, p3, p4;
            cout << "Введіть ймовірність того, що 1-й верстат НЕ потребує наладки: ";
            cin >> p1;
            cout << "Введіть ймовірність того, що 2-й верстат НЕ потребує наладки: ";
            cin >> p2;
            cout << "Введіть ймовірність того, що 3-й верстат НЕ потребує наладки: ";
            cin >> p3;
            cout << "Введіть ймовірність того, що 4-й верстат НЕ потребує наладки: ";
            cin >> p4;
            bool validInput = !cin.fail() && p1>=0 && p1<=1 && p2>=0 && p2<=1 && p3>=0 && p3<=1 && p4>=0 && p4<=1;
            if(!validInput) {
                throw invalid_argument("Ймовірності мають бути числами від 0 до 1.");
            }
            double allWorking = p1 * p2 * p3 * p4;
            double result = 1 - allWorking;
            cout << "\nЙмовірність того, що хоча б один верстат потребує наладки = " << result << "\n";
            break;
        }
        catch(const exception& e) {
            cout << "\033[31mПомилка: " << e.what() << "\033[0m\n";
            cin.clear();
            cin.ignore(10000,'\n');
        }
    }
    return 0;
}