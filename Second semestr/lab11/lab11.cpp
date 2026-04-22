#include <iostream>
#include <vector>
#include <string>

using namespace std;

char encryptChar(char c, int shift) {
    if (isalpha(c)) {
        char base = islower(c) ? 'a' : 'A';
        return base + (c - base + shift) % 26;
    }
    return c;
}

// 6. ВИВІД МАСИВУ
void printArray(const vector<int>& array, int index = 0) {
    if (index >= array.size()) {
        return;
    }
    cout << array[index] << " ";
    printArray(array, index + 1);
}

// 9. СЕРЕДНЄ АРИФМЕТИЧНЕ
double sumRecursive(const vector<int>& array, int index = 0) {
    if (index >= array.size()) {
        return 0;
    }
    return array[index] + sumRecursive(array, index + 1);
}

double averageRecursive(const vector<int>& array) {
    if (array.empty()) {
        return 0;
    }
    return sumRecursive(array) / array.size();
}

// 12. ДОБУТОК НЕПАРНИХ
long long productOdd(const vector<int>& array, int index = 0) {
    if (index >= array.size()) {
        return 1;
    }
    if (array[index] % 2 != 0) {
        return array[index] * productOdd(array, index + 1);
    }
    return productOdd(array, index + 1);
}

int main() {
    string text;
    int shift;
    cout << "Введіть текст: ";
    getline(cin, text);
    cout << "Введіть зсув: ";
    cin >> shift;
    vector<int> data;
    for (char c : text) {
        char enc = encryptChar(c, shift);
        data.push_back((int)enc);
    }
    cout << "\nЗашифровані коди:\n";
    printArray(data);
    cout << "\n\nСереднє значення кодів: ";
    cout << averageRecursive(data);
    cout << "\nДобуток непарних елементів: ";
    cout << productOdd(data);
    cout << endl;
    return 0;
}