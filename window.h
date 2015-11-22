#ifndef WINDOW_H
#define WINDOW_H

int setWindow(int **grille, int *dir);
void fillSnake(int **g,int line,int column, int *dir);
void fillObstacle(int **g,int line,int column);
void fillCell(int **g,int line,int column);
void fillHead(int **g, int line,int column, int *dir);
void fillField(int **g, int *dir);
void refresh(int **g, int *dir);
int moveSnake(int **g, int *dir, double *head, double *tail);


#endif