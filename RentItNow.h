#ifndef RENTITNOW_H
#define RENTITNOW_H

#include "CarManager.h"
#include "UserManager.h"

class RentItNow {
private:
    CarManager carManager;
    UserManager userManager;

public:
    void registerUser(User user);
    void addCar(Car car);
    bool rentCar(CarType type, int passengers, int startCircle, int endCircle);
    void returnCar(string licensePlate, int newLocation);
    void printCars();
    bool checkStatus(string licensePlate);
    bool editCar(string licensePlate, string brand, string name, CarType carType, int location, int km, bool available);
    bool removeCar(string licensePlate);
    void addUser(User user);
    bool editUser(User user);
    bool removeUser(string drivingLicense);
    bool removeRegisteredUser();
    bool editRegisteredUser(string name, string surname, string address, string creditCard);
    void printUsers();

};

#endif
