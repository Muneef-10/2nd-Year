#include <iostream>
#include <string>

class Vehicle {
protected:
    float speed;       // Speed of the vehicle in km/h
    float fuelLevel;   // Fuel level in liters

public:
    Vehicle(float spd, float fuel) : speed(spd), fuelLevel(fuel) {}

    virtual void displayInfo() const {
        std::cout << "Speed: " << speed << " km/h, Fuel Level: " << fuelLevel << " L" << std::endl;
    }
};

class LandVehicle : public Vehicle {
protected:
    int wheelCount;    // Number of wheels

public:
    LandVehicle(float spd, float fuel, int wheels) 
        : Vehicle(spd, fuel), wheelCount(wheels) {}

    void displayInfo() const override {
        Vehicle::displayInfo();
        std::cout << "Wheel Count: " << wheelCount << std::endl;
    }
};

class FlyingVehicle :virtual public Vehicle {
protected:
    float altitude;     // Altitude in meters

public:
    FlyingVehicle(float spd, float fuel, float alt) 
        : Vehicle(spd, fuel), altitude(alt) {}

    void displayInfo() const override {
        Vehicle::displayInfo();
        std::cout << "Altitude: " << altitude << " m" << std::endl;
    }
};

class FlyingCar : public LandVehicle, public FlyingVehicle {
public:
    FlyingCar(float spd, float fuel, int wheels, float alt) 
        : Vehicle(spd, fuel), LandVehicle(spd, fuel, wheels), FlyingVehicle(spd, fuel, alt) {}

    void displayInfo() const override {
        std::cout << "Flying Car Info:" << std::endl;
        LandVehicle::displayInfo();
        FlyingVehicle::displayInfo();
    }
};

int main() {
    FlyingCar myFlyingCar(150, 50, 4, 1000);
    myFlyingCar.displayInfo();

    return 0;
}
