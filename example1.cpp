#include <iostream>
#include <string>
using namespace std;

class University {
protected:
    string name;
public:
    University(string nm) : name(nm) {}
    virtual void print() const {
        cout << "\nУніверситет: " << name;
    }
    virtual ~University() {}
};

class Faculty : public University {
protected:
    string facultyName;
public:
    Faculty(string univer, string facult) : University(univer), facultyName(facult) {
    }
    void print() const override {
        cout << "\nУніверситет: " << name << ", Факультет: " << facultyName;
    }
};

class Department : public Faculty {
    string departmentName;
public:
    Department(string univer, string facult, string depart) : Faculty(univer, facult), departmentName(depart) {
    }
    void print() const override {
        cout << "\nУніверситет: " << name << ", Факультет: " << facultyName << ", Кафедра: " << departmentName << "\n";
    }
};

int main() {
    University* array[] = {
        new University("МНТУ"),
        new Faculty("МНТУ", "???"),
        new Department("МНТУ", "???", "ІПЗ")
    };

    for (University* univer : array)
        univer->print();

    for (University* univer : array)
        delete univer;

    return 0;
}
