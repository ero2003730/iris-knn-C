#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "iris.h"

void ColocaClasse(Flor flor[], int count)
{
    for (int i = 0; i < count; i++)
    {
        if (strcmp(flor[i].variety, "Setosa") == 0)
            flor[i].classe = 0;
        else if (strcmp(flor[i].variety, "Versicolor") == 0)
            flor[i].classe = 1;
        else if (strcmp(flor[i].variety, "Virginica") == 0)
            flor[i].classe = 2;
    }
}

void IniciaPlano(Plano plano[], int count)
{
    for (int i = 0; i < count; i++)
    {
        plano[i].x = 0.0;
        plano[i].y = 0.0;
        plano[i].z = 0.0;
        plano[i].h = 0.0;
    }
}

void embaralhar(Flor flores[], int count)
{
    for (int i = 0; i < count; i++)
    {
        int j = rand() % count;
        Flor temp = flores[i];
        flores[i] = flores[j];
        flores[j] = temp;
    }
}