/*Zafer Yıldız 150170054 (g++ -Wall -Werror 150170054.cpp -o main)*/

#ifndef OOPHW3_NEURON_H
#define OOPHW3_NEURON_H

#include <iostream>
#include <cmath>

using namespace std;

class Neuron{                           //Abstract class for the neurons
protected:
    double a;
    double z;
public:
    virtual void activate() = 0;        //virtual activate method
    virtual ~Neuron() = 0;              //virtual destructor
    double getA() const;                //getter method for a
};

Neuron::~Neuron(){

}

double Neuron::getA() const {           //It returns a value of the object
    return a;
}

class SigmoidNeuron : public Neuron{    //Sigmoid neuron class
public:
    SigmoidNeuron();                                //default constructor
    SigmoidNeuron(const double a, const double z);  //constructor with some parameters
    void activate();                                //activate function
};

SigmoidNeuron::SigmoidNeuron(){         //It initializes a and z values of the object with 0
    this->a = 0;
    this->z = 0;
}

SigmoidNeuron::SigmoidNeuron(const double a, const double z){
    this->a = a;                        //a and z values are assigned to given parameters
    this->z = z;
}

void SigmoidNeuron::activate() {        //activate function of the Sigmoid Neuron
    this->a = 1 / (1 + exp((-1) * z));
}
class ReluNeuron : public Neuron{       //Relu Neuron class
public:
    ReluNeuron();                                   //default constructor
    ReluNeuron(const double a, const double z);     //constructor with some parameters
    void activate();                                //activate function
};

ReluNeuron::ReluNeuron(){           //It initializes a and z values of the object with 0
    this->a = 0;
    this->z = 0;
}

ReluNeuron::ReluNeuron(const double a, const double z){
    this->a = a;                            //a and z values are assigned to given parameters
    this->z = z;
}

void ReluNeuron::activate() {               //activate function of the Relu Neuron
    this->a = max(0.0, z);
}
class LReluNeuron : public Neuron{          //Leaky Relu Neuron class
public:
    LReluNeuron();                                  //default constructor
    LReluNeuron(const double a, const double z);    //constructor with some parameters
    void activate();                                //activate function
};

LReluNeuron::LReluNeuron(){             //It initializes a and z values of the object with 0
    this->a = 0;
    this->z = 0;
}

LReluNeuron::LReluNeuron(const double a, const double z){
    this->a = a;                        //a and z values are assigned to given parameters
    this->z = z;
}

void LReluNeuron::activate() {          //activate function of the Leaky Relu Neuron
    this->a =  max(0.1*z, (double)z);
}
#endif //OOPHW3_NEURON_H
