//
// Created by Ezio on 31/03/2024.
//

#include "init.h"
#include "SDL2/SDL.h"
#include "SDL2/SDL_ttf.h"
#include "structs.h"
#include "define.h"


App init(void)
{
    SDL_Init(SDL_INIT_EVERYTHING);
    TTF_Init();
    SDL_Window *window = SDL_CreateWindow("Jogo", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, SCREEN_HEIGHT, SCREEN_WIDTH, SDL_WINDOW_FULLSCREEN );
    SDL_Renderer *renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
    App app = {renderer, window};
    return app;

}