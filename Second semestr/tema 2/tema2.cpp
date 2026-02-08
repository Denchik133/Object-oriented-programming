#include <iostream>

using namespace std;

class Cipher {
public:
    virtual double encrypt(double value, int position) = 0;
    virtual ~Cipher() {}
};

class MirrorCipher : public Cipher {
public:
    double encrypt(double value, int position) override {
        return -value + position;
    }
};

class ScaleCipher : public Cipher {
public:
    double encrypt(double value, int position) override {
        return value * 2 + position;
    }
};

bool readPosition(int& position) {
    double posInput;
    cin >> posInput;
    if (cin.fail()) {
        cin.clear();
        cin.ignore(10000, '\n');
        cout << "\033[31mНекоректне введення. Введіть число.\033[0m\n";
        return false;
    }
    if (posInput < 0 || posInput != static_cast<int>(posInput)) {
        cout << "\033[31mПозиція має бути невід'ємним цілим числом.\033[0m\n";
        return false;
    }
    position = static_cast<int>(posInput);
    return true;
}

void task1() {
    cout << "\nЗавдання 1: Поліморфізм для двох класів (виклик через покажчик ->)";
    double value;
    int position;
    while (true) {
        cout << "\nВведіть значення для шифрування (Щоб завершити програму введіть 0): ";
        cin >> value;
        if (value == 0) {
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

void process(Cipher* cipher, double value, int position) {
    cout << "\033[32mЗашифроване значення: " << cipher->encrypt(value, position) << "\033[0m\n";
}

void task2() {
    cout << "\n\nЗавдання 2: Поліморфізм для трьох класів (передача покажчика у функцію)\n";
    double value;
    int position, choice;
    while (true) {
        cout << "Введіть значення для шифрування (Щоб завершити програму введіть 0): ";
        cin >> value;
        if (value == 0) {
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
    void execute(Cipher& cipher, double value, int position) {
        cout << "\033[32mЗашифроване значення: " << cipher.encrypt(value, position) << "\033[0m\n";
    }
};

void task3() {
    cout << "\n\nЗавдання 3: Поліморфізм для трьох класів (передача посилання у метод)\n";
    double value;
    int position, choice;
    while (true) {
        cout << "Введіть значення для шифрування (Щоб завершити програму введіть 0): ";
        cin >> value;
        if (value == 0) {
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