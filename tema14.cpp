#include <iostream>
#include <string>
using namespace std;

int exe(int acc, const string& op, int value);

class Person {
private:
    string _name;
    Person& operator=(const Person&);
public:
    explicit Person(const char []);
    Person(const Person&);
    ~Person();
    const string& getName() const;
};

Person::Person(const char name[]): _name(name) {
    cout<<"A person "<<_name<<" was created"<<endl;
}
Person::Person(const Person& other): _name(other._name) {}
Person::~Person() {
    cout<<"A person "<<_name<<" was deleted"<<endl;
}
const string& Person::getName() const {return _name;}

class Employer;
class Employee;
class Accountant;

class Position {
    friend class Accountant;
private:
    string _name;
    unsigned int _salary;
    Position& operator=(const Position&);
    Position(const Position&);
public:
    Position(char [], unsigned int);
    ~Position();
    const string& getPositionName() const;
    unsigned int getSalary() const;
};

Position::Position(char name[], unsigned int salary)
    : _name(name), _salary(salary)
{
    cout<<"A Position "<<_name<<'('<<_salary<<")was created"<<endl;
}
Position::~Position() {
    cout<<"A Position "<<_name<<" was deleted"<<endl;
}
const string& Position::getPositionName() const {return _name;}
unsigned int Position::getSalary() const {return _salary;}

class Employee {
    friend class Employer;
private:
    const Position& _what;
    const Person& _who;
    Employee(const Person&, const Position&);
    Employee(const Employee&);
    Employee& operator=(const Employee&);
    ~Employee();
public:
    const Person& who() const;
    const Position& what() const;
};

Employee::Employee(const Person& who, const Position& what)
    : _who(who), _what(what)
{
    cout<<"Employee "<<_who.getName()<<" takes a position "
        <<_what.getPositionName()<<endl;
}
Employee::~Employee() {
    cout<<"Employee "<<_who.getName()
        <<" fired from "<<_what.getPositionName()<<endl;
}
const Person& Employee::who() const { return _who; }
const Position& Employee::what() const { return _what; }

class Accountant {
    friend class Employee;
    friend class Position;
    friend class Employer;
public:
    void payroll() const;
    ~Accountant();
private:
    Accountant(const Employer&, const Person&);
    Accountant(const Accountant&);
    Accountant& operator=(const Accountant&);
    void payroll(const Employee&) const;

    const Employer& _myEmployer;
    const Person& _who;
};

class Employer {
    friend void Accountant::payroll() const;
private:
    struct Staff {
        Employee* _pemployee;
        bool _free;
    };

    size_t _volume;
    Staff* _office;
    Accountant* _accountant;
    const Person& _me;

    Employer(const Employer&);
    Employer& operator=(const Employer&);
public:
    Employer(const Person&, size_t, const Person&);
    ~Employer();
    size_t volume() const { return _volume; }
    void hire(const Person&, const Position&, size_t posNumber);
    void fire(size_t);
    void pay() const;
};

Accountant::Accountant(const Employer& employer, const Person& p)
    : _myEmployer(employer), _who(p)
{
    cout<<"Accountant "<<_who.getName()<<" is hired"<<endl;
}

Accountant::~Accountant() {
    cout<<"Accountant was deleted"<<endl;
}

void Accountant::payroll() const {
    cout<<"---Start payroll"<<endl;
    for(size_t i=0; i<_myEmployer.volume(); i++)
        if(!_myEmployer._office[i]._free)
            payroll(*_myEmployer._office[i]._pemployee);
    cout<<"---Stop payroll"<<endl;
}

void Accountant::payroll(const Employee& employee) const {
    cout<<"Pay "<<employee.who().getName()<<" amount "
        <<employee.what().getSalary()<<endl;
}

Employer::Employer(const Person& boss, size_t volume,
                   const Person& accountant)
    : _me(boss), _volume(volume),
      _office(new Staff[_volume]),
      _accountant(new Accountant(*this, accountant))
{
    cout<<"Employer "<<_me.getName()<<" with "<<_volume
        <<" positions was created"<<endl;

    for(size_t i=0; i<_volume; i++) {
        _office[i]._free = true;
        _office[i]._pemployee = nullptr;
    }
}

Employer::~Employer() {
    cout<<"Employer "<<_me.getName()<<" with "<<_volume
        <<" positions was deleted"<<endl;

    for(size_t i=0; i<_volume; i++)
        if(!_office[i]._free)
            delete _office[i]._pemployee;

    delete [] _office;
    delete _accountant;
}

void Employer::hire(const Person& person, const Position& position, size_t posNumber) {
size_t i = 0;
    while(i < _volume && !_office[i]._free) i++;

    if(i == _volume) {
        cout << "No vacant positions! Cannot hire " << person.getName() << endl;
        return;
    }

    Employee* pemployee = new Employee(person, position);
    _office[i]._free = false;
    _office[i]._pemployee = pemployee;

    cout << "Hired " << person.getName()
         << " as " << position.getPositionName()
         << " at position " << posNumber << endl;
}

void Employer::fire(size_t i) {
    if(i >= _volume) {
        cout << "Invalid index for fire(): " << i + 1 << endl;
        return;
    }

    if(_office[i]._free) {
        cout << "Position " << i + 1 << " already empty!" << endl;
        return;
    }

    cout << "Firing " << _office[i]._pemployee->who().getName()
    << " from " << _office[i]._pemployee->what().getPositionName()
    << " at slot " << i + 1 << endl;

    delete _office[i]._pemployee;
    _office[i]._pemployee = nullptr;
    _office[i]._free = true;
}

void Employer::pay() const {
    _accountant->payroll();
}

int exe(int acc, const string& op, int value) {
    if(op == "+") acc += value;
    else if(op == "-") acc -= value;
    else if(op == "*") acc *= value;
    else if(op == "/") {
        if(value == 0){
            cout << "Error: division by zero!" << endl;
            return acc;
        }
        acc /= value;
    }
    else if(op == "%") {
        if(value == 0){
            cout << "Error: modulo by zero!" << endl;
            return acc;
        }
        acc %= value;
    }
    else if(op == "=") acc = value;
    else {
        cout << "Unknown operation: " << op << endl;
    }
    return acc;
}



int main() {
    cout << "--- Create Employer ---\n";

    string bossName;
    cout << "Enter boss name: ";
    cin >> bossName;
    Person boss(bossName.c_str());

    string accName;
    cout << "Enter accountant name: ";
    cin >> accName;
    Person accountantPerson(accName.c_str());

    size_t volume;
    cout << "Enter number of positions: ";
    cin >> volume;

    Employer employer(boss, volume, accountantPerson);

    cout << "\n--- Create Positions ---\n";
    vector<Position*> positions;

    for (size_t i = 0; i < volume; i++) {
        string posName;
        unsigned int salary;

        cout << "Position №" << i + 1 << " name: ";
        cin >> posName;

        cout << "Salary: ";
        cin >> salary;

        positions.push_back(new Position((char*)posName.c_str(), salary));
    }

    cout << "\n--- MENU ---\n";
    cout << "1 – Hire\n";
    cout << "2 – Fire\n";
    cout << "3 – Pay\n";
    cout << "4 – Calculator exe()\n";
    cout << "0 – Exit\n";

    while (true) {
        cout << "\nChoice: ";
        int choice;
        cin >> choice;

        if (choice == 0) {
            cout << "Exiting...\n";
            break;
        }

        if (choice == 1) {
            string name;
            size_t posIndex;

            cout << "Enter employee name: ";
            cin >> name;

            cout << "Choose position index (1 - " << positions.size() << "): ";
            cin >> posIndex;

            if (posIndex < 1 || posIndex > positions.size()) {
                cout << "Invalid position!\n";
                continue;
            }

            Person* p = new Person(name.c_str());
            employer.hire(*p, *positions[posIndex - 1], posIndex);
        }

        else if (choice == 2) {
            size_t idx;
            cout << "Enter position index to fire (1 - " << positions.size() << "): ";
            cin >> idx;

            if (idx < 1 || idx > positions.size()) {
                cout << "Invalid index!\n";
                continue;
            }

            employer.fire(idx - 1);
        }

        else if (choice == 3) {
            employer.pay();
        }

        else if (choice == 4) {
            int acc = 0;
            cout << "Accumulator starts at 0.\n";

            while (true) {
                string op;
                int value;

                cout << "Enter operation (+ - * / % =) or exit: ";
                cin >> op;

                if (op == "exit") break;

                cout << "Enter value: ";
                cin >> value;

                acc = exe(acc, op, value);
                cout << "Accumulator = " << acc << endl;
            }
        }

        else {
            cout << "Unknown option!\n";
        }
    }

    for (auto p : positions)
        delete p;

    return 0;
}
