#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>  

class Car {
public:
    Car(const std::string &name, int id) : name(name), id(id) {
        std::cout << "Car " << name << " with ID " << id << " created." << std::endl;
    }

    void display() const {
        std::cout << "Car ID: " << id << ", Name: " << name << std::endl;
    }

private:
    std::string name;
    int id;
};

class Garage {
public:
    void parkCar(Car *car) {
        cars.push_back(car); 
    }

    void listCars() const {
        std::cout << "Listing all parked cars:" << std::endl;
        for (auto car : cars) {
            car->display();
        }
    }

private:
    std::vector<Car *> cars; 
};

int main(int argc, char *argv[]) {
    if (argc < 3) {
        std::cout << "Usage: " << argv[0] << " <num_cars> <car_name_1> <car_name_2> ..." << std::endl;
        return 1;
    }

    int numCars = std::atoi(argv[1]); 
    if (numCars < 1) {
        std::cout << "Please specify a valid number of cars." << std::endl;
        return 1;
    }

    std::vector<Car> cars;
    for (int i = 0; i < numCars; ++i) {
        std::string carName = argv[i + 2]; 
        cars.emplace_back(carName, i + 1); 
    }

    Garage garage;

    for (int i = 0; i < numCars; ++i) {
        garage.parkCar(&cars[i]); 
    }

    garage.listCars();

    return 0;
}
