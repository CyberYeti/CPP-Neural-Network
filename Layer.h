#ifndef Layer_h
#define Layer_h

#include "Matrix2D.h"

class Layer
{
    private:
        Matrix2D input;
        
    public:
        Layer(): input(1,1) {};
    
        Matrix2D forwardProp(const Matrix2D& inp)
        {
            input = inp;
            return Matrix2D(1, 1);
        }
        
        Matrix2D backProp(const Matrix2D& outputGradient, double learnRate)
        {
            return Matrix2D(1,1);
        }
        
        Matrix2D& getInput() { return input; }
        
        void setInput(const Matrix2D& inp) { input = inp; }
};

#endif