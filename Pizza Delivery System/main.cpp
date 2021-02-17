/* Zafer Yıldız 150170054 (g++ -Wall -Werror 150170054.cpp -o main) */

#include <iostream>
#include "OrderList.h"

using namespace std;

int main() {
    string operation;
    OrderList* myOrderList = new OrderList();         //OrderList which is used during taking and delivering orders is created

    while(true){

        cout<<"Welcome to Unicorn Pizza\n";           //The menu is printed on the screen
        cout<<"1. Add an order\n";
        cout<<"2. List Orders\n";
        cout<<"3. Deliver Order\n";
        cout<<"4. Exit\n";
        cout<<"Choose what to do:";

        getline(cin, operation);                //Input for the operation choice is taken from the user in string format
        cin.clear();

        if(operation == "1"){                         //If operation is 1, takeOrder of the OrderList is invoked
            myOrderList->takeOrder();
        }else if(operation == "2"){                   //If operation is 2, listOrders of the OrderList is invoked
            myOrderList->listOrders();
        }else if(operation == "3"){                   //If operation is 3, deliverOrders of the OrderList is invoked
            myOrderList->deliverOrders();
        }else if(operation == "4"){                   //If operation is 4, the program is terminated.
            cout<<"Goodbye...";
            delete myOrderList;
            return 0;
        }else{
            cout<<"\nInvalid input! Please try again!\n";   //If the input is different from 1,2,3 and 4; an error message is printed on the screen.
        }
    }   //End while.(If input is not valid for the program, it is asked again to user until he/she enters a valid input)
}
