/* Zafer Yıldız 150170054 (g++ -Wall -Werror 150170054.cpp -o main) */

#ifndef OOP_HW1_DRINKLINKEDLIST_H
#define OOP_HW1_DRINKLINKEDLIST_H

#include <string>
using namespace std;

class Drink{                                            //Drink class is a node for DrinkLinkedList structure
private:
    string name;                                        //name of the drink
    int count;                                          //number of this drink type
    Drink* next;                                        //next ptr for connection in the linked list
public:
    Drink(const string drinkName);                      //constructor with the name parameter
    const string& getName() const;                      //getter method for the name
    int getCount() const;                               //getter method for count
    Drink* getNext() const;                             //getter method for next ptr
    void setCount(int count);                           //setter method for count
    void setNext(Drink* next);                          //setter method for next ptr
};

Drink::Drink(const string drinkName) {                  //constructor with name parameter
    this->name = drinkName;                             //name of the drink is set to drinkName
    count = 1;                                          //number of this drink is set to 1
    next = NULL;                                        //next ptr is set to NULL
}

const string& Drink::getName() const {                  //It returns the name of the drink
    return name;
}

int Drink::getCount() const {                           //It returns the count of the drink
    return count;
}

Drink* Drink::getNext() const {                         //It returns the next drink of this drink
    return next;
}

void Drink::setCount(int count) {                       //It sets the count of the drink to count parameter
    this->count = count;
}

void Drink::setNext(Drink* next) {                      //It sets the next ptr of the drink to next parameter
    this->next = next;
}

class DrinkLinkedList{                                  //Linked list of the drinks in an order
private:
    int drinkCount;                                     //number of types of drinks
    Drink* headptr;                                     //headptr of the linked list
public:
    DrinkLinkedList();                                  //constructor
    ~DrinkLinkedList();                                 //destructor
    void addDrink(const string drinkName);              //it adds a new drink node to the linked list
    Drink* searchDrink(const string drinkName) const;   //it searches for a specific drink in the linked list
    int getDrinkCount() const;                          //getter method for drinkCount
    Drink* getHeadptr() const;                          //getter method for headptr
};

DrinkLinkedList::DrinkLinkedList() {                    //default constructor
    headptr = NULL;                                     //it sets headptr to NULL
    drinkCount = 0;                                     //it sets drinkCount to 0, because there is drink at start
}

DrinkLinkedList::~DrinkLinkedList(){                    //destructor
    Drink* temp;                                        //it traverse all nodes in the linked list from head to end of the linked list
    while(headptr){                                     //and it deallocates nodes
        temp = headptr;
        headptr = headptr->getNext();
        delete temp;
    }
    drinkCount = 0;                                     //Finally, it sets drinkCount to 0
}

Drink* DrinkLinkedList::searchDrink(const string drinkName) const{
    Drink* temp = this->headptr;                //temp traverses all linked list to find a node that has sama name with drinkName parameter
    while(temp){
        if(temp->getName() == drinkName){       //If it finds this node, it returns it
            return temp;
        }
        temp = temp->getNext();
    }
    return NULL;                                //If it can not find it, it returns NULL
}

void DrinkLinkedList::addDrink(const string drinkName) {
    Drink* target = searchDrink(drinkName);         //before adding process, it searches node with same drinkName

    if(target == NULL){                             //if there is no node that is added before with the same drinkName
        Drink* newDrink = new Drink(drinkName);     //it creates a new node that has drinkName parameter as name
        if(headptr == NULL){                        //Then, if headptr is NULL, that means there is no node in the linked list
            headptr = newDrink;                     //And the new node will be first node in the linked list, so head should show the newnode.
        }else{
            Drink* temp = headptr;                  //If it is not the first node, I slided temp to the end of the linked list
            while(temp->getNext()){
                temp = temp->getNext();
            }
            temp->setNext(newDrink);                //And, I added new node as last node of the linked list
        }
        drinkCount++;                               //Finally, I incremented drinkCount by 1, because a new node is added to linked list
    }else{
        target->setCount(target->getCount() + 1);   //If there is a node that has same name with given drinkName parameter, I do not need to create new node.
    }                                                     //I can just increment count of this drink by 1
}

int DrinkLinkedList::getDrinkCount() const {              //getter method for drinkCount
    return drinkCount;
}

Drink* DrinkLinkedList::getHeadptr() const {              //getter method for headptr
    return headptr;
}

#endif //OOP_HW1_DRINKLINKEDLIST_H