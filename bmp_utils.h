#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdbit.h>

#ifndef BMP_utils_H
#define BMP_utils_H

typedef struct BMP_IMG {
    unsigned char * pixArray;
    int fileSize;
    int width;
    int height;
    int bitsPerPixel;
    int pixArraySize;
    int rowSize;
} BMP_IMG;

typedef struct Color{
    unsigned char r;
    unsigned char g;
    unsigned char b;
    unsigned char a;
} Color;

static const Color NULL_COLOR = {0,0,0,0};
static const Color BLACK = {0  ,0  ,0  ,255};
static const Color WHITE = {255,255,255,255};
static const Color RED =   {255,0  ,0  ,255};
static const Color GREEN = {0  ,255,0  ,255};
static const Color BLUE =  {0  ,0  ,255,255};
static const Color MAGENTA =   {255,0  ,255,255};
static const Color YELLOW =    {255,255,0  ,255};
static const Color CYAN =      {0  ,255,255,255};

/**
 * Reads data from the given file, 
 * and creates a new BMP_IMG structure with it.
 *  
 * filepath : must be a valid file path. Will exit if the file is not a bitmap file. 
 */
BMP_IMG importBMP(const char * filepath);

/**
 * Take an image pointer, valid pixel coordinates x y,
 * and returns the selected pixel's color of type Color.
 */
Color getPixel(BMP_IMG * img, int x, int y);

/**
 * Take an image pointer, valid pixel coordinates x y and a Color,
 * and set the selected pixel to the given Color.
 */
void putPixel(BMP_IMG * img, int x, int y, Color c);

/**
 * Take an image pointer,
 * and the image will be printed in the standard output (i.e. the current terminal emulator)
 * since the image is a binary image composed of only black and white,
 * the function will consider a pixel black if the blue value is at 255.
 */
void printBMP(BMP_IMG * img);

/**
 * Creates a new BMP_IMG struct of given height, width and color depth.
 * all pixels are set to white.
 * Returns a pointer to the new image.
 */
BMP_IMG * newBMP( int height, int width, int bpp );

/**
 * Creates an exact independant copy of a BMP_IMG struct, 
 * and returns a pointer to it.
 */
BMP_IMG * duplicateBMP(BMP_IMG * src);

/**
 * Frees all memory used by a BMP_IMG.
 */
void destroyBMP(BMP_IMG * img);

/**
 * Takes a BMP_IMG struct and a path and creates a .bmp file 
 * at the filename's location from it.
 */
void exportBMP(BMP_IMG img, const char * filename);

/**
 * Set all pixels from the referenced image pointer to the given color. 
 */
void clearColor(BMP_IMG * img, Color c);

/**
 * Checks wether color a and color b are the same.
 */
bool isSameColor(Color a , Color b);


#endif