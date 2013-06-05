#include "Defs4MorphologyTools.h"
using namespace std;

// --------------------- MAP methods
MAP::MAP(){                     // MAP constructor with no input
    this->theta = 0;
    this->map.empty();
    this->colDim_ = 0;
    this->rowDim_ = 0;
}

MAP::MAP(uint8_t col, uint8_t row){    // MAP constructor with dimension input
    this->theta = 0;
    this->map.resize(col*row, 0);
    this->colDim_ = col;
    this->rowDim_ = row;
}

MAP::~MAP(){                    // MAP descructor
}



// --------------------- UMBRA methods
UMBRA::UMBRA(){                                 // constructor, no inputs
    this->colDim_ = 0;
    this->heightDim_ = 0;
    this->rowDim_ = 0;
    this->theta = 0;
    this->umbra.empty();
}

UMBRA::UMBRA(uint8_t col, uint8_t row, uint8_t height){  // construcor, with dimension input
    this->colDim_ = col;
    this->heightDim_ = height;
    this->rowDim_ = row;
    this->theta = 0;
    this->umbra.resize(col*row*height);
}

UMBRA::~UMBRA(){                                // destructor
}
