#include <iostream>
#include <string>
#include <stdexcept>

using namespace std;

bool isVowel(char c) {
    string vowels = "aeiouAEIOUаеєиіїоуюяАЕЄИІЇОУЮЯ";
    return vowels.find(c) != string::npos;
}

char caesarEncrypt(char c, int shift) {
    if (isalpha(c)) {
        char base = islower(c) ? 'a' : 'A';
        return base + (c - base + shift) % 26;
    }
    return c;
}

void task1() {
    try {
        cin.ignore();
        string text;
        char replaceChar;
        cout << "Введіть речення:\n";
        getline(cin, text);
        cout << "Введіть символ для заміни голосних: ";
        cin >> replaceChar;
        string replaced = text;
        for (char& c : replaced) {
            if (isVowel(c)) {
                c = replaceChar;
            }
        }
        cout << "\nПісля заміни голосних:\n";
        cout << replaced << endl;
        int shift;
        cout << "\nВведіть зсув для шифру Цезаря: ";
        cin >> shift;
        string encrypted = replaced;
        for (char& c : encrypted) {
            c = caesarEncrypt(c, shift);
        }
        cout << "\nЗашифрований текст:\n";
        cout << encrypted << endl;
        cout << "\n(Комбіноване шифрування: підстановка + Цезар)\n";
    }
    catch (...) {
        cout << "Помилка введення\n";
        cin.clear();
        cin.ignore(10000, '\n');
    }
}

string getSubstring(string s, int n, int dl) {
    if (n < 0 || n >= s.size() || dl < 0) {
        throw invalid_argument("Некоректні параметри");
    }
    return s.substr(n, dl);
}

void task3() {
    try {
        cin.ignore();
        string s;
        int n, dl;
        cout << "Введіть рядок:\n";
        getline(cin, s);
        cout << "Введіть позицію n: ";
        cin >> n;
        cout << "Введіть довжину dl: ";
        cin >> dl;
        string result = getSubstring(s, n, dl);
        cout << "\nПідрядок: " << result << endl;
        cout << "\n(Виділення частини зашифрованого повідомлення)\n";
    }
    catch (exception& e) {
        cout << "Помилка: " << e.what() << endl;
        cin.clear();
        cin.ignore(10000, '\n');
    }
}

int findWordPosition(string s, int wordIndex) {
    int count = 0;
    for (int i = 0; i < s.size(); i++) {
        if ((i == 0 || s[i - 1] == ' ') && s[i] != ' ') {
            count++;
            if (count == wordIndex) {
                return i;
            }
        }
    }
    return -1;
}

void task7() {
    try {
        cin.ignore();
        string s;
        int k;
        cout << "Введіть рядок:\n";
        getline(cin, s);
        cout << "Введіть номер слова: ";
        cin >> k;
        if (cin.fail() || k <= 0) {
            throw invalid_argument("Некоректний номер");
        }
        int pos = findWordPosition(s, k);
        if (pos == -1) {
            cout << "Слово не знайдено\n";
        }
        else {
            cout << "Позиція: " << pos << endl;
        }
        cout << "\n(Аналіз структури зашифрованого тексту)\n";
    }
    catch (exception& e) {
        cout << "Помилка: " << e.what() << endl;
        cin.clear();
        cin.ignore(10000, '\n');
    }
}

int main() {
    int choice;
    do {
        cout << "\n----- МЕНЮ -----\n";
        cout << "1 - Шифрування (заміна голосних + Цезар)\n";
        cout << "2 - Виділити підрядок\n";
        cout << "3 - Знайти позицію слова\n";
        cout << "0 - Вихід\n";
        cout << "Ваш вибір: ";
        cin >> choice;
        if (cin.fail()) {
            cin.clear();
            cin.ignore(10000, '\n');
            cout << "Некоректний ввід\n";
            continue;
        }
        switch (choice) {
        case 1: task1(); break;
        case 2: task3(); break;
        case 3: task7(); break;
        case 0: cout << "Вихід...\n"; break;
        default: cout << "Невірний вибір\n";
        }

    } while (choice != 0);
    return 0;
}