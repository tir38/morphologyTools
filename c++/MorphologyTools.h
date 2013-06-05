#ifndef MORPHOLOGYTOOLS_H
#define MORPHOLOGYTOOLS_H

using namespace std;
#include <vector>
#include <stdint.h>
#include "Defs4MorphologyTools.h"


    UMBRA* umbraOf(std::vector<int> inputImage, int xDim, int yDim, int zDim);

    IMAGE* topSurfaceOf(UMBRA* inputUmbra);

#endif // MORPHOLOGYTOOLS_H

