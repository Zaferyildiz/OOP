/*Zafer Yıldız 150170054 g++ -Wall -WError main.cpp -o main*/

#ifndef OOPHW2_COURIER_H
#define OOPHW2_COURIER_H

#include "Person.h"
#include <string>
#include <stdlib.h>
using namespace std;

class Courier: public Person{
private:
    string vehicleType;                         //name of vehicle of the courier
    int transportationCapacity;                 //transportation capacity of the courier
public:
    Courier();                                                                      //default constructor
    Courier(const string name, const string surname, const string vehicleType);     //constructor with some parameters
    Courier(const Courier& Courier_in);                                             //copy constructor
    const string& getVehicleType() const;                                           //getter method for vehicleType
    int getTransportationCapacity() const;                                          //getter method for transportationCapacity
    bool operator==(const Courier& Courier_in);                                     //== operator overloading
};

Courier::Courier(){                                                                 //default constructor
    this->setName("defaultName");                                             //it sets name of the Courier to defaultName
    this->setSurname("defaultSurname");                                     //it sets surname of the Courier to defaultSurn     Name
    this->vehicleType = "defaultVehicle";
    this->transportationCapacity = 0;
}

Courier::Courier(const string name, const string surname, const string vehicleType){
    if(vehicleType == "car" || vehicleType == "motorcycle" || vehicleType == "bicycle"){    //If the vehicleType is valid
        this->setName(name);                            //It sets the name of the Courier to given name parameter
        this->setSurname(surname);                      //It sets the surname of the Courier to given surname parameter
        this->vehicleType = vehicleType;                //It sets the vehicle of the Courier to given vehicleType parameter
        if(vehicleType == "car"){                       //If the vehicleType is car
            this->transportationCapacity = 200;         //It sets transportation capacity to 200
        }else if(vehicleType == "motorcycle"){          //If the vehicleType is motorcycle
            this->transportationCapacity = 35;          //It sets transportation capacity to 35
        }else{                                          //If the vehicleType is bicycle
            this->transportationCapacity = 10;          //It sets transportation capacity to 10
        }
    }else{                                              //If the vehicleType is now equal to car, motorcycle or bicycle
        cout<<"Invalid vehicle!"<<endl;                 //It prints an error message
        exit(EXIT_FAILURE);                             //It terminates the program
    }
}

Courier::Courier(const Courier& Courier_in){            //copy constructor
    this->setName(Courier_in.getName());                //it sets the name to name of the copied Courier object
    this->setSurname(Courier_in.getSurname());          //it sets the surname to surname of the copied Courier object
    this->vehicleType = Courier_in.getVehicleType();    //it sets the vehicleType to vehicleType of the copied Courier object
    this->transportationCapacity = Courier_in.getTransportationCapacity();
}

bool Courier::operator==(const Courier& Courier_in) {   //Operator Overloading for ==
    if(this->getName() == Courier_in.getName() && this->getSurname() == Courier_in.getSurname() && this->getVehicleType()  == Courier_in.getVehicleType()){
        return true;            //It returns true if the name, surname and vehicleType of the given Courier is equal to Courier whose == operator is called
    }
    return false;               //If they are not same it returns false
}

const string& Courier::getVehicleType() const {         //getter method for the vehicleType
    return vehicleType;
}

int Courier::getTransportationCapacity() const {        //getter method for transportationCapacity
    return transportationCapacity;
}

#endif //OOPHW2_COURIER_H
