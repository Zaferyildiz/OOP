/*Zafer Yıldız 150170054 g++ -Wall -WError main.cpp -o main*/

#ifndef OOPHW2_OWNER_H
#define OOPHW2_OWNER_H

#include "Person.h"

class Owner: public Person{
private:
    double ownership;                                   //ownership percentage of the Owner
public:
    Owner();                                            //default constructor
    Owner(const string name, const string surname);     //constructor with parameters
    Owner(const Owner& Owner_in);                       //copy constructor
    double getOwnership() const;                        //getter method for the ownership
    void setOwnership(const double ownership);          //setter method for the ownership
};

Owner::Owner(){                                         //default constructor
    this->setName("defaultName");                 //it sets the name to defaultName
    this->setSurname("defaultSurname");         //it sets the surname to defaultSurname
    this->ownership = 0;                                //it sets ownership to 0
}

Owner::Owner(const string name, const string surname){  //constructor with name and surname parameters
    this->setName(name);                                //it sets the name to given name parameter
    this->setSurname(surname);                          //it sets the surname to given surname parameter
    this->ownership = 0;                                //it sets ownership to 0
}

Owner::Owner(const Owner& Owner_in){                    //copy constructor
    this->setName(Owner_in.getName());                  //it sets the name to name of the copied Owner object
    this->setSurname(Owner_in.getSurname());            //it sets the surname to surname of the copied Owner object
    this->ownership = Owner_in.ownership;               //it sets the ownership to ownership of the copied Owner object
}

double Owner::getOwnership() const {                    //getter method for ownership
    return ownership;
}

void Owner::setOwnership(const double ownership) {      //setter method for ownership
    this->ownership = ownership;
}

#endif //OOPHW2_OWNER_H
