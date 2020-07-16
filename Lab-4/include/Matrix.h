#include <iostream>

class Matrix
{
public:
    Matrix ( int, int );  // Basic matrix constructor
    Matrix ( int, int, bool );  // Transposed matrix constructor
    ~Matrix ();
    void fill_matrix( int *, int *, int * );
    void print_matrix();
    // Matrix difference overload
    friend Matrix operator - (const Matrix &, const Matrix &);
    // Matrix transpose overload
    friend Matrix operator ! (const Matrix &);
private:
    int _n; // number of columns
    int _m; // number of rows
    int ** _ptrMatrix; // matrix elements
};
