#ifndef MANDELBROT_H
#define MANDELBROT_H
#include <stdbool.h>

#define N_COLORS 3*256

#ifdef __cplusplus
extern "C" {
#endif
int calculeCouleurPixel(int posX, int posY, int zoom, int iterations_max);

#ifdef __cplusplus
}
#endif

#endif // MANDELBROT_H
