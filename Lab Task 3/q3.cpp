#include <iostream>
#include <cstdlib>  // For atoi (to convert string to int)
using namespace std;

class Glass {
public:
    int LiquidLevel;

    Glass() {
        LiquidLevel = 200;
    }

    void Drink(int milliliters) {
        if (milliliters > LiquidLevel) {
            cout << "Error: Cannot drink more than the current liquid level." << endl;
        } else {
            LiquidLevel -= milliliters;
            cout << "You drank " << milliliters << " ml. Current liquid level: " << LiquidLevel << " ml." << endl;

            if (LiquidLevel < 100) {
                Refill();
            }
        }
    }

    void Refill() {
        LiquidLevel = 200;
        cout << "The glass has been refilled to 200 ml." << endl;
    }
};

int main(int argc, char* argv[]) {
    Glass myGlass; 

    cout << "The glass is initially full (200 ml)." << endl;

    if (argc == 1) {
        cout << "No drinking amount provided. Please enter drinking amounts as command line arguments." << endl;
        return 1;
    }

    for (int i = 1; i < argc; ++i) {
        int drinkAmount = atoi(argv[i]);  

        if (drinkAmount <= 0) {
            cout << "Invalid amount. Please provide a positive integer for drinking." << endl;
            continue;
        }

        myGlass.Drink(drinkAmount);
    }

    cout << "Program ended." << endl;
    return 0;
}
