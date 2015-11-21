#ifndef FUNCTIONS_H
#define FUNCTIONS_H

void setObstacle (int **grille, int line, int column);

void setSnake (int **grille, int line, int column);

void setFree (int **grille, int line, int column);

void setCells (int **grille, int line, int column, int nbrCellsMax);

void setField (int **grille, int line, int column, int nbrCellsMax);

int **createArray(int line, int column);

int **setArray();

#endif /* FUNCTIONS_H */