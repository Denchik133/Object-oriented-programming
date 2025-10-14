#include <iostream>

using namespace std;

const int players = 4;
const int games = 3;

typedef struct {
	char* name;
	double results[games];
	int total;
	int wins;
 }shahist;

void calculateResults(shahist &s) {
	s.total = 0;
	s.wins = 0;
	for (int i = 0; i < games; i++) {
		s.total += s.results[i];
		if (s.results[i] == 1) {
			s.wins++;
		}
	}
}

void inputData(shahist array[]) {
	for (int i = 0; i < players; i++) {
		printf("\nВведіть прізвище гравця %d: ", i + 1);
		scanf_s("%s", array[i].name, 50);
		for (int j = 0; j < games; j++) {
			printf("Введіть результати гри %d (1 - перемога, -1 - нічия, 0 - поразка): ", j + 1);
			scanf_s("%lf", &array[i].results[j]);
			if (array[i].results[j] > 1 || array[i].results[j] < -1) {
				printf("Введено некоректний результат\n");
			}
		}
		calculateResults(array[i]);
	}
}

void writeResults(const char* filename, shahist array[]) {
	FILE* pointer = nullptr;
	if (fopen_s(&pointer, filename, "wb") != 0 || pointer == NULL) {
		printf("Проблема з відкриттям файлу");
		exit(1);
	}
	fwrite(array, sizeof(shahist), players, pointer);
	fclose(pointer);
}

void readResults(const char* filename, shahist array[]) {
    FILE* pointer = nullptr;
    if (fopen_s(&pointer, filename, "rb") != 0 || pointer == NULL) {
		printf("Проблема з відкриттям файлу");
		exit(1);
    }
    fread(array, sizeof(shahist), players, pointer);
    fclose(pointer);
}

void sortByTotal(shahist array[]) {
	for (int i = 0; i < players - 1; i++) {
		for (int j = 0; j < players - 1 - i; j++) {
			if (array[j].total < array[j + 1].total) {
				shahist tmp = array[j];
				array[j] = array[j + 1];
				array[j + 1] = tmp;
			}
		}
	}
}

void printWinners(shahist array[]) {
	printf("\n-----------------------------------------\n");
	printf("|	     Призові місця		|\n");
	printf("-----------------------------------------\n");
	int count = 3;
	if (count > players) {
		count = players;
	}
	for (int i = 0; i < count; i++) {
		printf("%d місце: %s\nКількість перемог %d\nЗагальний бал %d\n\n",
			i + 1, array[i].name, array[i].wins, array[i].total);
	}
}

/*void cesar(const char* inputfile, const char* outputfile, unsigned char key) {
	FILE* pointer = nullptr;
	if (fopen_s(&pointer, inputfile, "rb") != 0 || pointer == NULL) {
		printf("Проблема з відкриттям файлу");
		exit(1);
	}
	FILE* pointer1 = nullptr;
	if (fopen_s(&pointer1, outputfile, "wb") != 0 || pointer1 == NULL) {
		printf("Проблема з відкриттям файлу");
		exit(1);
	}
	const size_t bufferSize = 4096;
	unsigned char array[bufferSize];
	size_t n = 0;
	while (n = fread(array, 1, bufferSize, pointer) > 0) {
		for (int i = 0; i < n; i++) {
			array[i] += key;
		}
		if (fwrite(array, 1, n, pointer1) != n) {
			printf("Помилка");
			fclose(pointer);
			fclose(pointer1);
			exit(1);
		}
		fclose(pointer);
		fclose(pointer1);
	}
}

void cesarOut(const char* inputfile, const char* outputfile, unsigned char key) {
	cesar(inputfile, outputfile, 256 - key);
}*/

int main() {
	shahist array[players];
	for (int i = 0; i < players; i++) {
		array[i].name = new char[50];
	}
	inputData(array);
	writeResults("Tournament.dat", array);
	shahist array2[players];
	/*cesar("Tournament.dat", "Tournament.enc", 10);
	cesarOut("Tournament.enc", "Results.dat", 10);*/
	readResults("Tournament.dat", array2);
	sortByTotal(array2);
	printf("\n -----------------------------------------------\n");
	printf("| %15s |  %16s | %15s |\n", "Прізвище", "Кількість перемог", "Загальний бал");
	printf(" -----------------------------------------------\n");
	for (int i = 0; i < players; i++) {
		printf("| %7s  | %9d\t\t| %8d\t|\n", array2[i].name, array2[i].wins, array2[i].total);
	}
	printf(" -----------------------------------------------\n");
	printWinners(array2);
	for (int i = 0; i < players; i++) {
    delete[] array[i].name;
}
	return 0;
}