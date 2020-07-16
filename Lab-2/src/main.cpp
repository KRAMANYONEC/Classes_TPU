#include <iostream>

#include "../include/Pentangle.h"

int main () {
    // Parameters of pentagon
    double xCenter;
    double yCenter;
    double xVertex;
    double yVertex;
    double radius;
    
    // Some point 
    double xPoint;
    double yPoint;
    
    // Input pentagon's parameters
    std::cout << "Введите координату х центра ";
    std::cin >> xCenter;
    std::cout << "Введите координату y центра ";
    std::cin >> yCenter;
    std::cout << "Введите координату х вершины ";
    std::cin >> xVertex;
    std::cout << "Введите координату y вершины ";
    std::cin >> yVertex;
    std::cout << "Введите радиус описанной окружности ";
    std::cin >> radius;
    
    // Create an instance of Pentangle
    Pentangle pentangle (xCenter, yCenter
                     , xVertex, yVertex
                     , radius);
    
    // Calculate other coordinates 
    // of pentagon's vertexes
    pentangle.calc_coords();
    
    // Input point's parameters
    std::cout << "Введите координату х точки ";
    std::cin >> xPoint;
    std::cout << "Введите координату y точки ";
    std::cin >> yPoint;
    
    if(pentangle.is_point_belong(xPoint, yPoint)) {
        std::cout << "YES" << '\n';
    } else std::cout << "NO" << '\n';
    
    if (pentangle.is_cross_x()) {
        std::cout << "Figure crosses the X axis" << '\n';
    } else std::cout << "Figure doesn't cross the X axis" << '\n';
    
     if (pentangle.is_cross_y()) {
        std::cout << "Figure crosses the Y axis" << '\n';
    } else std::cout << "Figure doesn't cross the Y axis" << '\n';
    
    pentangle.calc_area();
        
    return 0;
}
