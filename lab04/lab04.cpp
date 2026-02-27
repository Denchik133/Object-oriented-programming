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
            throw runtime_error("Стек порожній!");
        }
        T value = data.back();
        data.pop_back();
        return value;
    }
    T longest() const {
        if (data.empty()) {
            throw runtime_error("Стек порожній!");
        }
        T maxStr = data[0];
        for (const auto& s : data) {
            if (s.length() > maxStr.length()) {
                maxStr = s;
            }
        }
        return maxStr;
    }
    void print() const {
        for (const auto& s : data) {
            cout << s << endl;
        }
    }
};

int main()
{
    Stack<string> cipherStack;
    int shift;
    while (true) {
        cout << "Введіть зсув для шифру Цезаря: ";
        cin >> shift;
        if (!cin.fail()) {
            break;
        }
        cout << "\033[31mНекоректний ввід. Спробуйте ще раз.\033[0m\n";
        cin.clear();
        cin.ignore(10000, '\n');
    }
    CesarCipher cipher(shift);
    int n;
    while (true) {
        cout << "Скільки повідомлень додати у стек: ";
        cin >> n;
        if (!cin.fail() && n > 0) {
            break;
        }
        cout << "\033[31mВведіть додатнє ціле число.\033[0m\n";
        cin.clear();
        cin.ignore(10000, '\n');
    }
    cin.ignore();
    cout << "Введіть повідомлення:\n";
    for (int i = 0; i < n; i++) {
        string text;
        while (true) {
            getline(cin, text);
            if (!text.empty()) {
                break;
            }
            cout << "\033[31mРядок не може бути порожнім. Введіть ще раз:\033[0m\n";
        }
        string encrypted = cipher.encrypt(text);
        cipherStack.push(encrypted);
    }
    cout << "\nЗашифровані повідомлення у стеку:\n";
    cipherStack.print();
    cout << "\nНайдовший зашифрований рядок:\n";
    cout << cipherStack.longest() << endl;
    return 0;
}