/* Zafer Yıldız 150170054 (g++ -Wall -Werror 150170054.cpp -o main) */

#ifndef OOP_HW1_ORDER_H
#define OOP_HW1_ORDER_H

#include "PizzaLinkedList.h"
#include "DrinkLinkedList.h"

#define SMALLPIZZAPRICE 15              //prices are defined as constants
#define MEDIUMPIZZAPRICE 20
#define BIGPIZZAPRICE 25
#define COLAPRICE 4
#define SODAPRICE 2
#define ICETEAPRICE 3
#define FRUITJUICEPRICE 3.5

using namespace std;

class Order{
    string customer;                    //name of the customer
    PizzaLinkedList* pizza;             //list of all pizzas in this order
    DrinkLinkedList* drink;             //list of all drinks in this order
    Order* next;                        //next ptr of the object
public:
    Order(const string customer, PizzaLinkedList* const pizza, DrinkLinkedList* const drink);   //constructor with some parameters
    Order(const string customer, PizzaLinkedList* const pizza);                                 //constructor with some parameters
    ~Order();                                                                       //destructor
    double getPrice() const;                                                        //it calculates the price of the order
    void printOrder() const;                                                        //it prints the content of the order
    const string& getCustomer() const;                                              //getter method for customer name
    Order* getNext() const;                                                         //getter method for next ptr
    void setNext(Order *next);                                                      //setter method for next ptr
};

Order::Order(const string customer, PizzaLinkedList* const pizza, DrinkLinkedList* const drink) {
    this->pizza = pizza;                        //this function sets all attributes to given parameters
    this->drink = drink;                        //it is used for orders that include also drink
    this->next = NULL;
    this->customer = customer;
}

Order::Order(const string customer, PizzaLinkedList* const pizza){
    this->pizza = pizza;                        //this function sets all attributes to given parameters
    this->next = NULL;                          //it is used for orders that has no drink
    this->customer = customer;
    this->drink = new DrinkLinkedList();        //However, it's drink linked list is created, and it's head points to NULL when it is created with default constructor
}

Order::~Order(){                                //destructor
    delete pizza;                               //it deallocates pizza and drink linked list from the memory
    delete drink;                               //they are the only allocated parts in this class
}

double Order::getPrice() const{                 //it calculates price of the order
    double total = 0;

    Pizza* temp = this->pizza->getHeadptr();    //Firstly, it calculates total price of pizzas, and add corresponding prices to total price
    while(temp){
        string size = temp->getSize();
        if(size == "big"){
            total += BIGPIZZAPRICE;
        }else if(size == "medium"){
            total += MEDIUMPIZZAPRICE;
        }else{
            total += SMALLPIZZAPRICE;
        }
        temp = temp->getNext();
        size.clear();
    }

    if(this->drink->getDrinkCount() != 0){      //Then, it calculates total price of drinks, and add corresponding prices to total price again
        Drink* temp2 = this->drink->getHeadptr();
        while(temp2){
            string drinkName = temp2->getName();
            if(drinkName == "cola"){
                total += temp2->getCount() * COLAPRICE;
            }else if(drinkName == "soda"){
                total += temp2->getCount() * SODAPRICE;
            }else if(drinkName == "ice tea"){
                total += temp2->getCount() * ICETEAPRICE;
            }else{
                total += temp2->getCount() * FRUITJUICEPRICE;
            }
            temp2 = temp2->getNext();
            drinkName.clear();
        }
    }
    return total;       //Finally, it returns the total price
}

void Order::printOrder() const{         //It prints the order contents to the screen
    cout<<"--------------------------------------------"<<endl;
    cout<<"Name: "<<this->customer<<endl<<endl;     //it prints the name of the customer

    Pizza* temp = this->pizza->getHeadptr();        //Then, it prints all content of pizzas in this order by traversing pizza linked list in the order
    while(temp){
        cout<<temp->getName()<<"(";
        IngredientsLinkedList* temp2 = temp->getIngredients();
        temp2->printIngredients();
        cout<<")"<<endl;
        cout<<"size: "<<temp->getSize()<<", crust: "<<temp->getCrustType()<<endl<<endl;
        temp = temp->getNext();
    }
    cout<<endl;

    Drink* temp2 = this->drink->getHeadptr();       //Then, it prints all drinks in this order by traversing drink linked list in the order

    if(this->drink->getDrinkCount() != 0){
        while(temp2){
            cout<<temp2->getCount()<<" "<<temp2->getName()<<", ";
            temp2 = temp2->getNext();
        }
        cout<<endl;
    }
    cout<<"--------------------------------------------"<<endl;
}

const string& Order::getCustomer() const{             //getter method for customer name
    return this->customer;
}

Order* Order::getNext() const {                       //getter method for next ptr
    return next;
}

void Order::setNext(Order *next) {                    //setter method for next ptr
    this->next = next;
}

#endif //OOP_HW1_ORDER_H