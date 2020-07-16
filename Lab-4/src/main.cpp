/*
Дана действительная матрица, содержащая m строк и n столбцов. 
Матрица размещается в памяти динамически с помощью операции new, 
значения n, m вводится по запросу с клавиатуры. 
В конце работы программы освободить выделенную память. 
Вывести исходную матрицу. Через перегрузку операторов реализовать
вычитание матриц, транспонирование матрицы. 
*/

#include <iostream>
#include "../include/Matrix.h"

int main() {
    int n;  // Number of columns
    int m;  // Number of rows
    int a;  // Matrix element
    
    std::cout << "Введите число строк матрицы: ";
    std::cin >> m;
    std::cout << "Введите число столбцов матрицы: ";
    std::cin >> n;
    
    // The first matrix input
    Matrix matrix1(m, n);
    std::cout << "Введите элементы первой матрицы:" << '\n';
    for (int i = 0; i < m; i++) {
        for (int k = 0; k < n; k++) {
            std::cin >> a;
            matrix1.fill_matrix (&i, &k, &a);
        }
    }
    std::cout << '\n' << "Первая матрица:";
    matrix1.print_matrix();
    
    // The second matrix input
    Matrix matrix2(m,n);
    std::cout << "Введите элементы второй матрицы:" << '\n';
    for (int i = 0; i < m; i++) {
        for (int k = 0; k < n; k++) {
            std::cin >> a;
            matrix2.fill_matrix (&i, &k, &a);
        }
    }
    std::cout << '\n' << "Вторая матрица:";
    matrix2.print_matrix();
    
    // Matrix difference
    Matrix matrixDif = matrix1 - matrix2;
    std::cout  << '\n' << "Разность первой и второй матриц:";
    matrixDif.print_matrix();  
    
    // The first matrix transpose
    Matrix matrixT = ! matrix1;
    std::cout << '\n' << "Транспонированная первая матрица:";
    matrixT.print_matrix();

    return 0;
}
