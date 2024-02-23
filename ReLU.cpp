#include "ReLU.h"
#include <iostream>
using namespace std;

Matrix2D ReLU::forwardProp(const Matrix2D& inp)
{
    //Save input
    setInput(inp);
    
    //Create output Matrix
    Matrix2D output(inp.getRows(), inp.getColumns());
    
    //Update values based of ReLU Activation function
    for(int r = 0; r < inp.getRows(); r++)
    {
        for(int c = 0; c < inp.getColumns(); c++)
        {
            //ReLU function
            if(inp.get(r,c) > 0)
            {
                output.set(inp.get(r,c), r, c);
            }
            else
            {
                output.set(0, r, c);
            }
        }
    }
    return output;
}

Matrix2D ReLU::backProp(const Matrix2D& outputGradient, double learnRate)
{
    outputGradient.print();
    //Create the input gradient matrix
    Matrix2D inputGradient(outputGradient.getRows(), outputGradient.getColumns());
    
    //Update values based of ReLU Activation function
    for(int r = 0; r < outputGradient.getRows(); r++)
    {
        for(int c = 0; c < outputGradient.getColumns(); c++)
        {
            //Derivitive ReLU
            double value = (int)(getInput().get(r,c) > 0) * outputGradient.get(r,c);
            inputGradient.set(value, r, c);
        }
    }
    
    outputGradient.print();
    return inputGradient;
}