#ifndef USER_H
#define USER_H

#include <string>
using namespace std;

class User {
private:
    string name;
    string surname;
    string address;
    string creditCard;
    string drivingLicense;

public:
    User(string pName, string pSurname, string pAddress, string pCreditCard, string pDrivingLicense);

    //getters
    string getName();
    string getSurname();
    string getAddress();
    string getCreditCard();
    string getDrivingLicense();

    //setters
    void setName(string pName);
    void setSurname(string pSurname);
    void setAddress(string pAddress);
    void setCreditCard(string pCreditCard);
    void setDrivingLicense(string pDrivingLicense);
};

#endif
