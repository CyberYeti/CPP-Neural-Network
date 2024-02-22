#ifndef ReLU_h
#define ReLU_h

#include "Layer.h"

class ReLU : public Layer
{
    public:
        Matrix2D forwardProp(const Matrix2D& inp);
        
        Matrix2D backProp(const Matrix2D& outputGradient, double learnRate);
};

#endif