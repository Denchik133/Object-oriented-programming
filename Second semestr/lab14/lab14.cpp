#include <iostream>
#include <fstream>
#include <string>
#include <stdexcept>

using namespace std;

char cesarEncrypt(char c, int shift) {
    if (isalpha(c)) {
        char base = islower(c) ? 'a' : 'A';
        return base + (c - base + shift) % 26;
    }
    return c;
}

void task3() {
    try {
        cin.ignore();
        string text;
        int shift;
        cout << "Введіть текст:\n";
        getline(cin, text);
        cout << "Введіть зсув: ";
        cin >> shift;
        if (cin.fail()) {
            throw invalid_argument("Помилка введення");
        }
        string encrypted = text;
        for (char& c : encrypted) {
            c = cesarEncrypt(c, shift);
        }
        ofstream out("cipher.txt");
        if (!out) {
            throw runtime_error("Помилка файлу");
        }
        out << encrypted;
        out.close();
        ifstream in("cipher.txt");
        string readText;
        getline(in, readText);
        cout << "\nЗашифрований текст з файлу:\n";
        cout << readText << "\n";
        double sum = 0;
        for (char c : readText) {
            sum += (int)c;
        }
        cout << "\nСереднє ASCII: " << sum / readText.size() << "\n";
    }
    catch (exception& e) {
        cout << "Помилка: " << e.what() << "\n";
        cin.clear();
        cin.ignore(10000, '\n');
    }
}

void task5() {
    try {
        int array[5];
        cout << "Введіть 5 чисел:\n";
        for (int i = 0; i < 5; i++) {
            cin >> array[i];
            if (cin.fail()) {
                throw invalid_argument("Помилка введення");
            }
        }
        ofstream out("array.txt");
        for (int i = 0; i < 5; i++) {
            out << array[i] << " ";
        }
        out.close();
        ifstream in("array.txt");
        cout << "\nМасив з файлу:\n";
        int x;
        while (in >> x) {
            cout << x << "\n";
        }
    }
    catch (exception& e) {
        cout << "Помилка: " << e.what() << "\n";
        cin.clear();
        cin.ignore(10000, '\n');
    }
}

struct CipherData {
    char name[20];
    int key;
};

void task9() {
    try {
        CipherData c;
        cout << "Введіть назву шифру: ";
        cin >> c.name;
        cout << "Введіть ключ: ";
        cin >> c.key;
        if (cin.fail()) {
            throw invalid_argument("Помилка введення");
        }
        ofstream out("structs.bin", ios::binary | ios::app);
        out.write((char*)&c, sizeof(c));
        out.close();
        cout << "\nСтруктуру додано\n";
    }
    catch (exception& e) {
        cout << "Помилка: " << e.what() << "\n";
        cin.clear();
        cin.ignore(10000, '\n');
    }
}

int main() {
    int choice;
    do {
        cout << "\n===== МЕНЮ =====\n";
        cout << "1 - Шифрування Цезаря (файл)\n";
        cout << "2 - Масив у файл\n";
        cout << "3 - Структура (шифр)\n";
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
        case 1: task3(); break;
        case 2: task5(); break;
        case 3: task9(); break;
        case 0: cout << "Вихід...\n"; break;
        default: cout << "Невірний вибір\n";
        }
    } while (choice != 0);
    return 0;
}