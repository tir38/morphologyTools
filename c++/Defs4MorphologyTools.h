#ifndef DEFS4MORPHOLOGYTOOLS_H
#define DEFS4MORPHOLOGYTOOLS_H

using namespace std;
#include <stdint.h>
#include <vector>



struct UMBRA {
    //class methods
    UMBRA();                                            // constructor
    UMBRA(int col, int row, int height);    // constructor w/ size inputs
    ~UMBRA();                                           // destructor

    // member variables
    int colDim_;
    int rowDim_;
    int heightDim_;
    std::vector<int> umbra_; // 1D vector containing row-major (then column, then height) representation of 3D matrix
};



struct IMAGE{
    // class methods
    IMAGE();                            // constructor with no inputs
    IMAGE(int col, int row);    // constructor with dimension inputs
    ~IMAGE();                           // destructor

    IMAGE& operator= (const IMAGE& rhs){ // define '=' operator
        this->image_    = rhs.image_;
        this->colDim_   = rhs.colDim_;
        this->rowDim_   = rhs.rowDim_;
        return *this;
    }

    // member variables
    int colDim_;                    // column dimension; needed to resize 1D vector into 2D image
    int rowDim_;                    // row dimension; needed to resize 1D vector into 2D image
    std::vector<int> image_;    // vector to store 2D image in row-major order
};

#endif // DEFS4MORPHOLOGYTOOLS_H
