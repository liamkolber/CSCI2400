/********************************************************
 * Kernels to be optimized for the CS:APP Performance Lab
 ********************************************************/
#include <stdio.h>
#include <stdlib.h>
#include "defs.h"

/*
 * Please fill in the following student struct:
 */
const team_t team = {
    "liko7561@colorado.edu", //Replace this with your email address.
    ""                   //Replace this with your partner's email address. Leave blank if working alone.
};

/***************
 * FLIP KERNEL
 ***************/

/******************************************************
 * Your different versions of the flip kernel go here
 ******************************************************/
 
/* 
 * naive_flip - The naive baseline version of flip 
 */
char naive_flip_descr[] = "naive_flip: Naive baseline implementation";
void naive_flip(int dim, pixel *src, pixel *dst) {
    int i, j;
    for (i = 0; i < dim; i++){
        for (j = 0; j < dim; j++){
            dst[RIDX_F(i, j, dim)].red   = src[RIDX(i, j, dim)].red;
            dst[RIDX_F(i, j, dim)].green = src[RIDX(i, j, dim)].green;
            dst[RIDX_F(i, j, dim)].blue  = src[RIDX(i, j, dim)].blue;
        }
    }
}

/* 
 * flip - Your current working version of flip
 * IMPORTANT: This is the version you will be graded on
 */
char flip_descr[] = "flip: Current working version";
void flip(int dim, pixel *src, pixel *dst) {

    int i,j;
    switch(dim) {
        case 96:
            for (i = 0; i < (dim); i+=2){
                for (j = 0; j < dim; j++){
                    dst[RIDX_F(i, j, dim)].red   = src[RIDX(i, j, dim)].red;
                    dst[RIDX_F(i, j, dim)].green = src[RIDX(i, j, dim)].green;
                    dst[RIDX_F(i, j, dim)].blue  = src[RIDX(i, j, dim)].blue;

                    dst[RIDX_F(i+1, j, dim)].red   = src[RIDX(i+1, j, dim)].red;
                    dst[RIDX_F(i+1, j, dim)].green = src[RIDX(i+1, j, dim)].green;
                    dst[RIDX_F(i+1, j, dim)].blue  = src[RIDX(i+1, j, dim)].blue;
                }
            }
            break;

        case 256:
            for (i = 0; i < dim; i+=4){
		        for (j = 0; j < dim; j+=2){
		            dst[RIDX_F(i, j, dim)].red   = src[RIDX(i, j, dim)].red;
		            dst[RIDX_F(i, j, dim)].green = src[RIDX(i, j, dim)].green;
		            dst[RIDX_F(i, j, dim)].blue  = src[RIDX(i, j, dim)].blue;

                    dst[RIDX_F(i, j+1, dim)].red   = src[RIDX(i, j+1, dim)].red;
                    dst[RIDX_F(i, j+1, dim)].green = src[RIDX(i, j+1, dim)].green;
                    dst[RIDX_F(i, j+1, dim)].blue  = src[RIDX(i, j+1, dim)].blue;
                //----------------------------
                    dst[RIDX_F(i+1, j, dim)].red   = src[RIDX(i+1, j, dim)].red;
                    dst[RIDX_F(i+1, j, dim)].green = src[RIDX(i+1, j, dim)].green;
                    dst[RIDX_F(i+1, j, dim)].blue  = src[RIDX(i+1, j, dim)].blue;

                    dst[RIDX_F(i+1, j+1, dim)].red   = src[RIDX(i+1, j+1, dim)].red;
                    dst[RIDX_F(i+1, j+1, dim)].green = src[RIDX(i+1, j+1, dim)].green;
                    dst[RIDX_F(i+1, j+1, dim)].blue  = src[RIDX(i+1, j+1, dim)].blue;
                //----------------------------
                    dst[RIDX_F(i+2, j, dim)].red   = src[RIDX(i+2, j, dim)].red;
                    dst[RIDX_F(i+2, j, dim)].green = src[RIDX(i+2, j, dim)].green;
                    dst[RIDX_F(i+2, j, dim)].blue  = src[RIDX(i+2, j, dim)].blue;

                    dst[RIDX_F(i+2, j+1, dim)].red   = src[RIDX(i+2, j+1, dim)].red;
                    dst[RIDX_F(i+2, j+1, dim)].green = src[RIDX(i+2, j+1, dim)].green;
                    dst[RIDX_F(i+2, j+1, dim)].blue  = src[RIDX(i+2, j+1, dim)].blue;
                //----------------------------
                    dst[RIDX_F(i+3, j, dim)].red   = src[RIDX(i+3, j, dim)].red;
                    dst[RIDX_F(i+3, j, dim)].green = src[RIDX(i+3, j, dim)].green;
                    dst[RIDX_F(i+3, j, dim)].blue  = src[RIDX(i+3, j, dim)].blue;

                    dst[RIDX_F(i+3, j+1, dim)].red   = src[RIDX(i+3, j+1, dim)].red;
                    dst[RIDX_F(i+3, j+1, dim)].green = src[RIDX(i+3, j+1, dim)].green;
                    dst[RIDX_F(i+3, j+1, dim)].blue  = src[RIDX(i+3, j+1, dim)].blue;
                }
		    }
            break;

        case 512:
        	for (i = 0; i < dim; i+=8){
                for (j = 0; j < dim; j+=2){
                    dst[RIDX_F(i, j, dim)].red   = src[RIDX(i, j, dim)].red;
                    dst[RIDX_F(i, j, dim)].green = src[RIDX(i, j, dim)].green;
                    dst[RIDX_F(i, j, dim)].blue  = src[RIDX(i, j, dim)].blue;

                    dst[RIDX_F(i, j+1, dim)].red   = src[RIDX(i, j+1, dim)].red;
                    dst[RIDX_F(i, j+1, dim)].green = src[RIDX(i, j+1, dim)].green;
                    dst[RIDX_F(i, j+1, dim)].blue  = src[RIDX(i, j+1, dim)].blue;
                //----------------------------
                    dst[RIDX_F(i+1, j, dim)].red   = src[RIDX(i+1, j, dim)].red;
                    dst[RIDX_F(i+1, j, dim)].green = src[RIDX(i+1, j, dim)].green;
                    dst[RIDX_F(i+1, j, dim)].blue  = src[RIDX(i+1, j, dim)].blue;

                    dst[RIDX_F(i+1, j+1, dim)].red   = src[RIDX(i+1, j+1, dim)].red;
                    dst[RIDX_F(i+1, j+1, dim)].green = src[RIDX(i+1, j+1, dim)].green;
                    dst[RIDX_F(i+1, j+1, dim)].blue  = src[RIDX(i+1, j+1, dim)].blue;
                //----------------------------
                    dst[RIDX_F(i+2, j, dim)].red   = src[RIDX(i+2, j, dim)].red;
                    dst[RIDX_F(i+2, j, dim)].green = src[RIDX(i+2, j, dim)].green;
                    dst[RIDX_F(i+2, j, dim)].blue  = src[RIDX(i+2, j, dim)].blue;

                    dst[RIDX_F(i+2, j+1, dim)].red   = src[RIDX(i+2, j+1, dim)].red;
                    dst[RIDX_F(i+2, j+1, dim)].green = src[RIDX(i+2, j+1, dim)].green;
                    dst[RIDX_F(i+2, j+1, dim)].blue  = src[RIDX(i+2, j+1, dim)].blue;
                //----------------------------
                    dst[RIDX_F(i+3, j, dim)].red   = src[RIDX(i+3, j, dim)].red;
                    dst[RIDX_F(i+3, j, dim)].green = src[RIDX(i+3, j, dim)].green;
                    dst[RIDX_F(i+3, j, dim)].blue  = src[RIDX(i+3, j, dim)].blue;

                    dst[RIDX_F(i+3, j+1, dim)].red   = src[RIDX(i+3, j+1, dim)].red;
                    dst[RIDX_F(i+3, j+1, dim)].green = src[RIDX(i+3, j+1, dim)].green;
                    dst[RIDX_F(i+3, j+1, dim)].blue  = src[RIDX(i+3, j+1, dim)].blue;
                //----------------------------
                    dst[RIDX_F(i+4, j, dim)].red   = src[RIDX(i+4, j, dim)].red;
                    dst[RIDX_F(i+4, j, dim)].green = src[RIDX(i+4, j, dim)].green;
                    dst[RIDX_F(i+4, j, dim)].blue  = src[RIDX(i+4, j, dim)].blue;

                    dst[RIDX_F(i+4, j+1, dim)].red   = src[RIDX(i+4, j+1, dim)].red;
                    dst[RIDX_F(i+4, j+1, dim)].green = src[RIDX(i+4, j+1, dim)].green;
                    dst[RIDX_F(i+4, j+1, dim)].blue  = src[RIDX(i+4, j+1, dim)].blue;
                //----------------------------
                    dst[RIDX_F(i+5, j, dim)].red   = src[RIDX(i+5, j, dim)].red;
                    dst[RIDX_F(i+5, j, dim)].green = src[RIDX(i+5, j, dim)].green;
                    dst[RIDX_F(i+5, j, dim)].blue  = src[RIDX(i+5, j, dim)].blue;

                    dst[RIDX_F(i+5, j+1, dim)].red   = src[RIDX(i+5, j+1, dim)].red;
                    dst[RIDX_F(i+5, j+1, dim)].green = src[RIDX(i+5, j+1, dim)].green;
                    dst[RIDX_F(i+5, j+1, dim)].blue  = src[RIDX(i+5, j+1, dim)].blue;
                //----------------------------
                    dst[RIDX_F(i+6, j, dim)].red   = src[RIDX(i+6, j, dim)].red;
                    dst[RIDX_F(i+6, j, dim)].green = src[RIDX(i+6, j, dim)].green;
                    dst[RIDX_F(i+6, j, dim)].blue  = src[RIDX(i+6, j, dim)].blue;

                    dst[RIDX_F(i+6, j+1, dim)].red   = src[RIDX(i+6, j+1, dim)].red;
                    dst[RIDX_F(i+6, j+1, dim)].green = src[RIDX(i+6, j+1, dim)].green;
                    dst[RIDX_F(i+6, j+1, dim)].blue  = src[RIDX(i+6, j+1, dim)].blue;
                //----------------------------
                    dst[RIDX_F(i+7, j, dim)].red   = src[RIDX(i+7, j, dim)].red;
                    dst[RIDX_F(i+7, j, dim)].green = src[RIDX(i+7, j, dim)].green;
                    dst[RIDX_F(i+7, j, dim)].blue  = src[RIDX(i+7, j, dim)].blue;

                    dst[RIDX_F(i+7, j+1, dim)].red   = src[RIDX(i+7, j+1, dim)].red;
                    dst[RIDX_F(i+7, j+1, dim)].green = src[RIDX(i+7, j+1, dim)].green;
                    dst[RIDX_F(i+7, j+1, dim)].blue  = src[RIDX(i+7, j+1, dim)].blue;
                }
            }
            break;

        case 1024:
        	for (i = 0; i < dim; i+=16){
                for (j = 0; j < dim; j+=2){
                    dst[RIDX_F(i, j, dim)].red   = src[RIDX(i, j, dim)].red;
                    dst[RIDX_F(i, j, dim)].green = src[RIDX(i, j, dim)].green;
                    dst[RIDX_F(i, j, dim)].blue  = src[RIDX(i, j, dim)].blue;

                    dst[RIDX_F(i, j+1, dim)].red   = src[RIDX(i, j+1, dim)].red;
                    dst[RIDX_F(i, j+1, dim)].green = src[RIDX(i, j+1, dim)].green;
                    dst[RIDX_F(i, j+1, dim)].blue  = src[RIDX(i, j+1, dim)].blue;
                //----------------------------
                    dst[RIDX_F(i+1, j, dim)].red   = src[RIDX(i+1, j, dim)].red;
                    dst[RIDX_F(i+1, j, dim)].green = src[RIDX(i+1, j, dim)].green;
                    dst[RIDX_F(i+1, j, dim)].blue  = src[RIDX(i+1, j, dim)].blue;

                    dst[RIDX_F(i+1, j+1, dim)].red   = src[RIDX(i+1, j+1, dim)].red;
                    dst[RIDX_F(i+1, j+1, dim)].green = src[RIDX(i+1, j+1, dim)].green;
                    dst[RIDX_F(i+1, j+1, dim)].blue  = src[RIDX(i+1, j+1, dim)].blue;
                //----------------------------
                    dst[RIDX_F(i+2, j, dim)].red   = src[RIDX(i+2, j, dim)].red;
                    dst[RIDX_F(i+2, j, dim)].green = src[RIDX(i+2, j, dim)].green;
                    dst[RIDX_F(i+2, j, dim)].blue  = src[RIDX(i+2, j, dim)].blue;

                    dst[RIDX_F(i+2, j+1, dim)].red   = src[RIDX(i+2, j+1, dim)].red;
                    dst[RIDX_F(i+2, j+1, dim)].green = src[RIDX(i+2, j+1, dim)].green;
                    dst[RIDX_F(i+2, j+1, dim)].blue  = src[RIDX(i+2, j+1, dim)].blue;
                //----------------------------
                    dst[RIDX_F(i+3, j, dim)].red   = src[RIDX(i+3, j, dim)].red;
                    dst[RIDX_F(i+3, j, dim)].green = src[RIDX(i+3, j, dim)].green;
                    dst[RIDX_F(i+3, j, dim)].blue  = src[RIDX(i+3, j, dim)].blue;

                    dst[RIDX_F(i+3, j+1, dim)].red   = src[RIDX(i+3, j+1, dim)].red;
                    dst[RIDX_F(i+3, j+1, dim)].green = src[RIDX(i+3, j+1, dim)].green;
                    dst[RIDX_F(i+3, j+1, dim)].blue  = src[RIDX(i+3, j+1, dim)].blue;
                //----------------------------
                    dst[RIDX_F(i+4, j, dim)].red   = src[RIDX(i+4, j, dim)].red;
                    dst[RIDX_F(i+4, j, dim)].green = src[RIDX(i+4, j, dim)].green;
                    dst[RIDX_F(i+4, j, dim)].blue  = src[RIDX(i+4, j, dim)].blue;

                    dst[RIDX_F(i+4, j+1, dim)].red   = src[RIDX(i+4, j+1, dim)].red;
                    dst[RIDX_F(i+4, j+1, dim)].green = src[RIDX(i+4, j+1, dim)].green;
                    dst[RIDX_F(i+4, j+1, dim)].blue  = src[RIDX(i+4, j+1, dim)].blue;
                //----------------------------
                    dst[RIDX_F(i+5, j, dim)].red   = src[RIDX(i+5, j, dim)].red;
                    dst[RIDX_F(i+5, j, dim)].green = src[RIDX(i+5, j, dim)].green;
                    dst[RIDX_F(i+5, j, dim)].blue  = src[RIDX(i+5, j, dim)].blue;

                    dst[RIDX_F(i+5, j+1, dim)].red   = src[RIDX(i+5, j+1, dim)].red;
                    dst[RIDX_F(i+5, j+1, dim)].green = src[RIDX(i+5, j+1, dim)].green;
                    dst[RIDX_F(i+5, j+1, dim)].blue  = src[RIDX(i+5, j+1, dim)].blue;
                //----------------------------
                    dst[RIDX_F(i+6, j, dim)].red   = src[RIDX(i+6, j, dim)].red;
                    dst[RIDX_F(i+6, j, dim)].green = src[RIDX(i+6, j, dim)].green;
                    dst[RIDX_F(i+6, j, dim)].blue  = src[RIDX(i+6, j, dim)].blue;

                    dst[RIDX_F(i+6, j+1, dim)].red   = src[RIDX(i+6, j+1, dim)].red;
                    dst[RIDX_F(i+6, j+1, dim)].green = src[RIDX(i+6, j+1, dim)].green;
                    dst[RIDX_F(i+6, j+1, dim)].blue  = src[RIDX(i+6, j+1, dim)].blue;
                //----------------------------
                    dst[RIDX_F(i+7, j, dim)].red   = src[RIDX(i+7, j, dim)].red;
                    dst[RIDX_F(i+7, j, dim)].green = src[RIDX(i+7, j, dim)].green;
                    dst[RIDX_F(i+7, j, dim)].blue  = src[RIDX(i+7, j, dim)].blue;

                    dst[RIDX_F(i+7, j+1, dim)].red   = src[RIDX(i+7, j+1, dim)].red;
                    dst[RIDX_F(i+7, j+1, dim)].green = src[RIDX(i+7, j+1, dim)].green;
                    dst[RIDX_F(i+7, j+1, dim)].blue  = src[RIDX(i+7, j+1, dim)].blue;
                //----------------------------
                    dst[RIDX_F(i+8, j, dim)].red   = src[RIDX(i+8, j, dim)].red;
                    dst[RIDX_F(i+8, j, dim)].green = src[RIDX(i+8, j, dim)].green;
                    dst[RIDX_F(i+8, j, dim)].blue  = src[RIDX(i+8, j, dim)].blue;

                    dst[RIDX_F(i+8, j+1, dim)].red   = src[RIDX(i+8, j+1, dim)].red;
                    dst[RIDX_F(i+8, j+1, dim)].green = src[RIDX(i+8, j+1, dim)].green;
                    dst[RIDX_F(i+8, j+1, dim)].blue  = src[RIDX(i+8, j+1, dim)].blue;
                //----------------------------
                    dst[RIDX_F(i+9, j, dim)].red   = src[RIDX(i+9, j, dim)].red;
                    dst[RIDX_F(i+9, j, dim)].green = src[RIDX(i+9, j, dim)].green;
                    dst[RIDX_F(i+9, j, dim)].blue  = src[RIDX(i+9, j, dim)].blue;

                    dst[RIDX_F(i+9, j+1, dim)].red   = src[RIDX(i+9, j+1, dim)].red;
                    dst[RIDX_F(i+9, j+1, dim)].green = src[RIDX(i+9, j+1, dim)].green;
                    dst[RIDX_F(i+9, j+1, dim)].blue  = src[RIDX(i+9, j+1, dim)].blue;
                //----------------------------
                    dst[RIDX_F(i+10, j, dim)].red   = src[RIDX(i+10, j, dim)].red;
                    dst[RIDX_F(i+10, j, dim)].green = src[RIDX(i+10, j, dim)].green;
                    dst[RIDX_F(i+10, j, dim)].blue  = src[RIDX(i+10, j, dim)].blue;

                    dst[RIDX_F(i+10, j+1, dim)].red   = src[RIDX(i+10, j+1, dim)].red;
                    dst[RIDX_F(i+10, j+1, dim)].green = src[RIDX(i+10, j+1, dim)].green;
                    dst[RIDX_F(i+10, j+1, dim)].blue  = src[RIDX(i+10, j+1, dim)].blue;
                //----------------------------
                    dst[RIDX_F(i+11, j, dim)].red   = src[RIDX(i+11, j, dim)].red;
                    dst[RIDX_F(i+11, j, dim)].green = src[RIDX(i+11, j, dim)].green;
                    dst[RIDX_F(i+11, j, dim)].blue  = src[RIDX(i+11, j, dim)].blue;

                    dst[RIDX_F(i+11, j+1, dim)].red   = src[RIDX(i+11, j+1, dim)].red;
                    dst[RIDX_F(i+11, j+1, dim)].green = src[RIDX(i+11, j+1, dim)].green;
                    dst[RIDX_F(i+11, j+1, dim)].blue  = src[RIDX(i+11, j+1, dim)].blue;
                //----------------------------
                    dst[RIDX_F(i+12, j, dim)].red   = src[RIDX(i+12, j, dim)].red;
                    dst[RIDX_F(i+12, j, dim)].green = src[RIDX(i+12, j, dim)].green;
                    dst[RIDX_F(i+12, j, dim)].blue  = src[RIDX(i+12, j, dim)].blue;

                    dst[RIDX_F(i+12, j+1, dim)].red   = src[RIDX(i+12, j+1, dim)].red;
                    dst[RIDX_F(i+12, j+1, dim)].green = src[RIDX(i+12, j+1, dim)].green;
                    dst[RIDX_F(i+12, j+1, dim)].blue  = src[RIDX(i+12, j+1, dim)].blue;
                //----------------------------
                    dst[RIDX_F(i+13, j, dim)].red   = src[RIDX(i+13, j, dim)].red;
                    dst[RIDX_F(i+13, j, dim)].green = src[RIDX(i+13, j, dim)].green;
                    dst[RIDX_F(i+13, j, dim)].blue  = src[RIDX(i+13, j, dim)].blue;

                    dst[RIDX_F(i+13, j+1, dim)].red   = src[RIDX(i+13, j+1, dim)].red;
                    dst[RIDX_F(i+13, j+1, dim)].green = src[RIDX(i+13, j+1, dim)].green;
                    dst[RIDX_F(i+13, j+1, dim)].blue  = src[RIDX(i+13, j+1, dim)].blue;
                //----------------------------
                    dst[RIDX_F(i+14, j, dim)].red   = src[RIDX(i+14, j, dim)].red;
                    dst[RIDX_F(i+14, j, dim)].green = src[RIDX(i+14, j, dim)].green;
                    dst[RIDX_F(i+14, j, dim)].blue  = src[RIDX(i+14, j, dim)].blue;

                    dst[RIDX_F(i+14, j+1, dim)].red   = src[RIDX(i+14, j+1, dim)].red;
                    dst[RIDX_F(i+14, j+1, dim)].green = src[RIDX(i+14, j+1, dim)].green;
                    dst[RIDX_F(i+14, j+1, dim)].blue  = src[RIDX(i+14, j+1, dim)].blue;
                //----------------------------
                    dst[RIDX_F(i+15, j, dim)].red   = src[RIDX(i+15, j, dim)].red;
                    dst[RIDX_F(i+15, j, dim)].green = src[RIDX(i+15, j, dim)].green;
                    dst[RIDX_F(i+15, j, dim)].blue  = src[RIDX(i+15, j, dim)].blue;

                    dst[RIDX_F(i+15, j+1, dim)].red   = src[RIDX(i+15, j+1, dim)].red;
                    dst[RIDX_F(i+15, j+1, dim)].green = src[RIDX(i+15, j+1, dim)].green;
                    dst[RIDX_F(i+15, j+1, dim)].blue  = src[RIDX(i+15, j+1, dim)].blue;
                }
            }
            break;

        case 2048:
            for (i = 0; i < dim; i+=16){
                for (j = 0; j < dim; j+=2){
                    dst[RIDX_F(i, j, dim)].red   = src[RIDX(i, j, dim)].red;
                    dst[RIDX_F(i, j, dim)].green = src[RIDX(i, j, dim)].green;
                    dst[RIDX_F(i, j, dim)].blue  = src[RIDX(i, j, dim)].blue;

                    dst[RIDX_F(i, j+1, dim)].red   = src[RIDX(i, j+1, dim)].red;
                    dst[RIDX_F(i, j+1, dim)].green = src[RIDX(i, j+1, dim)].green;
                    dst[RIDX_F(i, j+1, dim)].blue  = src[RIDX(i, j+1, dim)].blue;
                //----------------------------
                    dst[RIDX_F(i+1, j, dim)].red   = src[RIDX(i+1, j, dim)].red;
                    dst[RIDX_F(i+1, j, dim)].green = src[RIDX(i+1, j, dim)].green;
                    dst[RIDX_F(i+1, j, dim)].blue  = src[RIDX(i+1, j, dim)].blue;

                    dst[RIDX_F(i+1, j+1, dim)].red   = src[RIDX(i+1, j+1, dim)].red;
                    dst[RIDX_F(i+1, j+1, dim)].green = src[RIDX(i+1, j+1, dim)].green;
                    dst[RIDX_F(i+1, j+1, dim)].blue  = src[RIDX(i+1, j+1, dim)].blue;
                //----------------------------
                    dst[RIDX_F(i+2, j, dim)].red   = src[RIDX(i+2, j, dim)].red;
                    dst[RIDX_F(i+2, j, dim)].green = src[RIDX(i+2, j, dim)].green;
                    dst[RIDX_F(i+2, j, dim)].blue  = src[RIDX(i+2, j, dim)].blue;

                    dst[RIDX_F(i+2, j+1, dim)].red   = src[RIDX(i+2, j+1, dim)].red;
                    dst[RIDX_F(i+2, j+1, dim)].green = src[RIDX(i+2, j+1, dim)].green;
                    dst[RIDX_F(i+2, j+1, dim)].blue  = src[RIDX(i+2, j+1, dim)].blue;
                //----------------------------
                    dst[RIDX_F(i+3, j, dim)].red   = src[RIDX(i+3, j, dim)].red;
                    dst[RIDX_F(i+3, j, dim)].green = src[RIDX(i+3, j, dim)].green;
                    dst[RIDX_F(i+3, j, dim)].blue  = src[RIDX(i+3, j, dim)].blue;

                    dst[RIDX_F(i+3, j+1, dim)].red   = src[RIDX(i+3, j+1, dim)].red;
                    dst[RIDX_F(i+3, j+1, dim)].green = src[RIDX(i+3, j+1, dim)].green;
                    dst[RIDX_F(i+3, j+1, dim)].blue  = src[RIDX(i+3, j+1, dim)].blue;
                //----------------------------
                    dst[RIDX_F(i+4, j, dim)].red   = src[RIDX(i+4, j, dim)].red;
                    dst[RIDX_F(i+4, j, dim)].green = src[RIDX(i+4, j, dim)].green;
                    dst[RIDX_F(i+4, j, dim)].blue  = src[RIDX(i+4, j, dim)].blue;

                    dst[RIDX_F(i+4, j+1, dim)].red   = src[RIDX(i+4, j+1, dim)].red;
                    dst[RIDX_F(i+4, j+1, dim)].green = src[RIDX(i+4, j+1, dim)].green;
                    dst[RIDX_F(i+4, j+1, dim)].blue  = src[RIDX(i+4, j+1, dim)].blue;
                //----------------------------
                    dst[RIDX_F(i+5, j, dim)].red   = src[RIDX(i+5, j, dim)].red;
                    dst[RIDX_F(i+5, j, dim)].green = src[RIDX(i+5, j, dim)].green;
                    dst[RIDX_F(i+5, j, dim)].blue  = src[RIDX(i+5, j, dim)].blue;

                    dst[RIDX_F(i+5, j+1, dim)].red   = src[RIDX(i+5, j+1, dim)].red;
                    dst[RIDX_F(i+5, j+1, dim)].green = src[RIDX(i+5, j+1, dim)].green;
                    dst[RIDX_F(i+5, j+1, dim)].blue  = src[RIDX(i+5, j+1, dim)].blue;
                //----------------------------
                    dst[RIDX_F(i+6, j, dim)].red   = src[RIDX(i+6, j, dim)].red;
                    dst[RIDX_F(i+6, j, dim)].green = src[RIDX(i+6, j, dim)].green;
                    dst[RIDX_F(i+6, j, dim)].blue  = src[RIDX(i+6, j, dim)].blue;

                    dst[RIDX_F(i+6, j+1, dim)].red   = src[RIDX(i+6, j+1, dim)].red;
                    dst[RIDX_F(i+6, j+1, dim)].green = src[RIDX(i+6, j+1, dim)].green;
                    dst[RIDX_F(i+6, j+1, dim)].blue  = src[RIDX(i+6, j+1, dim)].blue;
                //----------------------------
                    dst[RIDX_F(i+7, j, dim)].red   = src[RIDX(i+7, j, dim)].red;
                    dst[RIDX_F(i+7, j, dim)].green = src[RIDX(i+7, j, dim)].green;
                    dst[RIDX_F(i+7, j, dim)].blue  = src[RIDX(i+7, j, dim)].blue;

                    dst[RIDX_F(i+7, j+1, dim)].red   = src[RIDX(i+7, j+1, dim)].red;
                    dst[RIDX_F(i+7, j+1, dim)].green = src[RIDX(i+7, j+1, dim)].green;
                    dst[RIDX_F(i+7, j+1, dim)].blue  = src[RIDX(i+7, j+1, dim)].blue;
                //----------------------------
                    dst[RIDX_F(i+8, j, dim)].red   = src[RIDX(i+8, j, dim)].red;
                    dst[RIDX_F(i+8, j, dim)].green = src[RIDX(i+8, j, dim)].green;
                    dst[RIDX_F(i+8, j, dim)].blue  = src[RIDX(i+8, j, dim)].blue;

                    dst[RIDX_F(i+8, j+1, dim)].red   = src[RIDX(i+8, j+1, dim)].red;
                    dst[RIDX_F(i+8, j+1, dim)].green = src[RIDX(i+8, j+1, dim)].green;
                    dst[RIDX_F(i+8, j+1, dim)].blue  = src[RIDX(i+8, j+1, dim)].blue;
                //----------------------------
                    dst[RIDX_F(i+9, j, dim)].red   = src[RIDX(i+9, j, dim)].red;
                    dst[RIDX_F(i+9, j, dim)].green = src[RIDX(i+9, j, dim)].green;
                    dst[RIDX_F(i+9, j, dim)].blue  = src[RIDX(i+9, j, dim)].blue;

                    dst[RIDX_F(i+9, j+1, dim)].red   = src[RIDX(i+9, j+1, dim)].red;
                    dst[RIDX_F(i+9, j+1, dim)].green = src[RIDX(i+9, j+1, dim)].green;
                    dst[RIDX_F(i+9, j+1, dim)].blue  = src[RIDX(i+9, j+1, dim)].blue;
                //----------------------------
                    dst[RIDX_F(i+10, j, dim)].red   = src[RIDX(i+10, j, dim)].red;
                    dst[RIDX_F(i+10, j, dim)].green = src[RIDX(i+10, j, dim)].green;
                    dst[RIDX_F(i+10, j, dim)].blue  = src[RIDX(i+10, j, dim)].blue;

                    dst[RIDX_F(i+10, j+1, dim)].red   = src[RIDX(i+10, j+1, dim)].red;
                    dst[RIDX_F(i+10, j+1, dim)].green = src[RIDX(i+10, j+1, dim)].green;
                    dst[RIDX_F(i+10, j+1, dim)].blue  = src[RIDX(i+10, j+1, dim)].blue;
                //----------------------------
                    dst[RIDX_F(i+11, j, dim)].red   = src[RIDX(i+11, j, dim)].red;
                    dst[RIDX_F(i+11, j, dim)].green = src[RIDX(i+11, j, dim)].green;
                    dst[RIDX_F(i+11, j, dim)].blue  = src[RIDX(i+11, j, dim)].blue;

                    dst[RIDX_F(i+11, j+1, dim)].red   = src[RIDX(i+11, j+1, dim)].red;
                    dst[RIDX_F(i+11, j+1, dim)].green = src[RIDX(i+11, j+1, dim)].green;
                    dst[RIDX_F(i+11, j+1, dim)].blue  = src[RIDX(i+11, j+1, dim)].blue;
                //----------------------------
                    dst[RIDX_F(i+12, j, dim)].red   = src[RIDX(i+12, j, dim)].red;
                    dst[RIDX_F(i+12, j, dim)].green = src[RIDX(i+12, j, dim)].green;
                    dst[RIDX_F(i+12, j, dim)].blue  = src[RIDX(i+12, j, dim)].blue;

                    dst[RIDX_F(i+12, j+1, dim)].red   = src[RIDX(i+12, j+1, dim)].red;
                    dst[RIDX_F(i+12, j+1, dim)].green = src[RIDX(i+12, j+1, dim)].green;
                    dst[RIDX_F(i+12, j+1, dim)].blue  = src[RIDX(i+12, j+1, dim)].blue;
                //----------------------------
                    dst[RIDX_F(i+13, j, dim)].red   = src[RIDX(i+13, j, dim)].red;
                    dst[RIDX_F(i+13, j, dim)].green = src[RIDX(i+13, j, dim)].green;
                    dst[RIDX_F(i+13, j, dim)].blue  = src[RIDX(i+13, j, dim)].blue;

                    dst[RIDX_F(i+13, j+1, dim)].red   = src[RIDX(i+13, j+1, dim)].red;
                    dst[RIDX_F(i+13, j+1, dim)].green = src[RIDX(i+13, j+1, dim)].green;
                    dst[RIDX_F(i+13, j+1, dim)].blue  = src[RIDX(i+13, j+1, dim)].blue;
                //----------------------------
                    dst[RIDX_F(i+14, j, dim)].red   = src[RIDX(i+14, j, dim)].red;
                    dst[RIDX_F(i+14, j, dim)].green = src[RIDX(i+14, j, dim)].green;
                    dst[RIDX_F(i+14, j, dim)].blue  = src[RIDX(i+14, j, dim)].blue;

                    dst[RIDX_F(i+14, j+1, dim)].red   = src[RIDX(i+14, j+1, dim)].red;
                    dst[RIDX_F(i+14, j+1, dim)].green = src[RIDX(i+14, j+1, dim)].green;
                    dst[RIDX_F(i+14, j+1, dim)].blue  = src[RIDX(i+14, j+1, dim)].blue;
                //----------------------------
                    dst[RIDX_F(i+15, j, dim)].red   = src[RIDX(i+15, j, dim)].red;
                    dst[RIDX_F(i+15, j, dim)].green = src[RIDX(i+15, j, dim)].green;
                    dst[RIDX_F(i+15, j, dim)].blue  = src[RIDX(i+15, j, dim)].blue;

                    dst[RIDX_F(i+15, j+1, dim)].red   = src[RIDX(i+15, j+1, dim)].red;
                    dst[RIDX_F(i+15, j+1, dim)].green = src[RIDX(i+15, j+1, dim)].green;
                    dst[RIDX_F(i+15, j+1, dim)].blue  = src[RIDX(i+15, j+1, dim)].blue;
                }
            }
            break;
    }
}

/*********************************************************************
 * register_flip_functions - Register all of your different versions
 *     of the flip kernel with the driver by calling the
 *     add_flip_function() for each test function. When you run the
 *     driver program, it will test and report the performance of each
 *     registered test function.  
 *********************************************************************/

void register_flip_functions() {
    add_flip_function(&flip, flip_descr);   
    //add_flip_function(&naive_flip, naive_flip_descr);   
    /* ... Register additional test functions here */
}


/***************
 * CONVOLVE KERNEL
 **************/
 
/***************************************************************
 * Various typedefs and helper functions for the convolve function
 * You may modify these any way you like.
 **************************************************************/

/* A struct used to compute a pixel value */
typedef struct {
    float red;
    float green;
    float blue;
    float weight;
} pixel_sum;

/******************************************************
 * Your different versions of the convolve kernel go here
 ******************************************************/

/*
 * naive_convolve - The naive baseline version of convolve 
 */
char naive_convolve_descr[] = "naive_convolve: Naive baseline implementation";
void naive_convolve(int dim, pixel *src, pixel *dst) {
    int i, j, ii, jj, curI, curJ;
    pixel_sum ps;
    
    for (j = 0; j < dim; j++){
        for (i = 0; i < dim; i++){
            ps.red    = 0.0;
            ps.green  = 0.0;
            ps.blue   = 0.0;
            ps.weight = 0.0;
            for (jj = -2; jj <= 2; jj++){
                for (ii = -2; ii <= 2; ii++){
                    curJ = j+jj;
                    if(curJ<0 || curJ>=dim){
                        continue;
                    }
                    curI = i+ii;
                    if(curI<0 || curI>=dim){
                        continue;
                    }
                    ps.red   += src[RIDX(curI, curJ, dim)].red *   kernel[ii+2][jj+2];
                    ps.green += src[RIDX(curI, curJ, dim)].green * kernel[ii+2][jj+2];
                    ps.blue  += src[RIDX(curI, curJ, dim)].blue *  kernel[ii+2][jj+2];
                    ps.weight += kernel[ii+2][jj+2];
                }
            }
            dst[RIDX(i,j,dim)].red   = (unsigned short)(ps.red/ps.weight);
            dst[RIDX(i,j,dim)].green = (unsigned short)(ps.green/ps.weight);
            dst[RIDX(i,j,dim)].blue  = (unsigned short)(ps.blue/ps.weight);
        }
    }
}

/*
 * convolve - Your current working version of convolve. 
 * IMPORTANT: This is the version you will be graded on
{{1.000000, 1.000000, 1.000000, 1.000000, 0.000000},
{1.000000, 16.000000, 4.000000, 0.000000, -1.000000},
{1.000000, 4.000000, 1.000000, -4.000000, -1.000000},
{1.000000, 0.000000, -4.000000, -16.000000, -1.000000},
{0.000000, -1.000000, -1.000000, -1.000000, -1.000000}};
 */
char convolve_descr[] = "convolve: Current working version";
void convolve(int dim, pixel *src, pixel *dst)  {
    int i, j, ii, jj, curI, curJ, newRIDX, cntr;
    pixel_sum ps;
    cntr = 0;
    for (i = 0; i < dim; i++){
        for (j = 0; j < dim; j++){
            ps.red    = 0.0;
            ps.green  = 0.0;
            ps.blue   = 0.0;
            ps.weight = 0.0;
            for (jj = -2; jj <= 2; jj++){
                curJ = j+jj;
                if(curJ<0 || curJ>=dim){
                    continue;
                }
                for (ii = -2; ii <= 2; ii++){
                    curI = i+ii;
                    if(curI<0 || curI>=dim){
                        continue;
                    }
                    newRIDX = (curI*dim)+curJ;
                    ps.red   += src[newRIDX].red *   kernel[ii+2][jj+2];
                    ps.green += src[newRIDX].green * kernel[ii+2][jj+2];
                    ps.blue  += src[newRIDX].blue *  kernel[ii+2][jj+2];
                    ps.weight += kernel[ii+2][jj+2];
                }
            }
            dst[cntr].red   = (unsigned short)(ps.red/ps.weight);
            dst[cntr].green = (unsigned short)(ps.green/ps.weight);
            dst[cntr].blue  = (unsigned short)(ps.blue/ps.weight);
            cntr++;
        }
    }
    /*
    int i, j, ii, jj, curI, curJ, uncleJ;
	pixel_sum ps;
	int czar = 0;
	for (i = 0; i < dim; i++){
		for (j = 0; j < dim; j++){
			ps.red    = 0.0;
			ps.green  = 0.0;
			ps.blue   = 0.0;
			ps.weight = 0.0;
			for (jj = -2; jj <= 2; jj++){
				curJ = j+jj;
				if(curJ<0 || curJ>=dim){
					continue;}
				for (ii = -2; ii <= 2; ii++){
					curI = i+ii;
					if(curI<0 || curI>=dim){
						continue;
					}
					uncleJ = (curI*dim)+curJ;
					ps.red   += src[uncleJ].red *	kernel[ii+2][jj+2];
					ps.green += src[uncleJ].green * kernel[ii+2][jj+2];
					ps.blue  += src[uncleJ].blue *	kernel[ii+2][jj+2];
					ps.weight += kernel[ii+2][jj+2];
				}
			}
			dst[czar].red   = (unsigned short)(ps.red/ps.weight);
			dst[czar].green = (unsigned short)(ps.green/ps.weight);
			dst[czar].blue  = (unsigned short)(ps.blue/ps.weight);
			czar++;
		}
	}*/
}



/********************************************************************* 
 * register_convolve_functions - Register all of your different versions
 *     of the convolve kernel with the driver by calling the
 *     add_convolve_function() for each test function.  When you run the
 *     driver program, it will test and report the performance of each
 *     registered test function.  
 *********************************************************************/

void register_convolve_functions() {
    add_convolve_function(&convolve, convolve_descr);
    //add_convolve_function(&naive_convolve, naive_convolve_descr);
    /* ... Register additional test functions here */
}

