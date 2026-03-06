#include <iostream>
#include <vector>
#include <string>
#include <stdexcept>
#include <locale>

using namespace std;

class CesarCipher {
private:
    int shift;
    int mode;

public:
    CesarCipher(int s, int m) {
        shift = s;
        mode = m;
    }

    wstring encrypt(const wstring& text)
    {
        const wstring latinUpper = L"ABCDEFGHIJKLMNOPQRSTUVWXYZ";
        const wstring latinLower = L"abcdefghijklmnopqrstuvwxyz";

        const wstring cyrUpper = L"АБВГДЕЁЖЗИЙКЛМНОПРСТУФХЦЧШЩЪЫЬЭЮЯ";
        const wstring cyrLower = L"абвгдеёжзийклмнопрстуфхцчшщъыьэюя";

        const wstring digits = L"0123456789";
        wstring result = text;
        for (wchar_t& c : result) {
            if (mode == 1) {
                size_t pos = latinUpper.find(c);
                if (pos != wstring::npos) {
                    c = latinUpper[(pos + shift % 26 + 26) % 26];
                    continue;
                }
                pos = latinLower.find(c);
                if (pos != wstring::npos) {
                    c = latinLower[(pos + shift % 26 + 26) % 26];
                    continue;
                }
            }
            if (mode == 2) {
                size_t pos = cyrUpper.find(c);
                if (pos != wstring::npos) {
                    c = cyrUpper[(pos + shift % cyrUpper.size() + cyrUpper.size()) % cyrUpper.size()];
                    continue;
                }
                pos = cyrLower.find(c);
                if (pos != wstring::npos) {
                    c = cyrLower[(pos + shift % cyrLower.size() + cyrLower.size()) % cyrLower.size()];
                    continue;
                }
            }
            size_t pos = digits.find(c);
            if (pos != wstring::npos) {
                c = digits[(pos + shift % 10 + 10) % 10];
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
            wcout << s << endl;
        }
    }
};

int main() {
    setlocale(LC_ALL, "");
    locale::global(locale(""));
    wcout.imbue(locale());
    Stack<wstring> cipherStack;
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
    int mode;
    while (true) {
        cout << "\nОберіть алфавіт:\n";
        cout << "1 - Латиниця\n";
        cout << "2 - Кирилиця\n";
        cout << "Ваш вибір: ";
        cin >> mode;
        if (!cin.fail() && (mode == 1 || mode == 2)) {
            break;
        }
        cout << "\033[31mНекоректний вибір.\033[0m\n";
        cin.clear();
        cin.ignore(10000, '\n');
    }
    CesarCipher cipher(shift, mode);
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
    wcout << L"Введіть повідомлення:\n";
    for (int i = 0; i < n; i++) {
        wstring text;
        while (true) {
            getline(wcin, text);
            if (!text.empty()) {
                break;
            }
            wcout << L"\033[31mРядок не може бути порожнім. Введіть ще раз:\033[0m\n";
        }
        wstring encrypted = cipher.encrypt(text);
        cipherStack.push(encrypted);
    }
    wcout << L"\nЗашифровані повідомлення у стеку:\n";
    cipherStack.print();
    wcout << L"\nНайдовший зашифрований рядок:\n";
    wcout << cipherStack.longest() << endl;
    return 0;
}
