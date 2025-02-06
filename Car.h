#ifndef CAR_H
#define CAR_H

#include <string>
using namespace std;

enum class CarType { ECO, MID_CLASS, DELUXE };

class Car {
private:
    string licensePlate;
    string brand;
    string name;
    CarType type;
    int kmDriven;
    bool available;
    int lastServiceKm;
    int location; // 0 = Inner Circle, 1 = Middle Circle, 2 = Outer Circle

public:
    Car(string pLicensePlate, string pBrand, string pName, CarType pType, int pLocation);

    // Getters
    string getLicensePlate();
    string getBrand();
    string getName();
    CarType getType();
    int getKmDriven();
    bool isAvailable();
    int getLocation();
    int getLastServiceKm();

    // Setters
    void setLicensePlate(string licensePlate);
    void setBrand (string brand);
    void setName (string name);
    void setType (CarType type);

    void setAvailability(bool availability);
    void updateLocation(int newLocation);
    void addKm(int km);
    void setKm(int km);

    // Service check
    bool needsService();
    void performService();
};

#endif // CAR_H
