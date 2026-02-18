#include <iostream>

using namespace std;

bool inputBool(const string& text)
{
    int x;
    while(true)
    {
        cout << text;
        cin >> x;
        if(cin.fail())
        {
            cout << "Помилка! Введіть тільки 0 або 1.\n";
            cin.clear();
            cin.ignore(10000,'\n');
            continue;
        }
        if(x != 0 && x != 1)
        {
            cout << "Допустимі значення тільки 0 або 1.\n";
            continue;
        }

        return x;
    }
}

int main()
{
    bool A1, A2;
    bool B1, B2;
    bool C1, C2, C3;
    cout << "Введіть справність елементів (1 - працює, 0 - ні)\n";
    A1 = inputBool("A1 (транзистор 1): ");
    A2 = inputBool("A2 (транзистор 2): ");
    B1 = inputBool("B1 (конденсатор 1): ");
    B2 = inputBool("B2 (конденсатор 2): ");
    C1 = inputBool("C1 (резистор 1): ");
    C2 = inputBool("C2 (резистор 2): ");
    C3 = inputBool("C3 (резистор 3): ");
    bool D = (A1 || A2) && (B1 && B2) && ((C1 && C2) || (C1 && C3) || (C2 && C3));
    if(D) {
        cout << "\nСхема працездатна.";
    }
    else {
        cout << "\nСхема НЕ працездатна.";
    }
    return 0;
}