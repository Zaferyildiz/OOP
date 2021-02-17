/* Zafer Yıldız 150170054 (g++ -Wall -Werror 150170054.cpp -o main) */

#ifndef OOP_HW1_ORDERLIST_H
#define OOP_HW1_ORDERLIST_H

#include <sstream>
#include "Order.h"

using namespace std;

bool intInputValidator(const string input){         //this function decides whether a string can convert to an int or not
    stringstream ss(input);                         //I took all inputs in string format with getline
    int intInput;
    if(ss >> intInput){                             //If the string input can be converted to an int
        string remainPart;                          //I also checked for the remainin part of the string for strings in 12sdf format
        getline(ss, remainPart);
        if(remainPart == ""){                       //If the remain part of the string is empty that means user enters a int input(12)
            return true;
        }else{
            return false;                           //If the remaining part is not empty(for instance sdf for 12sdf input), it returns false
        }
    }else{
        return false;                               //if the input can not be converted to an int, it return false(lskdfj format)
    }
}

class OrderList{                                    //It is a linked list that keeps all orders in pizza shop
    int n;                                          //it is the number of order in the linked list
    Order* head;                                    //headptr of the linked list
public:
    OrderList();                                    //constructor
    ~OrderList();                                   //destructor
    int getN() const;                               //getter method for n
    void addOrder(Order* newOrder);                 //It adds a new order to the linked list
    Order* searchOrder(const string customerName);  //it searchs whole linked list for a specific node
    void removeOrder(const string CustomerName);    //It removes an order from the linked list
    void takeOrder();                               //It takes a new order from the user
    DrinkLinkedList* takeDrinkOrder();              //It takes drink order fromm the user
    void listOrders() const;                        //It prints all orders to the screen
    void deliverOrders();                           //It delivers an order
};

OrderList::OrderList(){                             //constructor
    n = 0;                                          //it sets n to 0, because there is no order in the linked list at start
    head = NULL;                                    //it sets head to NULL
}

OrderList::~OrderList(){                            //destructor
    Order* temp;                                    //it traverses all nodes in the linked list and deallocates these nodes from the memory
    while(head){
        temp = head;
        head = head->getNext();
        delete temp;
    }
    n = 0;
}

int OrderList::getN() const {                       //getter method for n
    return n;
}

void OrderList::addOrder(Order* newOrder) {         //it adds a new order node to the linked list
    if(head == NULL){                               //if head is NULL, that means there is no node in the linked list and the new node will be first node in the linked list
        head = newOrder;
    }else{                                          //If head is not NULL, that means there are some nodes in linked list, and new node should be added as last node in linked list
        Order* temp = head;                         //So, to find correct location, I slided temp to the end of the linked list
        while(temp->getNext()){
            temp = temp->getNext();
        }
        temp->setNext(newOrder);                    //Finally, when I found the correct position, I added new order as the next order of the temp ptr
    }
    n++;
}

DrinkLinkedList* OrderList::takeDrinkOrder() {      //It takes only drink order from the user

    DrinkLinkedList* drinks = new DrinkLinkedList();    //I used again a linked list structure to keep drinks

    string input;
    int drink = -2;

    while(true){                                         //This while loop continues until the user enters a valid input
        cout<<"Please choose a drink:\n";                //Firstly, it prints drink menu to the screen
        cout<<"0. no drink\n";
        cout<<"1. cola 4 TL\n";
        cout<<"2. soda 2 TL\n";
        cout<<"3. ice tea 3 TL\n";
        cout<<"4. fruit juice 3.5 TL\n";
        cout<<"Press -1 for save your order\n";

        getline(cin, input);                       //it takes input from the user in string format
        cin.clear();

        if(intInputValidator(input)){                    //if the input is an integer
            stringstream ss(input);
            ss>>drink;
            if(drink == -1 || drink == 0 || drink == 1 || drink == 2 || drink == 3 || drink == 4){
                break;                                   //and if the input is -1,0,1,2,3 or 4, while loop ends
            }else{
                cout<<"Invalid operation! Please try again\n"; //if it is not, input is asked again to the user
            }
        }else{
            cout<<"Invalid operation! Please try again\n"; //if it is not an integer, input is asked again to the user
        }
    }
    if(drink == 0 || drink == -1){                  //If the user enters 0 as first input, I returned a NULL ptr
        delete drinks;
        return NULL;
    }else{
        if(drink == 1){                             //If the user wants to add a drink his/her order, I added corresponding drink to drinks linked list
            drinks->addDrink("cola");
        }else if(drink == 2){
            drinks->addDrink("soda");
        }else if(drink == 3){
            drinks->addDrink("ice tea");
        }else if(drink == 4){
            drinks->addDrink("fruit juice");
        }
    }

    while(true){                                    //After the first input, if the user did not enter 0 or -1 as input, it asked again user for other drinks
        while(true){
            getline(cin, input);              //Same input validation operation I explained above
            cin.clear();
            if(intInputValidator(input)){
                stringstream ss(input);
                ss>>drink;
                if(drink == -1 ||drink == 0 || drink == 1 || drink == 2 || drink == 3 || drink == 4){
                    break;
                }else{
                    cout<<"Invalid operation! Please try again\n";
                }
            }else{
                cout<<"Invalid operation! Please try again\n";
            }
        }

        if(drink == -1){                                //If input is -1, that means the user wants to save his/her drink order
            return drinks;                              //So, it returns current drinks linked list
        }else if(drink == 0){                           //If the user enters 0 after some drinks, it return NULL
            delete drinks;
            return NULL;
        }else if(drink == 1){                           //If the user wants to add a drink his/her order, I added corresponding drink to drinks linked list
            drinks->addDrink("cola");
        }else if(drink == 2){
            drinks->addDrink("soda");
        }else if(drink == 3){
            drinks->addDrink("ice tea");
        }else if(drink == 4){
            drinks->addDrink("fruit juice");
        }
    }
}

void OrderList::takeOrder() {                       //It takes a new order from the user
    int pizzaType, amount;
    string size, crust_type, customer, input;

    while(true){                        //Firstly,it prints the pizza menu to the user
        cout<<"Pizza Menu\n";
        cout<<"1. Chicken Pizza (mozarella, chicken, mushroom, corn, onion, tomato)\n";
        cout<<"2. Brocolli Pizza (mozarella, brocolli, pepperoni, olive, corn, onion)\n";
        cout<<"3. Sausage Pizza (mozarella, sausage, tomato, olive, mushroom, corn)\n";
        cout<<"0. Back to main menu\n";

        getline(cin, input);      //Then takes input in string format from the user
        cin.clear();

        if(intInputValidator(input)){   //If the user enters an integer
            stringstream ss(input);
            ss>>pizzaType;
            if(pizzaType == 0){         //If the input is 0, the program backs to main menu, so I returned here
                return;
            }else if(pizzaType == 1 || pizzaType == 2 || pizzaType == 3){   //If the user enters 1,2 or 3 as pizzaType
                while(true){
                    cout<<"Select size: small (15 TL), medium (20 TL), big (25 TL)\n";
                    getline(cin, size);                               //It asks for pizza size to the user
                    cin.clear();
                    if(size == "small" || size == "medium" || size == "big" ){
                        break;                                              //If user enters small, medium or big that means the input is valis
                    }else{
                        cout<<"Invalid pizza size! Please try again\n";     //if it is different string from small, medium and big, it prints an error message and asks again
                    }
                }

                while(true){                                                //Then it asks for crust type
                    cout<<"Select crust type: thin, normal, thick\n";
                    getline(cin, crust_type);                        //It takes input from the user
                    cin.clear();
                    if(crust_type == "thin" || crust_type == "normal" || crust_type == "thick" ){
                        break;                    //If crust type is thin, normal or thick that means the crust type is valid
                    }else{
                        cout<<"Invalid crust type! Please try again\n"; //else it prints an error message and asks again
                    }
                }

                while(true){                                  //Then the program asks for amount of pizza to the user
                    cout<<"Enter the amount:";
                    getline(cin, input);                //It takes input as a string from the user
                    cin.clear();
                    if(intInputValidator(input)){             //If the input is an integer
                        stringstream ss(input);
                        ss>>amount;
                        if(amount > 0){                       //And if it is greater than 0, that means the input is valid
                            break;
                        }else{                                //else it prints an error message, and asks for amount again
                            cout<<"Invalid input! Please try again!"<<endl;
                        }
                    }else{
                        cout<<"Invalid input! Please try again!"<<endl; //If the input is not an integer, it asks for amount again
                    }
                }
                //After necessary inputs are taken, pizza object is created with these inputs as parameters to constructor
                Pizza* newPizza = new Pizza(size, crust_type, pizzaType);
                PizzaLinkedList* newPizzaLinkedList = new PizzaLinkedList();
                newPizzaLinkedList->addPizza(newPizza);     //And the new pizza is added to pizza linked list

                if(amount == 1){                            //If amount is 1, that means it is not necessary to ask user for ingredient removing
                    DrinkLinkedList* drinks = takeDrinkOrder(); //Drink order is taken by takeDrinkOrder function
                    cout<< "Please enter your name:";       //Name of customer is taken
                    getline(cin, customer);
                    cin.clear();
                    while(true){
                        if(customer == ""){                 //If the user enters a empty string as name, an error message is printed on the screen
                            cout<<"Please enter a name:";
                            getline(cin, customer);  //An it is asked again to the user
                            cin.clear();
                        }else{
                            break;                          //If the name is not empty that means name is valid
                        }
                    }
                    while(searchOrder(customer) != NULL){   //If there is a customer with same name, an error message is printed to the screen
                        cout<<"\nThere is a customer with the same name\n";
                        cout<<"Please enter a different name:"; //And it is asked again to the user
                        getline(cin, customer);
                        cin.clear();
                    }
                    cout<<"\nYour order is saved, it will be delivered when it is ready...\n";

                    if(drinks == NULL){     //If the user does not want to any drink, new order is created with no drink
                        Order* newOrder = new Order(customer, newPizzaLinkedList);
                        this->addOrder(newOrder);           //new order is added to orderList
                        newOrder->printOrder();             //after adding the content of the order is printed on the screen
                    }else{                  //If the user wants to drink, new order is created with corresponding drink linked list
                        Order* newOrder = new Order(customer, newPizzaLinkedList, drinks);
                        this->addOrder(newOrder);           //new order is added to orderList
                        newOrder->printOrder();             //after adding the content of the order is printed on the screen
                    }
                }
                else{                                       //If the amount is greater than 1
                    string target;                          //the program asks for ingredient that will be removed by user
                    for(int i=0; i<amount-1; i++){
                        cout<<"Please enter the number of ingredients you want to remove from your pizza.\n";
                        Pizza* copyPizza = new Pizza(*newPizza);    //New pizza is created as a copy of first pizza by copy constructor
                        copyPizza->printIngredients();              //And it's ingredients are printed to the screen for removing operation
                        cout<<"Press 0 to save it.\n";

                        int ingredientAmount = copyPizza->getIngredients()->getIngredientCount(); //ingredient amount in the pizza
                        string* arr = new string[ingredientAmount];                               //string array that keeps all ingredients in the pizza is created
                        for(int i=0; i<ingredientAmount; i++){
                            arr[i] = copyPizza->getIngredients()->getIngredient(i+1);
                        }

                        int deleted = -1;
                        while(true){
                            while(true){
                                getline(cin, input);                //the number of ingredient that will be removed is taken from the user
                                cin.clear();
                                if(intInputValidator(input)){             //If the input is an integer
                                    stringstream ss(input);
                                    ss>>deleted;                          //It is casted to an integer
                                    if(deleted > -1 && deleted <= ingredientAmount){
                                        break;                            //If this number is between 0 and ingredient amount in this pizza, that means the input is valid
                                    }else{                                //else it is not valid, and is asked again to the user
                                        cout<<"Invalid input! Please try again!"<<endl;
                                    }
                                }else{                                    //If the input is not an integer, an error message is printed on screen, it is asked again to the user
                                    cout<<"Invalid input! Please try again!"<<endl;
                                }
                            }
                            if(deleted == 0){                             //If the input is 0, that means the user does not want to ingredient anymore
                                break;
                            }
                            target = arr[deleted - 1];                    //If it is not 0, that means an ingredient will be removed from the ingredient linked list of this pizza
                            if(copyPizza->getIngredients()->getIngredientCount() == 1 && copyPizza->getIngredients()->getIngredient(1) == target){
                                cout<<"It should be at least one ingredient in the pizza, otherwise we have to send you just crust :)\n\n";
                                break;                 //If there is only one ingredient in the pizza and the user wants to remove this ingredient an error message is printed on screen
                            }
                            if(!copyPizza->getIngredients()->removeIngredient(target) ){ //If the user try to removed an ingredients which is already deleted
                                cout<<"You have already deleted this ingredient\n";      //an error message is printed on screen
                            }
                            copyPizza->getIngredients()->removeIngredient(target);      //If the input is a valid number corresponding ingredient removed from the pizza
                        }
                        newPizzaLinkedList->addPizza(copyPizza);           //Finally the new pizza is added to pizza linked list
                        delete[] arr;
                    }

                    DrinkLinkedList* drinks = takeDrinkOrder();       //After pizza order is taken, drink order is taken
                    cout<< "Please enter your name:";                 //Customer name is asked
                    getline(cin, customer);
                    cin.clear();
                    while(true){
                        if(customer == ""){                           //If name is a empty string, it is asked again
                            cout<<"Please enter a name:";
                            getline(cin, customer);
                            cin.clear();
                        }else{
                            break;
                        }
                    }
                    while(searchOrder(customer) != NULL){            //If there is a customer with same name, an error message is printed to the screen
                        cout<<"\nThere is a customer with the same name\n";
                        cout<<"Please enter a different name:";     //and it is asked again to the user
                        getline(cin, customer);
                        cin.clear();
                    }
                    if(drinks == NULL){                              //If the user does not want to any drink, new order is created with no drink
                        Order* newOrder = new Order(customer, newPizzaLinkedList);
                        this->addOrder(newOrder);                   //new order is added to orderList
                        newOrder->printOrder();                     //after adding the content of the order is printed on the screen
                    }else{                                  //If the user wants to drink, new order is created with corresponding drink linked list
                        Order* newOrder = new Order(customer, newPizzaLinkedList, drinks);
                        this->addOrder(newOrder);           //new order is added to orderList
                        newOrder->printOrder();             //after adding the content of the order is printed on the screen
                    }
                    cout<<"\nYour order is saved, it will be delivered when it is ready...\n";
                }
                return;
            }else{   //if the pizza type is different from 0,1,2 or 3, an error message is printed on screen and it is asked again to the user
                cout<<"Invalid pizza type! Please try again!"<<endl;
            }
        }else{      //If pizza type is not an integer, an error message is printed on screen and it is asked again to the user
            cout<<"Invalid pizza type! Please try again!"<<endl;
        }
    }
}

void OrderList::listOrders() const{         //It prints all orders in the linked list
    Order* temp = this->head;
    if(this->n == 0){                       //if there is no order in linked list an error message is printed on screen
        cout<<"\nTHERE IS NO ORDER!\n";
    }else{                                  //if there is at least one order in linked list
        for(int i=1; i<=this->n; i++){      //all orders are printed on screen from head to end of the orderList
            cout<<i<<endl;
            temp->printOrder();
            temp = temp->getNext();
        }
    }
    cout<<endl;
}

void OrderList::deliverOrders() {           //it delivers a order
    string customerName, promotionCode;
    string yesOrNo;
    this->listOrders();                     //Firstly it prints all orders to the screen
    if(this->getN() == 0){                  //if there is no order in linked list it returns
        return;
    }
    cout<<"Please write the customer name in order to deliver his/her order:";
    getline(cin, customerName);      //If there is at least one order in linked list, customer name is taken from the user
    cin.clear();
    Order* deliveredOrder = this->searchOrder(customerName);    //and it searchs the order that has same name with the given input
    if(deliveredOrder == NULL){                 //If there is no order like that an error message is printed to screen, and it return to main menu
        cout<<"There is no customer like that\n";
        return;
    }
    cout<<"\nFollowing order is delivering...\n";   //If the target order is found
    deliveredOrder->printOrder();                   //it's content is printed on screen
    double totalPrice = deliveredOrder->getPrice(); //and it's price is calculated and printed
    cout<<"Total Price: "<<totalPrice<<"\n";

    do{                                             //Then it is asked to user for promotion code
        while(true){
            cout<<"Do you have a promotion code? (y/n)\n";
            getline(cin, yesOrNo);
            cin.clear();
            if(yesOrNo == "y" || yesOrNo == "n"){       //If the user enters y or n, that means the input is valid
                break;
            }else{
                cout<<"Please enter only y or n!\n";    //else an error message is printed to screen and it is asked again
            }
        }

        if(yesOrNo == "y"){                             //if the user has a promotion code
            cout<<"Please enter your promotion code:";  //promotion code is asked to user
            getline(cin, promotionCode);
            cin.clear();
            if(promotionCode == "I am a student" || promotionCode == "i am a student"){
                totalPrice = totalPrice * 0.9;          //if promotion code is valid, price is calculated again
                cout<<"\nDiscounted Price: "<<totalPrice;     //and new price is printed on screen.
                this->removeOrder(customerName);            //the order that has same name with given input, it is removed from the orderList
                cout<<"\nThe order is delivered succesfully!\n\n";
                return;
            }else{                              //if promotion code is not valid, an error message is printed and it is asked again to user
                cout<<"Promotion code is not accepted.\n";
            }
        }else{                                  //if the user does not have a promotion code, then it is removed with old price
            this->removeOrder(customerName);
            cout<<"\nThe order is delivered succesfully\n\n";
            return;
        }
    }while(promotionCode != "I am a student" && promotionCode != "i am a student");
}

Order* OrderList::searchOrder(const string customerName){   //it searches an order that has same customer name with given parameter
    Order* temp = this->head;                   //temp traverses all nodes from the head to end of the linked list
    while(temp){                                //if temp's name is same with given parameter
        if(temp->getCustomer() == customerName){
            return temp;                        //temp is returned
        }
        temp = temp->getNext();
    }
    return NULL;                                //if there is no order like that, it returns NULL
}

void OrderList::removeOrder(const string customerName){ //It removes an order from the orderList
    Order* temp = this->head;           //it traverses all orders in linked list with temp
    Order* tail = NULL;                 //tail ptr is always points to previous node which is pointed by temp
    while(temp){
        if(temp->getCustomer() == customerName){    //if the temp's customerName is same with given parameter
            if(temp == this->head){                 //and if the temp is the first in the linked list
                this->head = temp->getNext();       //head should be slided to second node
            }else if(temp->getNext() == NULL){      //if it is the last node, tail should be new last node
                tail->setNext(NULL);
            }else{
                tail->setNext(temp->getNext()) ;    //if it is between first and last node, I made necessary connections
            }
            delete temp;                            //I deallocated temp from the memory
            n--;                                    //I decremented number of order by 1
            return;                                 //then it returns
        }
        tail = temp;                                //if temp is not the node I am looking for
        temp = temp->getNext();                     //I slided both temp and tail to next node.
    }
}

#endif //OOP_HW1_ORDERLIST_H
