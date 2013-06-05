#include "MorphologyTools.h"
#include <iostream>


/**
 * @brief creates a single umbra of an input image;
 *          You will need to manage this resource (i.e. delete it) OUTSIDE this method.
 *
 * @return pointer to UMBRA structure
 *
 */
UMBRA* umbraOf(std::vector<int> inputImage, int xDim, int yDim, int zDim){

    UMBRA* myUmbra;
    myUmbra = new UMBRA(xDim,yDim,zDim);

    // fill all cells of umbras with zero
    int totalLength = myUmbra->colDim_ * myUmbra->heightDim_ * myUmbra->rowDim_;
    for (int i = 0; i < totalLength; i++){
        myUmbra->umbra_[i] = 0;
    }

    // fill in occupied cells
    for (int i = 0; i < myUmbra->rowDim_; i++){
        for(int j = 0; j < myUmbra->colDim_; j++){
            int cellHeight = inputImage[xDim*i + j];

            // confirm cellHeight isn't too tall, if it is scale it down to height of umbra
            if (cellHeight > zDim){
                cellHeight = zDim;
            }

            for (int k = 0; k < cellHeight; k++){
                int location = 0;
                location = (k*xDim*yDim) + (j*xDim) + i; // convert 3D location into 1D location
                myUmbra->umbra_[location] = 1;            // set umbra value to 1 (occupied)
            }
        }
    }
    return myUmbra; // returnPointer to myUmbra
}


/**
 * @brief creates a single top surface of an input (pointer to) umbra
 *          You will need to manage this resource (i.e. delete it) OUTSIDE this method.
 *
 * @return pointer to IMAGE structure
 *
 */
IMAGE* topSurfaceOf(UMBRA* inputUmbra){
//   logger_.log_debug("================= inside topSurfaceOf() =================");

    int xDim = inputUmbra->rowDim_;
    int yDim = inputUmbra->colDim_;
    int zDim = inputUmbra->heightDim_;

   IMAGE* outputImage;
   outputImage = new IMAGE(xDim, yDim);

   // build top surface
   for (int x = 0; x < xDim; x++){
       for(int y = 0; y < yDim; y++){
           int cellCount = 0;

           // pull values from umbra at each layer for x = i, y = j
           for (int p = (x*xDim +  y); p < xDim*yDim*zDim; p+=(xDim*yDim)){
               // p is position in 1D array corresponding to (x,y,layer#)
               // Starting with (x,y) on first layer, increase by layer size, until end of array
               if (inputUmbra->umbra_[p] > 0.01){ // greater than some threshold
                   cellCount++;
               }
               else if(inputUmbra->umbra_[p] < 0.01){ // since starting from the "bottom" layer
                                                   // once I reach a zero, I can assume that there wont' be any occupied cells on layers above;
                   continue;
               }
           }
           outputImage->image_[x*xDim+y] = cellCount;// put cellCount into image
       }
   }
   return outputImage;
}
