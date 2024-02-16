/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, OCaml, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
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