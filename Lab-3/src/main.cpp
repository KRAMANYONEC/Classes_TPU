/* This program is realization of simple 
 * operations with 3-dimensional vectors.
 * It provides all basic operations and
 * user menu with multiple choice
 */

#include <iostream>
#include "../include/Vector.h"

int main() {
    double coords[3]; // Coordinates of vector
    double k;   // Scalar
    double scalarCross; // The result of scalarCross
    // Menu variables
    int choice; 
    std::string isContinue = "Yes";
    
    do {
        // Show the menu
        std::cout << "Выберите интересующую операцию :" << '\n'
              << "1. Сумма векторов" << '\n'
              << "2. Разность векторов" << '\n'
              << "3. Умножение вектора на скаляр" << '\n'
              << "4. Скалярное произведение векторов" << '\n'
              << "5. Векторное произведение векторов" << '\n';
              
        std::cin >> choice;
              
        switch(choice) {
            case 1: { 
    
                std::cout << "Введите координаты первого вектора" << '\n';
                for (int i = 0; i < 3; i++) {
                    std::cin >> coords[i];
                }
                Vector v1(coords);
                
                std::cout << "Введите координаты второго вектора" << '\n';
                for (int i = 0; i < 3; i++) {
                    std::cin >> coords[i];
                }
                Vector v2(coords);
                
                Vector vSum = v1 + v2;
                std::cout << "Вектор суммы: " << vSum
                          << '\n' << "Продолжить (Yes/No)?" << '\n';
                std::cin >> isContinue;
                break;
            }
        
            case 2: { 
                std::cout << "Введите координаты первого вектора" << '\n';
                for (int i = 0; i < 3; i++) {
                    std::cin >> coords[i];
                }
                Vector v1(coords);
                
                std::cout << "Введите координаты второго вектора" << '\n';
                for (int i = 0; i < 3; i++) {
                    std::cin >> coords[i];
                }
                Vector v2(coords);
                
                Vector vDif = v1 - v2;
                std::cout << "Вектор разности: " << vDif
                          << '\n' << "Продолжить?" << '\n';
                std::cin >> isContinue;
                break;
            }
            
            case 3: {
                std::cout << "Введите координаты вектора" << '\n';
                for (int i = 0; i < 3; i++) {
                    std::cin >> coords[i];
                }
                Vector v1(coords);
                
                std::cout << "Введите коэффициент" << '\n';
                std::cin >> k;
                
                Vector vNew = v1 * k;
                std::cout << "Вектор, умноженный на коэффициент: "
                          << vNew << '\n' << "Продолжить?" << '\n';
                std::cin >> isContinue;
                break;
            }
        
            case 4: {
                std::cout << "Введите координаты первого вектора" << '\n';
                for (int i = 0; i < 3; i++) {
                    std::cin >> coords[i];
                }
                Vector v1(coords);
                
                std::cout << "Введите координаты второго вектора" << '\n';
                for (int i = 0; i < 3; i++) {
                    std::cin >> coords[i];
                }
                Vector v2(coords);
                
                scalarCross = v1 * v2;
                std::cout << "Скалярное произведение первого и второго векторов равно "
                          << scalarCross << '\n' << '\n' << "Продолжить?" << '\n';
                std::cin >> isContinue;
                break;
            }
                
            case 5: {
                std::cout << "Введите координаты первого вектора" << '\n';
                for (int i = 0; i < 3; i++) {
                    std::cin >> coords[i];
                }
                Vector v1(coords);
                
                std::cout << "Введите координаты второго вектора" << '\n';
                for (int i = 0; i < 3; i++) {
                    std::cin >> coords[i];
                }
                Vector v2(coords);
                
                Vector vCross = v1 *= v2;
                std::cout << "Векторное произведение первого и второго векторов: "
                          << vCross << '\n' << "Продолжить?" << '\n';
                std::cin >> isContinue;
                break;
            }
        } 
    }  while  (isContinue == "Yes");           
    
    return 0;
}
