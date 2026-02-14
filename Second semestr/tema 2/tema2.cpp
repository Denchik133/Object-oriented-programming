#include <iostream>
#include <string>

using namespace std;

class Cipher {
public:
    virtual string encrypt(const string& text, int position) = 0;
    virtual ~Cipher() {}
};

class MirrorCipher : public Cipher {
public:
    string encrypt(const string& text, int position) override {
        string result = text;

        for (char& c : result) {
            if (c >= 'A' && c <= 'Z')
                c = 'Z' - (c - 'A');
            else if (c >= 'a' && c <= 'z')
                c = 'z' - (c - 'a');
        }
        return result;
    }
};

class ScaleCipher : public Cipher {
public:
    string encrypt(const string& text, int position) override {
        string result = text;

        int shift = ((position % 26) + 26) % 26;

        for (char& c : result) {
            if (c >= 'A' && c <= 'Z')
                c = (c - 'A' + shift) % 26 + 'A';
            else if (c >= 'a' && c <= 'z')
                c = (c - 'a' + shift) % 26 + 'a';
        }
        return result;
    }
};

bool readPosition(int& position) {
    while (true) {
        int posInput;
        cin >> posInput;
        while (cin.fail()) {
            cin.clear();
            cin.ignore(10000, '\n');
            cout << "\033[31mНекоректне введення. Введіть число.\033[0m\n";
            cin >> posInput;
        }
        if (posInput < 0 || posInput != static_cast<int>(posInput)) {
            cout << "\033[31mПозиція має бути невід'ємним цілим числом.\033[0m\n";
            continue;
        }
        position = static_cast<int>(posInput);
        return true;
    }
}

void task1() {
    cout << "\nЗавдання 1: Поліморфізм для двох класів (виклик через покажчик ->)";
    string value;
    int position;
    while (true) {
        cout << "\nВведіть текст для шифрування (0 - вихід): ";
        cin.ignore();
        getline(cin, value);
        if (value == "0") {
            cout << "\nЗавершення роботи.";
            break;
        }
        cout << "Введіть позицію елемента: ";
        if (!readPosition(position)) {
            continue;
        }
        Cipher* cipher;
        MirrorCipher mirror;
        cipher = &mirror;
        cout << "\033[32mЗашифроване значення: " << cipher->encrypt(value, position) << "\033[0m\n";
        break;
    }
}

void process(Cipher* cipher, const string& value, int position) {
    cout << "\033[32mЗашифроване значення: " << cipher->encrypt(value, position) << "\033[0m\n";
}

void task2() {
    cout << "\n\nЗавдання 2: Поліморфізм для трьох класів (передача покажчика у функцію)\n";
    string value;
    int position, choice;
    while (true) {
        cout << "\nВведіть текст для шифрування (0 - вихід): ";
        cin.ignore();
        getline(cin, value);
        if (value == "0") {
            cout << "\nЗавершення роботи.";
            break;
        }
        cout << "Введіть позицію елемента: ";
        if (!readPosition(position)) {
            continue;
        }
        cout << "\033[36mОберіть алгоритм шифрування:";
        cout << "\n1 - Дзеркальне шифрування";
        cout << "\n2 - Масштабування\033[0m";
        cout << "\nВаш вибір: ";
        cin >> choice;
        if (choice != 1 && choice != 2) {
            cout << "Невірний вибір. Спробуйте ще раз.";
            continue;
        }
        MirrorCipher mirror;
        ScaleCipher scale;
        if (choice == 1) {
            process(&mirror, value, position);
        }
        else {
            process(&scale, value, position);
        }
        break;
    }
}

class EncryptionService {
public:
    void execute(Cipher& cipher, const string& value, int position) {
        cout << "\033[32mЗашифроване значення: " << cipher.encrypt(value, position) << "\033[0m\n";
    }
};

void task3() {
    cout << "\n\nЗавдання 3: Поліморфізм для трьох класів (передача посилання у метод)\n";
    string value;
    int position, choice;
    while (true) {
        cout << "\nВведіть текст для шифрування (0 - вихід): ";
        cin.ignore();
        getline(cin, value);
        if (value == "0") {
            cout << "\nЗавершення роботи.";
            break;
        }
        cout << "Введіть позицію елемента: ";
        if (!readPosition(position)) {
            continue;
        }
        cout << "\033[36mОберіть алгоритм шифрування:";
        cout << "\n1 - Дзеркальне шифрування";
        cout << "\n2 - Масштабування\033[0m";
        cout << "\nВаш вибір: ";
        cin >> choice;
        if (choice != 1 && choice != 2) {
            cout << "Невірний вибір. Спробуйте ще раз.";
            continue;
        }
        MirrorCipher mirror;
        ScaleCipher scale;
        EncryptionService service;
        if (choice == 1) {
            service.execute(mirror, value, position);
        }
        else {
            service.execute(scale, value, position);
        }
        break;
    }
}

int main() {
    task1();
    task2();
    task3();
    cout << "\nРоботу програми завершено.";
    return 0;
}
