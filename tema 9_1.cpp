#include <iostream>

using namespace std;

void input() {
	double R, r, S;
	cout << "Щоб вийти, введіть 0\n";
	while (true) {
		cout << "\nЩоб вийти, введіть 0\n";
		cout << "Введіть значення зовнішнього радіуса кола R: ";
		cin >> R;
		if (R < 0) {
			cout << "Введено від'ємний радіус";
			continue;
		}
		else if (R == 0) {
			exit(0);
		}
		cout << "Введіть значення внутрішнього радіуса кола r: ";
		cin >> r;
		if (R < r || r < 0) {
			cout << "Радіус зовнішнього кола R не може бути менше, ніж внутрішнього кола r, або введено від'ємний радіус\n";
			continue;
		}
		else {
			S = 3.14 * (R * R - r * r);
			cout << "Площа кільця = " << S;
		}
	}
}

int main() {
	input();
}