#include <iostream>
#include "Matrix.h"
using namespace std; 

// Constructor 
Matrix::Matrix(int rows, int cols, double init) {
    this->rows = rows;      
    this->cols = cols;
    this->total = rows * cols; 
    data = (double *) malloc(sizeof(double) * total); 
    for (int i = 0; i < total; i++) {
        this->data[i] = init;
    } 
}

// destructor 
Matrix::~Matrix() {

}

// print out the current matrix
void Matrix::print() {
    for (int i = 0; i < this->rows; i++) {
        for (int j = 0; j < this->cols; j++) {
            cout << data[i * this->cols + j] << " "; 
        }
        cout << endl;
    }
}

// return the number of rows of the current matrix
int Matrix::getRows() {
    return this->rows;
}

// return the number of cols of the current matrix
int Matrix::getCols() {
    return this->cols;
}

// using operate () to access the element of Matrix(row, col)
double& Matrix::operator()(int row, int col) {
    if (row >= this->rows) {
        throw "input row exceed the rows of the matrix";
    }

    if (col >= this->cols) {
        throw "input column exceed the columns of the matrix";
    }
    
    return this->data[row * this->cols + col];
}

// return result of current matrix matrix-multiply input B
Matrix Matrix::operator* (Matrix& B) {

    if (this->cols != B.rows) {
        throw "Columns of A must be equal to rows of B";
    }

    Matrix Re(this->rows, B.cols, 0.0); 

    for (int r = 0; r < this->rows; r++) {
        for (int c = 0; c < B.cols; c++) {
            double total = 0.0;        // sum of shared dimension
            for (int d = 0; d < this->cols; d++) {
                total += this->data[r * this->cols + d] * B(d, c);
            }
            Re(r, c) = total;
        }
    }

    return Re;  
}


// transpose the currrent matrix  
void Matrix::Transpose() {
    double *newData = (double *) malloc(sizeof(double) * this->total); 
    
    for (int i = 0; i < this->rows; i++) {
        for (int j = 0; j < this->cols; j++) {
            newData[j * this->rows + i] = this->data[i * this->rows + j];
        }
    }
    
    int t = this->cols; 
    this->cols = this->rows;
    this->rows = t;

    double* tp = this->data; 
    this->data = newData; 
    free(tp);                          // free the unused memory 
}


// return the result of Matrix A matrix-multiply Matrix B  
Matrix MulMatrix(Matrix& A, Matrix& B) {

    if (A.getCols() != B.getRows()) {
        throw "Columns of A must be equal to rows of B";
    }

    int oRows = A.getRows(); 
    int oCols = B.getCols();
    int shareDim = A.getCols();
    Matrix Re(oRows, oCols, 0.0); 

    for (int r = 0; r < oRows; r++) {
        for (int c = 0; c < oCols; c++) {   
            double total = 0; 
            for (int d = 0; d < shareDim; d++) {
                total += A(r, d) * B(d, c);
            }
            Re(r, c) = total;
        }
    }

    return Re;  
}

// transpose the input Matrix A
Matrix TransposeMatrix(Matrix& A) {
    Matrix Re(A.getCols(), A.getRows(), 0.0);
    
    for (int i = 0; i < A.getRows(); i++) {
        for (int j = 0; j < A.getCols(); j++) {
            Re(j,i) = A(i, j);
        }
    } 

    return Re;
}; 
