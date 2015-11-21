#include <stdio.h>
#include <stdlib.h>
#include <graph.h>
#include "functions.h"

int	main(int argc, char *argv[]) 
{
	int i;
	int j;
    int grille[42][62];
    setArray(grille);
    for (i = 0; i < 42; ++i)
    {
        for (j = 0; j < 62; ++j)
        {
        	//printf("grille[%d][%d] => %d\n", i, j, grille[i][j]);
        }
    }
	return EXIT_SUCCESS;
}