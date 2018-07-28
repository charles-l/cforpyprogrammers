#ifndef LIB_H
#define LIB_H

int run(int width, int height, char *data);
int run_with_fn(int width, int height, char *data, void (*fn)());

#endif // LIB_H
