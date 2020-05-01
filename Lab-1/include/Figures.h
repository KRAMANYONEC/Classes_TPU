#include <iostream>

class Figures 
{
public:
    Figures(double &, double &  // Coordinates of pentagon's center
          , double &, double &  // Coordinates of one of pentagon's vertexes
          , double &);  // radius of circumscribed circle
    ~Figures ();
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
private:
    double _xC;
    double _yC;
    double _xV1;
    double _yV1;
    double _R;
    double _vertexCoords [5][2];
};

    
    
