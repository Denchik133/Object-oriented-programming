#include <iostream>
#include <fstream>
#include <iomanip>
#include <vector>
#include <stdexcept>

using namespace std;

class Function {
private:
    double* x;
    double* y;
    int size;
public:
    Function() : x(nullptr), y(nullptr), size(0) {}
    ~Function() {
        try {
            delete[] x;
            delete[] y;
        }
        catch (...) {
            cout << "Помилка в деструкторі\n";
        }
    }

    Function(double* xArray, double* yArray, int n) {
        size = n;
        x = new double[n];
        y = new double[n];
        for (int i = 0; i < n; i++) {
            x[i] = xArray[i];
            y[i] = yArray[i];
        }
    }

    friend istream& operator>>(istream& in, Function& f) {
        vector<double> tx, ty;
        double a, b, c;
        while (in >> a >> b >> c) {
            tx.push_back(a);
            ty.push_back(b);
        }
        f.size = tx.size();
        f.x = new double[f.size];
        f.y = new double[f.size];
        for (int i = 0; i < f.size; i++) {
            f.x[i] = tx[i];
            f.y[i] = ty[i];
        }
        return in;
    }

    friend ostream& operator<<(ostream& out, Function& f) {
        out << "\nГрафік (ASCII):\n";
        for (int i = 0; i < f.size; i++) {
            out << setw(5) << f.x[i] << " | ";
            int stars = (int)f.y[i];
            for (int j = 0; j < stars; j++) {
                out << "*";
            }
            out << "\n";
        }
        return out;
    }

    double getX(int i) { return x[i]; }
    double getY(int i) { return y[i]; }
    int getSize() { return size; }
    void setY(double* newY) {
        for (int i = 0; i < size; i++) {
            y[i] = newY[i];
        }
    }
    double* getYArray() { return y; }
};

void findMinMax(Function& f) {
    double minVal = f.getY(0);
    double maxVal = f.getY(0);
    for (int i = 1; i < f.getSize(); i++) {
        if (f.getY(i) < minVal) {
            minVal = f.getY(i);
        }
        if (f.getY(i) > maxVal) {
            maxVal = f.getY(i);
        }
    }
    cout << "\nMin = " << minVal << " Max = " << maxVal << "\n";
}

void writeFormatted(const string& input, const string& output) {
    ifstream in(input);
    ofstream out(output);
    if (!in || !out) {
        throw runtime_error("Помилка роботи з файлами");
    }
    double a, b, c;
    while (in >> a >> b >> c) {
        out << setw(10) << fixed << setprecision(3) << showpos << a << "\t" << setw(10) << fixed << setprecision(3) << showpos << b << "\t" << setw(10) << fixed << setprecision(3) << showpos << c << "\n";
    }
}

int main() {
    try {
        ifstream file("input.txt");
        if (!file) {
            throw runtime_error("Файл не відкрито");
        }
        vector<double> x, y1, y2;
        double a, b, c;
        while (file >> a >> b >> c) {
            x.push_back(a);
            y1.push_back(b);
            y2.push_back(c);
        }
        int n = x.size();
        double* arrayX = new double[n];
        double* arrayY1 = new double[n];
        double* arrayY2 = new double[n];
        for (int i = 0; i < n; i++) {
            arrayX[i] = x[i];
            arrayY1[i] = y1[i];
            arrayY2[i] = y2[i];
        }
        Function f1(arrayX, arrayY1, n);
        Function f2(arrayX, arrayY2, n);
        cout << "\nФункція 1:";
        cout << f1;
        cout << "\nФункція 2:";
        cout << f2;
        findMinMax(f1);
        findMinMax(f2);
        writeFormatted("input.txt", "output.txt");
        cout << "\nДані записано у output.txt\n";
        delete[] arrayX;
        delete[] arrayY1;
        delete[] arrayY2;
    }
    catch (exception& e) {
        cout << "Помилка: " << e.what() << endl;
    }
    return 0;
}