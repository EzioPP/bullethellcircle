//
// Created by Ezio on 29/03/2024.
//
#include <stdio.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>
#include "utils.h"
#include <math.h>
#include <time.h>
#include "geometry.h"
#include "define.h"
#include "init.h"
#include "structs.h"
#include "menu.h"

Circle circles[CIRCLES];



int recover;
typedef struct {
    int32_t x;
    int32_t y;
    int32_t radius;
} Life;

Life life[10]; //era pra ter 11 mas por alguma maldiçao tem sempre 1 a menos
int WinMain(int argc, char *argv[])
{
    App app = init();
    if(menu(&app) == 1) {
        return 0;
    }
    for (int i = 0; i < 10; i++) {
        life[i].x = 50;
        life[i].y = 50;
        life[i].radius = 25;
    }
    int remaining = 10;
    recover = 0;
    int KFPS = 1000/ MAX_FPS;
    Player player; //player é estatico, pq fds n da pra fazer um jogo com 2 players
    memset(&player, 0, sizeof(Player));
    player.x = SCREEN_WIDTH / 2;
    player.y = SCREEN_HEIGHT * 0.75;


    if (app.window == NULL || app.renderer == NULL)
    {
        printf("Erro ao criar janela ou renderer: %s\n", SDL_GetError());
        return 1;
    }
    int color;

    bool running = true;
    SDL_Event event;

    for (int i = 0; i < 50; i++) {
        circles[i].x = randomNum(0, SCREEN_WIDTH);
        circles[i].y = randomNum(0, 0);
        circles[i].radius = randomNum(10, 50);
        circles[i].speed = randomNum(3, 8);
        circles[i].angle = randomNum(0, 360);
    }



    while (running)

    {
        printf("%d\n", recover);
        if(player.isTouching) {
           color = 255;
        } else {
            color = 0;
        }
        int start = SDL_GetTicks64();

        while (SDL_PollEvent(&event)) {
            switch (event.type) {
                case SDL_QUIT:
                    running = 0;
                    break;
                case SDL_KEYDOWN:
                    switch (event.key.keysym.sym) {
                        case SDLK_UP:
                            player.up = 1;
                            break;
                        case SDLK_DOWN:
                            player.down = 1;
                            break;
                        case SDLK_LEFT:
                            player.left = 1;
                            break;
                        case SDLK_RIGHT:
                            player.right = 1;
                            break;
                        case SDLK_ESCAPE:
                            running = 0;
                            break;


                        default:
                            break;

                    }
                    break;
                case SDL_KEYUP:
                    switch (event.key.keysym.sym) {
                        case SDLK_UP:
                            player.up = 0;
                            break;
                        case SDLK_DOWN:
                            player.down = 0;
                            break;
                        case SDLK_LEFT:
                            player.left = 0;
                            break;
                        case SDLK_RIGHT:
                            player.right = 0;
                            break;
                        default:
                            break;
                    }
                    break;
                default:
                    break;
            }

        }
        if (player.up) {
            player.y -= 5;
        }
        if (player.down) {
            player.y += 5;
        }
        if (player.left) {
            player.x -= 5;
        }
        if (player.right) {
            player.x += 5;
        }

        SDL_SetRenderDrawColor(app.renderer, color, 0, 0, 255);
        SDL_RenderClear(app.renderer);
        draw_circle(app.renderer, player.x, player.y, 25, 1);
        renderCircle(circles, app.renderer, CIRCLES, 0);



        if (detectCollision(circles, &player, &recover)) {
            player.isTouching = true;
            remaining--;
        } else {
            player.isTouching = false;
        }

        for (int i = 0; i < remaining; i++) {
            draw_circle(app.renderer, life[i].x + (i *50), life[i].y, life[i].radius, 2);
        }
        moveCircle(circles, SCREEN_WIDTH, SCREEN_HEIGHT);




        SDL_RenderPresent(app.renderer);
        int end = SDL_GetTicks64();

        int frameTime = end - start;
        if(recover > 0) {
            recover--;
        }
        if (frameTime < KFPS)
        {
            SDL_Delay(KFPS - frameTime);
        }
    }

    SDL_DestroyWindow(app.window);
    SDL_Quit();


    return 0;
}