#include "RentItNow.h"
#include<iostream>
using namespace std;

int main() {

    RentItNow system;
    int choice;
    do{
        cout << endl << "SERVICES FOR THE RentItNow OWNER" << endl;
        cout << "Press 1 to add a car" << endl;
        cout << "Press 2 to check the status of a car" << endl;
        cout << "Press 3 to edit a car" << endl;
        cout << "Press 4 to remove a car" << endl;
        cout << "Press 5 to list the cars" << endl;
        cout << "Press 6 to add a user" << endl;
        cout << "Press 7 to update a user" << endl;
        cout << "Press 8 to remove a user" << endl;
        cout<<"Press 9 to list the users"<<endl;

        cout << endl << "RentItNow CUSTOMER SERVICES" << endl;
        cout << "Press 10 to sign up" << endl;
        cout << "Press 11 to delete your account" << endl;
        cout << "Press 12 to edit your account" << endl;
        cout << "Press 13 to book a car" << endl;

        cout << endl << "Press 0 to exit" << endl<<endl;
        cin>>choice;

        switch(choice){
            case 1:{
                string licensePlate, brand, name;
                int type, location;
                CarType carType;

                cout<<endl<<"Enter the license plate: ";
                cin>>licensePlate;
                cout<<endl<<"Enter the car brand: ";
                cin>>brand;
                cout<<endl<<"Enter the car name: ";
                cin>>name;
                do{
                    cout<<endl<<"Enter the type car (0 = ECO, 1 = MID_CLASS, 2 = DELUXE): ";
                    cin>>type;
                    if (type==0){
                        carType = CarType::ECO;
                    } else if (type==1){
                        carType = CarType::MID_CLASS;
                    } else if (type==2){
                        carType = CarType::DELUXE;
                    }
                } while (type!=0 && type!=1 && type!=2);
                do{
                    cout<<endl<<"Enter the location (0 = Inner Circle, 1 = Middle Circle, 2 = Outer Circle): ";
                    cin>>location;
                } while (location!=0 && location!=1 && location!=2);

                system.addCar(Car(licensePlate, brand, name, carType, location));

                break;
            }
            case 2: {
                string licensePlate;
                cout<<endl<<"Enter the license plate: ";
                cin>>licensePlate;
                if(!system.checkStatus(licensePlate)){
                    cout<<endl<<"Car not found"<<endl;
                }
                break;
            }
            case 3: {
                string licensePlate, brand, name, availability;
                int type, location, km;
                CarType carType;

                cout<<endl<<"Enter the license plate of the car to modify: ";
                cin>>licensePlate;

                cout<<endl<<"Enter the car brand: ";
                cin>>brand;
                cout<<endl<<"Enter the car name: ";
                cin>>name;
                do{
                    cout<<endl<<"Enter the type car (0 = ECO, 1 = MID_CLASS, 2 = DELUXE): ";
                    cin>>type;
                    if (type==0){
                        carType = CarType::ECO;
                    } else if (type==1){
                        carType = CarType::MID_CLASS;
                    } else if (type==2){
                        carType = CarType::DELUXE;
                    }
                } while (type!=0 && type!=1 && type!=2);
                do{
                    cout<<endl<<"Enter the location (0 = Inner Circle, 1 = Middle Circle, 2 = Outer Circle): ";
                    cin>>location;
                } while (location!=0 && location!=1 && location!=2);

                cout<<endl<<"Enter km of the car: "<<endl;
                cin>>km;

                do{
                    cout<<endl<<"Enter the availability of the car (YES/NO): ";
                    cin>>availability;
                } while (availability!="YES" && availability!="NO");

                bool available;
                if (availability=="YES"){
                    available=true;
                } else {
                    available=false;
                }

                if (system.editCar(licensePlate, brand, name, carType, location, km, available)){
                    cout<<endl<<"Car modified"<<endl;
                } else {
                    cout<<endl<<"Car not found"<<endl;
                }
                break;
            }
            case 4: {
                string licensePlate;
                cout<<endl<<"Enter the license plate of the car to remove: ";
                cin>>licensePlate;
                if (system.removeCar(licensePlate)){
                    cout<<endl<<"Car removed"<<endl;
                } else {
                    cout<<endl<<"Car not found"<<endl;
                }
                break;
            }
            case 5: {
                system.printCars();
                break;
            }
            case 7: {
                string drivingLicense, name, surname, address, creditCard;

                cout<<endl<<"Enter the driving license of the user to modify: ";
                cin>>drivingLicense;

                cout<<endl<<"Enter user name: ";
                cin>>name;
                cout<<endl<<"Enter user surname: ";
                cin>>surname;
                cout<<endl<<"Enter user address: ";
                cin>>address;
                cout<<endl<<"Enter user credit card: ";
                cin>>creditCard;
                User user (name, surname, address, creditCard, drivingLicense);
                if(system.editUser(user)){
                    cout<<endl<<"User modified!"<<endl;
                } else {
                    cout<<endl<<"User not found!"<<endl;
                }
                break;
            }
            case 8:{
                string drivingLicense;

                cout<<endl<<"Enter the driving license of the user to remove: ";
                cin>>drivingLicense;

                if(system.removeUser(drivingLicense)){
                    cout<<endl<<"User removed!"<<endl;
                } else {
                    cout<<endl<<"User not found!"<<endl;
                }

                break;
            }
            case 9: {
                system.printUsers();
                break;
            }
            case 6:
            case 10: {
                string name, surname, address, creditCard, drivingLicense;

                cout<<endl<<"Enter user name: ";
                cin>>name;
                cout<<endl<<"Enter user surname: ";
                cin>>surname;
                cout<<endl<<"Enter user address: ";
                cin>>address;
                cout<<endl<<"Enter user credit card: ";
                cin>>creditCard;
                cout<<endl<<"Enter user driving license: ";
                cin>>drivingLicense;
                User user (name, surname, address, creditCard, drivingLicense);
                system.registerUser(user);
                break;
            }
            case 11: {
                if(system.removeRegisteredUser()){
                    cout<<endl<<"User removed!"<<endl;
                } else {
                    cout<<endl<<"User not found!"<<endl;
                }
                break;
            }
            case 12: {
                string name, surname, address, creditCard;

                cout<<endl<<"Enter user name: ";
                cin>>name;
                cout<<endl<<"Enter user surname: ";
                cin>>surname;
                cout<<endl<<"Enter user address: ";
                cin>>address;
                cout<<endl<<"Enter user credit card: ";
                cin>>creditCard;

                if(system.editRegisteredUser(name, surname, address, creditCard)){
                    cout<<endl<<"User modified!"<<endl;
                } else {
                    cout<<endl<<"User not found!"<<endl;
                }
                break;
            }
            case 13: {
                int type, passengers, startCircle, endCircle;
                CarType carType;

                do{
                    cout<<endl<<"Enter the type car (0 = ECO, 1 = MID_CLASS, 2 = DELUXE): ";
                    cin>>type;
                    if (type==0){
                        carType = CarType::ECO;
                    } else if (type==1){
                        carType = CarType::MID_CLASS;
                    } else if (type==2){
                        carType = CarType::DELUXE;
                    }
                } while (type!=0 && type!=1 && type!=2);

                do{
                    cout<<endl<<"Enter the starting location (0 = Inner Circle, 1 = Middle Circle, 2 = Outer Circle): ";
                    cin>>startCircle;
                } while (startCircle!=0 && startCircle!=1 && startCircle!=2);

                do{
                    cout<<endl<<"Enter the destination location (0 = Inner Circle, 1 = Middle Circle, 2 = Outer Circle): ";
                    cin>>endCircle;
                } while (endCircle!=0 && endCircle!=1 && endCircle!=2);

                cout<<endl<<"Enter the number of passengers: ";
                cin>>passengers;

                system.rentCar(carType, passengers, startCircle, endCircle);

            }
        }
    } while(choice!=0);

    return 0;
}
