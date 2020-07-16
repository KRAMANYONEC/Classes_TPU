#include <iostream>

#include "ClosedFigure.h"
#include "Point.h"

class Pentangle : public ClosedFigure
{
public:
    Pentangle(double &, double &  // Coordinates of pentagon's center
            , double &, double &  // Coordinates of one of pentagon's vertexes
            , double &);  // radius of circumscribed circle
    ~Pentangle ();
    // Method, calculating coordinates of
    // undefined vertexes 
    void calc_coords();
    // Method, returning 1 if point belongs
    // to pentagon
    bool is_point_belong ( double &, double &);
    // Method, returning 1 if pentagon crosses
    // the X axis
    bool is_cross_x();
    //Method, returning 1 if pentagon crosses 
    // the Y axis
    bool is_cross_y();
    // Method, calculating area of pentangle
    double calc_area();
private:
    Point _center;
    Point _vertex;
    double _R;
    double _vertexCoords [5][2];
};

    
    
