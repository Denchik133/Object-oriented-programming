#include <iostream>
#include <list>
#include <string>
#include <stdexcept>
#include <cctype>

using namespace std;

template <typename T>
class SparseArray {
private:
    struct Node {
        int index;
        T value;
        Node(int i, const T& v) : index(i), value(v) {}
    };
    int logicalSize;
    list<Node> data;
public:
    SparseArray(int size = 0) {
        if (size < 0) {
            throw invalid_argument("Некоректний розмір масиву");
        }
        logicalSize = size;
    }
    SparseArray(const SparseArray& other) {
        logicalSize = other.logicalSize;
        data = other.data;
    }
    SparseArray& operator=(const SparseArray& other) {
        if (this != &other) {
            logicalSize = other.logicalSize;
            data = other.data;
        }
        return *this;
    }
    T& operator[](int index) {
        if (index < 0 || index >= logicalSize) {
            throw out_of_range("Індекс виходить за межі масиву");
        }
        for (auto& node : data) {
            if (node.index == index) {
                return node.value;
            }
        }
        data.push_back(Node(index, T()));
        return data.back().value;
    }

    void print() {
        cout << "\nЗбережені елементи у розрідженому масиві:\n";
        for (auto& node : data) {
            cout << "індекс: " << node.index << " значення: " << node.value << endl;
        }
    }
};

char cesarEncrypt(char c, int shift) {
    if (isalpha(c)) {
        char base = islower(c) ? 'a' : 'A';
        return base + (c - base + shift) % 26;
    }

    return c;
}

string encryptText(string text, int shift) {
    for (char& c : text) {
        c = cesarEncrypt(c, shift);
    }
    return text;
}

int main() {
    try {
        int size;
        string text;
        int shift;
        cout << "Введіть логічний розмір розрідженого масиву: ";
        cin >> size;
        cin.ignore();
        cout << "Введіть текст для шифрування: ";
        getline(cin, text);
        cout << "Введіть зсув шифру Цезаря: ";
        cin >> shift;
        string encrypted = encryptText(text, shift);
        cout << "\nЗашифрований текст: " << encrypted << endl;
        SparseArray<char> array(size);
        for (int i = 0; i < encrypted.size(); i++) {
            array[i] = encrypted[i];
        }
        array.print();
    }
    catch (exception& e) {
        cout << "Помилка: " << e.what() << endl;
    }
    return 0;
}