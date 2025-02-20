#include <iostream>
#include <cmath>  
using namespace std;

class Circle {
private:
    double radius;

public:
    Circle(double r) : radius(r) {}

    double getArea() const {
        return M_PI * radius * radius;
    }

    double getPerimeter() const {
        return 2 * M_PI * radius;
    }
};

int main(int argc, char* argv[]) {
    if (argc != 2) {
        cerr << "Usage: <radius>" << endl;
        return 1;
    }

    double radius = stod(argv[1]);

    Circle circle(radius);

    cout << "Circle with radius " << radius << ":" << endl;
    cout << "Area: " << circle.getArea() << endl;
    cout << "Perimeter: " << circle.getPerimeter() << endl;

    return 0;
}
