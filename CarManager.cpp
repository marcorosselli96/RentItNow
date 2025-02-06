#include "CarManager.h"
#include <iostream>

void CarManager::addCar(Car car) {
    cars.push_back(car);
}

bool CarManager::removeCar(string licensePlate) {
    for (vector<Car>::iterator car = cars.begin(); car != cars.end(); ++car) {
        if (car->getLicensePlate() == licensePlate) {
            cars.erase(car);
            return true;
        }
    }
    return false;
}

Car* CarManager::findAvailableCar(CarType type, int location) {
    for (Car& car : cars) {
        if (car.getType() == type && car.isAvailable() && car.getLocation() == location) {
            return &car;
        }
    }
    return nullptr;
}

void CarManager::updateCarAvailability(string licensePlate, bool availability) {
    for (Car& car : cars) {
        if (car.getLicensePlate() == licensePlate) {
            car.setAvailability(availability);
        }
    }
}

void CarManager::printCarList(){
    for (Car& car : cars) {
        cout<<endl<<"License plate: "<<car.getLicensePlate()<<endl;
        cout<<"Model: "<<car.getName()<<endl;
        cout<<"KM Driven: "<<car.getKmDriven()<<endl;
        cout<<"Last service km: "<<car.getLastServiceKm()<<endl;
        int location = car.getLocation();
        if (location==0){
            cout<<"Location: Inner Circle"<<endl;
        } else if (location==1){
            cout<<"Location: Middle Circle"<<endl;
        } else if (location==2){
            cout<<"Location: Outer Circle"<<endl;
        }
        cout<<"Available: " << (car.isAvailable() ? "Yes" : "No") << endl;
    }
}


bool CarManager::checkStatus(string licensePlate){
    for (Car& car : cars) {
        if (car.getLicensePlate() == licensePlate) {
            int location = car.getLocation();
            if (location==0){
                cout<<endl<<"Location: Inner Circle"<<endl;
            } else if (location==1){
                cout<<endl<<"Location: Middle Circle"<<endl;
            } else if (location==2){
                cout<<endl<<"Location: Outer Circle"<<endl;
            }
            cout<<"Total distance traveled: "<<car.getKmDriven()<<endl;
            cout<<"Next service in km: "<<car.getLastServiceKm()<<endl;
            cout<<"Availability: "<<(car.isAvailable() ? "Si" : "No") << endl;
            return true;
        }
    }
    return false;
}

bool CarManager::editCar(string licensePlate, string brand, string name, CarType carType, int location, int km, bool available){
    for (Car& car : cars) {
        if (car.getLicensePlate() == licensePlate) {
            car.setBrand(brand);
            car.setName(name);
            car.setType(carType);
            car.updateLocation(location);
            car.setKm(km);
            car.setAvailability(available);
            return true;
        }
    }
    return false;
}
