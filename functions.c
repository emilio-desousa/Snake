#include <stdio.h>
#include <stdlib.h>
#include <graph.h>
#include <time.h>

void setObstacle (int **grille, int line, int column)
{
    if ( (line == 0) || (line == 41) || (column == 0) || (column== 61) )
    {
        grille[line][column] = 2;
    }
}

void setSnake (int **grille, int line, int column)
{
    if ((line==21) && (column==35))
    {
        grille[line][column] = 4;
    }else if ( (line == 21) && (column > 25 && column < 35) )
    {
        grille[line][column] = 12;
    }
}

void setFree (int **grille, int line, int column) 
{
    if ((line != 21) && (column < 26 && column > 35) )
    {
        grille[line][column] = 0;
    }
}

void setCells (int **grille, int line, int column, int nbrCellsMax)
{
    int nbrCells;
    nbrCells = 0;
    srand(time(NULL));
    while (nbrCells != nbrCellsMax) {
        line = (rand() % (41 - 1 + 1)) + 1;
        column = (rand() % (61 - 1 + 1)) + 1;
        if (grille[line][column] == 0)
        {
            grille[line][column] = 3;
            nbrCells++;   
        }
    }
}

void setField (int **grille, int line, int column, int nbrCellsMax)
{
    for (line = 0; line < 42; line++)
    {
        for (column = 0; column < 62; ++column)
        {
            setObstacle(grille, line, column);
            setFree(grille, line, column);
            setSnake(grille, line, column);
        }
    }
    setCells(grille, line, column, nbrCellsMax);
}

int **createArray(int line, int column) 
{
    int **grille;
    int i;
    line = 42;
    column = 62;
    grille = malloc(line * sizeof(int*));
    for (i = 0 ; i < line ; i++)
    {
        grille[i] = malloc(column * sizeof(int));
    }
    return grille;
}

int **setArray()
{
    int **grille;
    int nbrCellsMax;
    int line;
    int column;
    grille = createArray(line, column);
    nbrCellsMax = 5;
    line = 0;
    column = 0;
    setField(grille, line, column, nbrCellsMax);
    return grille;
}