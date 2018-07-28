#include "lib.h"

#define WIDTH 800
#define HEIGHT 600
#include <string.h>

void set_pixel(char *data, int x, int y, char r, char g, char b) {
    // modify set_pixel from assignemnt1
}

void set_hline(char *data, int y, char r, char g, char b) {
    // implement this
}

void set_vline(char *data, int x, char r, char g, char b) {
    // implement this
}

int main() {
    char pixels[WIDTH * HEIGHT * 3];
    memset(pixels, 255, WIDTH * HEIGHT * 3);

    // write other draw code here

    run(WIDTH, HEIGHT, pixels);
}
