#include "lib.h"

#define WIDTH 800
#define HEIGHT 600
#define NBYTES_IN_IMG (WIDTH * HEIGHT * 3)

void set_pixel(char *data, int x, int y, char brightness) {
    // WRITE CODE HERE!
}

int main() {
    char pixels[NBYTES_IN_IMG];
    run(WIDTH, HEIGHT, pixels);
}
