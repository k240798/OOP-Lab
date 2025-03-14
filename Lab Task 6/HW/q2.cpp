#include <iostream>
#include <string>
using namespace std;

class Vehicle {
protected:
    double price;

public:
    Vehicle(double price) : price(price) {}

    virtual void displayDetails() = 0;

    virtual ~Vehicle() = default;
};

class Car : public Vehicle {
protected:
    int seatingCapacity;
    int numDoors;        
    string fuelType;     

public:
    Car(double price, int seatingCapacity, int numDoors, const string& fuelType)
        : Vehicle(price), seatingCapacity(seatingCapacity), numDoors(numDoors), fuelType(fuelType) {}

    void displayDetails() override {
        cout << "Price: $" << price << endl;
        cout << "Seating Capacity: " << seatingCapacity << endl;
        cout << "Number of Doors: " << numDoors << endl;
        cout << "Fuel Type: " << fuelType << endl;
    }
};

class Motorcycle : public Vehicle {
protected:
    int numCylinders;    
    int numGears;        
    int numWheels;       

public:
    Motorcycle(double price, int numCylinders, int numGears, int numWheels)
        : Vehicle(price), numCylinders(numCylinders), numGears(numGears), numWheels(numWheels) {}

    void displayDetails() override {
        cout << "Price: $" << price << endl;
        cout << "Number of Cylinders: " << numCylinders << endl;
        cout << "Number of Gears: " << numGears << endl;
        cout << "Number of Wheels: " << numWheels << endl;
    }
};

class Audi : public Car {
private:
    string modelType; 

public:
    Audi(double price, int seatingCapacity, int numDoors, const string& fuelType, const string& modelType)
        : Car(price, seatingCapacity, numDoors, fuelType), modelType(modelType) {}

    void displayDetails() override {
        Car::displayDetails();
        cout << "Model Type: " << modelType << endl;
    }
};

class Yamaha : public Motorcycle {
private:
    string makeType; 

public:
    Yamaha(double price, int numCylinders, int numGears, int numWheels, const string& makeType)
        : Motorcycle(price, numCylinders, numGears, numWheels), makeType(makeType) {}

    void displayDetails() override {
        Motorcycle::displayDetails(); 
        cout << "Make Type: " << makeType << endl;
    }
};

int main() {
    Audi audi(50000, 5, 4, "Petrol", "A6");
    
    Yamaha yamaha(15000, 4, 6, 2, "R15");

    cout << "Audi Car Details:" << endl;
    audi.displayDetails();
    cout << endl;

    cout << "Yamaha Motorcycle Details:" << endl;
    yamaha.displayDetails();

    return 0;
}
