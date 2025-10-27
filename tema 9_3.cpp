#include <iostream>

using namespace std;

bool verifyN(int n) {
	if (n < 0) {
		n = -n;
	}
	return n >= 10 && n <= 99;
}

void input() {
	int n, a, b, sum, production;
	while (true) {
		cout << "Введіть двоцифрове число: ";
		if (cin >> n && verifyN(n)) {
			a = n / 10;
			b = n % 10;
			sum = a + b;
			production = a * b;
			cout << "Кількість десятків = " << a << "\n";
			cout << "Кількість одиниць = " << b << "\n";
			cout << "Сума цифр = " << sum << "\n";
			cout << "Доубток цифр = " << production << "\n";
		}
		else {
			cout << "Помилка виконання програми\n";
			continue;
		}
		cout << "\n\nБажаєте завершити виконання програми?\n1 - Так, 0 - Ні\n";
		int x;
		cin >> x;
		if (x == 1) {
			exit(0);
		}
	}
}

int main() {
	input();
}