/* Zafer Yıldız 150170054 (g++ -Wall -Werror 150170054.cpp -o main) */

#ifndef OOP_HW1_PIZZA_H
#define OOP_HW1_PIZZA_H

#include "IngredientsLinkedList.h"

using namespace std;

class Pizza{
private:
    Pizza* next;                                                //next pointer of the pizza node, because it is kept in a linked list
    string name;                                                //name of the pizza
    string size;                                                //size of the pizza
    string crust_type;                                          //crust type of the pizza
    IngredientsLinkedList* ingredients;                         //ingredients of the pizza(Linked List)
public:
    Pizza();                                                    //default constructor
    Pizza(const string size, const string crust_type, const int pizza_type);  //constructor with some parameters
    Pizza(const Pizza& Pizza_in);                               //copy constructor
    ~Pizza();                                                   //destructor
    Pizza* getNext() const;                                     //getter method for next ptr
    const string& getName() const;                              //getter method for name of the pizza
    const string& getSize() const;                              //getter method for size of the pizza
    const string& getCrustType() const;                         //getter method for crust type of the pizza
    IngredientsLinkedList* getIngredients() const;              //getter method for ingredients of of the pizza
    void setNext(Pizza* next);                                  //setter method for next ptr of the pizza
    void printIngredients() const;                              //it prints all ingredients of the pizza
};

Pizza::Pizza(){                                                 //default constructor
    this->next = NULL;                                          //next ptr is set to NULL
    this->size = "medium";                                      //size of the pizza is set to medium as default
    this->crust_type = "normal";                                //crust type of the pizza is set to normal as default
    this->ingredients = new IngredientsLinkedList();            //ingredients of the pizza is created as a linked list
    this->ingredients->addIngredient("mozarella"); //mozarella is added to the ingredients of the pizza as default
}

Pizza::Pizza(const string size, const string crust_type, const int pizza_type) {
    this->next = NULL;                                          //next ptr is set to NULL
    this->size = size;                                          //size of the pizza is set to medium as default
    this->crust_type = crust_type;                              //crust type of the pizza is set to normal as default
    this->ingredients = new IngredientsLinkedList();            //ingredients of the pizza is created as a linked list
    this->ingredients->addIngredient("mozarella"); //mozarella is added to the ingredients of the pizza as default
    if(pizza_type == 1){                                        //If the pizza_type is 1, that means it is chicken pizza
        this->name = "Chicken Pizza";                           //name of the pizza is set to Chicken Pizza
        ingredients->addIngredient("chicken");    //And corresponding ingredients is added to ingredients of the pizza
        ingredients->addIngredient("mushroom");
        ingredients->addIngredient("corn");
        ingredients->addIngredient("onion");
        ingredients->addIngredient("tomato");
    }else if(pizza_type == 2){                                  //If the pizza_type is 2, that means it is brocolli pizza
        this->name = "Brocolli Pizza";                          //name of the pizza is set to Brocolli Pizza
        ingredients->addIngredient("brocolli");   //And corresponding ingredients is added to ingredients of the pizza
        ingredients->addIngredient("pepperoni");
        ingredients->addIngredient("olive");
        ingredients->addIngredient("corn");
        ingredients->addIngredient("onion");
    }else{                                                      //If the pizza_type is 3, that means it is sausage pizza
        this->name = "Sausage Pizza";                           //(I checked the correctness of the pizza_type while taking input from the user, so it can not be different from the 1,2 and 3)
        ingredients->addIngredient("sausage");    //name of the pizza is set to Sausage Pizza and corresponding ingredients is added to ingredients of the pizza
        ingredients->addIngredient("tomato");
        ingredients->addIngredient("olive");
        ingredients->addIngredient("mushroom");
        ingredients->addIngredient("corn");
    }
}

Pizza::Pizza(const Pizza& Pizza_in) {                               //copy constructor
    this->next = NULL;                                              //next ptr is set to NULL
    this->name = Pizza_in.name;                                     //name of the pizza which is created is set to name of Pizza_in
    this->size = Pizza_in.size;                                     //size of the pizza which is created is set to size of Pizza_in
    this->crust_type = Pizza_in.crust_type;                         //crust type of the pizza which is created is set to crust type of Pizza_in
    this->ingredients = new IngredientsLinkedList();                //ingredients linked list is allocated.
    for(int i=0; i<Pizza_in.ingredients->getIngredientCount(); i++){//All ingredients of the Pizza_in is copied to the ingredients of the new pizza object
        this->ingredients->addIngredient(Pizza_in.ingredients->getIngredient(i+1));
    }
}

void Pizza::printIngredients()const{                                //It prints the all ingredients of the pizza
    Ingredient* temp = this->ingredients->getHeadptr();             //temp ptr which is used to traverse ingredients is set to headptr of ingredients linked list
    for(int i=0; i<this->ingredients->getIngredientCount(); i++){   //temp is slided until it reaches to the end of the linked list
        cout<<i+1<<". "<<temp->getName()<<endl;                     //name of the ingredient which is showed by temp is printed on the screen
        temp = temp->getNext();
    }
}

Pizza::~Pizza(){
    delete ingredients;       //it deletes ingredients linked list from the memory, which is only dynamically allocated part of the pizza object when it is created
}

Pizza* Pizza::getNext() const {                 //getter method for next ptr
    return next;
}

const string& Pizza::getName() const {          //getter method for name
    return name;
}

const string& Pizza::getSize() const {          //getter method for size
    return size;
}

const string& Pizza::getCrustType() const {     //getter method for crust type
    return crust_type;
}

IngredientsLinkedList* Pizza::getIngredients() const {  //getter method for ingredients
    return ingredients;
}

void Pizza::setNext(Pizza* next) {                  //setter method for next ptr
    Pizza::next = next;
}

#endif //OOP_HW1_PIZZA_H