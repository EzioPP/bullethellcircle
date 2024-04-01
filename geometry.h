//
// Created by Ezio on 31/03/2024.
//

#ifndef A_GEOMETRY_H
#define A_GEOMETRY_H
#include "SDL2/SDL.h"
#include "structs.h"

void draw_circle(SDL_Renderer * renderer, Circle circle, int type);
void draw_circle_array(SDL_Renderer * renderer, Circle circles[], int type, int size);
#endif //A_GEOMETRY_H
