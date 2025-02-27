#include <iostream>

using namespace std;

class Car {
public:
    mutable int engine_horsepower;
    mutable int seating_capacity;
    mutable int no_of_speakers;

    Car(int hp, int seats, int speakers) 
        : engine_horsepower(hp), seating_capacity(seats), no_of_speakers(speakers) {}

    void displayCar() const {
        cout << "Car Specifications:\n";
        cout << "Engine Horsepower: " << engine_horsepower << "\n";
        cout << "Seating Capacity: " << seating_capacity << "\n";
        cout << "Number of Speakers: " << no_of_speakers << "\n";
    }

    void modifyCar(int new_hp, int new_seats, int new_speakers) const {
        engine_horsepower = new_hp;
        seating_capacity = new_seats;
        no_of_speakers = new_speakers;

        cout << "Car attributes updated inside a const function!\n";
    }
};

int main(int argc, char* argv[]) {
    if (argc < 4) {
        cerr << "Usage: " << argv[0] << " <horsepower> <seating_capacity> <no_of_speakers>\n";
        return 1;
    }

    int hp = stoi(argv[1]);
    int seats = stoi(argv[2]);
    int speakers = stoi(argv[3]);

    Car myCar(200, 5, 6); 

    cout << "Before modification:\n";
    myCar.displayCar();

    myCar.modifyCar(hp, seats, speakers);

    cout << "\nAfter modification:\n";
    myCar.displayCar();

    return 0;
}
