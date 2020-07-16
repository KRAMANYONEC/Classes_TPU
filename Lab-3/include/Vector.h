#include <iostream>

class Vector
{
public:
    Vector(); // default constructor
    Vector(double *); // constructor with parameters
    Vector(const Vector &); // copy constructor
    ~Vector();
    // Output overload
    friend std::ostream& operator << (std::ostream &out, const Vector &vector);
    // Sum overload
    friend Vector operator + (const Vector v1, const Vector v2);
    // Difference overload
    friend Vector operator - (const Vector v1, const Vector v2);
    // Multiplication overload (vector multiplied by scalar)
    friend Vector operator * (const Vector v1, const double k);
    // Multiplication overload (scalar product of vectors)
    friend double operator * (const Vector v1, const Vector v2);
    // Multiplication overload (vector product of vectors)
    friend Vector operator *= (const Vector v1, const Vector v2);
private:
    double _coordinates [3];
};
