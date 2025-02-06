#include "Car.h"

Car::Car(string pLicensePlate, string pBrand, string pName, CarType pType, int pLocation){
    licensePlate = pLicensePlate;
    brand = pBrand;
    name = pName;
    type = pType;
    location = pLocation;

    kmDriven = 0;
    available = true;
    lastServiceKm = 0;
}

string Car::getLicensePlate(){
    return licensePlate;
}

string Car::getBrand(){
    return brand;
}

string Car::getName(){
    return name;
}

CarType Car::getType(){
    return type;
}

int Car::getKmDriven(){
    return kmDriven;
}

bool Car::isAvailable(){
    return available;
}

int Car::getLocation(){
    return location;
}

int Car::getLastServiceKm(){
    return lastServiceKm;
}

void Car::setLicensePlate(string pLicensePlate){
    licensePlate = pLicensePlate;
}

void Car::setBrand(string pBrand){
    brand = pBrand;
}

void Car::setName (string pName){
    name = pName;
}

void Car::setType (CarType pType){
    type = pType;
}

void Car::setAvailability(bool availability){
    available = availability;
}

void Car::updateLocation(int newLocation){
    location = newLocation;
}

void Car::addKm(int km){
    kmDriven += km;
}

void Car::setKm(int km){
    kmDriven = km;
}

bool Car::needsService(){
    return (kmDriven - lastServiceKm) >= 1500;
}

void Car::performService() {
    lastServiceKm = kmDriven;
    available = false;
}
