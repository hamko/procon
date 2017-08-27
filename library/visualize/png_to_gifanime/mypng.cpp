#include <png.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdarg.h>
#include "mypng.hpp"

#define PNG_DEBUG 3

void abort_(const char * s, ...)
{
    va_list args;
    va_start(args, s);
    vfprintf(stderr, s, args);
    fprintf(stderr, "\n");
    va_end(args);
    abort();
}

RGBBitmap* read_png_file(char* file_name)
{
        int width, height;
        png_structp png_ptr;
        png_infop info_ptr;
        png_bytep * row_pointers;

        char header[8];    // 8 is the maximum size that can be checked

        /* open file and test for it being a png */
        FILE *fp = fopen(file_name, "rb");
        if (!fp)
                abort_("[read_png_file] File %s could not be opened for reading", file_name);
        fread(header, 1, 8, fp);
        if (png_sig_cmp((png_bytep)header, 0, 8))
                abort_("[read_png_file] File %s is not recognized as a PNG file", file_name);


        /* initialize stuff */
        png_ptr = png_create_read_struct(PNG_LIBPNG_VER_STRING, NULL, NULL, NULL);

        if (!png_ptr)
                abort_("[read_png_file] png_create_read_struct failed");

        info_ptr = png_create_info_struct(png_ptr);
        if (!info_ptr)
                abort_("[read_png_file] png_create_info_struct failed");

        if (setjmp(png_jmpbuf(png_ptr)))
                abort_("[read_png_file] Error during init_io");

        png_init_io(png_ptr, fp);
        png_set_sig_bytes(png_ptr, 8);

        png_read_info(png_ptr, info_ptr);

        width = png_get_image_width(png_ptr, info_ptr);
        height = png_get_image_height(png_ptr, info_ptr);
        png_read_update_info(png_ptr, info_ptr);


        /* read file */
        if (setjmp(png_jmpbuf(png_ptr)))
                abort_("[read_png_file] Error during read_image");

        row_pointers = (png_bytep*) malloc(sizeof(png_bytep) * height);
        for (int y=0; y<height; y++)
                row_pointers[y] = (png_byte*) malloc(png_get_rowbytes(png_ptr,info_ptr));

        png_read_image(png_ptr, row_pointers);

        fclose(fp);

        RGBBitmap* ret = allocRGBBitmap(width, height);

        if (png_get_color_type(png_ptr, info_ptr) == PNG_COLOR_TYPE_RGB) {
            printf("RGB file\n");
            for (int y=0; y<height; y++) {
                png_byte* row = row_pointers[y];
                for (int x=0; x<width; x++) {
                    png_byte* ptr = &(row[x*3]);
                    getPixelAt(ret, y, x).red = ptr[0];
                    getPixelAt(ret, y, x).green = ptr[1];
                    getPixelAt(ret, y, x).blue = ptr[2];
                }
            }
        }

        if (png_get_color_type(png_ptr, info_ptr) == PNG_COLOR_TYPE_RGBA) {
            printf("RGBA file\n");
            for (int y=0; y<height; y++) {
                png_byte* row = row_pointers[y];
                for (int x=0; x<width; x++) {
                    png_byte* ptr = &(row[x*4]);
                    getPixelAt(ret, y, x).red = ptr[0];
                    getPixelAt(ret, y, x).green = ptr[1];
                    getPixelAt(ret, y, x).blue = ptr[2];
                }
            }
        }

        return ret;
}


/* Attempts to save PNG to file; returns 0 on success, non-zero on error. */
int save_png_to_file(RGBBitmap *bitmap, const char *path)
{
    FILE *fp;
    png_structp png_ptr = NULL;
    png_infop info_ptr = NULL;
    size_t x, y;
    png_byte **row_pointers = NULL;

    /* File Open */
    if (!(fp = fopen(path, "wb"))) {
        perror(path);
        return -1;
    }

    /* Initialize the write struct. */
    png_ptr = png_create_write_struct(PNG_LIBPNG_VER_STRING, NULL, NULL, NULL);
    if (png_ptr == NULL) {
    	fclose(fp);
    	return -1;
    }

    /* Initialize the info struct. */
    info_ptr = png_create_info_struct(png_ptr);
    if (info_ptr == NULL) {
    	png_destroy_write_struct(&png_ptr, NULL);
    	fclose(fp);
    	return -1;
    }

    /* Set up error handling. */
    if (setjmp(png_jmpbuf(png_ptr))) {
    	png_destroy_write_struct(&png_ptr, &info_ptr);
    	fclose(fp);
    	return -1;
    }

    /* Set image attributes. */
    png_set_IHDR(png_ptr,
                 info_ptr,
                 bitmap->width,
                 bitmap->height,
                 8,
                 PNG_COLOR_TYPE_RGB,
                 PNG_INTERLACE_NONE,
                 PNG_COMPRESSION_TYPE_DEFAULT,
                 PNG_FILTER_TYPE_DEFAULT);

    /* Initialize rows of PNG. */
    int bytes_per_row = bitmap->width * sizeof(uint8_t) * 3;
    row_pointers = (png_byte**)png_malloc(png_ptr, bitmap->height * sizeof(png_byte *));
    for (y = 0; y < bitmap->height; ++y) {
    	uint8_t *row = (uint8_t *)png_malloc(png_ptr, bytes_per_row);
    	row_pointers[y] = (png_byte *)row;
    	for (x = 0; x < bitmap->width; ++x) {
    		RGBPixel color = getPixelAt(bitmap, y, x);
    		*row++ = color.red; *row++ = color.green; *row++ = color.blue;
    	}
    }

    /* Actually write the image data. */
    png_init_io(png_ptr, fp);
    png_set_rows(png_ptr, info_ptr, row_pointers);
    png_write_png(png_ptr, info_ptr, PNG_TRANSFORM_IDENTITY, NULL);

    /* Cleanup. */
    for (y = 0; y < bitmap->height; y++) 
    	png_free(png_ptr, row_pointers[y]);
    png_free(png_ptr, row_pointers);

    /* Finish writing. */
    png_destroy_write_struct(&png_ptr, &info_ptr);
    fclose(fp);

    return 0;
}

// just alloc
RGBBitmap *allocRGBBitmap(size_t width, size_t height)
{
    RGBBitmap *img = (RGBBitmap*)malloc(sizeof(RGBBitmap));
    img->width = width; 
    img->height = height;
    img->pixels = (RGBPixel*)malloc(sizeof(RGBPixel)*img->width*img->height);

    return img;
}

void freeRGBBitmap(RGBBitmap* tofree)
{
    free(tofree->pixels);
}
