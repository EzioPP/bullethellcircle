//
// Created by Ezio on 31/03/2024.
//

#ifndef A_GEOMETRY_H
#define A_GEOMETRY_H
#include "SDL2/SDL.h"
#include "structs.h"
int randomNum(int min, int max);
int randomColor(void);
double distance(int x1, int y1, int x2, int y2);
bool detectCollision(Circle circles[], Player *player,int *recover);



void renderCircle(Circle circles[], SDL_Renderer *renderer, int size, int type);
void checkInsideScreen(Circle circles[], int width, int height);
void moveCircle(Circle circles[], int width, int height);
#endif //A_GEOMETRY_H
