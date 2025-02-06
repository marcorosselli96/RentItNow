#include "User.h"

User::User(string pName, string pSurname, string pAddress, string pCreditCard, string pDrivingLicense){
    name = pName;
    surname = pSurname;
    address = pAddress;
    creditCard = pCreditCard;
    drivingLicense = pDrivingLicense;
}

string User::getName() {
    return name;
}

string User::getSurname() {
    return surname;
}

string User::getAddress() {
    return address;
}

string User::getCreditCard() {
    return creditCard;
}

string User::getDrivingLicense() {
    return drivingLicense;
}

void User::setName(string pName){
    name = pName;
}

void User::setSurname(string pSurname){
    surname = pSurname;
}

void User::setAddress(string pAddress){
    address = pAddress;
}

void User::setCreditCard(string pCreditCard){
    creditCard = pCreditCard;
}

void User::setDrivingLicense(string pDrivingLicense){
    drivingLicense = pDrivingLicense;
}
