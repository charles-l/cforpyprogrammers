#include "lib.h"
#include <stdio.h>
#include <math.h>

#define WIDTH 800
#define HEIGHT 600
#include <string.h>

char pixels[WIDTH * HEIGHT * 3];
float slope = 0;

void set_pixel(char *data, int x, int y, char r, char g, char b) {
    if(x >= WIDTH || y >= HEIGHT) return;
    data[(WIDTH * 3) * y + (x * 3)] = r;
    data[(WIDTH * 3) * y + (x * 3) + 1] = g;
    data[(WIDTH * 3) * y + (x * 3) + 2] = b;
}

void update() {
    slope += 0.01;
    for(int i = 0; i < WIDTH; i++) {
        set_pixel(pixels, i, slope * i, 0, 0, 0);
    }
}

int main() {
    memset(pixels, 255, WIDTH * HEIGHT * 3);

    run_with_fn(WIDTH, HEIGHT, pixels, &update);
}
