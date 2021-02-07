#ifndef MATRIX_H
#define MATRIX_H 

using namespace std; 

class Matrix {
    private: 
        int rows;                                // #row of the matrix             
        int cols;                                // #col of the matrix 
        int total;                               // total elements 
        double* data;                            // data storing the numbers

    public: 
        Matrix(int rows, int cols, double init); // Constructor
        ~Matrix();                               // Destructor        
        void print();                            // print out current matrix
        int getRows();                           // get number of rows
        int getCols();                           // get number of cols
        double& operator() (int row, int col);   // get element of Matrix
        Matrix operator* (Matrix& B);            // matrix multiply
        void Transpose();                        // matrix transpose 
};

// matrix multiply with Matrix A and B
Matrix MulMatrix(Matrix& A, Matrix& B);

// matrix transpose input Matrix A 
Matrix TransposeMatrix(Matrix& A); 

#endif  //MATRIX_H

