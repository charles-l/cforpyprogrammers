#include "lib.h"
#include <math.h>
#include <stdio.h>
#include <string.h>

#define WIDTH 800
#define HEIGHT 600
#define SPIRAL_SCALE 2

void set_pixel(char *data, int x, int y, char r, char g, char b) {
    if(x >= WIDTH || x < 0 || y >= HEIGHT || y < 0) return;
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

void set_circle(char *data, struct point center, int r) {
    for(int y = center.y - r; y < center.y + r; y++) {
        for(int x = center.x - r; x < center.x + r; x++) {
            if(dist((struct point) center, (struct point) {x, y}) < r) {
                set_pixel(data, x, y, 0, 0, 0);
            }
        }
    }
}

int main() {
    char pixels[WIDTH * HEIGHT * 3];
    memset(pixels, 255, WIDTH * HEIGHT * 3);

    struct point pos;
    int dir = 0;

    pos.x = WIDTH / 2;
    pos.y = HEIGHT / 2;

    int n_2 = 1, n_1 = 1;
    for(int i = 0; i < 15; i++) {
        struct point center = pos;
        switch(dir) {
            case 0:
                center.x -= n_2 * SPIRAL_SCALE / 2;
                pos.x -= n_2 * SPIRAL_SCALE;
                break;
            case 1:
                center.y += n_2 * SPIRAL_SCALE / 2;
                pos.y += n_2 * SPIRAL_SCALE;
                break;
            case 2:
                center.x += n_2 * SPIRAL_SCALE / 2;
                pos.x += n_2 * SPIRAL_SCALE;
                break;
            case 3:
                center.y -= n_2 * SPIRAL_SCALE / 2;
                pos.y -= n_2 * SPIRAL_SCALE;
                break;
        }
        set_circle(pixels, center, n_2 * SPIRAL_SCALE / 3);

        dir = (dir + 1) % 4;

        int n = n_1 + n_2;
        n_2 = n_1;
        n_1 = n;
    }

    run(WIDTH, HEIGHT, pixels);
}
