#include <iostream>
using namespace std;

class RotationFigures {
public:
    virtual double volume() const = 0;
    virtual void print() const = 0;
    virtual ~RotationFigures() {}
};

class Cone : public RotationFigures {
    double r, h;
public:
    Cone(double r, double h) : r(r), h(h) {}
    double volume() const override {
        return 3.14 * r * r * h / 3;
    }
    void print() const override {
        cout << "Конус:\nРадіус = " << r << ", висота = " << h << ", об'єм = " << volume() << "\n";
    }
};

int main() {
    int n;
    while (true) {
        cout << "Введіть потрібну кількість конусів: ";
        cin >> n;
        if (n > 0)
            break;
        cout << "Кількість повинна бути більше 0. Спробуйте ще раз.\n";
    }
    RotationFigures** array = new RotationFigures * [n];
    for (int i = 0; i < n; i++) {
        double r, h;
        while (true) {
            cout << "Введіть радіус для конуса " << i + 1 << ": ";
            cin >> r;
            if (r > 0)
                break;
            cout << "Радіус повинен бути більше 0. Спробуйте ще раз.\n";
        }
        while (true) {
            cout << "Введіть висоту для конуса " << i + 1 << ": ";
            cin >> h;
            if (h > 0)
                break;
            cout << "Висота повинна бути більше 0. Спробуйте ще раз.\n";
        }
        array[i] = new Cone(r, h);
        cout << "\n";
    }
    for (int i = 0; i < n; i++)
        array[i]->print();
    for (int i = 0; i < n; i++)
        delete array[i];
    delete[] array;
    return 0;
}