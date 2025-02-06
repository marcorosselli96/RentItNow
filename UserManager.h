#ifndef USERMANAGER_H
#define USERMANAGER_H

#include "User.h"
#include <vector>
using namespace std;

class UserManager {
private:
    vector<User> users;

public:
    void addUser(User user);
    bool removeUser(string drivingLicense);
    bool editUser(User user);
    bool removeRegisteredUser();
    bool editRegisteredUser(string name, string surname, string address, string creditCard);
    void printUsersList();
};

#endif
