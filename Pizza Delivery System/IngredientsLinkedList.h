/* Zafer Yıldız 150170054 (g++ -Wall -Werror 150170054.cpp -o main) */

#ifndef OOP_HW1_INGREDIENTSLINKEDLIST_H
#define OOP_HW1_INGREDIENTSLINKEDLIST_H

using namespace std;

class Ingredient{                                   //It is node for the IngredientLinkedList structure
private:
    string name;                                    //name of the ingredient
    Ingredient* next;                               //next ptr of the node to connect nodes
public:
    Ingredient(const string ingredientName);        //constructor with name parameter
    const string& getName() const;                  //getter method for the name
    Ingredient* getNext() const;                    //getter method for the next ptr
    void setNext(Ingredient* next);                 //setter method for the next ptr
};

Ingredient::Ingredient(const string ingredientName){ //constructor with name parameter
    this->name = ingredientName;                     //It sets name of the ingredient to the ingredientName parameter
    this->next = NULL;                               //It sets next ptr to NULL.
}

const string& Ingredient::getName() const{           //getter method for the name of the ingredient
    return (this->name);                             //it returns the name of the ingredient
}

Ingredient* Ingredient::getNext() const{             //getter method for the next ptr of the ingredient
    return this->next;                               //it returns the next ptr of the ingredient
}

void Ingredient::setNext(Ingredient* next) {         //setter method for the next ptr of the ingredient
    this->next = next;                               //it sets the next ptr of the ingredient to the next parameter
}

class IngredientsLinkedList{                         //It keeps all ingredients of a pizza in a linked list structure
private:
    Ingredient* headptr;                             //headptr of the linked list
    int ingredientCount;                             //number of the ingredient in the linked list(node number)
public:
    IngredientsLinkedList();                            //default constructor
    ~IngredientsLinkedList();                           //destructor
    void addIngredient(const string ingredientName);    //it adds a new ingredient to the linked list
    bool removeIngredient(const string ingredientName); //it removes an ingredient from the linked list
    void printIngredients() const;                      //it prints all ingredients in the linked list to the screen
    const string& getIngredient(const int nodeNumber);  //getter method for a specific ingredient in the linked list
    Ingredient* getHeadptr() const;                     //getter method for the headptr of the linked list
    int getIngredientCount() const;                     //getter method for the ingredientCount
};

IngredientsLinkedList::IngredientsLinkedList(){         //default constructor
    headptr = NULL;                                     //it sets headptr to NULL
    ingredientCount = 0;                                //it sets ingredientCount to 0
}

IngredientsLinkedList::~IngredientsLinkedList() {       //destructor
    Ingredient* temp;                                   //it deallocates all nodes of the linked list from the head to the end of the linked list
    while(headptr){
        temp = headptr;
        headptr = headptr->getNext();
        delete temp;
    }
    ingredientCount = 0;                                //it sets ingredientCount to 0, because I deleted all nodes from the linked list
}

void IngredientsLinkedList::addIngredient(const string ingredientName) { //it adds a new ingredient to the linked list
    Ingredient* newIngredient = new Ingredient(ingredientName);          //new Ingredient node is created with given ingredientName
    if(this->headptr == NULL){                                           //if headptr is NULL, that means there is no ingredient in the linked list
        this->headptr = newIngredient;                                   //So, the headptr should show the new node.
    }else{                                                               //If the headptr is not NULL, that means there are some nodes in the linked list
        Ingredient* temp = this->headptr;                                //And I will add the new node to the end of the linked list
        while(temp->getNext()){                                          //So, I created a temp ptr, and I slided this temp ptr to the end of the linked list
            temp = temp->getNext();
        }
        temp->setNext(newIngredient);                                    //When I reached the end of the linked list, I added new node as next node of the temp ptr
    }
    this->ingredientCount++;                                             //I also incremented the number of ingredients in the linked list, because I have added a new ingredient
}

bool IngredientsLinkedList::removeIngredient(const string ingredientName){ //It removes a node from the linked list

    Ingredient* temp = this->headptr;               //It removes the node that has name as same with ingredientName parameter.
    Ingredient* tail = NULL;                        //I kept a tail ptr which points previous node of the temp
    while(temp){                                    //I searched whole linked list to find the node that has same ingredient name with the given parameter.
        if(temp->getName() == ingredientName){      //If I found the removed node
            if(temp == this->headptr){              //and if this node is the first node in the linked list
                this->headptr = temp->getNext();    //I should slide headptr to next node
            }else if(temp->getNext() == NULL){      //if it is the last node I should set the next ptr of the previous node as NULL, because it is the new last node in the linked list
                tail->setNext(NULL);
            }else{
                tail->setNext( temp->getNext() );   //If it is between start and end of the linked list, I should connect previous node to next node of the removed node
            }
            delete temp;                            //I deallocated temp
            this->ingredientCount--;                //I decremented number of ingredients, because I deleted an ingredient
            return true;                            //If remove operation is succesfull, the function returns true
        }
        tail = temp;                                //If temp is not the node I am looking for I slided temp and tail to next node
        temp = temp->getNext();
    }
    return false;                                   //If remove operation is not succesfulli the function returns false
}

const string& IngredientsLinkedList::getIngredient(const int nodeNumber){ //It returns the name of the ingredient of the nodeNumberth node
    Ingredient* temp = this->headptr;                                     //in the linked list
    for(int i=0; i<nodeNumber-1; i++){                                    //To do this I slided temp ptr nodeNumber-1 times from the head
        temp = temp->getNext();
    }
    return temp->getName();                                       //When I found the node I am looking for, function returbs its name
}

void IngredientsLinkedList::printIngredients() const{   //It prints all ingredients in the linked list, by traversing all nodes in the linked list
    Ingredient* temp = this->headptr;
    while(temp){
        cout<<temp->getName()<<", ";
        temp = temp->getNext();
    }
}

Ingredient* IngredientsLinkedList::getHeadptr() const {  //getter method for the headptr of the linked list
    return headptr;
}

int IngredientsLinkedList::getIngredientCount() const {  //getter method for the number of ingredients in the linked list
    return ingredientCount;
}

#endif //OOP_HW1_INGREDIENTSLINKEDLIST_H
