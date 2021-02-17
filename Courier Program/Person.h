/*Zafer Yıldız 150170054 g++ -Wall -WError main.cpp -o main*/

#ifndef OOPHW2_PERSON_H
#define OOPHW2_PERSON_H

using namespace std;

class Person{
private:
    string name;                                    //name of the Person
    string surname;                                 //surname fo the Person
public:
    Person();                                       //default constructor
    Person(const Person& Person_in);                //copy constructor
    const string& getName() const;                  //getter and setter methods for name and surname
    const string& getSurname() const;
    void setName(const string &name);
    void setSurname(const string &surname);
};

Person::Person(){                                   //default constructor
    this->name = "defaultName";
    this->surname = "defaultSurname";
}

Person::Person(const Person& Person_in){            //copy constructor
    this->name = Person_in.getName();
    this->surname = Person_in.getSurname();
}

const string& Person::getName() const {             //getter and setter methods for name and surname
    return name;
}

const string& Person::getSurname() const {
    return surname;
}

void Person::setName(const string& name) {
    this->name = name;
}

void Person::setSurname(const string& surname) {
    this->surname = surname;
}

#endif //OOPHW2_PERSON_H
