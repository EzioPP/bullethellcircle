//
// Created by Ezio on 31/03/2024.
//

#include "menu.h"
#include "SDL2/SDL.h"
#include "structs.h"


void menu(App *app) {
    SDL_Event event;
    int quit = 0;
    while (!quit) {
        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_QUIT) {
                quit = 1;
            }
        }
        SDL_SetRenderDrawColor(app->renderer, 0, 0, 0, 255);
        SDL_RenderClear(app->renderer);
        SDL_RenderPresent(app->renderer);
    }
}