#include <iostream>

using namespace std;

class Point3D {
	double x, y, z;
public:
	Point3D() : x(0), y(0), z(0) {}
	~Point3D() {
		printf("\n");
		printf("Точка з координатами %.2f, %.2f, %.2f видалено\n", x, y, z);
	}
	Point3D(double x, double y, double z) : x(x), y(y), z(z) {}
	Point3D operator+(Point3D& otherPoint) {
		return Point3D(this->x + otherPoint.x, this->y + otherPoint.y, this->z + otherPoint.z);
	}
	Point3D operator-(Point3D& otherPoint) {
		return Point3D(this->x - otherPoint.x, this->y - otherPoint.y, this->z - otherPoint.z);
	}
	void print() {
		printf("\nТочка з координатами %.2f, %.2f, %.2f", x, y, z);
	}
	void input() {
		printf("Введіть координати через пробіл (x y z): ");
		scanf_s("%lf %lf %lf", &x, &y, &z);
	}
	void printPolar() {
		double r = sqrt(x * x + y * y + z * z);
		double phi = atan2(y, x);
		double teta;
		if (r != 0)
			teta = acos(z / r);
		else
			teta = 0;
		double phi_deg = phi * 180.0 / 3.14;
		double teta_deg = teta * 180.0 / 3.14;

		printf("\nПолярні координати:");
		printf("\n r = %.2f", r);
		printf("\n φ (азимут): %.4f рад = %.2f°", phi, phi_deg);
		printf("\n θ (полярний): %.4f рад = %.2f°\n", teta, teta_deg);
	}
};

int main() {
	Point3D t1, t2;
	t1.input();
	t2.input();
	t1.print();
	t2.print();
	Point3D t3 = t1 + t2;
	printf("\n\nРезультат додавання:");
	t3.print();
	Point3D t4 = t1 - t2;
	printf("\n\nРезультат віднімання:");
	t4.print();
	printf("\n");
	printf("\n\nПолярні координати для результату віднімання:");
	t4.printPolar();
	return 0;
}