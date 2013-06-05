#include "Defs4MorphologyTools.h"
using namespace std;

// --------------------- IMAGE methods
IMAGE::IMAGE(){                     // IMAGE constructor with no input
    this->image_.empty();
    this->colDim_ = 0;
    this->rowDim_ = 0;
}

IMAGE::IMAGE(int col, int row){    // IMAGE constructor with dimension input
    this->image_.resize(col*row, 0);
    this->colDim_ = col;
    this->rowDim_ = row;
}

IMAGE::~IMAGE(){                    // IMAGE descructor
}



// --------------------- UMBRA methods
UMBRA::UMBRA(){                                 // constructor, no inputs
    this->colDim_ = 0;
    this->heightDim_ = 0;
    this->rowDim_ = 0;
    this->umbra_.empty();
}

UMBRA::UMBRA(int col, int row, int height){  // construcor, with dimension input
    this->colDim_ = col;
    this->heightDim_ = height;
    this->rowDim_ = row;
    this->umbra_.resize(col*row*height);
}

UMBRA::~UMBRA(){                                // destructor
}
