#include <iostream>     // for cout
#include <stdint.h>     // for uint8_t
#include <vector>       // for std::vector
#include <math.h>       // for floor, abs

#include "head.h"
#include "MorphologyTools.h"
#include "Defs4MorphologyTools.h"

/**
 * @brief wrapper to handle image loading,  umbraOf() and topSurfaceOf() calls, and results
 *
 * @return int; 1 if successful; -1 if fail.
 *
 */
int main(){
    cout << "\t Loading  image..." << endl;
    // =========== load image ============
    IMAGE* inputImage;          // instantiate IMAGE for storage
    inputImage = new IMAGE();
    int heightSize = 0;
    loadImage(inputImage, heightSize);

    // =========== generate umbra of image ================
    cout << "\t Generating umbra of image." << endl;
    UMBRA* myUmbra;
    myUmbra =  umbraOf(inputImage->image_, inputImage->rowDim_, inputImage->colDim_, heightSize);

    // =========== generate top surface of umbra ================
    cout << "\t Generating top sufrace of umbra of image.\n";
    IMAGE* topSurface;
    topSurface = topSurfaceOf(myUmbra);

    // =========== compare top surface with original image ================
    int error = 0;
    results.resize(inputImage->rowDim_ * inputImage->colDim_);
    for (int i = 0; i < inputImage->rowDim_* inputImage->colDim_; i++){
        error += abs(topSurface->image_[i] - inputImage->image_[i]);
    }
    cout << "\t Total error = " << error << endl;

    // =========== delete ================
    delete myUmbra;
    delete inputImage;
    delete topSurface;

    cout << "\t Done!" << endl;
	return 1; // success
}

/**
 * @brief does all of the image loading using SDL and SDL_image
 *          This is not really part of the morphologyTool box;
 *          just used to display image/results.
 *
 * @return Uint32 pixel intensity
 *
 */
void loadImage(IMAGE* inputImage, int& heightSize){

    // load and display image
    SDL_Init( SDL_INIT_EVERYTHING );     //Start SDL
    SDL_Surface* screen;
    screen = SDL_SetVideoMode( 512, 512, 32, SDL_SWSURFACE );     //Set up screen
    SDL_Surface* loadedImage;
    loadedImage = IMG_Load("lena.jpg");
    SDL_BlitSurface( loadedImage, NULL, screen, NULL );    //Apply image to screen
    SDL_Flip( screen );    //Update Screen
    SDL_Delay( 2000 );    //Pause

    // get image dimensions
    cout << "\t\t Height: " << loadedImage->h << endl;
    cout << "\t\t Width: " << loadedImage->w << endl;
    int rowSize = loadedImage->h;
    int colSize = loadedImage->w;
    inputImage->image_.resize(rowSize *colSize);             // resize IMAGE structure now that we know input image dimensions

    // get pixel format
    SDL_PixelFormat* pixelFormat;
    pixelFormat = loadedImage->format; // get pixel format from loaded image (i.e. its color space and how it converts pixelvalue to RGB)

    // iterate through cells in loadedImage to create IMAGE
    Uint8 red, green, blue;
    for (int row = 0; row < rowSize; row++){
        for (int col = 0; col < colSize; col++){
            Uint32 pixelValue = getpixel(loadedImage, row, col);    // get pixel value
            getRGB(pixelValue, pixelFormat, red, green, blue);      // convert to RGB
            int intensity = floor((red + blue + green) / 3);                  // convert RGB to greyscale (simple method
            inputImage->image_[row*rowSize + col] = intensity;              // set pixel value in IMAGE
            if (intensity > heightSize){
                heightSize = intensity;
            }
        }
    }
    cout << "\t\t maximum pixel intensity is " << heightSize << endl;
}


/**
 * @brief gets pixel intensity from single pixel
 *          copied from here http://www.libsdl.org/cgi/docwiki.fcg/Pixel_Access
 *
 * @return Uint32 pixel intensity
 *
 */
Uint32 getpixel(SDL_Surface *surface, int x, int y){
    int bpp = surface->format->BytesPerPixel;
    /* Here p is the address to the pixel we want to retrieve */
    Uint8 *p = (Uint8 *)surface->pixels + y * surface->pitch + x * bpp;

    switch(bpp) {
    case 1:
        return *p;
        break;

    case 2:
        return *(Uint16 *)p;
        break;

    case 3:
        if(SDL_BYTEORDER == SDL_BIG_ENDIAN)
            return p[0] << 16 | p[1] << 8 | p[2];
        else
            return p[0] | p[1] << 8 | p[2] << 16;
        break;

    case 4:
        return *(Uint32 *)p;
        break;

    default:
        return 0;       /* shouldn't happen, but avoids warnings */
    }
}


/**
 * @brief converts pixel intensity into RGB
 *           adapted from : http://www.libsdl.org/docs/html/sdlpixelformat.html
 *
 * @return void; RGB are passed back through reference
 *
 */
void getRGB(Uint32 pixel, SDL_PixelFormat* pixelFormat, Uint8& red, Uint8& green, Uint8& blue){
    Uint32 temp;

    /* Get Red component */
    temp=pixel&pixelFormat->Rmask; /* Isolate red component */
    temp=temp>>pixelFormat->Rshift;/* Shift it down to 8-bit */
    temp=temp<<pixelFormat->Rloss; /* Expand to a full 8-bit number */
    red=(Uint8)temp;

    /* Get Green component */
    temp=pixel&pixelFormat->Gmask; /* Isolate green component */
    temp=temp>>pixelFormat->Gshift;/* Shift it down to 8-bit */
    temp=temp<<pixelFormat->Gloss; /* Expand to a full 8-bit number */
    green=(Uint8)temp;

    /* Get Blue component */
    temp=pixel&pixelFormat->Bmask; /* Isolate blue component */
    temp=temp>>pixelFormat->Bshift;/* Shift it down to 8-bit */
    temp=temp<<pixelFormat->Bloss; /* Expand to a full 8-bit number */
    blue=(Uint8)temp;
}
