#include <iostream>
#include <cstring> 

class Engine {
public:
    Engine() : isRunning(false) {
        std::cout << "Engine created." << std::endl;
    }

    void start() {
        if (!isRunning) {
            isRunning = true;
            std::cout << "Engine started." << std::endl;
        } else {
            std::cout << "Engine is already running." << std::endl;
        }
    }

    void stop() {
        if (isRunning) {
            isRunning = false;
            std::cout << "Engine stopped." << std::endl;
        } else {
            std::cout << "Engine is already stopped." << std::endl;
        }
    }

    bool isEngineRunning() const {
        return isRunning;
    }

private:
    bool isRunning;
};

class Car {
public:
    Car() {
        std::cout << "Car created." << std::endl;
    }

    void startCar() {
        engine.start();
        std::cout << "Car started." << std::endl;
    }

    void stopCar() {
        engine.stop();
        std::cout << "Car stopped." << std::endl;
    }

private:
    Engine engine;
};

int main(int argc, char *argv[]) {
    Car myCar;

    if (argc != 2) {
        std::cout << "Usage: " << argv[0] << " <start|stop>" << std::endl;
        return 1;  
    }

    if (strcmp(argv[1], "start") == 0) {
        myCar.startCar(); 
    } else if (strcmp(argv[1], "stop") == 0) {
        myCar.stopCar();  
    } else {
        std::cout << "Invalid argument. Please use 'start' or 'stop'." << std::endl;
        return 1;  
    }

    return 0;  
}
