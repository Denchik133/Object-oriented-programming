#include <iostream>

using namespace std;

class complexNumber {
	double real, imaginary;
public:
	complexNumber(double real = 0, double imaginary = 0) : real(real), imaginary(imaginary) {}
	complexNumber operator+(complexNumber& otherNumber) {
		return complexNumber(real + otherNumber.real, imaginary + otherNumber.imaginary);
	}
	complexNumber operator*(complexNumber& otherNumber) {
		return complexNumber(real * otherNumber.real - imaginary * otherNumber.imaginary, 
			real * otherNumber.imaginary + otherNumber.real * imaginary);
	}
	complexNumber operator-(complexNumber& otherNumber) {
		return complexNumber(real - otherNumber.real, imaginary - otherNumber.imaginary);
	}
	complexNumber conjugated() {
		return complexNumber(real, -imaginary);
	}
	complexNumber operator/(complexNumber& otherNumber) {
		return complexNumber((real * otherNumber.real + imaginary * otherNumber.imaginary) / 
			(otherNumber.real * otherNumber.real + otherNumber.imaginary * otherNumber.imaginary));
	}
	complexNumber pol(double n) {
		double r = sqrt(real * real + imaginary * imaginary);
		double phi = atan2(imaginary, real);
		if (r == 0) {
			if (n > 0) {
				return complexNumber(0, 0);
			}
			else { throw domain_error("0 в степені n не визначено для n <= 0"); }
		}
		double newR = pow(r, n);
		double newPhi = phi * n;
		return complexNumber(newR * cos(newPhi), newR * sin(newPhi));
	}
	pair <complexNumber, complexNumber> complexSqrt() {
		double r = sqrt(real * real + imaginary * imaginary);
		double phi = atan2(imaginary, real);
		double newR = sqrt(r);
		double newPhi = phi / 2;
		complexNumber s(newR * cos(newPhi), newR * sin(newPhi));
		return { s, complexNumber(s.real * -1, s.imaginary * -1) };
	}
};

int main() {

}