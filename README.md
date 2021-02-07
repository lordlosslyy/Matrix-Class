## Execution 	
```make```

## File Description

### Main.cpp 
Create the matrix and do the testing 

### Matrix.h 
Header file of matrix, define function transpose, getRow etc. 

### Matrix.cpp 
Implementation of functions in Matrix class and two function `MulMatrix` and `TransposeMatrix`


## Note

I create two different matrix multiplications and transpositions. The main difference is the number of input matrices and return types. One multiplication and transposition are implemented in Matrix class. And the others are implemented outside the class. 
```
class  Matrix {
	Matrix  operator* (Matrix&  B); // matrix multiply
	void  Transpose(); // matrix transpose
}
```

```
// matrix multiply with Matrix A and B
Matrix  MulMatrix(Matrix&  A, Matrix&  B);

// matrix transpose input Matrix A
Matrix  TransposeMatrix(Matrix&  A);
```
