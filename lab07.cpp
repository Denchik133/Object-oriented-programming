#include <iostream>
#include <vector>

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
	double getX() {
		return x;
	}
	double getY() {
		return y;
	}
	double getZ() {
		return z;
	}
};

class Cube : public Shape {
	double a;
public:
	Cube() : a(1) {}
	Cube(double x, double y, double z, double a) : Shape(x, y, z), a(a) {}
	void edit(istream& is = cin, ostream& os = cout) {
		os << "\nПоточні координати: " << x << ", " << y << ", " << z << ", Довжина ребра а = " << a << "\n";
		os << "Введіть нове значення для х: ";
		is >> x;
		os << "Введіть нове значення для y: ";
		is >> y;
		os << "Введіть нове значення для z: ";
		is >> z;
		os << "Введіть нове значення для a: ";
		is >> a;
	}
	void print(ostream& os = cout, int index = 0) const {
		os << "Куб. Поточні координати: " << x << ", " << y << ", " << z << ", Довжина ребра а = " << a << "\n";
		os << "Індекс фігури: " << index;
	}
};

class Tetrahedron : public Shape {
	double a;
public:
	Tetrahedron() : a(1) {}
	Tetrahedron(double x, double y, double z, double a) : Shape(x, y, z), a(a) {}
	void edit(istream& is = cin, ostream& os = cout) {
		os << "\nПоточні координати: " << x << ", " << y << ", " << z << ", Довжина ребра а = " << a  << "\n";
		os << "Введіть нове значення для х: ";
		is >> x;
		os << "Введіть нове значення для y: ";
		is >> y;
		os << "Введіть нове значення для z: ";
		is >> z;
		os << "Введіть нове значення для a: ";
		is >> a;
	}
	void print(ostream& os = cout, int index = 0) const {
		os << "Тетраедр. Поточні координати: " << x << ", " << y << ", " << z << ", Довжина ребра а = " << a << "\n";
		os << "Індекс фігури: " << index;
	}
};

class Sphere : public Shape {
	double r;
public:
	Sphere() : r(1) {}
	Sphere(double x, double y, double z, double r) : Shape(x, y, z), r(r) {}
	void edit(istream& is = cin, ostream& os = cout) {
		os << "\nПоточні координати: " << x << ", " << y << ", " << z << ", Радіус кола = " << r << "\n";
		os << "Введіть нове значення для х: ";
		is >> x;
		os << "Введіть нове значення для y: ";
		is >> y;
		os << "Введіть нове значення для z: ";
		is >> z;
		os << "Введіть нове значення для радіуса: ";
		is >> r;
	}
	void print(ostream& os = cout, int index = 0) const {
		os << "Куля. Поточні координати: " << x << ", " << y << ", " << z << ", Радіус кола = " << r << "\n";
		os << "Індекс фігури: " << index;
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

double askDouble(string textPrompt) {
	while (true) {
		cout << textPrompt;
		double userChoice;
		if (cin >> userChoice) {
			return userChoice;
		}
		cout << "Введено некоректне значенняn\n";
	}
}

int main() {
	vector <unique_ptr<Shape>> items;
	while (true) {
		cout << "\n1 - Додати фігуру\n";
		cout << "2 - Вивести всі фігури\n";
		cout << "3 - Пошук\n";
		cout << "4 - Редагувати\n";
		cout << "5 - Видалити фігуру\n";
		cout << "6 - Вихід\n";
		int cmd = askInt("Зробіть свій вибір: ", 1, 6);
		if (cmd == 1) {
			cout << "\nОберіть фігуру, яку потрібно додати:\n";
			cout << "1 - Куб\n";
			cout << "2 - Тетраедр\n";
			cout << "3 - Куля\n";
			cmd = askInt("Зробіть свій вибір: ", 1, 3);
			double x = askDouble("Введіть координату х: ");
			double y = askDouble("Введіть координату y: ");
			double z = askDouble("Введіть координату z: ");
			if (cmd == 1) {
				double a = askDouble("Введіть ребро куба: ");
				items.push_back(make_unique<Cube>(x, y, z, a));
			}
			else if (cmd == 2) {
				double a = askDouble("Введіть ребро тетраедра: ");
				items.push_back(make_unique<Tetrahedron>(x, y, z, a));
			}
			else if (cmd == 3) {
				double r = askDouble("Введіть радіус кулі: ");
				items.push_back(make_unique<Sphere>(x, y, z, r));
			}
		}
		else if (cmd == 2) {
			if (items.empty()) {
				cout << "Елементи не додано до колекції\n";
				continue;
			}
			for (int i = 0; i < items.size(); i++) {
				items[i]->print();
			}
		}
		else if (cmd == 3) {
			cout << "Пошук за точними координатами\n";
			double x = askDouble("Введіть х: ");
			double y = askDouble("Введіть y: ");
			double z = askDouble("Введіть z: ");
			vector<int> found;
			for (int i = 0; i < items.size(); i++) {
				if (items[i]->getX() == x && items[i]->getY() == y && items[i]->getZ() == z) {
					found.push_back(i);
				}
			}
			if (found.empty()) {
				cout << "Нічого не було знайдено за цими координатами";
				continue;
			}
			cout << "Знайдено: ";
			for (int i = 0; i < found.size(); i++) {
				int index = found[i];
				items[index]->print();
			}
		}
		else if (cmd == 4) {
			if (!items.empty()) {
				cout << "0 - " << items.size() - 1;
				int index = askInt("Введіть індекс фігури, яку потрібно відредагувати: ", 0, items.size() - 1);
				items[index]->edit();
				continue;
			}
			cout << "\nСпочатку додайте фігуру!";
		}
		else if (cmd == 5) {
			if (!items.empty()) {
				cout << "0 - " << items.size() - 1;
				int index = askInt("Введіть індекс фігури, яку потрібно видалити: ", 0, items.size() - 1);
				items.erase(items.begin()+index);
			}
			cout << "\nСпочатку додайте фігуру!";
		}
		else if (cmd == 6) {
			cout << "Вихід з програми";
			exit(1);
		}
	}
}
