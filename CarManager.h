#ifndef CARMANAGER_H
#define CARMANAGER_H

#include "Car.h"
#include <vector>
using namespace std;

class CarManager {
private:
    vector<Car> cars;

public:
    void addCar(Car car);
    bool removeCar(string licensePlate);
    Car* findAvailableCar(CarType type, int location);
    void updateCarAvailability(string licensePlate, bool availability);
    void printCarList();
    bool checkStatus(string licensePlate);
    bool editCar(string licensePlate, string brand, string name, CarType carType, int location, int km, bool available);
};

#endif
