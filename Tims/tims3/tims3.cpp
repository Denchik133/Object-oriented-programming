#include <iostream>
#include <stdexcept>

using namespace std;

int main()
{
    while (true)
    {
        try
        {
            double R;
            cout << "Введіть радіус круга: ";
            cin >> R;
            bool validInput = !cin.fail() && R > 0;
            if (!validInput) {
                throw invalid_argument("Некоректний ввід або радіус <= 0.");
            }
            double circleArea = 3.14 * R * R;
            double side = (2 * R) / sqrt(2);
            double squareArea = side * side;
            double probability = squareArea / circleArea;
            cout << "Ймовірність попадання точки у квадрат = " << probability << "\n";
            break;
        }
        catch (const exception& e)
        {
            cout << "\033[31mПомилка: " << e.what() << "\033[0m\n";
            cin.clear();
            cin.ignore(10000, '\n');
        }
    }
    return 0;
}