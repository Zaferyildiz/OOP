/*Zafer Yıldız 150170054 (g++ -Wall -Werror 150170054.cpp -o main)*/

#ifndef OOPHW3_LAYER_H
#define OOPHW3_LAYER_H

#include "Neuron.h"
using namespace std;

class Layer{                                    //I have used a dynamic array to keep neurons in a layer
    Neuron** arr;                               //Neuron arr
    int capacity;                               //capacity of the arr
    int name;                                   //name of the layer
    int size;                                   //size of the arr
public:
    Layer(const int name);                      //constructor with name parameter
    ~Layer();                                   //destructor
    void push(Neuron* const newNeuron);         //It adds a new neuron to neuron arr
    int getSize() const;                        //It returns number of the neuron in the layer
    Neuron* getNeuron(const int index);         //It returns a specific neuron which is in the given index
};

Neuron* Layer::getNeuron(const int index) {
    return arr[index];                          //It returns a specific neuron which is in the given index
}

Layer::Layer(const int name){                   //constructor
    this->name = name;                          //name of the object is assinged to name parameter
    arr = new Neuron*[1];                       //arr is allocated
    capacity = 1;                               //capacity is assigned to 1
    size = 0;                                   //size is assigned to 1
}

Layer::~Layer(){
    for(int i=0; i<size; i++){                  //2D arr is deallocated
        delete arr[i];
    }
    delete[] arr;
}

void Layer::push(Neuron* const newNeuron) {         //It adds a new neuron to neuron arr
    if(size == capacity){                           //If size is equal to capacity
        Neuron** temp = new Neuron*[2*capacity];    //capacity of the arr is multiplied by 2

        for (int i = 0; i < size; i++) {        //And old content is copied to new arr
            temp[i] = arr[i];
        }
        delete[] arr;
        capacity *= 2;
        arr = temp;
    }
    arr[size] = newNeuron;           //new neuron is added as last neuron in the arr
    size++;                          //size is incremented by 1
}

int Layer::getSize() const{         //getter method for the size
    return size;
}

#endif //OOPHW3_LAYER_H
