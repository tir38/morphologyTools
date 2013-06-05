#ifndef DEFS4MORPHOLOGYTOOLS_H
#define DEFS4MORPHOLOGYTOOLS_H

using namespace std;
#include <stdint.h>
#include <vector>



struct UMBRA { // for gradient vehicle kernel
    //class methods
    UMBRA();                                // constructor

    UMBRA(uint8_t col, uint8_t row, uint8_t height); // constructor w/ size inputs

    ~UMBRA();                               // destructor

//    UMBRA& operator=(const UMBRA& rhs){
//        // don't need this yet
//    }

    // member variables
    int colDim_;
    int rowDim_;
    int heightDim_;
    std::vector<uint8_t> umbra; // 1D vector containing row-major (then column, then height) representation of 3D matrix
};



struct MAP{  // for single vehicle kernel or single configuration map
    // class methods
    MAP();                      // constructor with no inputs
    MAP(uint8_t col, uint8_t row);    // constructor with dimension inputs
    ~MAP();                     // destructor

    MAP& operator= (const MAP& rhs){ // define '=' operator
        this->map       = rhs.map;
        this->colDim_   = rhs.colDim_;
        this->rowDim_   = rhs.rowDim_;
        return *this;
    }

    // member variables
    std::vector<uint8_t> map;   // vector to store 2D map in row-major order
    int colDim_;                // column dimension; needed to resize 1D 'map' into 2D
    int rowDim_;                // row dimension; needed to resize 1D 'map' into 2D
};

#endif // DEFS4MORPHOLOGYTOOLS_H
