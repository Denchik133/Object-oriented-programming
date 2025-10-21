#include <iostream>
#include <string>

using namespace std;

class Consumer {
    string surname;
    string name;
    string middlename;
    string address;
    long long creditCardNumber;
    long long bankAccountNumber;

public:
    Consumer(long long creditCardNumber = 0, long long bankAccountNumber = 0) : 
        creditCardNumber(creditCardNumber), bankAccountNumber(bankAccountNumber) {}

    Consumer(string s, string n, string m, string a, long long card, long long acc) : 
        surname(s), name(n), middlename(m), address(a), creditCardNumber(card), bankAccountNumber(acc) {}

    void setSurname(const string& s) { surname = s; }
    void setName(const string& n) { name = n; }
    void setMiddlename(const string& m) { middlename = m; }
    void setAddress(const string& a) { address = a; }
    void setCreditCardNumber(long long card) { creditCardNumber = card; }
    void setBankAccountNumber(long long acc) { bankAccountNumber = acc; }

    string getSurname() const { return surname; }
    string getName() const { return name; }
    string getMiddlename() const { return middlename; }
    string getAddress() const { return address; }
    long long getCreditCardNumber() const { return creditCardNumber; }
    long long getBankAccountNumber() const { return bankAccountNumber; }

    void print() const {
        printf("Прізвище: %s\nІм'я: %s\nПо батькові: %s\nАдреса: %s\nНомер кредитної картки: %lld\nНомер банківського рахунку: %lld\n", 
            surname.c_str(), name.c_str(), middlename.c_str(), address.c_str(), creditCardNumber, bankAccountNumber);
        printf("---------------------------------------------\n");
    }

    int compare(const Consumer& other) const {
        if (surname != other.surname) {
            if (surname > other.surname) { return 1; }
            else { return -1; }
        }
        if (name != other.name) {
            if (name > other.name) { return 1; }
            else { return -1; }
        }
        if (middlename != other.middlename) {
            if (middlename > other.middlename) { return 1; }
            else { return -1; }
        }
        return 0;
    }

    static void bubbleSort(Consumer arr[], int n) {
        for (int i = 0; i < n - 1; i++) {
            for (int j = 0; j < n - i - 1; j++) {
                if (arr[j].compare(arr[j + 1]) > 0) {
                    Consumer temp = arr[j];
                    arr[j] = arr[j + 1];
                    arr[j + 1] = temp;
                }
            }
        }
    }
};

int main() {
    int n;
    printf("Введіть кількість покупців: ");
    scanf_s("%d", &n);
    Consumer* consumers = new Consumer[n];
    for (int i = 0; i < n; i++) {
        string s, nm, m, a;
        long long card, acc;
        printf("\nПокупець №%d\n", i + 1);
        printf("Прізвище: ");
        getline(cin>>ws, s);
        printf("Ім'я: ");
        getline(cin, nm);
        printf("По батькові: ");
        getline(cin, m);
        printf("Адреса: ");
        getline(cin, a);
        printf("Номер кредитної картки: ");
        scanf_s("%lld", &card);
        printf("Номер банківського рахунку: ");
        scanf_s("%lld", &acc);
        consumers[i] = Consumer(s, nm, m, a, card, acc);
    }
    Consumer::bubbleSort(consumers, n);
    printf("\n--- Список покупців в алфавітному порядку ---\n");
    for (int i = 0; i < n; i++) {
        consumers[i].print();
    }
    long long low, high;
    printf("\nВведіть нижню межу номера картки: ");
    scanf_s("%lld", &low);
    printf("Введіть верхню межу номера картки: ");
    scanf_s("%lld", &high);

    if (low > high) {
        long long t = low;
        low = high;
        high = t;
    }

    printf("\n--- Покупці з номером картки у діапазоні [%lld, %lld] ---\n", low, high);
    bool found = false;

    for (int i = 0; i < n; i++) {
        long long card = consumers[i].getCreditCardNumber();
        if (card >= low && card <= high) {
            consumers[i].print();
            found = true;
        }
    }

    if (!found)
        printf("Немає покупців у цьому діапазоні.\n");

    delete[] consumers;
    return 0;
}
