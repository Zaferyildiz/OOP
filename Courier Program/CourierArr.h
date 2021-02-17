/*Zafer Yıldız 150170054 g++ -Wall -WError main.cpp -o main*/

#ifndef OOPHW2_COURIERARR_H
#define OOPHW2_COURIERARR_H

#include <iostream>
#include <stdlib.h>
#include "Courier.h"
using namespace std;

class CourierArr {
private:                                            //Implementation of vector
    Courier* arr;                                   //Dynamic array that keeps data
    int capacity;                                   //capacity of the arr
    int size;                                       //size of the arr
public:
    CourierArr();                                   //default constructor
    ~CourierArr();                                  //default destructor
    void push(const Courier& newCourier);           //it adds new element to the arr
    void remove(const int index);                   //it removes the element which is in the given index number
    int getSize() const;                            //getter method for size of the arr
    Courier& get(const int index);                  //it returns the Courier which is in the given index number
};

CourierArr::CourierArr(){                           //default constructor
    arr = new Courier[1];                           //it allocates memory for one Courier Class
    capacity = 1;                                   //and sets capacity to 1
    size = 0;                                       //sets size to 0
}

CourierArr::~CourierArr(){                          //default destructor
    delete[] arr;                                   //it deallocates arr
}

void CourierArr::remove(const int index) {          //it removes the element which is in the given index number
    for(int i=index; i<size-1; i++){                //it slides all elements from the given index to end of the array to the left
        arr[i] = arr[i+1];
    }
    size--;                                         //size is decremented by 1.
}

void CourierArr::push(const Courier& newCourier) {  //it adds new element to the arr
    if(size == capacity){                           //if size is equal to capacity that means arr is full
        Courier* temp = new Courier[2*capacity];    //so we should allocate new memory

        for (int i = 0; i < capacity; i++) {        //it should copy old data to new allocated memory part
            temp[i] = arr[i];
        }
        delete[] arr;                               //it deallocates old arr
        capacity *= 2;                              //it multiplies capacity with 2
        arr = temp;                                 //arr should point the new allocated memory part
    }
    arr[size] = newCourier;                         //new Courier data is placed at the end of the arr
    size++;                                         //size is incremented by 1
}

Courier& CourierArr::get(const int index) {         //it returns the Courier which is in the given index number
    if(index < size){                              //if index is smaller than size of the arr
        return arr[index];                          //it returns the Courier which is in the given index
    }
    exit(EXIT_FAILURE);
}

int CourierArr::getSize() const{                    //getter method for size of the arr
    return size;
}

#endif //OOPHW2_COURIERARR_H