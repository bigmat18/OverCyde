#include <SDL.h>
#include <stdlib.h>

#ifndef GLOBAL_H
#define GLOBAL_H

/* Window settings */
#define HEIGHT 800
#define WIDTH 900

#define TITLE "OverCyde"

#define X_OFFSET 100
#define Y_OFFSET 100

/* Camera settings */
#define ZOOM 45.0f
#define YAW -90.0f
#define PITCH 0.0f
#define SPEED 700.0f
#define SENSITIVITY 0.1f

/* Colors settings */
#define BACKGROUND_COLOR 0x000000FF

#define HEX_COLOR(hex)             \ 
        ((hex) >> (3 * 8)) & 0xFF, \
        ((hex) >> (2 * 8)) & 0xFF, \
        ((hex) >> (1 * 8)) & 0xFF, \
        ((hex) >> (0 * 8)) & 0xFF

#define DESTRUCT(color) color.x, color.y, color.z, color.w

/* Check settings */
static inline void scc(int code){
    if(code < 0){
        SDL_Log("SDL Error: %s", SDL_GetError());
        exit(1);
    }
    return;
}

static inline void *scp(void *ptr){
    if(ptr == NULL){
        SDL_Log("SDL Error: %s", SDL_GetError());
        exit(1);
    }
    return ptr;
}

#endif
