#include <stdio.h>
#include <stdlib.h>
#include <graph.h>
#include <time.h>

void setArray(int g[42][62])
{
	int column;
    int line;
    int nbrPomme;
    int nbrPommeMax;
    nbrPommeMax = 5;
    nbrPomme = 0;
    for (line = 0; line < 42; line++)
    {
        for (column = 0; column < 62; ++column)
        {
            if ( (line == 0) || (line == 41) || (column == 0) || (column== 61) )
            {
                g[line][column] = 2;
            } else 
            {
                if ((line == 21) && (column > 25 && column < 36) )
                {
                    g[line][column] = 1;
                    printf("snake %d => grille[%d][%d]\n", column - 25, line, column);
                } else 
                {
                    g[line][column] = 0;  
                }
            }
        }
    }
    srand(time(NULL));
    while (nbrPomme != nbrPommeMax) {
        line = (rand() % (41 - 1 + 1)) + 1;
        column = (rand() % (61 - 1 + 1)) + 1;
        if (g[line][column] == 0)
        {
            g[line][column] = 3;
            printf("pomme %d => grille[%d][%d]\n", nbrPomme, line, column);
            nbrPomme++;   
        }
    }
}