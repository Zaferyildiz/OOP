/*Zafer Yıldız 150170054 g++ -Wall -WError main.cpp -o main*/

#ifndef OOPHW2_BUSINESS_H
#define OOPHW2_BUSINESS_H

#include <stdlib.h>
#include "Courier.h"
#include "CourierArr.h"

using namespace std;

class Business{
private:
    string name;                                    //name of the business
    string address;                                 //address of the business
    Owner* owners;                                  //owner
    CourierArr* couriers;                           //courier arr
    int ownershipCount;                             //number of of ownerships
public:
    Business();                                                     //default constructor
    Business(const string name, const string address,const Owner* const arr, const int ownershipCount);
    Business(const Business& Business_in);                          //copy constructor
    ~Business();                                                    //default destructor
    void hire_courier(const Courier& hiredCourier) const;           //it adds new courier to couriers array
    void fire_courier(const Courier& firedCourier) const;           //it removes a courier from the couriers array
    void list_couriers() const;                                     //it prints information of all couriers to the screen
    void list_owners() const;                                       //it prints information of all owners to the screen
    int calculate_shipment_capacity() const;                        //it calculates total transportation capacity
    void operator()() const;                                        //operator overloading for ()
    Courier& operator[](const int index) const;                     //operator overloading for []

    const string &getName() const;                                  //getter methods
    const string &getAddress() const;
    Owner* getOwners() const;
    CourierArr *getCouriers() const;
    int getOwnershipCount() const;
};

Business::Business(){                                               //default constructor
    this->name = "defaultName";
    this->address = "defaultAddress";
    this->owners = NULL;
    this->couriers = new CourierArr();
    this->ownershipCount = 0;
}

Business::Business(const string name, const string address, const Owner* const arr, const int ownershipCount){
    this->name = name;                                              //it sets the name of the object to name parameter
    this->address = address;                                        //it sets the address of the object to adress parameter
    this->owners = new Owner[ownershipCount];                       //it allocates a new owner array
    for(int i=0; i<ownershipCount; i++){                            //It copies the data in the arr parameter to new owner array
        owners[i] = arr[i];
    }
    this->ownershipCount = ownershipCount;                          //It sets ownershipcount to ownership parameter
    for(int i=0; i<ownershipCount; i++){                            //It sets ownership percentage of all owners to 100.0/ownershipcount
        owners[i].setOwnership(100.0/ownershipCount);
    }
    this->couriers = new CourierArr();                             //It creates new courier arr.
}

Business::Business(const Business& Business_in){                    //copy constructor
    this->name = Business_in.getName();                             //it sets the name to name of the copied Business object
    this->address = Business_in.getAddress();                       //it sets the address to address of the copied Business object
    this->owners = new Owner[Business_in.getOwnershipCount()];      //it allocates memory for the owners arr
    for(int i=0; i<Business_in.getOwnershipCount(); i++){           //it copies all data in the owner arr of the copied object to owners arr of the new object
        this->owners[i] = Business_in.getOwners()[i];
    }
    this->couriers = new CourierArr();                              //it creates new courier arr for the new object
    for(int i=0; i<Business_in.getCouriers()->getSize(); i++){      //it copies all data in the courier arr of the copied object to courier arr of the new object
        this->couriers->push(Business_in.getCouriers()->get(i));
    }
    this->ownershipCount = Business_in.getOwnershipCount();         //it sets ownershipcount to ownershipcount of the copied object
}

Business::~Business(){                                              //default destructor
    delete[] owners;                                                //it deallocates owner arr
    delete couriers;                                                //it calls the destructor of the courier arr
}

void Business::hire_courier(const Courier& hiredCourier)const {
    this->couriers->push(hiredCourier);                             //it pushes a new courier to the courier arr of the object
}

void Business::fire_courier(const Courier& firedCourier)const{
    bool found = false;                                             //I kept a boolean variable
    for(int i=0; i<couriers->getSize(); i++){                       //It looks all couriers in courier arr and searches for the ginven Courier
        if(couriers->get(i) == firedCourier){                       //if it is found
            couriers->remove(i);                                    //it is removed from the couriers arr
            found = true;                                           //and found variable is set to true
        }
    }
    if(!found){                                                     //If it is not found in the courier arr
        cout<<"There is no courier like that!"<<endl;               //Then, it prints an error message
        exit(EXIT_FAILURE);                                         //and program is terminated
    }
}

void Business::list_couriers() const{                              //It prints all couriers to the screen
    if(couriers->getSize() == 0){                                  //If there is no courier, then it prints an error message
        cout<<"There is no courier!"<<endl;
        return;
    }
    for(int i=0; i<couriers->getSize(); i++){
        cout<<couriers->get(i).getName()<<" "<<couriers->get(i).getSurname()<<" "<<couriers->get(i).getVehicleType()<<endl;
    }
}

void Business::list_owners() const{                                 //It prints all owners to the screen
    for(int i=0; i<this->ownershipCount; i++){
        cout<<owners[i].getName()<<" "<<owners[i].getSurname()<<" "<<owners[i].getOwnership()<<endl;
    }
}

int Business::calculate_shipment_capacity() const{                  //it calculates total transportation capacity
    int sum = 0;
    for(int i=0; i<couriers->getSize(); i++){                       //it traverses courier arr
        sum += couriers->get(i).getTransportationCapacity();        //and it adds transportation capacity of the courier to the sum variable
    }
    return sum;
}

void Business::operator()() const{                                  //operator overloading for ()
    cout<<this->name<<" "<<this->address<<endl;                     //it prints all information about a business (name, address)
    this->list_owners();                                            //it calls list_owners and list_couriers function
    this->list_couriers();                                          //to print owner and courier information
}

Courier& Business::operator[](const int index) const{               //operator overloading for []
    if(index > -1 && index < couriers->getSize()){                  //If the given index is valid
        return couriers->get(index);                                //it returns corresponding courier
    }else{                                                          //If the given index is not valid
        cout<<"Invalid index!"<<endl;                               //it prints an error message
        exit(EXIT_FAILURE);                                         //and program is terminated
    }
}

const string &Business::getName() const {                           //getter methods
    return name;
}

const string &Business::getAddress() const {
    return address;
}

Owner *Business::getOwners() const {
    return owners;
}

CourierArr *Business::getCouriers() const {
    return couriers;
}

int Business::getOwnershipCount() const {
    return ownershipCount;
}

#endif //OOPHW2_BUSINESS_H
