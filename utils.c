//
// Created by Ezio on 30/03/2024.
//

#include "utils.h"
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>
#include <math.h>
#include "geometry.h"
#include "define.h"
#include "structs.h"
int randomNum(int min, int max)
{
    static bool initialized = false;
    if (!initialized)
    {
        srand(time(NULL));
        initialized = true;
    }
    return rand() % (max - min + 1) + min;
}
int randomColor(void)
{
    return randomNum(0, 255);
}
double distance(int x1, int y1, int x2, int y2) {
    return sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
}
bool detectCollision(Circle circles[], Player *player,int *recover) {
    for (int i = 0; i < CIRCLES; i++) {
        if ((distance(circles[i].x, circles[i].y, player->x, player->y) < circles[i].radius + 25) && (*recover == 0)) {
            *recover = 100;
            printf("Collision %d\n", *recover);
            return true;
        }
    }
    return false;
}



void renderCircle(Circle circles[], SDL_Renderer *renderer, int size, int type){
    for (int i = 0; i < size; i++) {
        draw_circle(renderer, circles[i].x, circles[i].y, circles[i].radius, type);

    }
}

void checkInsideScreen(Circle circles[], int width, int height) {
    for (int i = 0; i < CIRCLES; i++) {
        if (circles[i].x > width) {
            circles[i].x = 0;
        }
        if (circles[i].x < 0) {
            circles[i].x = width;
        }
        if (circles[i].y > height) {
            circles[i].y = 0;
        }
        if (circles[i].y < 0) {
            circles[i].y = height;
        }
    }
}
void moveCircle(Circle circles[], int width, int height) {
    for (int i = 0; i < CIRCLES; i++) {
        circles[i].x += cos(circles[i].angle) * circles[i].speed;
        circles[i].y += sin(circles[i].angle) * circles[i].speed;
    }
    checkInsideScreen(circles, width, height);
}