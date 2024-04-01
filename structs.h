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
} Circle;
typedef struct {
    Circle circle;
    float speed;
    float angle;
}Enemy;


typedef struct {
    Circle circle;
    int up;
    int down;
    int left;
    int right;
    bool isTouching;
} Player;
typedef struct {
    Circle circle;
} Life;
#endif //A_STRUCTS_H
