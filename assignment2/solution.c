#include "lib.h"

#define WIDTH 800
#define HEIGHT 600
#include <string.h>

void set_pixel(char *data, int x, int y, char r, char g, char b) {
    data[(WIDTH * 3) * y + (x * 3)] = r;
    data[(WIDTH * 3) * y + (x * 3) + 1] = g;
    data[(WIDTH * 3) * y + (x * 3) + 2] = b;
}

void set_hline(char *data, int y, char r, char g, char b) {
    for(int i = 0; i < WIDTH; i++) {
        set_pixel(data, i, y, r, g, b);
    }
}

void set_vline(char *data, int x, char r, char g, char b) {
    for(int i = 0; i < HEIGHT; i++) {
        set_pixel(data, x, i, r, g, b);
    }
}

int main() {
    char pixels[WIDTH * HEIGHT * 3];
    memset(pixels, 255, WIDTH * HEIGHT * 3);

    for(int i = 1; i < WIDTH / 40; i++) {
        set_vline(pixels, i * 40, 0, 255, 0);
    }

    for(int i = 1; i < HEIGHT / 40; i++) {
        set_hline(pixels, i * 40, 0, 0, 255);
    }

    run(WIDTH, HEIGHT, pixels);
}
