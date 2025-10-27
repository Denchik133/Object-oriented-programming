#include <iostream>

using namespace std;

void input() {
	double R, r, S;
	while (true) {
		cout << "Введіть значення зовнішнього радіуса кола R: ";
		cin >> R;
		if (R <= 0) {
			cout << "Введено від'ємний радіус";
			continue;
		}
		cout << "Введіть значення внутрішнього радіуса кола r: ";
		cin >> r;
		if (R < r || r <= 0) {
			cout << "Радіус зовнішнього кола R не може бути менше, ніж внутрішнього кола r, або введено від'ємний радіус\n";
			continue;
		}
		else {
			S = 3.14 * (R * R - r * r);
			cout << "Площа кільця = " << S;
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
