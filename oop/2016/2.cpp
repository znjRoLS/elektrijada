//
// Created by rols on 5/13/17.
//

#include <iostream>

#define BATTERY "economic"

#define BMB95 void

int cost = 0;

int itinirery = 3;

bool areWeThereYet(char* dest, int x = itinirery);

class Vehicle {

protected:

    int mileage;

public:

    Vehicle() : mileage(0) {

//Is this brand new?\\

        std::cout << "new vehicle ";

        std::cout << "cost:" << (cost += 50) << std::endl;

    }

    Vehicle(int km) : mileage(km) {

//This must be used vehicle...:/

        cost <<= 1; std::cout << "cost:" << cost << std::endl; }

    void move(int distance) {

        std::cout << "Moved further to " << (itinirery % 2 ? "left" : "right") <<

                  std::endl;

        (itinirery % 2 ? cost : distance) += (cost % 3 ? 10 : -10);

        mileage += distance;

    }

};

void letsParty(Vehicle& vehicle);

class Engine {

public:

    Engine() { running = false; std::cout << "unknown engine cost:" << (cost *= 3) <<

                                          std::endl; }

    Engine(char* type) { running = false; std::cout << type << " engine\n"; }

    void start() {

        if (running == false) {

            cost += 50;

            running = true;

            std::cout << "Brrrmm\nstart cost:" << cost << std::endl;

        }

    }

    void stop() {

        if (running =! false) {

            running = false;

            std::cout << "Cool-off\n";

        }

    }

    ~Engine() { stop(); }

private:

    bool running;

};

Vehicle bike;

class Car : public Vehicle {

    Engine e;

public:

    Car() { std::cout << "welcome" << std::endl; }

    Car(Engine engine) : Vehicle(100), e(engine) { std::cout << "awesome! cost:" <<

                                                             (cost - 50); }

    int driveTo(char* location) {

        bool areWeThereYet(char* dest, int x = 10);

        e.start();

        while (!::areWeThereYet(location)) {

            move(50);

            std::cout << "mileage:" << mileage << " cost:" << cost << std::endl;

        }

        e.stop();

        return mileage;

    }

};

int main() {

    Engine gasoline(BMB95), electric(BATTERY);

    Car yugo, tesla(electric);

    tesla.driveTo("Rimini");

    letsParty(yugo);

    return (int)0;

}

bool areWeThereYet(char* dest, int x) {

    itinirery--; std::cout << dest << ", wait for it..." << x << "\n";

    return x <= 0;

}

void letsParty(Vehicle& vehicle) {

    std::cout << "Budget:" << cost << " Andiamo, party! ";

}