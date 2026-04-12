#include <iostream>
#include <string>
#include <stdexcept>

using namespace std;

string cesarEncrypt(string text, int shift) {
    for (char& c : text) {
        if (isalpha(c)) {
            char base = islower(c) ? 'a' : 'A';
            c = base + (c - base + shift) % 26;
        }
    }
    return text;
}

struct Node {
    string data;
    Node* next;
};

class SinglList {
private:
    Node* head;
public:
    SinglList() : head(nullptr) {}

    void addFront(string value) {
        Node* newNode = new Node{ value, head };
        head = newNode;
    }

    void addBack(string value) {
        Node* newNode = new Node{ value, nullptr };
        if (!head) {
            head = newNode;
            return;
        }
        Node* temp = head;
        while (temp->next) {
            temp = temp->next;
        }
        temp->next = newNode;
    }

    void removeFront() {
        if (!head) throw runtime_error("Список порожній");
        Node* temp = head;
        head = head->next;
        delete temp;
    }

    void removeBack() {
        if (!head) {
            throw runtime_error("Список порожній");
        }
        if (!head->next) {
            delete head;
            head = nullptr;
            return;
        }
        Node* temp = head;
        while (temp->next->next) {
            temp = temp->next;
        }
        delete temp->next;
        temp->next = nullptr;
    }

    void removeByValue(string value) {
        if (!head) {
            throw runtime_error("Список порожній");
        }
        if (head->data == value) {
            removeFront();
            return;
        }
        Node* temp = head;
        while (temp->next && temp->next->data != value) {
            temp = temp->next;
        }
        if (!temp->next) {
            throw runtime_error("Елемент не знайдено");
        }
        Node* del = temp->next;
        temp->next = del->next;
        delete del;
    }

    void print() {
        Node* temp = head;
        cout << "\nСписок:\n";
        while (temp) {
            cout << temp->data << " -> ";
            temp = temp->next;
        }
        cout << "NULL\n";
    }
    void clear() {
        while (head) removeFront();
    }
};

struct DNode {
    string data;
    DNode* next;
    DNode* prev;
};

class DoublList {
private:
    DNode* head;
    DNode* tail;
public:
    DoublList() : head(nullptr), tail(nullptr) {}

    void add(string value) {
        DNode* newNode = new DNode{ value, nullptr, tail };
        if (!head) {
            head = tail = newNode;
        }
        else {
            tail->next = newNode;
            tail = newNode;
        }
    }

    void printForward() {
        DNode* temp = head;
        cout << "\nВперед:\n";
        while (temp) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }

    void printBackward() {
        DNode* temp = tail;
        cout << "\nНазад:\n";
        while (temp) {
            cout << temp->data << " ";
            temp = temp->prev;
        }
        cout << endl;
    }

    void remove(string value) {
        DNode* temp = head;
        while (temp && temp->data != value) {
            temp = temp->next;
        }
        if (!temp) {
            throw runtime_error("Не знайдено");
        }
        if (temp->prev) {
            temp->prev->next = temp->next;
        }
        else {
            head = temp->next;
        }
        if (temp->next) {
            temp->next->prev = temp->prev;
        }
        else {
            tail = temp->prev;
        }
        delete temp;
    }
    void clear() {
        while (head) {
            DNode* temp = head;
            head = head->next;
            delete temp;
        }
        tail = nullptr;
    }
};

int main() {
    SinglList list;
    DoublList dlist;
    while (true) {
        try {
            int choice;
            cout << "\n1.Додати (в кінець)\n2.Видалити\n3.Вивести\n4.Двозв'язний список\n0.Вихід\n>";
            cin >> choice;
            if (cin.fail()) {
                throw invalid_argument("Помилка вводу");
            }
            if (choice == 0) {
                break;
            }
            if (choice == 1) {
                string text;
                int shift;
                cout << "Введіть текст: ";
                cin.ignore();
                getline(cin, text);
                cout << "Зсув: ";
                cin >> shift;
                string enc = cesarEncrypt(text, shift);
                list.addBack(enc);
                dlist.add(enc);
            }
            else if (choice == 2) {
                string text;
                cout << "Що видалити: ";
                cin.ignore();
                getline(cin, text);
                list.removeByValue(text);
                dlist.remove(text);
            }
            else if (choice == 3) {
                list.print();
            }
            else if (choice == 4) {
                dlist.printForward();
                dlist.printBackward();
            }
            else {
                throw invalid_argument("Невірний вибір");
            }
        }
        catch (exception& e) {
            cout << "\033[31mПомилка: " << e.what() << "\033[0m\n";
            cin.clear();
            cin.ignore(10000, '\n');
        }
    }
    return 0;
}