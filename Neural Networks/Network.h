/*Zafer Yıldız 150170054 (g++ -Wall -Werror 150170054.cpp -o main)*/

#ifndef OOPHW3_NETWORK_H
#define OOPHW3_NETWORK_H

#include "Layer.h"
using namespace std;

class Network{                              //I have used a dynamic array to keep layers in a network
    Layer** arr;                            //Layer arr
    int capacity;                           //capacity of the arr
    int size;                               //size of the arr
public:
    Network();                              //constructor
    ~Network();                             //destructor
    void push(Layer* const newLayer);       //It adds a new layer to layer arr
    Layer* getLayer(const int index);       //It returns a specific layer which is in the given index
    void print() const;                     //It prints the content of the network object
};

Network::Network(){                         //constructor
    arr = new Layer*[1];                    //arr is allocated
    capacity = 1;                           //capacity is assigned to 1
    size = 0;                               //size is assigned to 1
}

Network::~Network(){                        //2D arr is deallocated
    for(int i=0; i<size; i++){
        delete arr[i];
    }
    delete[] arr;
}

void Network::push(Layer* const newLayer) {     //It adds a new layer to layer arr
    if(size == capacity){                       //If size is equal to capacity
        Layer** temp = new Layer*[2*capacity];  //capacity of the arr is multiplied by 2

        for (int i = 0; i < size; i++) {        //And old content is copied to new arr
            temp[i] = arr[i];
        }
        delete[] arr;
        capacity *= 2;
        arr = temp;
    }
    arr[size] = newLayer;                   //new layer is added as last layer in the arr
    size++;                                 //size is incremented by 1
}

void Network::print() const{                //It prints the content of the network object in given format
    for(int i=0; i<size; i++){
        cout<<"Layer "<<i<<":"<<endl;
        for(int j=0; j<arr[i]->getSize(); j++){
            cout<<arr[i]->getNeuron(j)->getA()<<endl;
        }
    }
}

Layer* Network::getLayer(const int index) {
    return arr[index];                      //It returns a specific layer which is in the given index
}

#endif //OOPHW3_NETWORK_H
