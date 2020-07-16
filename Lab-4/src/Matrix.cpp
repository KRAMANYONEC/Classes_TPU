#include <iostream>

#include "../include/Matrix.h"

// Basic matrix destructor
Matrix::Matrix ( int m, int n) {
    // Setting order of a matrix
    _n = n;
    _m = m;
    
    // Memory alotment
    _ptrMatrix = new int * [_m];
    for (int i = 0; i < _m; i++) {
        _ptrMatrix[i] = new int [_n];
    }
}

// Transposed matrix constructor
// ( in case, you need to get transposed matrix
// pass 0 as the value of flag, in other cases
// pass 1 )
Matrix::Matrix ( int m, int n, bool flag) {
    // Setting order of a matrix
    if (flag) {
    _n = n;
    _m = m;
    }
    if (!flag) {
    _n = m;
    _m = n;
    }
    
    // Memory alotment
    _ptrMatrix = new int * [_m];
    for (int i = 0; i < _m; i++) {
        _ptrMatrix[i] = new int [_n];
    }
}

Matrix:: ~Matrix() {
    // Memory deallocation
    for (int i = 0; i < _m; i++) {
        delete [] _ptrMatrix[i];
    }
}

// Matrix output
void Matrix::print_matrix() {
    std::cout << '\n';
    for (int i = 0; i < _m; i++) {
        for (int k = 0; k < _n; k++) {
            std::cout << _ptrMatrix[i][k] << " ";
        }
        std::cout << '\n';
    }
}

// Matrix elements setting
void Matrix::fill_matrix ( int * i, int * k, int * a ) {
            _ptrMatrix[*i][*k] = *(a);
}

// Difference overload
Matrix operator - (const Matrix &matrix1, const Matrix &matrix2)
{
    int m = matrix2._m;
    int n = matrix2._n;
    Matrix matrixDif(m, n);
    
   for (int i = 0; i < m; i++) {
       for (int k = 0; k < n; k++) {
           matrixDif._ptrMatrix[i][k] = matrix1._ptrMatrix[i][k]
                                      - matrix2._ptrMatrix[i][k];
       }
   }
   return matrixDif;
}
   
// Transpose overload
Matrix operator ! (const Matrix &matrix1)
{   int m = matrix1._m;
    int n = matrix1._n;
    Matrix matrixT (m, n, 0);
    for (int i = 0; i < n; i++) {
       for (int k = 0; k < m; k++) {
           matrixT._ptrMatrix[i][k] = matrix1._ptrMatrix[k][i];
       }
   }
   return matrixT;
}
