#include "Matrix2D.h"
#include <iostream>

using namespace std;

Matrix2D::Matrix2D(int rows, int columns)
{
    numRows = rows;
    numColumns = columns;
    arr = new numType*[rows];
    
    //Setup the second set of arrays and set values to 0
    for(int r = 0; r < numRows; r++)
    {
        arr[r] = new numType[columns];
        for(int c = 0; c < numColumns; c++)
        {
            arr[r][c] = 0;
        }
    }
}

Matrix2D::~Matrix2D()
{
    //Does this create a memory leak?
    delete[] arr;
}

void Matrix2D::print() const
{
    cout << "[";
    for(int r = 0; r < numRows; r++)
    {
        //Front space formatting
        if(r != 0)
        {
            cout << " ";
        }
        
        //Print inside array
        cout << "[";
        for(int c = 0; c < numColumns; c++)
        {
            cout << arr[r][c];
            if(c+1 != numColumns)
            {
                cout << " ";
            }
        }
        cout << "]";
        
        //line end formatting
        if(r+1 != numRows)
        {
            cout << endl;
        }
    }
    cout << "]" << endl;
}


void Matrix2D::set(double value, int r, int c)
{
    arr[r][c] = value;
}

numType Matrix2D::get(int r, int c) const
{
    return arr[r][c];
}

Matrix2D Matrix2D::dot(const Matrix2D &rMatrix) const
{
    //Check if it is a valid dot product
    if(numColumns != rMatrix.numRows)
    {
        cout << "Invalid matrix sizes! Attempted to dot ";
        cout << "(" << numRows << "," << numColumns << ")" << " and ";
        cout << "(" << rMatrix.numRows << "," << rMatrix.numColumns << ") matrices." << endl;
        return Matrix2D(1,1);
    }
    
    int numMulti = numColumns; //Represents the number of multiplications needed per number.
    Matrix2D resultant = Matrix2D(numRows, rMatrix.numColumns);
    //Basic Matrix multiplication
    for(int r = 0; r < numRows; r++)
    {
        for(int c = 0; c < rMatrix.numColumns; c++)
        {
            double value = 0;
            for(int i = 0; i < numMulti; i++)
            {
                value += arr[r][i] * rMatrix.get(i, c);
            }
            resultant.arr[r][c] = value;
        }
    }
    return resultant;
}

Matrix2D Matrix2D::transpose() const
{
    //Create a matrix with swapped dimensions
    Matrix2D transposed(numColumns, numRows);
    
    //Set values
    for(int r = 0; r < numRows; r++)
    {
        for(int c = 0; c < numColumns; c++)
        {
            transposed.arr[c][r] = arr[r][c];
        }
    }
    
    return transposed;
}