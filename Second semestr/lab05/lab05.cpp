#include <iostream>
#include <vector>
#include <string>
#include <stdexcept>

using namespace std;

class CesarCipher {
private:
    int shift;
public:
    CesarCipher(int s) {
        shift = s % 26;
    }
    string encrypt(const string& text) {
        string result = text;
        for (char& c : result) {
            if (isupper(c)) {
                c = 'A' + (c - 'A' + shift + 26) % 26;
            }
            else if (islower(c)) {
                c = 'a' + (c - 'a' + shift + 26) % 26;
            }
        }
        return result;
    }
};

template<typename T>
class Stack {
private:
    vector<T> data;
public:

    void push(const T& value) {
        data.push_back(value);
    }

    T pop() {
        if (data.empty()) {
            throw runtime_error("Стек порожній");
        }
        T value = data.back();
        data.pop_back();
        return value;
    }

    bool empty() const {
        return data.empty();
    }

    void print() const {
        for (const auto& v : data) {
            cout << v << endl;
        }
    }

    vector<T> getData() const {
        return data;
    }
};

template<typename T>
Stack<T> mergeStacks(const Stack<T>& s1, const Stack<T>& s2) {
    vector<T> a = s1.getData();
    vector<T> b = s2.getData();
    Stack<T> result;
    int i = 0;
    int j = 0;
    while (i < a.size() && j < b.size()) {
        if (a[i] <= b[j]) {
            result.push(a[i]);
            i++;
        }
        else {
            result.push(b[j]);
            j++;
        }
    }
    while (i < a.size()) {
        result.push(a[i]);
        i++;
    }
    while (j < b.size()) {
        result.push(b[j]);
        j++;
    }
    return result;
}

int main() {
    try {
        int shift;
        while (true) {
            cout << "Введіть зсув для шифру Цезаря: ";
            cin >> shift;
            if (!cin.fail()) {
                break;
            }
            cout << "\033[31mПомилка введення.\033[0m\n";
            cin.clear();
            cin.ignore(10000, '\n');
        }
        CesarCipher cipher(shift);
        Stack<string> stack1;
        Stack<string> stack2;
        int n1, n2;
        while (true) {
            cout << "Введіть кількість елементів для першого стеку: ";
            cin >> n1;
            if (!cin.fail() && n1 > 0) {
                break;
            }
            cout << "\033[31mНекоректне число.\033[0m\n";
            cin.clear();
            cin.ignore(10000, '\n');
        }
        cin.ignore();
        cout << "Введіть впорядковані рядки:\n";
        for (int i = 0; i < n1; i++) {
            string text;
            getline(cin, text);
            string encrypted = cipher.encrypt(text);
            stack1.push(encrypted);
        }
        while (true) {
            cout << "Введіть кількість елементів для другого стеку: ";
            cin >> n2;
            if (!cin.fail() && n2 > 0) {
                break;
            }
            cout << "\033[31mНекоректне число.\033[0m\n";
            cin.clear();
            cin.ignore(10000, '\n');
        }
        cin.ignore();
        cout << "Введіть впорядковані рядки:\n";
        for (int i = 0; i < n2; i++) {
            string text;
            getline(cin, text);
            string encrypted = cipher.encrypt(text);
            stack2.push(encrypted);
        }
        Stack<string> merged = mergeStacks(stack1, stack2);
        cout << "\nОб'єднаний стек:\n";
        merged.print();
    }
    catch (const exception& e) {
        cout << "\033[31mПомилка: " << e.what() << "\033[0m\n";
    }
    return 0;
}