#include <iostream>
#include <string>
using namespace std;

class Car {
protected:
    string model;
    double price;

public:
    Car(string m, double p) : model(m), price(p) {}

    string getModel() const {
        return model;
    }

    void setModel(string m) {
        model = m;
    }

    double getPrice() const {
        return price;
    }

    virtual void setPrice(double p) = 0;

    virtual ~Car() {}
};

class Color : public Car {
private:
    string color;

public:
    Color(string m, double p, string c) : Car(m, p), color(c) {}

    string getColor() const {
        return color;
    }

    void setColor(string c) {
        color = c;
    }

    void setPrice(double p) override {
        if (p > 0) {
            price = p;
        } else {
            cout << "Invalid price" << endl;
        }
    }

    void displayInfo() const {
        cout << "Car Model: " << getModel() << endl;
        cout << "Price: $" << getPrice() << endl;
        cout << "Color: " << getColor() << endl;
    }
};

class Company : public Car {
private:
    string companyName;

public:
    Company(string m, double p, string c) : Car(m, p), companyName(c) {}

    string getCompanyName() const {
        return companyName;
    }

    void setCompanyName(string c) {
        companyName = c;
    }

    void setPrice(double p) override {
        if (p > 0) {
            price = p;
        } else {
            cout << "Invalid price" << endl;
        }
    }

    void displayInfo() const {
        cout << "Car Model: " << getModel() << endl;
        cout << "Price: $" << getPrice() << endl;
        cout << "Company: " << getCompanyName() << endl;
    }
};

int main() {
    Color colorCar("Model X", 35000.0, "Red");
    Company companyCar("Model Y", 45000.0, "Tesla");

    cout << "Color Car Info:" << endl;
    colorCar.displayInfo();
    cout << endl;

    cout << "Company Car Info:" << endl;
    companyCar.displayInfo();

    colorCar.setPrice(36000.0);
    companyCar.setPrice(47000.0);

    cout << "\nUpdated Car Info:" << endl;
    cout << "Color Car Info:" << endl;
    colorCar.displayInfo();
    cout << endl;

    cout << "Company Car Info:" << endl;
    companyCar.displayInfo();

    return 0;
}
