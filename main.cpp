#include <iostream>
#include "Matrix2D.h"
#include "ReLU.h"

using namespace std;

int main()
{
    //Create a test matrix
    Matrix2D mat1(2,3);
    int counter = -3;
    for(int r = 0; r < 2; r++)
    {
        for(int c = 0; c < 3; c++)
        {
            mat1.set(counter, r, c);
            counter++;
        }
    }
    mat1.print();
    cout << endl;

    
    //Test ReLU Layer
    ReLU relu;
    Matrix2D ReLUOut = relu.forwardProp(mat1);
    ReLUOut.print();
    
    
    return 0;
}