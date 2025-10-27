#include <iostream>

using namespace std;

void input() {
	double a, b, c, P;
	while(true) {
		cout << "\nВведіть перший катет а: ";
		cin >> a;
		cout << "Введіть другий катет b: ";
		cin >> b;
		if (a <= 0 || b <= 0) {
			cout << "\nВведено від'ємне значення для катета(-ів)";
			continue;
		}
		c = sqrt(a * a + b * b);
		cout << "Гіпотенуза трикутника = " << c;
		if (a + b > c && a + c > b && b + c > a) {
			cout << "\n\nТакий трикутник може існувати";
		}
		P = a + b + c;
		cout << "\n\nПериметр трикутника = " << P;
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