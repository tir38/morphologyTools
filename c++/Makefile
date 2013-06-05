CC=g++ 
CFLAGS=-I. 
LIBS = -lSDL -lSDL_image

morphologyTools: head.cc MorphologyTools.cc Defs4MorphologyTools.cc
	$(CC) $(CFLAGS) -o morphologyTools head.cc MorphologyTools.cc Defs4MorphologyTools.cc $(LIBS)
