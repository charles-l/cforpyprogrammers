#include "lib.h"

#define WIDTH 800
#define HEIGHT 600
#include <string.h>

void set_pixel(char *data, int x, int y, char brightness) {
    data[(WIDTH * 3) * y + (x * 3)] = brightness;
    data[(WIDTH * 3) * y + (x * 3) + 1] = brightness;
    data[(WIDTH * 3) * y + (x * 3) + 2] = brightness;
}

int main() {
    char pixels[WIDTH * HEIGHT * 3];
    memset(pixels, 255, WIDTH * HEIGHT * 3);

    for(int i = 1; i < WIDTH / 40; i++) {
        for(int j = 1; j < HEIGHT / 40; j++) {
            set_pixel(pixels, i * 40, 40 * j, 0);
        }
    }

    run(WIDTH, HEIGHT, pixels);
}
