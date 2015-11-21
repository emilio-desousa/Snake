#include <stdio.h>
#include <stdlib.h>
#include <graph.h>
#include "functions.h"

int	main(int argc, char *argv[]) 
{
    int **grille;
	int column;
	int line;
    int nbrCells = 0;
    grille = setArray(grille);
    for (line = 0; line < 42; line++)
    {
        for (column = 0; column < 62; column++)
        {
            if (grille[line][column] == 1)
            {
                printf("Snake %d => grille[%d][%d]\n", column - 25, line, column);
            } else if (grille[line][column] == 3) 
            {
        	   printf("Cell %d => grille[%d][%d]\n", nbrCells, line, column);
               nbrCells++;
            }
        }
    }
	return EXIT_SUCCESS;
}