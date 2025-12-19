#include <iostream>
using namespace std;

template <typename T>
void findInRange(T array[], int size, T min, T max) {
    for (int i = 0; i < size; i++) {
        if (array[i] >= min && array[i] <= max)
            cout << array[i] << " ";
    }
    cout << "\n";
}

int main() {
    int n;
    cout << "Введіть кількість елементів: ";
    cin >> n;
    int* array = new int[n];
    cout << "Введіть елементи масиву: ";
    for (int i = 0; i < n; i++)
        cin >> array[i];
    int min, max;
    cout << "Введіть мінімум і максимум: ";
    cin >> min >> max;
    cout << "\n";
    findInRange(array, n, min, max);
    delete[] array;
    return 0;
}