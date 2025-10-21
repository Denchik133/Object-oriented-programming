#include <iostream>

using namespace std;

const int nameMaxLengths = 40;
const int amountOfGrades = 5;
const int groupNumber = 15;


class Student {
	char name[nameMaxLengths];
	char group[groupNumber];
	int grades[amountOfGrades];
public:
	void input() {
		printf("\nВведіть прізвище: ");
		scanf_s("%s", name, nameMaxLengths);
		printf("Введіть групу: ");
		scanf_s("%s", group, groupNumber);
		printf("Введіть 5 оцінок через пробіл: ");
		for (int i = 0; i < amountOfGrades; i++) {
			scanf_s("%d", &grades[i]);
			if (grades[i] < 1 || grades[i] > 5) {
				printf("Некоректна оцінка! Можливі значення: 1–5\n");
				i--;
			}
		}
	}

	double average() const {
		double sum = 0;
		for (int i = 0; i < amountOfGrades; i++) {
			sum += grades[i];
		}
		return sum / amountOfGrades;
	}

	bool allGood(){
		for (int i = 0; i < amountOfGrades; i++) {
			if (grades[i] < 4) {
				return false;
			}
		}
		return true;
	}

	void print(int index) const {
		printf("| %-3d | %-20s   | %-10s |   %5.2f      |\n", index, name, group, average());
	}

	const char* getName() { return name; }
	const char* getGroup() { return group; }
};

void bubbleSort(Student* array, int n) {
	for (int i = 0; i < n - 1; i++) {
		for (int j = 0; j < n - i - 1; j++) {
			if (array[j].average() > array[j + 1].average()) {
				Student temp = array[j];
				array[j] = array[j + 1];
				array[j + 1] = temp;
			}
		}
	}
}

int main() {
	int n;
	printf("Введіть кількість студентів у групі: ");
	scanf_s("%d", &n);
	Student* array = new Student[n];
	printf("\nВведіть інформацію про студентів:\n");
	for (int i = 0; i < n; i++) {
		printf("\nСтудент № %d", i + 1);
		array[i].input();
	}
	bubbleSort(array, n);
	printf("\n=============================================================\n");
	printf("| №   | Прізвище та ініціали   | Група      | Середній бал |\n");
	printf("-------------------------------------------------------------\n");
	for (int i = 0; i < n; i++)
		array[i].print(i + 1);
	printf("=============================================================\n");

	printf("\nСтуденти, у яких всі оцінки 4 або 5\n");
	bool found = false;
	for (int i = 0; i < n; i++) {
		if (array[i].allGood()) {
			printf("%s — група %s\n", array[i].getName(), array[i].getGroup());
			found = true;
		}
	}
	if (!found)
		printf("Немає студентів, які мають лише оцінки 4 або 5.\n");
	delete[] array;
	return 0;
}