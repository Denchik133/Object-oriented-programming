#include <iostream>
#include <list>
#include <vector>
#include <cmath>

using namespace std;

class NumberEncryption {
private:
    list<double> data;
    vector<char> encryptedData;
public:
    void inpupData(int n) {
        double x;
        for (int i = 0; i < n; i++) {
            cin >> x;
            data.push_back(x);
        }
    }

    bool checkForMinusThree() const {
        for (auto it = data.begin(); it != data.end(); ++it) {
            if (*it < -3) {
                return true;
            }
        }
        return false;
    }

    void transform() {
        if (checkForMinusThree()) {
            for (auto it = data.begin(); it != data.end(); ++it) {
                if (*it < 0) {
                    *it = (*it) * (*it);
                }
            }
        }
        else {
            for (auto it = data.begin(); it != data.end(); ++it) {
                *it *= 0.1;
            }
        }
    }

    void printReverse() const {
        for (auto it = data.rbegin(); it != data.rend(); ++it) {
            cout << *it << " ";
        }
    }
    
    void encrypt() {
        encryptedData.clear();
        for (auto it = data.begin(); it != data.end(); ++it) {
            int integerPart = static_cast<int>(floor(*it));
            if (integerPart % 2 == 0) {
                encryptedData.push_back('E');
            }
            else {
                encryptedData.push_back('O');
            }
        }
    }

    void printEncryptedData() const {
        for (char c : encryptedData) {
            cout << c << " ";
        }
    }
};

int main() {
    int n;
    NumberEncryption enc;
    cout << "Введіть кількість елементів списку: ";
    cin >> n;
    if (n <= 0) {
        cout << "Кількість елементів повинна бути додатньою.";
        return 1;
    }
    cout << "Введіть елементи списку: ";
    enc.inpupData(n);
    enc.transform();
    cout << "Результат у зворотньому порядку: ";
    enc.printReverse();
    enc.encrypt();
    cout << "\nЗашифровані дані: ";
    enc.printEncryptedData();
    return 0;
}
