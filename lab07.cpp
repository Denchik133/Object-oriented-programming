#include <iostream>

using namespace std;

class Shape {
protected:
	double x, y, z;
public:
	Shape() : x(0), y(0), z(0) {}
	Shape(double x, double y, double z) : x(x), y(y), z(z) {}
	void edit(istream& is = cin, ostream& os = cout) {
		os << "Поточні координати: " << x << ", " << y << ", " << z << "\n";
		os << "Введіть нове значення для х: ";
		is >> x;
		os << "Введіть нове значення для y: ";
		is >> y;
		os << "Введіть нове значення для z: ";
		is >> z;
	}
	void print(ostream& os = cout) const {
		os << "Поточні координати: " << x << ", " << y << ", " << z << "\n";
	}
};

class Cube : public Shape {
	double a;
	Cube() : a(1) {}
	Cube(double x, double y, double z, double a) : Shape(x, y, z), a(a) {}
	void edit(istream& is = cin, ostream& os = cout) {
		os << "Поточні координати: " << x << ", " << y << ", " << z << ", Довжина ребра а = " << a << "\n";
		os << "Введіть нове значення для х: ";
		is >> x;
		os << "Введіть нове значення для y: ";
		is >> y;
		os << "Введіть нове значення для z: ";
		is >> z;
		os << "Введіть нове значення для a: ";
		is >> a;
	}
	void print(ostream& os = cout) const {
		os << "Поточні координати: " << x << ", " << y << ", " << z << ", Довжина ребра а = " << a << "\n";
	}
};

class Tetrahedron : public Shape {
	double a;
	Tetrahedron() : a(1) {}
	Tetrahedron(double x, double y, double z, double a) : Shape(x, y, z), a(a) {}
	void edit(istream& is = cin, ostream& os = cout) {
		os << "Поточні координати: " << x << ", " << y << ", " << z << ", Довжина ребра а = " << a  << "\n";
		os << "Введіть нове значення для х: ";
		is >> x;
		os << "Введіть нове значення для y: ";
		is >> y;
		os << "Введіть нове значення для z: ";
		is >> z;
		os << "Введіть нове значення для a: ";
		is >> a;
	}
	void print(ostream& os = cout) const {
		os << "Поточні координати: " << x << ", " << y << ", " << z << ", Довжина ребра а = " << a << "\n";
	}
};

class Sphere : public Shape {
	double r;
	Sphere() : r(1) {}
	Sphere(double x, double y, double z, double r) : Shape(x, y, z), r(r) {}
	void edit(istream& is = cin, ostream& os = cout) {
		os << "Поточні координати: " << x << ", " << y << ", " << z << ", Радіус кола = " << r << "\n";
		os << "Введіть нове значення для х: ";
		is >> x;
		os << "Введіть нове значення для y: ";
		is >> y;
		os << "Введіть нове значення для z: ";
		is >> z;
		os << "Введіть нове значення для радіуса: ";
		is >> r;
	}
	void print(ostream& os = cout) const {
		os << "Поточні координати: " << x << ", " << y << ", " << z << ", Радіус кола = " << r << "\n";
	}
};

int askInt(string textPrompt, int low, int high) {
	while (true) {
		cout << textPrompt;
		int userChoice;
		if (cin >> userChoice && userChoice >= low && userChoice <= high) {
			return userChoice;
		}
		cout << "Введено некоректне значення";
	}
}

int main() {
	while (true) {
		cout << "1 - Додати фігуру";
		cout << "2 - Вивести всі фігури";
		cout << "3 - Пошук";
		cout << "4 - Редагувати";
		cout << "5 - Видалити фігуру";
		cout << "6 - Вихід";
		int cmd = askInt("Зробіть свій вибір", 1, 6);
		if (cmd == 1) {
			cout << "Оберіть фігуру, яку потрібно додати:";
			cout << "1 - Куб";
			cout << "2 - Тетраедр";
			cout << "3 - Куля";
			int cmd = askInt("Зробіть свій вибір", 1, 3);
		}
		else if (cmd == 2) {
			
		}
		else if (cmd == 3) {

		}
		else if (cmd == 4) {

		}
		else if (cmd == 5) {

		}
		else if (cmd == 6) {
			exit(1);
		}
	}
}
