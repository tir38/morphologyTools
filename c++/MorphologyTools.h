#ifndef MORPHOLOGYTOOLS_H
#define MORPHOLOGYTOOLS_H

using namespace std;
#include <vector>
#include <stdint.h>
#include "Defs4MorphologyTools.h"

class MorphologyTools
{
public:
    MorphologyTools(); // constructor

    ~MorphologyTools(); // destructor

    bool myFunct();

    UMBRA* umbraOf(std::vector<uint8_t> inputMap, int xDim, int yDim, int zDim);

    MAP* topSurfaceOf(UMBRA* inputUmbra, int xDim, int yDim, int zDim);
};
#endif // MORPHOLOGYTOOLS_H

