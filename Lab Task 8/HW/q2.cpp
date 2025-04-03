#include <iostream>
using namespace std;

class Shape {
private:
    double area;

public:
    Shape(double a) : area(a) {}

    double Area() const {
        return area;
    }

    double operator+(const Shape& other) const {
        return this->area + other.area;  
    }
};

int main() {
    Shape shape1(50.5);  
    Shape shape2(30.25); 

    cout << "Area of shape1: " << shape1.Area() << endl;
    cout << "Area of shape2: " << shape2.Area() << endl;

    double totalArea = shape1 + shape2;  

    cout << "Total area of shape1 and shape2: " << totalArea << endl;

    return 0;
}
