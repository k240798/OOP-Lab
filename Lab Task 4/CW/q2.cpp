#include <iostream>
#include <vector>
#include <stdexcept>
#include <sstream>
using namespace std;

class Polynomial {
private:
    double* coefficients;
    int degree;

    void allocateMemory(int deg) {
        coefficients = new double[deg + 1] {};
    }

    void deallocateMemory() {
        delete[] coefficients;
    }

public:
    Polynomial() : coefficients(nullptr), degree(0) {
        allocateMemory(0);
    }

    Polynomial(int deg, const double* coeffs) : degree(deg) {
        allocateMemory(deg);
        for (int i = 0; i <= degree; ++i) {
            coefficients[i] = coeffs[i];
        }
    }

    Polynomial(const Polynomial& other) : degree(other.degree) {
        allocateMemory(degree);
        for (int i = 0; i <= degree; ++i) {
            coefficients[i] = other.coefficients[i];
        }
    }

    ~Polynomial() {
        if (coefficients != nullptr) {
            deallocateMemory();
        }
    }

    int getDegree() const {
        return degree;
    }

    double evaluate(double x) const {
        double result = 0;
        double power = 1;
        for (int i = 0; i <= degree; ++i) {
            result += coefficients[i] * power;
            power *= x;
        }
        return result;
    }

    void print() const {
        for (int i = degree; i >= 0; --i) {
            cout << coefficients[i];
            if (i > 0) cout << "x^" << i << " + ";
        }
        cout << endl;
    }
};

int main(int argc, char* argv[]) {
    if (argc < 3) {
        cerr << "Usage: <degree> <coefficients...>" << endl;
        return 1;
    }

    int degree = stoi(argv[1]);
    double* coeffs = new double[degree + 1];

    for (int i = 0; i <= degree; ++i) {
        coeffs[i] = stod(argv[i + 2]);
    }

    Polynomial poly(degree, coeffs);

    cout << "Polynomial: ";
    poly.print();
    
    delete[] coeffs;

    return 0;
}
