#include "mandelbrot.h"
#include <math.h>

static const double x_1=-2.1;
static const double x_2=0.6;
static const double y_1=-1.2;
static const double y_2=1.2;

//On renvoie une nuance de bleu pour le pixel
int calculeCouleurPixel(int posX, int posY, int zoom, int iterations_max) {
    double c_r=posX/(double)zoom+x_1;
    double c_i=posY/(double)zoom+y_1;
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

    if(i == iterations_max) {
        return 0;
    } else {
        return i*(N_COLORS - 1)/iterations_max;
    }
}

