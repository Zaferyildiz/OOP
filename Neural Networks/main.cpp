/*Zafer Yıldız 150170054 (g++ -Wall -Werror 150170054.cpp -o main)*/

#include <iostream>
#include <fstream>
#include <string>
#include "Matrix.h"
#include "Layer.h"
#include "Network.h"
#include "Neuron.h"

using namespace std;

int main(int argc, char *argv[]) {
    char* fileName = argv[1];

    ifstream file;
    file.open(fileName);

    int layer, temp;
    int row = 0;                                        //It indicates the row number of the input except first row.
    file>>layer;
    int** input = new int*[3];                          //I kept the input in a 2D array except the amount of layer
    for(int i=0; i<2; i++){                             //First 2 row of the input arr is allocated
        input[i] = new int[layer];
    }
    for(int j=0; j<layer; j++){                         //Then, I have read input from the file to the input arr
        file>>temp;
        input[row][j] = temp;                           //After I have read number of neurons in the first layer
        if(j == 0){                                     //I have allocated a new row that has number of neuron in the layer 0 column for the input arr
            input[2] = new int[input[0][0]];
        }
    }
    row++;                                              //After reading the first row, row is incremented by 1.

    for(int j=0; j<layer; j++){                         //For the second row I have used try catch to catch invalid neuron type
        try{
            file>>temp;
            if(!(temp == 0 || temp == 1 || temp == 2)){
                string error = "Unidentified activation function!";
                throw error;                            //If the number I have read from the file is not equal to 0,1 or 2
            }                                           //An error is catched.
        }
        catch (const string error){
            cout<<error<<endl;                         //If the error is occurred while file reading
            for (int i = 0; i < 3; i++) {              //I deallocate input arr
                delete[] input[i];
            }
            delete[] input;
            return 0;                                  //Then, program is terminated
        }
        input[row][j] = temp;                 //If everything is okay, file reading is continued.
    }
    row++;                                      //After reading the second row, row is incremented by 1.

    int* buffer = new int[50];                  //I used a buffer arr for the last row
    int counter = 0;                            //number of int I have read from the file
    try{
        while(!file.eof()){                     //I have continued file reading until end of the file
            file>>temp;                         //And, I have copied the numbers I have read to the buffer
            buffer[counter] = temp;
            counter++;                          //And, I have incremented counter by 1
        }
        if(counter != input[0][0]){             //If the number of int I have read from the file is not equal to first element of the input arr
            string error = "Input shape does not match!";
            throw error;                        //An error is catched by the try catch block
        }
    }
    catch (const string error){                 //If an error is occurred
        cout<<error<<endl;                      //I printed an error message to the screen
        for (int i = 0; i < 3; i++) {           //Then, I have deallocated input arr
            delete[] input[i];
        }
        delete[] input;
        delete[] buffer;
        return 0;                               //Finally, program is terminated
    }

    for(int j=0; j<counter; j++){               //If everything is okay about the last row, I have copied buffer to last row of the input arr
        input[row][j] = buffer[j];
    }

    Network* myNetwork = new Network();         //After reading the file, I have created a network and a layer
    Layer* firstLayer = new Layer(0);

    for(int i=0; i<input[0][0]; i++){           //Then, I have created corresponding neurons and added them to the layer object
        if(input[1][0] == 0){
            SigmoidNeuron* newNeuron = new SigmoidNeuron(input[2][i], input[2][i]);
            firstLayer->push(newNeuron);
        }else if(input[1][0] == 1){
            LReluNeuron* newNeuron = new LReluNeuron(input[2][i], input[2][i]);
            firstLayer->push(newNeuron);
        }else{
            ReluNeuron* newNeuron = new ReluNeuron(input[2][i], input[2][i]);
            firstLayer->push(newNeuron);
        }
    }
    myNetwork->push(firstLayer);                //Then, first layer is added to network

    for(int i=1; i<layer; i++){                 //For the other layers
        Layer* newLayer = new Layer(i);         //Firstly, I have created again a layer
        //Then, necessary matrices is created to calculated Z values.
        Matrix* W = new Matrix(input[0][i], myNetwork->getLayer(i-1)->getSize(), 0.1);
        Matrix* B = new Matrix(input[0][i], 1, 0.1);
        Matrix* X = new Matrix(myNetwork->getLayer(i-1)->getSize(), 1, 0.0);
        Layer* previousLayer = myNetwork->getLayer(i-1);
        for(int j=0; j<input[0][i-1]; j++){
            X->arr[j][0] = previousLayer->getNeuron(j)->getA();
        }
        Matrix* WX = matrixMul(W, X);
        Matrix* Z = matrixAdd(WX, B);           //Z matrix is created as a result of necessary matrix operations
        for(int j=0; j<input[0][i]; j++){       //I have created corresponding neurons again for other layers
            if(input[1][i] == 0){
                SigmoidNeuron* newNeuron = new SigmoidNeuron(Z->arr[j][0], Z->arr[j][0]);
                newNeuron->activate();          //And activate functions of them is called
                newLayer->push(newNeuron);      //When they are activated, they are added to layer
            }else if(input[1][i] == 1){
                LReluNeuron* newNeuron = new LReluNeuron(Z->arr[j][0], Z->arr[j][0]);
                newNeuron->activate();
                newLayer->push(newNeuron);
            }else{
                ReluNeuron* newNeuron = new ReluNeuron(Z->arr[j][0], Z->arr[j][0]);
                newNeuron->activate();
                newLayer->push(newNeuron);
            }
        }
        delete W;                           //I have deallocated matrices
        delete WX;
        delete X;
        delete B;
        delete Z;
        myNetwork->push(newLayer);          //Finally, the new layer is added to network object
    }
    myNetwork->print();                     //Content of the network object is printed to the screen
    file.close();

    for (int i = 0; i < 3; i++) {           //Then, I have deallocated my input arr and network object
        delete[] input[i];
    }
    delete[] input;
    delete[] buffer;
    delete myNetwork;
    return  0;
}
