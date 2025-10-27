#include <iostream>

using namespace std;

void input() {
	double S, a, P;
	while (true) {
		cout << "Введіть значення площі квадрата: ";
		cin >> S;
		if (S < 0) {
			cout << "Площа не може бути від'ємною\n";
			continue;
		}
		else {
			a = sqrt(S);
			P = 4 * a;
			cout << "Сторона квадрата = " << a << "\n";
			cout << "Периметр квадрата = " << P << "\n";
		}
		cout << "\n\nБажаєте завершити виконання програми?\n1 - Так, 0 - Ні\n";
		int n;
		cin >> n;
		if (n == 1) {
			exit(0);
		}
	}
}

int main() {
	input();
}