#include <iostream>
#include <fstream>

using namespace std;

string encrypt(string original) {
	string result = original;
	for (char& c : result) {
		c = c + 3;
	}
	return result;
}

string encrypt(string original, int shift) {
	string result = original;
	for (char& c : result) {
		c = c + shift;
	}
	return result;
}

void encrypt(istream& in, ostream& out, int shift) {
	int c;
	while ((c = in.get()) != EOF) {
		out.put(c + shift);
	}
}

void encrypt(istream& in, ostream& out) {
	int c;
	while ((c = in.get()) != EOF) {
		out.put(c + 3);
	}
}

bool encryptFile(const string& inputFile, const string& outputFile, int shift) {
	ifstream fin(inputFile);
	if (!fin) {
		cout << "Помилка роботи з вхідним файлом";
		return false;
	}
	ofstream fout(outputFile);
	if (!fout) {
		cout << "Помилка роботи з вихідним файлом";
		return false;
	}
	encrypt(fin, fout, shift);
	return true;
}

bool encryptFile(const string& inputFile, const string& outputFile) {
	ifstream fin(inputFile);
	if (!fin) {
		cout << "Помилка роботи з вхідним файлом";
		return false;
	}
	ofstream fout(outputFile);
	if (!fout) {
		cout << "Помилка роботи з вихідним файлом";
		return false;
	}
	encrypt(fin, fout);
	return true;
}

int main() {
	string inputFile = "input.txt";
	string outputFile = "output.txt";
	int shift;
	cout << "Введіть зсув для шифрування: ";
	cin >> shift;
	if (shift <= 0) {
		cout << "Помилка: зсув повинен бути додатним числом\n";
		return 1;
	}
	else if (encryptFile(inputFile, outputFile, shift)) {
		cout << "Файл успішно зашифровано зі зсувом " << shift << "\n";
	}
	else {
		cout << "Помилка під час шифрування\n";
	}
}
