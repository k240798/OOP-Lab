#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class BigInteger {
private:
    vector<int> digits;
    bool negative;     

    void removeLeadingZeros() {
        while (digits.size() > 1 && digits.back() == 0) {
            digits.pop_back();
        }
    }

public:
    BigInteger() : negative(false) {
        digits.push_back(0);
    }

    BigInteger(const string& num) {
        negative = (num[0] == '-');
        size_t start = (negative) ? 1 : 0;
        digits.clear();

        for (size_t i = num.size(); i-- > start;) {
            digits.push_back(num[i] - '0');
        }

        removeLeadingZeros();
    }

    BigInteger(int num) {
        negative = num < 0;
        if (num == 0) {
            digits.push_back(0);
        } else {
            while (num != 0) {
                digits.push_back(abs(num % 10));
                num /= 10;
            }
        }
    }

    BigInteger operator+(const BigInteger& other) const {
        if (negative == other.negative) {
            BigInteger result;
            result.negative = negative;
            int carry = 0;
            size_t i = 0, j = 0;
            while (i < digits.size() || j < other.digits.size() || carry) {
                int sum = carry;
                if (i < digits.size()) sum += digits[i++];
                if (j < other.digits.size()) sum += other.digits[j++];
                carry = sum / 10;
                result.digits.push_back(sum % 10);
            }
            result.removeLeadingZeros();
            return result;
        } else if (negative) {
            BigInteger temp = *this;
            temp.negative = false;
            return other - temp;
        } else {
            BigInteger temp = other;
            temp.negative = false;
            return *this - temp;
        }
    }

    BigInteger operator-(const BigInteger& other) const {
        if (negative != other.negative) {
            return *this + (-other);
        }

        bool resultNegative = false;
        const BigInteger *larger, *smaller;

        if (*this < other) {
            resultNegative = true;
            larger = &other;
            smaller = this;
        } else {
            larger = this;
            smaller = &other;
        }

        BigInteger result;
        result.negative = resultNegative;

        int borrow = 0;
        size_t i = 0, j = 0;
        while (i < larger->digits.size() || j < smaller->digits.size() || borrow) {
            int diff = borrow;
            if (i < larger->digits.size()) diff += larger->digits[i++];
            if (j < smaller->digits.size()) diff -= smaller->digits[j++];

            if (diff < 0) {
                diff += 10;
                borrow = -1;
            } else {
                borrow = 0;
            }

            result.digits.push_back(diff);
        }
        result.removeLeadingZeros();
        return result;
    }

    BigInteger operator*(const BigInteger& other) const {
        BigInteger result;
        result.digits.resize(digits.size() + other.digits.size(), 0);
        result.negative = (negative != other.negative);

        for (size_t i = 0; i < digits.size(); i++) {
            for (size_t j = 0; j < other.digits.size(); j++) {
                int product = digits[i] * other.digits[j];
                int carry = product / 10;
                result.digits[i + j] += product % 10;

                size_t k = i + j;
                while (result.digits[k] >= 10) {
                    result.digits[k] -= 10;
                    result.digits[++k] += 1;
                }
            }
        }
        result.removeLeadingZeros();
        return result;
    }

    bool operator==(const BigInteger& other) const {
        return digits == other.digits && negative == other.negative;
    }

    bool operator!=(const BigInteger& other) const {
        return !(*this == other);
    }

    bool operator<(const BigInteger& other) const {
        if (negative != other.negative) return negative;
        if (digits.size() != other.digits.size()) return digits.size() < other.digits.size();
        for (int i = digits.size() - 1; i >= 0; --i) {
            if (digits[i] != other.digits[i]) {
                return digits[i] < other.digits[i];
            }
        }
        return false;
    }

    bool operator>(const BigInteger& other) const {
        return other < *this;
    }

    bool operator<=(const BigInteger& other) const {
        return !(*this > other);
    }

    bool operator>=(const BigInteger& other) const {
        return !(*this < other);
    }

    friend ostream& operator<<(ostream& os, const BigInteger& n) {
        if (n.negative) os << "-";
        for (int i = n.digits.size() - 1; i >= 0; i--) {
            os << n.digits[i];
        }
        return os;
    }

    friend istream& operator>>(istream& is, BigInteger& n) {
        string str;
        is >> str;
        n = BigInteger(str);
        return is;
    }

    BigInteger operator-() const {
        BigInteger result = *this;
        result.negative = !result.negative;
        return result;
    }
};

int main() {
    BigInteger a("123456789012345678901234567890");
    BigInteger b("987654321098765432109876543210");

    cout << "a = " << a << endl;
    cout << "b = " << b << endl;

    BigInteger sum = a + b;
    BigInteger diff = a - b;
    BigInteger prod = a * b;

    cout << "Sum = " << sum << endl;
    cout << "Difference = " << diff << endl;
    cout << "Product = " << prod << endl;

    return 0;
}
