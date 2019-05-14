#include "mandelbrot.h"
#include <math.h>

double _x1=-2.1;
double _x2=0.6;
double _y1=-1.2;
double _y2=1.2;

//On renvoie une nuance de bleu pour le pixel
int calculeCouleurPixel(int posX, int posY, int zoom, int iterations_max) {
    double c_r=posX/(double)zoom+_x1;
    double c_i=posY/(double)zoom+_y1;
    double z_r=0;
    double z_i=0;
    double i=0;

    do
    {
        double tmp=z_r;
        z_r=z_r*z_r-z_i*z_i+c_r; //y
        z_i=2*z_i*tmp+c_i; //x
        ++i;
    } while(z_r*z_r+z_i*z_i<4&&i<iterations_max);

    if(i == iterations_max)
        return 0;
    else
        return i*(N_COLORS - 1)/iterations_max;
}

