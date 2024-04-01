//
// Created by Ezio on 31/03/2024.
//

#include "menu.h"
#include "SDL2/SDL.h"
#include "structs.h"
#include "init.h"
#include "define.h"
#include "utils.h"
typedef struct {
    int up;
    int down;
    int pos;
} Chooser; //ingles em dia


int menu(App *app) {
    Chooser chooser = *(Chooser*)malloc(sizeof(Chooser));
    chooser.up = 0;
    chooser.down = 0;
    chooser.pos = 300;
    SDL_Event event;
    int quit = 0;
    while (!quit) {
        while (SDL_PollEvent(&event)) {
            switch (event.type) {
                case SDL_QUIT:
                    quit = 1;
                    return 1;
                case SDL_KEYDOWN:
                    switch (event.key.keysym.sym) {
                        case SDLK_UP:
                            chooser.up = 1;
                            break;
                        case SDLK_DOWN:
                            chooser.down = 1;
                            break;
                        case SDLK_RETURN:
                            if (chooser.pos == 300) {
                                return 0;
                            } else if (chooser.pos == 400) {
                                return 1;
                            }
                            free(&chooser);
                            break;
                        default:
                            break;
                    }
                    break;
                case SDL_KEYUP:
                    switch (event.key.keysym.sym) {
                        case SDLK_UP:
                            chooser.up = 0;
                            break;
                        case SDLK_DOWN:
                            chooser.down = 0;
                            break;
                        default:
                            break;
                    }
                    break;
                default:
                    break;
            }

        }
        if (chooser.down && chooser.pos < 301) {
            chooser.pos += 100;
        }
        if (chooser.up && chooser.pos > 301) {
            chooser.pos -= 100;
        }

        SDL_SetRenderDrawColor(app->renderer, 0, 0, 0, 255);
        SDL_RenderClear(app->renderer);
        SDL_SetRenderDrawColor(app->renderer, 255,255, 255, 255);
        SDL_Rect choice = {SCREEN_WIDTH/2 - 100, chooser.pos, 200, 100};
        SDL_RenderDrawRect(app->renderer, &choice);

        SDL_Rect title = {SCREEN_WIDTH/2 - 250, 50, 500, 200};

        SDL_SetRenderDrawColor(app->renderer, randomColor(), randomColor(), randomColor(), randomColor());
        SDL_Texture *Message = renderText(app, "Autism 1",true);
        SDL_RenderCopy(app->renderer, Message, NULL, &title);
        SDL_SetRenderDrawColor(app->renderer, 255, 255, 255, 255);

        SDL_Rect tip = {SCREEN_WIDTH/2 - 150, 600, 300, 100};
        SDL_SetRenderDrawColor(app->renderer, randomColor(), randomColor(), randomColor(), randomColor());
        SDL_Texture *Message0 = renderText(app, "Press Enter to select an option",true);
        SDL_RenderCopy(app->renderer, Message0, NULL, &tip);


        SDL_Rect play = {SCREEN_WIDTH/2 - 100, 300, 100, 100};
        SDL_Texture *Message2 = renderText(app, "Play",true);
        SDL_SetRenderDrawColor(app->renderer, randomColor(), randomColor(), randomColor(), randomColor());
        SDL_RenderCopy(app->renderer, Message2, NULL, &play);

        SDL_Rect exit = {SCREEN_WIDTH/2 - 100, 400, 100, 100};
        SDL_Texture *Message3 = renderText(app, "Exit",true);
        SDL_SetRenderDrawColor(app->renderer, randomColor(), randomColor(), randomColor(), randomColor());
        SDL_RenderCopy(app->renderer, Message3, NULL, &exit);


        SDL_RenderPresent(app->renderer);
    }
}