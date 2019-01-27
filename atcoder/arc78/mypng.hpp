#ifndef MYPNG_HPP_INCLUDED
#define MYPNG_HPP_INCLUDED

#include <png.h>
#include <stdint.h>

#define getPixelAt(img, y, x) ((img)->pixels[(y)*(img)->width+(x)])

/* Pixels in this bitmap structure are stored as BGR. */
typedef struct _RGBPixel {
    uint8_t blue, green, red;
} RGBPixel;

/* Structure for containing decompressed bitmaps. */
typedef struct _RGBBitmap {
    RGBPixel *pixels;
    size_t width, height;
} RGBBitmap;

extern RGBBitmap* read_png_file(char* file_name); // please free yourself
extern int save_png_to_file(RGBBitmap *bitmap, const char *path);
extern RGBBitmap *allocRGBBitmap(size_t width, size_t height);
extern void freeRGBBitmap(RGBBitmap* tofree);



#endif
