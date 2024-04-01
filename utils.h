//
// Created by Ezio on 30/03/2024.
//

#ifndef A_UTILS_H
#define A_UTILS_H
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

int randomNum(int min, int max);

int randomColor(void);

double distance(int x1, int y1, int x2, int y2);

bool detectCollision(Circle *circles, Player *player, int *recover);

void checkInsideScreen(Circle circle);

void moveCircle(Enemy enemy[], int sizeArray);

#endif //A_UTILS_H