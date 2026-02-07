#include <iostream>
#include <list>

using namespace std;

void inputList(list<double>& list, int n) {
    double x;
    for (int i = 0; i < n; i++) {
        cin >> x;
        list.push_back(x);
    }
}

bool checkForMinusThree(const list<double>& list) {
    for (auto i = list.begin(); i != list.end(); ++i) {
        if (*i < -3) {
            return true;
        }
    }
    return false;
}

void listProcessing(list<double>& list, bool checkForMinusThree) {
    if (checkForMinusThree) {
        for (auto i = list.begin(); i != list.end(); ++i) {
            if (*i < 0) {
                *i = (*i) * (*i);
            }
        }
    }
    else {
        for (auto i = list.begin(); i != list.end(); ++i) {
            *i *= 0.1;
        }
    }
}

void listReverse(const list<double>& list) {
    for (auto i = list.rbegin(); i != list.rend(); ++i) {
        cout << *i << " ";
    }
}

int main() {
    int n;
    list<double> numbers;
    cout << "Введіть кількість елементів списку: ";
    cin >> n;
    if (n <= 0) {
        cout << "Кількість елементів повинна бути додатньою.";
        return 1;
    }
    cout << "Введіть елементи списку: ";
    inputList(numbers, n);
    bool condition = checkForMinusThree(numbers);
    listProcessing(numbers, condition);
    cout << "Результат у зворотньому порядку: ";
    listReverse(numbers);
    return 0;
}