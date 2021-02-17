/* Zafer Yıldız 150170054 (g++ -Wall -Werror 150170054.cpp -o main) */

#ifndef OOP_HW1_PIZZALINKEDLIST_H
#define OOP_HW1_PIZZALINKEDLIST_H

#include "Pizza.h"

using namespace std;

class PizzaLinkedList{                                      //It is a linked list which keeps all pizzas in an order
private:
    Pizza* headptr;                                         //headptr of the linked list
    int pizzaCount;                                         //number of pizzas in the linked list
public:
    void addPizza(Pizza* const newPizza);                   //it adds a new pizza to the linked list
    PizzaLinkedList();                                      //constructor
    ~PizzaLinkedList();                                     //destructor
    Pizza* getHeadptr() const;                              //getter method for the headptr of the linked list
};

PizzaLinkedList::PizzaLinkedList() {                        //constructor
    headptr = NULL;                                         //It sets headptr of the linked list to NULL
    pizzaCount = 0;                                         //It sets pizzaCount to 0, because there is no pizza in the linked list at start
}

PizzaLinkedList::~PizzaLinkedList(){                        //destructor
    Pizza* temp;                                            //It deallocates all pizza nodes from the headptr to the end of the linked list
    while(headptr){
        temp = headptr;
        headptr = headptr->getNext();
        delete temp;
    }
    pizzaCount = 0;
}

void PizzaLinkedList::addPizza(Pizza* const newPizza) {     //It adds a newPizza to the linked list
    if(headptr == NULL){                                    //If headptr is NULL, that means there is no pizza in the linked list
        headptr = newPizza;                                 //So, headptr should show the new node.
    }else{                                                  //If headptr is not NULL, that means there are some nodes in the linked list
        Pizza* temp = headptr;                              //So, I will add the new node to the end of the linked list
        while(temp->getNext()){                             //To reach the end of the linked list, I slided temp ptr until it's next will be NULL
            temp = temp->getNext();
        }
        temp->setNext(newPizza);                            //When I found the correct position, I added the new node as next node of the temp
    }
    pizzaCount++;                                           //I also incremented number of pizza in the linked list
}

Pizza* PizzaLinkedList::getHeadptr() const {                //Getter method for the headptr of the linked list
    return headptr;                                         //It returns the headptr of the linked list
}
#endif //OOP_HW1_PIZZALINKEDLIST_H
