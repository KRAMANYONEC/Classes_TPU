#include <iostream>
#include <cmath> // included for cos, sin and std::abs
#include <vector>
#include <algorithm> // included for sort

#include "../include/Pentangle.h"

// Constructor, setting all the nessecery variables
// for defenition a pentagon
Pentangle::Pentangle (double & xCenter, double & yCenter
                , double & xVertex, double & yVertex
                , double & radius)
{
    _center.x = xCenter;
    _center.y = yCenter;
    _vertex.x = xVertex;
    _vertex.y = yVertex;
    _R = radius;
}

Pentangle::~Pentangle () {}

void Pentangle::calc_coords() 
{
    // Coordinates of the current vertex,
    // starting point for rotation,
    // in system of pentagon's center
    double xTemp = _vertex.x - _center.x;
    double yTemp = _vertex.y - _center.y;
    
    _vertexCoords[0][0] = _vertex.x;
    _vertexCoords[0][1] = _vertex.y;
    
    // The rotation angle
    double theta = 1.25664;
    
    for (int i = 1; i < 5; i++) {
        // Calculate coordinates (in initial system)
        //through the rotation transformation
        _vertexCoords[i][0] = (xTemp*cos(theta) 
                            + yTemp*sin(theta)) + _vertex.x;
        _vertexCoords[i][1] = (-xTemp*sin(theta) 
                            + yTemp*cos(theta)) + _vertex.y;
        
        // Set the next vertex
        xTemp = _vertexCoords[i][0] - _vertex.x;
        yTemp = _vertexCoords[i][1] - _vertex.y;
    }
    
    for (int i = 0; i < 5; i++) {
        std::cout << _vertexCoords[i][0] << " " 
                  << _vertexCoords[i][1] << '\n';
    }
}

bool Pentangle::is_point_belong (double & xPoint
                             , double & yPoint)  
{
    // Vector, containing 2 y coordinates
    // for comparison with yPoint
    std::vector<double> goodPoints;
    
    // Calculated value of y coordinate
    // of pentagone's side
    double yLine;
    
    for ( int i = 0; i < 4; i++) {
        // Is point located between two vertexes
        // on X axis
        if (( xPoint > _vertexCoords[i][0] && xPoint < _vertexCoords[i+1][0]) 
          || (xPoint < _vertexCoords[i][0] && xPoint > _vertexCoords[i+1][0])) 
        {
            // Calculate value from the line's equation
            yLine = ((_vertexCoords[i][1] - _vertexCoords[i+1][1]) 
                          * (xPoint - _vertexCoords[i][0])
                          / (_vertexCoords[i][0] - _vertexCoords[i+1][0])) 
                          + _vertexCoords[i][1];
                          
            // Add value to a vector              
            goodPoints.push_back(yLine);
        }
        // Is X coordinati of pont is equal
        // to x cooedinate of a vertex
        if (xPoint == _vertexCoords[i][0]) 
        {
            yLine = _vertexCoords[i][1];
            goodPoints.push_back(yLine);
        }
    }
    
    // The same procedure for last vertexes
    if (( xPoint > _vertexCoords[4][0] && xPoint < _vertexCoords[0][0]) 
      || (xPoint < _vertexCoords[4][0] && xPoint > _vertexCoords[0][0])) 
        {
            yLine = ((_vertexCoords[4][1] - _vertexCoords[0][1]) 
                          * (xPoint - _vertexCoords[4][0])
                          / (_vertexCoords[4][0] - _vertexCoords[0][0]))
                          + _vertexCoords[4][1];
            goodPoints.push_back(yLine);
        }
        if (xPoint == _vertexCoords[4][0])
        {
            yLine = _vertexCoords[4][1];
            goodPoints.push_back(yLine);
        }
        // The comparison constant
        const double val = 1e-6;
        
        // Sort vector for a good comparison
        if (goodPoints.size() == 2) {
        std::sort(goodPoints.begin(), goodPoints.end());
        //std::cout << goodPoints[0] << " " << goodPoints[1] << '\n';
        }
        
        // Is point belong to "good interval"
        // of Y axis
        if (goodPoints.size() == 2) {
            if (((yPoint > goodPoints[0] 
            && yPoint < goodPoints[1])) 
            || (std::abs(yPoint - goodPoints[0]) < val)
            || (std::abs(yPoint - goodPoints[1]) < val)) 
            {
                //std::cout << '\n' <<  std::abs(yPoint - goodPoints[0]) << '\n';
                //std::cout << '\n' <<  std::abs(yPoint - goodPoints[1]) << '\n';
                //std::cout << "Yes" << '\n';
                return 1; 
            } else 
            {
                //std::cout << "No" << '\n';
                return 0;
            }
        } else 
        {
            //std::cout << "No" << '\n';
            return 0;
        }
}

// Method is based on finding maximum and 
// minimum Y coordinate of pentangle. If 
// their signs are different, figure crosses 
// the X axis
bool Pentangle::is_cross_x() 
{   
    double maxY = _vertexCoords[0][1];
    double minY = _vertexCoords[0][1];
    
    for (int i = 1; i < 5; i++) {
        if (maxY < _vertexCoords[i][1]) {
        maxY = _vertexCoords[i][1]; 
        }
        if (_vertexCoords[i][1] < minY) {
            minY = _vertexCoords[i][1];
        }
    }
    if (minY <= 0 && maxY >= 0) {
        return 1;
    } else return 0;
}

// The same logic as is_cross_x()
bool Pentangle::is_cross_y() 
{   
    double maxX = _vertexCoords[0][0];
    double minX = _vertexCoords[0][0];
    
    for (int i = 1; i < 5; i++) {
        if (maxX < _vertexCoords[i][0]) {
        maxX = _vertexCoords[i][0]; 
        }
        if (_vertexCoords[i][0] < minX) {
            minX = _vertexCoords[i][0];
        }
    }
    if (minX <= 0 && maxX >= 0) {
        return 1;
    } else return 0;
}

// Return area of a regular pentagon
// using one of it's sides
double Pentangle::calc_area()
{
    // A side of pentangle
    double a = sqrt(((_vertexCoords[0][0] - _vertexCoords[1][0]) 
                   * (_vertexCoords[0][0] - _vertexCoords[1][0])) 
                   + ((_vertexCoords[0][1] - _vertexCoords[1][1]) 
                   * (_vertexCoords[0][1] - _vertexCoords[1][1])));
    // The area of pentangle
    double s = (5./2.) * a 
             * sqrt(((a / (2*sin(3.14/5)))
             * (a / (2*sin(3.14/5)))) - a*a/4.);
             std::cout <<'\n' << a << " "  << "Area is " << s;
    return s;
}
 
