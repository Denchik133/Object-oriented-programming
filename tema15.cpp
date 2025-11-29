#include <iostream>
#include <string>
using namespace std;

class Building {
protected:
    string address;
    int floors;
public:
    Building(string addr = "Відсутня", int fl = 0) : address(addr), floors(fl) {}
    virtual void print() const {
        cout << "Будинок\nАдреса: " << address << "\nПоверхів: " << floors << "\n";
    }
    virtual ~Building() {}
};

class EducationalBuilding : public Building {
    int classrooms;
public:
    EducationalBuilding(string addr = "Відсутня", int fl = 0, int cr = 0) : Building(addr, fl), classrooms(cr) {}
    void print() const override {
        cout << "Навчальний корпус\nАдреса: " << address << "\nПоверхів: " << floors << "\nКабінетів: " << classrooms << "\n";
    }
};

class DigitalDevice {
protected:
    string brand;
public:
    DigitalDevice(string br = "Невідомий") : brand(br) {}
    virtual void show() const {
        cout << "Цифрові пристрої\nБренд: " << brand << "\n";
    }
    virtual ~DigitalDevice() {}
};

class MobilePhone : public DigitalDevice {
    int battery;
public:
    MobilePhone(string br = "Невідомий", int bt = 0) : DigitalDevice(br), battery(bt) {}
    void show() const override {
        cout << "Мобільний телефон\nБренд: " << brand << "\nБатарея: " << battery << " mAh\n";
    }
};

template <typename T>
void findInRange(T array[], int size, T low, T high) {
    cout << "Елементи у діапазоні [" << low << "; " << high << "]: ";
    for (int i = 0; i < size; i++) {
        if (array[i] >= low && array[i] <= high)
            cout << array[i] << " ";
    }
    cout << "\n";
}

template <typename A, typename B>
class Pair {
public:
    A first;
    B second;
    Pair(A f, B s) : first(f), second(s) {}
    void print() const {
        cout << "Пара: (" << first << ", " << second << ")\n";
    }
};

int main() {
    Building* buildings[2];
    string addr;
    int fl, cr;
    cout << "Введіть адресу будинку: ";
    getline(cin, addr);
    cout << "Введіть кількість поверхів: ";
    cin >> fl;
    buildings[0] = new Building(addr, fl);
    cin.ignore();
    cout << "\nВведіть адресу навчального корпусу: ";
    getline(cin, addr);
    cout << "Введіть кількість поверхів: ";
    cin >> fl;
    cout << "Введіть кількість кабінетів: ";
    cin >> cr;
    buildings[1] = new EducationalBuilding(addr, fl, cr);
    cout << "\n--- Дані про будівлі ---\n";
    for (int i = 0; i < 2; i++) {
        buildings[i]->print();
        cout << "\n";
        delete buildings[i];
    }
    DigitalDevice* devices[2];
    string brand;
    int battery;
    cout << "\nВведіть бренд цифрових пристроїв: ";
    cin >> brand;
    devices[0] = new DigitalDevice(brand);
    cout << "Введіть бренд телефону: ";
    cin >> brand;
    cout << "Введіть ємність батареї: ";
    cin >> battery;
    devices[1] = new MobilePhone(brand, battery);
    cout << "\n--- Дані про пристрої ---\n";
    for (int i = 0; i < 2; i++) {
        devices[i]->show();
        cout << "\n";
        delete devices[i];
    }
    cout << "\n--- Тест діапазону ---\n";
    int choice, size;
    while (true) {
        cout << "Введіть розмір масиву (щоб вийти введіть 0): ";
        cin >> size;
        if (size == 0) break;
        else if (size < 0) {
        cout << "Розмір масиву повинен бути додатнім. Спробуйте ще раз.\n";
        continue;
        }
        cout << "Оберіть тип даних масиву:\n1 - int\n2 - double\nВаш вибір: ";
        cin >> choice;
        if (choice != 1 && choice != 2) {
        cout << "Невірний вибір типу даних.\n";
        continue;
        }
        else if (choice == 1) {
        int* array = new int[size];
        if (size >= 1 && size <= 4){
            cout << "Введіть " << size << " елементи типу int:\n";
        }
        else {
            cout << "Введіть " << size << " елементів типу int:\n";
        }
        for (int i = 0; i < size; i++) cin >> array[i];
        int low, high;
        cout << "Нижня межа: ";
        cin >> low;
        cout << "Верхня межа: ";
        cin >> high;
        if (low > high) {
            cout << "Нижня межа не може бути більшою за верхню. Спробуйте ще раз.\n";
            delete[] array;
            continue;
        }
        findInRange(array, size, low, high);
        delete[] array;
        }
        else {
        double* array = new double[size];
        if (size >= 1 && size <= 4){
            cout << "Введіть " << size << " елементи типу double:\n";
        }
        else {
            cout << "Введіть " << size << " елементів типу double:\n";
        }
        for (int i = 0; i < size; i++) cin >> array[i];
        double low, high;
        cout << "Нижня межа: ";
        cin >> low;
        cout << "Верхня межа: ";
        cin >> high;
        if (low > high) {
            cout << "Нижня межа не може бути більшою за верхню. Спробуйте ще раз.\n";
            delete[] array;
            continue;
        }
        findInRange(array, size, low, high);
        delete[] array;
        }
    }
    cout << "\n--- Пара значень ---\n";
    int a;
    double b;
    cout << "Введіть ціле число: ";
    cin >> a;
    cout << "Введіть число double: ";
    cin >> b;
    Pair<int, double> p(a, b);
    p.print();
    return 0;
}