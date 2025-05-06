#include <iostream>
using namespace std;

template <typename T>
class Base {
protected:
    T a, b;

public:
    Base(T x, T y) : a(x), b(y) {}

    T multiplyBase() {
        return a * b;
    }

    void displayBase() {
        cout << "Base class multiplication: " << multiplyBase() << endl;
    }
};

template <typename T>
class Derived : public Base<T> {
private:
    T c, d;

public:
    Derived(T x, T y, T m, T n) : Base<T>(x, y), c(m), d(n) {}

    T multiplyDerived() {
        return c * d;
    }

    void displayDerived() {
        cout << "Derived class multiplication: " << multiplyDerived() << endl;
    }

    void displayAll() {
        this->displayBase();
        this->displayDerived();
    }
};

int main() {
    Derived<int> obj(2, 3, 4, 5);
    obj.displayAll();

    Derived<double> objDouble(1.5, 2.0, 3.0, 4.5);
    objDouble.displayAll();

    return 0;
}
