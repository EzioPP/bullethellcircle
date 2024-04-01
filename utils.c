//
// Created by Ezio on 30/03/2024.
//

#include "utils.h"
#include <stdlib.h>
#include "stdio.h"
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
        if ((distance(circles[i].x, circles[i].y, player->circle.x, player->circle.y) < circles[i].radius + 25) && (*recover == 0)) {
            *recover = 40;
            printf("Collision %d\n", *recover);
            return true;
        }
    }
    return false;
}






void checkInsideScreen(Circle circle) {

        if (circle.x > SCREEN_WIDTH) {
            circle.x = 0;
        }
        if (circle.x < 0) {
            circle.x = SCREEN_WIDTH;
        }
        if (circle.y > SCREEN_HEIGHT) {
            circle.y = 0;
        }
        if (circle.y < 0) {
            circle.y = SCREEN_HEIGHT;
    }
}
void moveCircle(Enemy enemy[], int sizeArray) {
    for(int i = 0; i < sizeArray; i++) {
        enemy[i].circle.x += cos(enemy[i].angle) * enemy[i].speed;
        enemy[i].circle.y += sin(enemy[i].angle) * enemy[i].speed;
        checkInsideScreen(enemy[i].circle);
    }
};