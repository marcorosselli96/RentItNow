#include "RentItNow.h"
#include <iostream>
#include <cmath>

void RentItNow::registerUser(User user) {
    userManager.addUser(user);
}

bool RentItNow::editUser(User user) {
    return userManager.editUser(user);
}

bool RentItNow::removeUser(string drivingLicense) {
    return userManager.removeUser(drivingLicense);
}

void RentItNow::addCar(Car car) {
    carManager.addCar(car);
}

bool RentItNow::rentCar(CarType type, int passengers, int startCircle, int endCircle) {
    // Calculating the hops between circles
    int hops = abs(endCircle - startCircle) + 1;
    int distance = hops * 5; // 5 km per hop

    // Find an available car
    Car* car = carManager.findAvailableCar(type, startCircle);
    if (!car) {
        cout << endl<<"No cars available at the moment. Please wait..."<<endl;
        return false;
    }

    // Determine the price per km based on the type of car
    int pricePerKm = (type == CarType::ECO) ? 1 : (type == CarType::MID_CLASS) ? 2 : 5;
    int totalCost = pricePerKm * distance;

    // Simulate payment
    cout << endl<<"Total trip cost: $" << totalCost << ". Payment made"<<endl;

    // Update car status
    car->setAvailability(false);
    car->addKm(distance);

    // Check if the car needs maintenance
    if (car->needsService()) {
        cout << "The car" << car->getLicensePlate() << " needs maintenance"<<endl;
        car->performService();
    }

    return true;
}

void RentItNow::returnCar(string licensePlate, int newLocation) {
    carManager.updateCarAvailability(licensePlate, true);
}

void RentItNow::printCars() {
    carManager.printCarList();
}

bool RentItNow::checkStatus(string licensePlate) {
    return carManager.checkStatus(licensePlate);
}

bool RentItNow::editCar(string licensePlate, string brand, string name, CarType carType, int location, int km, bool available) {
    return carManager.editCar(licensePlate, brand, name, carType, location, km, available);
}

bool RentItNow::removeCar(string licensePlate) {
    return carManager.removeCar(licensePlate);
}

bool RentItNow::removeRegisteredUser(){
    return userManager.removeRegisteredUser();
}

bool RentItNow::editRegisteredUser(string name, string surname, string address, string creditCard){
    return userManager.editRegisteredUser(name, surname, address, creditCard);
}

void RentItNow::printUsers() {
    userManager.printUsersList();
}
