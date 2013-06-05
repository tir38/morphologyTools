Matlab and C++ tools 
-
for creating umbras and top surfaces
-
*************************************

Matlab
-
Running example.m will demonstrate the usage of umbraOf() and topSurfaceOf().
Included in the repo are several example figure outputs.

C++
-
*head.cc* is a wrapper that just demonstrates how to use umbraOf() and topSurfaceOf().
Two structures are included to help with the book keeping: IMAGE and UMBRA.

To demo the code:

```make
./morphologyTools
```
The wrapper uses SDL and SDL-image to load and display an image. It is not used buy
the actual toolbox. You are free to change the wrapper to import your own image.


License
-

MIT

All code written by Jason Atwood 2013, unless noted.

