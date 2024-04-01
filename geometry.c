//
// Created by Ezio on 31/03/2024.
//

#include "geometry.h"
#include "SDL2/SDL.h"
void draw_circle(SDL_Renderer * renderer, Circle circle, int type)
{   if(type == 1) {
        SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
    } else if (type == 0) {
        SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);
    } else {
        SDL_SetRenderDrawColor(renderer, 0, 255, 0, 255);
    }

    const int32_t diameter = (circle.radius * 2);

    int32_t x = (circle.radius - 1);
    int32_t y = 0;
    int32_t tx = 1;
    int32_t ty = 1;
    int32_t error = (tx - diameter);

    while (x >= y)
    {
        //  Each of the following renders an octant of the circle
        SDL_RenderDrawPoint(renderer, circle.x + x, circle.y - y);
        SDL_RenderDrawPoint(renderer, circle.x + x, circle.y + y);
        SDL_RenderDrawPoint(renderer, circle.x - x, circle.y - y);
        SDL_RenderDrawPoint(renderer, circle.x - x, circle.y + y);
        SDL_RenderDrawPoint(renderer, circle.x + y, circle.y - x);
        SDL_RenderDrawPoint(renderer, circle.x + y, circle.y + x);
        SDL_RenderDrawPoint(renderer, circle.x - y, circle.y - x);
        SDL_RenderDrawPoint(renderer, circle.x - y, circle.y + x);

        if (error <= 0)
        {
            ++y;
            error += ty;
            ty += 2;
        }

        if (error > 0)
        {
            --x;
            tx += 2;
            error += (tx - diameter);
        }
    }
}

        void draw_circle_array(SDL_Renderer * renderer, Circle circles[], int type, int size) {
    for (int i = 0; i < size; i++) {
        draw_circle(renderer, circles[i], type);
    }
}