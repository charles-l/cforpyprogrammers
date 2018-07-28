#include "lib.h"
#include <math.h>

#define WIDTH 800
#define HEIGHT 600
#include <string.h>

void set_pixel(char *data, int x, int y, char r, char g, char b) {
    data[(WIDTH * 3) * y + (x * 3)] = r;
    data[(WIDTH * 3) * y + (x * 3) + 1] = g;
    data[(WIDTH * 3) * y + (x * 3) + 2] = b;
}

struct point {
    int x;
    int y;
};

int dist(struct point a, struct point b) {
    return sqrt(pow(a.x - b.x, 2) + pow(a.y - b.y, 2));
}

int main() {
    char pixels[WIDTH * HEIGHT * 3];
    memset(pixels, 255, WIDTH * HEIGHT * 3);

    struct point center;
    center.x = WIDTH / 2;
    center.y = HEIGHT / 2;

    int r = 100;

    for(int y = center.y - r; y < center.y + r; y++) {
        for(int x = center.x - r; x < center.x + r; x++) {
            if(dist((struct point) center, (struct point) {x, y}) < r) {
                set_pixel(pixels, x, y, 0, 0, 0);
            }
        }
    }

    run(WIDTH, HEIGHT, pixels);
}
