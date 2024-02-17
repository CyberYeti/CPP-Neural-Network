#include <iostream>
#include "Matrix2D.h"
using namespace std;

int main()
{
    Matrix2D mat1(2,3);
    mat1.print();
    cout << endl;
    
    Matrix2D mat2(3,1);
    mat2.print();
    cout << endl;
    
    Matrix2D dot = mat1.dot(mat2);
    dot.print();

    return 0;
}