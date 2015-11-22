#include <stdio.h>
#include <stdlib.h>
#include <graph.h>
#include "functions.h"
#include "window.h"

int	main(int argc, char *argv[]) 
{
    int **grille;
	int column;
	int line;
    int nbrCells = 0;
    int dir=2;
    grille = setArray();
    setWindow(grille, &dir);

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
    unsigned long suivant=Microsecondes()+33333;
    unsigned long move=Microsecondes()+250000;
    double head=21.35;
    double tail=21.26;
    int fin=0;
    while(fin==0)
    {   
        if ((Microsecondes()>move) || (ToucheEnAttente()==1))
        {
            fin=moveSnake(grille,&dir,&head, &tail);
            move=Microsecondes()+250000;
        }
        if (Microsecondes()>suivant)
        {
            refresh(grille, &dir);
            suivant=Microsecondes()+33333;    
        }
        
    }
    
	return EXIT_SUCCESS;
}