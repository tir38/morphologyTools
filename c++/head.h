#ifndef HEAD_H
#define HEAD_H

#include <stdint.h>  // for Uint32
#include "SDL/SDL.h"
#include "/usr/include/SDL/SDL_image.h"
#include "Defs4MorphologyTools.h"


int main ();
void loadImage(IMAGE* inputImage, int& heightSize);
Uint32 getpixel(SDL_Surface *surface, int x, int y);
void getRGB(Uint32 pixel, SDL_PixelFormat* pixelFormat, Uint8& red, Uint8& green, Uint8& blue);

#endif // HEAD_H


