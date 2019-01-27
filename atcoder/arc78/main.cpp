#include <stdlib.h>
#include "mypng.hpp"
#include <bits/stdc++.h>
#include <string>
using namespace std;
#define ll int

bool f(ll a, ll b) {
    return (a <= b) ^ (std::to_string(a) <= std::to_string(b));
}
int main(int argc, char** argv) 
{
    /* alloc RGBBitmap whose width and height is (50 [pixel], 50 [pixel]) */
    RGBBitmap *img = allocRGBBitmap(1000/*width*/, 1000/*height*/);

    /* set the colors */
    for (int i = 0; i < (int)img->height; i++) {
        for (int j = 0; j < (int)img->width; j++) {
            ll c = 255 * f(i, j);
            getPixelAt(img, i, j).red = c;
            getPixelAt(img, i, j).green = c;
            getPixelAt(img, i, j).blue = c;
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
