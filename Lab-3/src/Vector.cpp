#include <iostream>

#include "../include/Vector.h"

// The default constructor implementation
Vector::Vector() {
    for ( int i = 0; i < 3; i++) {
        _coordinates[i] = 0;
    }
}

// The constructor with parameters implementation
Vector::Vector (double * coords) {
    for ( int i = 0; i < 3; i++) {
    _coordinates[i] = coords[i];
    }
}

// The copy constructor implementation
Vector::Vector(const Vector & vector) {
    for ( int i = 0; i < 3; i++) {
    _coordinates[i] = vector._coordinates[i];
    }
}

Vector:: ~Vector() {} // Default destructor

// Output overload
std::ostream& operator << (std::ostream &out, const Vector &vector)
{
    out << "{";
    for (int i = 0; i < 2; i++) {
    out << vector._coordinates[i] << "; ";
    }
    out << vector._coordinates[2] << "}" << '\n';
    return out;
}

// Sum of vectors
Vector operator + (const Vector v1, const Vector v2) {
    Vector vsum;
    for (int i = 0; i < 3; i++) {
        vsum._coordinates[i] = v1._coordinates[i] + v2._coordinates[i];
    }
    return vsum;
}

// Difference of vectors
Vector operator - (const Vector v1, const Vector v2) {
    Vector vdif;
    for (int i = 0; i < 3; i++) {
        vdif._coordinates[i] = v1._coordinates[i] - v2._coordinates[i];
    }
    return vdif;
}

// Vector, multiplied by scalar
Vector operator * (const Vector v1, const double k) {
    Vector vnew;
    for (int i = 0; i < 3; i++) {
        vnew._coordinates[i] = v1._coordinates[i] * k;
    }
    return vnew;
}

// Scalar product of vectors
double operator * (const Vector v1, const Vector v2) {
    double scalarCross = 0;
    for (int i = 0; i < 3; i++) {
        scalarCross = scalarCross + (v1._coordinates[i] * v2._coordinates[i]);
    }
    return scalarCross;
}

// Vector product of vectors
Vector operator *= (const Vector v1, const Vector v2) {
    Vector vectorCross;
    
        vectorCross._coordinates[0] = (v1._coordinates[2] * v2._coordinates[1])
                                    - (v1._coordinates[1] * v2._coordinates[2]);
                                    
        vectorCross._coordinates[1] = (v1._coordinates[0] * v2._coordinates[2])
                                    - (v1._coordinates[2] * v2._coordinates[0]);
        vectorCross._coordinates[2] = (v1._coordinates[1] * v2._coordinates[0])
                                    - (v1._coordinates[0] * v2._coordinates[1]);
    return vectorCross;
}

