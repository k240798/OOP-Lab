#include <iostream>
using namespace std;

class Shape {
public:
    virtual double getArea() = 0;
    
    virtual ~Shape() {}
};

class Rectangle : public Shape {
private:
    double width, height;
    
public:
    Rectangle(double w, double h) : width(w), height(h) {}
    
    double getArea() override {
        return width * height;
    }
};

class Triangle : public Shape {
private:
    double base, height;
    
public:
    Triangle(double b, double h) : base(b), height(h) {}
    
    double getArea() override {
        return 0.5 * base * height;
    }
};

int main() {
    Shape* rectangle = new Rectangle(10.0, 5.0);
    
    Shape* triangle = new Triangle(6.0, 4.0);
    
    cout << "Area of Rectangle: " << rectangle->getArea() << endl;
    cout << "Area of Triangle: " << triangle->getArea() << endl;
    
    delete rectangle;
    delete triangle;
    
    return 0;
}
