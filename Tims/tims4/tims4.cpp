#include <iostream>
#include <cmath>

using namespace std;

int main() {
    const int faces = 6;
    while(true) {
        try {
            int dice;
            int choice;
            cout << "Введіть кількість кубиків: ";
            cin >> dice;
            cout << "\nОберіть подію:\n";
            cout << "1 - На всіх кубиках випало 5\n";
            cout << "2 - На всіх кубиках однакова кількість очок\n";
            cout << "Ваш вибір: ";
            cin >> choice;
            bool validInput = !cin.fail() && dice > 0 && (choice == 1 || choice == 2);
            if(!validInput) {
                throw invalid_argument("Некоректні дані.");
            }
            double totalOutcomes = pow(faces, dice);
            double probability = 0;
            if(choice == 1) {
                probability = 1.0 / totalOutcomes;
            }
            else {
                probability = faces / totalOutcomes;
            }
            cout << "\nЙмовірність = " << probability << "\n";
            break;
        }
        catch(const exception& e) {
            cout << "\033[31mПомилка: " << e.what() << "\033[0m\n";
            cin.clear();
            cin.ignore(10000,'\n');
        }
    }
    return 0;
}