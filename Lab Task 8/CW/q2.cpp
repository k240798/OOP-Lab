#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

class PolynomialUtils;

class Polynomial {
private:
    vector<int> coefficients;  

public:
    Polynomial() {}

    Polynomial(const vector<int>& coeffs) : coefficients(coeffs) {
        while (coefficients.size() > 1 && coefficients.back() == 0) {
            coefficients.pop_back();
        }
    }

    Polynomial operator+(const Polynomial& other) const {
        size_t max_size = max(coefficients.size(), other.coefficients.size());
        vector<int> result(max_size, 0);

        for (size_t i = 0; i < coefficients.size(); i++) {
            result[i] += coefficients[i];
        }
        for (size_t i = 0; i < other.coefficients.size(); i++) {
            result[i] += other.coefficients[i];
        }

        return Polynomial(result);
    }

    Polynomial operator-(const Polynomial& other) const {
        size_t max_size = max(coefficients.size(), other.coefficients.size());
        vector<int> result(max_size, 0);

        for (size_t i = 0; i < coefficients.size(); i++) {
            result[i] += coefficients[i];
        }
        for (size_t i = 0; i < other.coefficients.size(); i++) {
            result[i] -= other.coefficients[i];
        }

        return Polynomial(result);
    }

    Polynomial operator*(const Polynomial& other) const {
        size_t result_size = coefficients.size() + other.coefficients.size() - 1;
        vector<int> result(result_size, 0);

        for (size_t i = 0; i < coefficients.size(); i++) {
            for (size_t j = 0; j < other.coefficients.size(); j++) {
                result[i + j] += coefficients[i] * other.coefficients[j];
            }
        }

        return Polynomial(result);
    }

    friend class PolynomialUtils;

    friend ostream& operator<<(ostream& os, const Polynomial& p) {
        if (p.coefficients.empty()) {
            os << "0";
            return os;
        }

        bool first = true;
        for (int i = p.coefficients.size() - 1; i >= 0; --i) {
            int coeff = p.coefficients[i];
            if (coeff != 0) {
                if (!first) {
                    os << (coeff > 0 ? " + " : " - ");
                } else {
                    if (coeff < 0) {
                        os << "-";
                    }
                    first = false;
                }

                if (abs(coeff) != 1 || i == 0) {
                    os << abs(coeff);
                }

                if (i > 0) {
                    os << "x";
                    if (i > 1) {
                        os << "^" << i;
                    }
                }
            }
        }

        return os;
    }
};

class PolynomialUtils {
public:
    static int evaluate(const Polynomial& p, int x) {
        int result = 0;
        int power_of_x = 1;  

        for (int coeff : p.coefficients) {
            result += coeff * power_of_x;
            power_of_x *= x;  
        }

        return result;
    }

    static Polynomial derivative(const Polynomial& p) {
        vector<int> deriv_coeffs;

        for (int i = 1; i < p.coefficients.size(); ++i) {
            deriv_coeffs.push_back(p.coefficients[i] * i);
        }

        return Polynomial(deriv_coeffs);
    }
};

int main() {
    Polynomial p1({2, 5, 0, -1});  
    Polynomial p2({1, -1, 3});     

    cout << "Polynomial 1: " << p1 << endl;
    cout << "Polynomial 2: " << p2 << endl;

    cout << "p1 + p2 = " << p1 + p2 << endl;
    cout << "p1 - p2 = " << p1 - p2 << endl;
    cout << "p1 * p2 = " << p1 * p2 << endl;

    cout << "p1 evaluated at x = 2: " << PolynomialUtils::evaluate(p1, 2) << endl;

    cout << "Derivative of p1: " << PolynomialUtils::derivative(p1) << endl;

    return 0;
}
