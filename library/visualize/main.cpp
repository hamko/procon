#include <stdlib.h>
#include "mypng.hpp" // g++ main.cpp mypng.cpp -lpng

int main(int argc, char** argv) 
{
    /* alloc RGBBitmap whose width and height is (50 [pixel], 50 [pixel]) */
    RGBBitmap *img = allocRGBBitmap(50/*width*/, 50/*height*/);

    /* set the colors */
    for (int i = 0; i < (int)img->height; i++) {
        for (int j = 0; j < (int)img->width; j++) {
            getPixelAt(img, i, j).red = 255;
            getPixelAt(img, i, j).green = 0;
            getPixelAt(img, i, j).blue = (int)((double)255 * i / (img->height));
        }
    }

    /* Attempts to save PNG to file; returns 0 on success, non-zero on error. */
    if (save_png_to_file(img, "test_output.png")) {
        printf("error\n");
        exit(1);
    }


    /* read png file you made and*/
    RGBBitmap* bitmap = read_png_file((char*)"test_input.png");

    /* set the colors */
    for (int i = 0; i < (int)bitmap->height; i++) {
        for (int j = 0; j < (int)bitmap->width; j++) {
            getPixelAt(bitmap, i, j).blue = 255 - getPixelAt(bitmap, i, j).blue;
            getPixelAt(bitmap, i, j).red = 255 - getPixelAt(bitmap, i, j).red;
            getPixelAt(bitmap, i, j).green = 255 - getPixelAt(bitmap, i, j).green;
        }
    }

    save_png_to_file(bitmap, "test_output2.png");
    freeRGBBitmap(bitmap);

    return 0;
}
