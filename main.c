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

Enemy enemies[CIRCLES];
int recover;
Life life[10]; //era pra ter 11 mas por alguma maldiçao tem sempre 1 a menos
int WinMain(int argc, char *argv[])
{
    App app = init();
    if(menu(&app) == 1) {
        return 0;
    }
    for (int i = 0; i < 10; i++) {
        life[i].circle.x = 10 + i * 30;
        life[i].circle.y = 10;
        life[i].circle.radius = 10;
    }
    int remaining = 10;
    recover = 0;
    int KFPS = 1000/ MAX_FPS;
    Player player; //player é estatico, pq fds n da pra fazer um jogo com 2 players
    memset(&player, 0, sizeof(Player));
    player.circle.x = SCREEN_WIDTH / 2;
    player.circle.y = SCREEN_HEIGHT * 0.75;
    player.circle.radius = 25;


    if (app.window == NULL || app.renderer == NULL)
    {
        printf("Erro ao criar janela ou renderer: %s\n", SDL_GetError());
        return 1;
    }
    int color;

    bool running = true;
    SDL_Event event;

    for (int i = 0; i < CIRCLES; i++) {
        enemies[i].circle.x = randomNum(0, SCREEN_WIDTH);
        enemies[i].circle.y  = randomNum(0, 0);
        enemies[i].circle.radius = randomNum(10, 50);
        enemies[i].speed = randomNum(3, 8);
        enemies[i].angle = randomNum(5, 280);
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
            player.circle.y -= 5;
        }
        if (player.down) {
            player.circle.y += 5;
        }
        if (player.left) {
            player.circle.x -= 5;
        }
        if (player.right) {
            player.circle.x += 5;
        }

        SDL_SetRenderDrawColor(app.renderer, color, 0, 0, 255);
        SDL_RenderClear(app.renderer);
        draw_circle(app.renderer, player.circle, 1);  //todo realmente n sei oq esta acontecendo aq
        draw_circle_array(app.renderer, &enemies[CIRCLES-1].circle, 0, CIRCLES);



        if (detectCollision(&enemies[CIRCLES-1].circle, &player, &recover)) {
            player.isTouching = true;
            remaining--;
        } else {
            player.isTouching = false;
        }

        draw_circle_array(app.renderer, &life[2].circle, 2, 10);

        moveCircle(enemies, CIRCLES);





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