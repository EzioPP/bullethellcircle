//
// Created by Ezio on 30/03/2024.
//

#include "utils.h"
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>
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
