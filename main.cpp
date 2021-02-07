#include <iostream>
#include "Matrix.h"
using namespace std;

int main () {
    // Initialize Matrix A 
    Matrix A(2, 3, 1.0); 
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 3; j++) {
            A(i, j) = i * 3 + j;
        }
    }

    // Initialize Matrix B
    Matrix B(3, 4, 1); 
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 4; j++) {
            B(i, j) = j + 1;
        }
    }

    // print out Matrix A and B 
    A.print();
    cout << endl;
    B.print();
    cout << endl; 

    // testing the operation * 
    Matrix C = A * B; 
    C.print(); 
    cout << endl;

    // testing the transpose in class 
    C.Transpose();
    C.print();
    cout << endl;

    // testing the function MulMatrix 
    Matrix E = MulMatrix(A, B); 
    E.print();
    cout << endl;

    // testing the function TransposeMatrix 
    Matrix F = TransposeMatrix(E); 
    F.print(); 
 
    return 0;
}
