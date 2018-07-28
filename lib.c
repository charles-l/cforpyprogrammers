#include <stdio.h>
#include <SDL2/SDL.h>
#include <stdbool.h>
#include "lib.h"

int run(int width, int height, char *data) {
    run_with_fn(width, height, data, NULL);
}

int run_with_fn(int width, int height, char *data, void (*fn)()) {
    SDL_Init(SDL_INIT_EVERYTHING);
    SDL_Window *win = SDL_CreateWindow("cdraw", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, width, height, SDL_WINDOW_SHOWN);
    SDL_Renderer *ren = SDL_CreateRenderer(win, -1, SDL_RENDERER_ACCELERATED);
    SDL_Texture *tex = SDL_CreateTexture(ren, SDL_PIXELFORMAT_RGB24, SDL_TEXTUREACCESS_STATIC, width, height);

    SDL_Event event;
    bool quit = false;
    while(!quit) {
        while(SDL_PollEvent(&event)) {
            if(event.type == SDL_QUIT) {
                quit = true;
            }
        }

        {
            int pitch = width * 3 * sizeof(char);
            SDL_UpdateTexture(tex, NULL, data, pitch);
        }

        if(fn) fn();

        SDL_RenderClear(ren);
        SDL_RenderCopy(ren, tex, NULL, NULL);
        SDL_RenderPresent(ren);
    }
    SDL_DestroyTexture(tex);
    SDL_DestroyRenderer(ren);
    SDL_DestroyWindow(win);
    SDL_Quit();
}
