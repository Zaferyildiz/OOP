/*Zafer Yıldız 150170054 (g++ -Wall -Werror 150170054.cpp -o main)*/

#ifndef OOPHW3_MATRIX_H
#define OOPHW3_MATRIX_H

#include <iostream>

class Matrix{               //I have created a matrix class for the matrix operations
public:
    int row;                //row number of the matrix
    int col;                //column number of the matrix
    double** arr;           //2D arr
    Matrix(const int row, const int col, const double initialValue);    //constructor
    ~Matrix();              //destructor
};

Matrix::Matrix(const int row, const int col, const double initialValue){
    arr = new double*[row];         //arr is allocated corresponding to given row and col parameters

    for(int i=0; i<row; i++){
        arr[i] = new double[col];
    }

    for(int i=0; i<row; i++){       //arr is filled by the initial value parameter
        for(int j=0; j<col; j++){
            arr[i][j] = initialValue;
        }
    }
    this->row = row;                //row and col parameters are assigned to row and col of the object
    this->col = col;
}

Matrix::~Matrix() {                     //destructor
    for (int i = 0; i < row; i++){      //2D arr is deallocted
        delete[] arr[i];
    }
    delete[] arr;
}

Matrix* matrixMul(const Matrix* const mat1, const Matrix* const mat2){     //It multiplies two matrix

    Matrix* res = new Matrix(mat1->row, mat2->col, 0.0);
    for(int i=0; i<mat1->row; ++i){
        for(int j=0; j<mat2->col; ++j){
            for(int k=0; k<mat1->col; ++k) {
                res->arr[i][j] += mat1->arr[i][k] * mat2->arr[k][j];
            }
        }
    }
    return res;
}

Matrix* matrixAdd(const Matrix* const mat1, const Matrix* const mat2){      //It adds two matrix
    Matrix* res = new Matrix(mat1->row, mat1->col, 0.0);
    for(int i = 0; i < mat1->row; i++){
        for(int j = 0; j < mat1->col; j++) {
            res->arr[i][j] = mat1->arr[i][j] + mat2->arr[i][j];
        }
    }
    return res;
}

#endif //OOPHW3_MATRIX_H
