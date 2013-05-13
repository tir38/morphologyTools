#include "MorphologyTools.h"


MorphologyTools::MorphologyTools() // constructor
{
}


bool MorphologyTools::myFunct(){
    // do nothing
}

/**
 * @brief creates a single umbra of an input map;
 *          You will need to manage this resource (i.e. delete it) OUTSIDE this method.
 *
 * @return pointer to UMBRA structure
 *
 */
UMBRA* MorphologyTools::umbraOf(std::vector<uint8_t> inputMap, int xDim, int yDim, int zDim){
//    logger_.log_debug("================= inside umbraOf() =================");

    UMBRA* myUmbra;
    myUmbra = new UMBRA(xDim,yDim,zDim);

    // fill all cells of umbras with zero
    int totalLength = myUmbra->colDim_ * myUmbra->heightDim_ * myUmbra->rowDim_;
    for (int i = 0; i < totalLength; i++){
        myUmbra->umbra[i] = 0;
    }

    // fill in occupied cells
    for (int i = 0; i < myUmbra->rowDim_; i++){
        for(int j = 0; j < myUmbra->colDim_; j++){
            uint8_t cellHeight = inputMap[xDim*i + j];

            // confirm cellHeight isn't too tall, if it is scale it down to height of umbra
            if (cellHeight > zDim){
                cellHeight = zDim;
            }

            for (int k = 0; k < cellHeight; k++){
                int location = 0;
                location = (k*xDim*yDim) + (j*xDim) + i; // convert 3D location into 1D location
                myUmbra->umbra[location] = 1;            // set umbra value to 1 (occupied)
            }
        }
    }
    return myUmbra; // returnPointer to myUmbra
}


/**
 * @brief creates a single top surface of an input (pointer to) umbra
 *          You will need to manage this resource (i.e. delete it) OUTSIDE this method.
 *
 * @return pointer to MAP structure
 *
 */
MAP* MorphologyTools::topSurfaceOf(UMBRA* inputUmbra, int xDim, int yDim, int zDim){
//   logger_.log_debug("================= inside topSurfaceOf() =================");
   MAP* outputMap;
   outputMap = new MAP(xDim, yDim);

    //note: I don't need any of MAP member variables except map, colDim_, and rowDim_

   // build top surface
   for (int x = 0; x < xDim; x++){
       for(int y = 0; y < yDim; y++){
           uint8_t cellCount = 0;

           // pull values from umbra at each layer for x = i, y = j
           for (int p = (x*xDim +  y); p < xDim*yDim*zDim; p+=(xDim*yDim)){
               // p is position in 1D array corresponding to (x,y,layer#)
               // Starting with (x,y) on first layer, increase by layer size, until end of array
               if (inputUmbra->umbra[p] > 0.01){ // greater than some threshold
                   cellCount++;
               }
               else if(inputUmbra->umbra[p] < 0.01){ // since starting from the "bottom" layer
                                                   // once I reach a zero, I can assume that there wont' be any occupied cells on layers above;
                   continue;
               }
           }
           outputMap->map[x*xDim+y] = cellCount;// put cellCount into map
       }
   }
   return outputMap;
}
