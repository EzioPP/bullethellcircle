//
// Created by Ezio on 31/03/2024.
//

#ifndef A_STRUCTS_H
#define A_STRUCTS_H
#include "SDL2/SDL.h"
typedef struct {
    SDL_Renderer *renderer;
    SDL_Window *window;
} App;
typedef struct {
    int32_t x;
    int32_t y;
    int32_t radius;
    float speed;
    float angle;

} Circle;

typedef struct {
    int32_t x;
    int32_t y;
    int32_t w;
    int up;
    int down;
    int left;
    int right;
    bool isTouching;
} Player;
#endif //A_STRUCTS_H
