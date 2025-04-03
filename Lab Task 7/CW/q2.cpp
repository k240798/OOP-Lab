#include <iostream>
#include <vector>
#include <cmath>
#include <string>
using namespace std;

class Shape {
protected:
    double positionX, positionY;  
    string color;                 
    double borderThickness;       

public:
    Shape(double x = 0, double y = 0, string c = "black", double border = 1)
        : positionX(x), positionY(y), color(c), borderThickness(border) {}

    virtual void draw() const = 0;

    virtual double calculateArea() const = 0;

    virtual double calculatePerimeter() const = 0;

    void displayInfo() const {
        cout << "Shape Info: Position(" << positionX << ", " << positionY << "), Color: " << color << ", Border Thickness: " << borderThickness << endl;
    }
};

class Circle : public Shape {
private:
    double radius;  

public:
    Circle(double x, double y, string c, double border, double r)
        : Shape(x, y, c, border), radius(r) {}

    void draw() const override {
        cout << "Drawing Circle at (" << positionX << ", " << positionY << ") with radius " << radius << " and color " << color << endl;
    }

    double calculateArea() const override {
        return M_PI * radius * radius;
    }

    double calculatePerimeter() const override {
        return 2 * M_PI * radius;
    }
};

class Rectangle : public Shape {
private:
    double width, height;  

public:
    Rectangle(double x, double y, string c, double border, double w, double h)
        : Shape(x, y, c, border), width(w), height(h) {}

    void draw() const override {
        cout << "Drawing Rectangle at (" << positionX << ", " << positionY << ") with width " << width << " and height " << height << " and color " << color << endl;
    }

    double calculateArea() const override {
        return width * height;
    }

    double calculatePerimeter() const override {
        return 2 * (width + height);
    }
};

class Triangle : public Shape {
private:
    double x1, y1, x2, y2, x3, y3;  

public:
    
    Triangle(double x, double y, string c, double border, double x1, double y1, double x2, double y2, double x3, double y3)
        : Shape(x, y, c, border), x1(x1), y1(y1), x2(x2), y2(y2), x3(x3), y3(y3) {}

    void draw() const override {
        cout << "Drawing Triangle with vertices (" << x1 << ", " << y1 << "), (" << x2 << ", " << y2 << "), (" << x3 << ", " << y3 << ") and color " << color << endl;
    }

    double sideLength(double x1, double y1, double x2, double y2) const {
        return sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2));
    }

    
    double calculateArea() const override {
        double a = sideLength(x1, y1, x2, y2);
        double b = sideLength(x2, y2, x3, y3);
        double c = sideLength(x3, y3, x1, y1);
        double s = (a + b + c) / 2;
        return sqrt(s * (s - a) * (s - b) * (s - c));  
    }

    double calculatePerimeter() const override {
        double a = sideLength(x1, y1, x2, y2);
        double b = sideLength(x2, y2, x3, y3);
        double c = sideLength(x3, y3, x1, y1);
        return a + b + c;
    }
};

class Polygon : public Shape {
private:
    vector<pair<double, double>> vertices;  

public:
    Polygon(double x, double y, string c, double border, const vector<pair<double, double>>& verts)
        : Shape(x, y, c, border), vertices(verts) {}

    void draw() const override {
        cout << "Drawing Polygon with vertices: ";
        for (const auto& vertex : vertices) {
            cout << "(" << vertex.first << ", " << vertex.second << ") ";
        }
        cout << "and color " << color << endl;
    }

    double calculateArea() const override {
        double area = 0;
        int n = vertices.size();
        for (int i = 0; i < n; i++) {
            int j = (i + 1) % n; 
            area += vertices[i].first * vertices[j].second;
            area -= vertices[j].first * vertices[i].second;
        }
        return abs(area) / 2;
    }

    double calculatePerimeter() const override {
        double perimeter = 0;
        int n = vertices.size();
        for (int i = 0; i < n; i++) {
            int j = (i + 1) % n;  
            perimeter += sqrt(pow(vertices[j].first - vertices[i].first, 2) + pow(vertices[j].second - vertices[i].second, 2));
        }
        return perimeter;
    }
};

int main() {
    Circle circle(0, 0, "Red", 2, 10);
    Rectangle rect(0, 0, "Blue", 2, 5, 8);
    Triangle triangle(0, 0, "Green", 2, 0, 0, 5, 0, 2, 5);
    vector<pair<double, double>> polygonVertices = {{0, 0}, {4, 0}, {4, 3}, {0, 3}};
    Polygon polygon(0, 0, "Yellow", 2, polygonVertices);

    circle.draw();
    circle.displayInfo();
    cout << "Area: " << circle.calculateArea() << ", Perimeter: " << circle.calculatePerimeter() << endl;

    rect.draw();
    rect.displayInfo();
    cout << "Area: " << rect.calculateArea() << ", Perimeter: " << rect.calculatePerimeter() << endl;

    triangle.draw();
    triangle.displayInfo();
    cout << "Area: " << triangle.calculateArea() << ", Perimeter: " << triangle.calculatePerimeter() << endl;

    polygon.draw();
    polygon.displayInfo();
    cout << "Area: " << polygon.calculateArea() << ", Perimeter: " << polygon.calculatePerimeter() << endl;

    return 0;
}
