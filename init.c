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
    SDL_Window *window = NULL;

    if(FULLSCREEN)
    {
        window = SDL_CreateWindow("Jogo", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_FULLSCREEN );
    } else {
        window = SDL_CreateWindow("Jogo", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, SCREEN_WIDTH, SCREEN_HEIGHT, 0 );
    }

    SDL_Renderer *renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
    App app = {renderer, window};
    return app;

}

SDL_Texture *renderText(App *app, char *text) {
    TTF_Font* BAUHS93 = TTF_OpenFont("BAUHS93.TTF", 24);
    SDL_Color colorWhite = {255, 255, 255};
    SDL_Surface* surfaceMessage =
            TTF_RenderText_Solid(BAUHS93, text, colorWhite);
    SDL_Texture* Message = SDL_CreateTextureFromSurface(app->renderer, surfaceMessage);
    return Message;
}

