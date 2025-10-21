#include <iostream>

using namespace std;

class complexNumber {
	double real, imaginary;
public:
	complexNumber(double real = 0, double imaginary = 0) : real(real), imaginary(imaginary) {}
	complexNumber operator+(complexNumber& otherNumber) {
		return complexNumber(real + otherNumber.real, imaginary + otherNumber.imaginary);
	}
	complexNumber operator*(complexNumber& otherNumber) {
		return complexNumber(real * otherNumber.real - imaginary * otherNumber.imaginary, 
			real * otherNumber.imaginary + otherNumber.real * imaginary);
	}
	complexNumber operator-(complexNumber& otherNumber) {
		return complexNumber(real - otherNumber.real, imaginary - otherNumber.imaginary);
	}
	complexNumber conjugated() {
		return complexNumber(real, -imaginary);
	}
	complexNumber operator/(complexNumber& otherNumber) {
		return complexNumber((real * otherNumber.real + imaginary * otherNumber.imaginary) / 
			(otherNumber.real * otherNumber.real + otherNumber.imaginary * otherNumber.imaginary));
	}
	complexNumber pol(double n) {
		double r = sqrt(real * real + imaginary * imaginary);
		double phi = atan2(imaginary, real);
		if (r == 0) {
			if (n > 0) {
				return complexNumber(0, 0);
			}
			else { throw domain_error("0 в степені n не визначено для n <= 0"); }
		}
		double newR = pow(r, n);
		double newPhi = phi * n;
		return complexNumber(newR * cos(newPhi), newR * sin(newPhi));
	}
	pair <complexNumber, complexNumber> complexSqrt() {
		double r = sqrt(real * real + imaginary * imaginary);
		double phi = atan2(imaginary, real);
		double newR = sqrt(r);
		double newPhi = phi / 2;
		complexNumber s(newR * cos(newPhi), newR * sin(newPhi));
		return { s, complexNumber(s.real * -1, s.imaginary * -1) };
	}
    void input(string label = "") {
        cout << label;
        cout << "Введіть дійсну частину: ";
        cin >> real;
        cout << "Введіть уявну частину: ";
        cin >> imaginary;
    }
    void print(string label = "") const {
        cout << label;
        if (imaginary >= 0)
            cout << real << " + " << imaginary << "i";
        else
            cout << real << " - " << -imaginary << "i";
        cout << endl;
    }
};

int main() {
    complexNumber a, b;
    cout << "===== Введення комплексних чисел =====";
    a.input("Перше число (a):");
    b.input("\nДруге число (b):");

    cout << "\n===== Результати обчислень =====";
    a.print("a = ");
    b.print("b = ");

    cout << "\n--- Додавання ---";
    (a + b).print("a + b = ");

    cout << "\n--- Віднімання ---";
    (a - b).print("a - b = ");

    cout << "\n--- Множення ---";
    (a * b).print("a * b = ");

    cout << "\n--- Ділення ---";
    (a / b).print("a / b = ");

    cout << "\n--- Комплексне спряження ---";
    a.conjugated().print("a = ");

    double n;
    cout << "\nВведіть степінь, у яку піднести a: ";
    cin >> n;
    cout << endl;
    try {
        a.pol(n).print("a^n = ");
    }
    catch (const exception& e) {
        cout << "Помилка: " << e.what() << endl;
    }

    cout << "\n--- Квадратний корінь з a ---" << endl;
    auto roots = a.complexSqrt();
    roots.first.print("√a (1) = ");
    roots.second.print("√a (2) = ");

    cout << "\n============================================" << endl;
    return 0;
}
