#ifndef Matrix2D_h
#define Matrix2D_h

using numType = double;

class Matrix2D
{
    private:
        int numRows;
        int numColumns;
        numType** arr;
        
    public:
        //Basic Constructor, generates an array of zeros
        Matrix2D(int rows, int columns);
        
        //Destructor
        ~Matrix2D();
        
        //Prints the array
        void print() const;
        
        //Get size of the Matrix
        int getRows() const { return numRows; }
        int getColumns() const { return numColumns; }
        
        //Sets a specific value in the array
        void set(double value, int r, int c);
        
        //Gets the value at a specific index in the array
        numType get(int r, int c) const;
        
        //Returns the dot product of this matrix and the provided matrix. [This Matrix][Provided Matrix]
        Matrix2D dot(const Matrix2D &rMatrix) const;
        
        //Returns the transposed matrix
        Matrix2D transpose() const;
};

#endif