#include "UserManager.h"
#include <iostream>

void UserManager::addUser(User user) {
    users.push_back(user);
}

bool UserManager::removeUser(string drivingLicense) {
    for (vector<User>::iterator user = users.begin(); user != users.end(); ++user) {
        if (user->getDrivingLicense() == drivingLicense) {
            users.erase(user);
            return true;
        }
    }
    return false;
}

bool UserManager::editUser(User user){
    for (vector<User>::iterator userIterator = users.begin(); userIterator != users.end(); ++userIterator) {
        if (userIterator->getDrivingLicense() == user.getDrivingLicense()) {
            userIterator->setAddress(user.getAddress());
            userIterator->setCreditCard(user.getCreditCard());
            userIterator->setName(user.getName());
            userIterator->setSurname(user.getSurname());
            return true;
        }
    }
    return false;
}

bool UserManager::removeRegisteredUser(){
    if (!users.empty()){
        users.erase(users.begin());
        return true;
    }
    return false;
}

bool UserManager::editRegisteredUser(string name, string surname, string address, string creditCard){
    if (!users.empty()){
        users[0].setName(name);
        users[0].setSurname(surname);
        users[0].setAddress(address);
        users[0].setCreditCard(creditCard);
        return true;
    }
    return false;
}

void UserManager::printUsersList(){
    for (User& user : users) {
        cout<<endl<<"Name: "<<user.getName()<<endl;
        cout<<"Surname: "<<user.getSurname()<<endl;
        cout<<"Address: "<<user.getAddress()<<endl;
        cout<<"Credit card: "<<user.getCreditCard()<<endl;
        cout<<"Driving license: "<<user.getDrivingLicense()<<endl;
    }
}
