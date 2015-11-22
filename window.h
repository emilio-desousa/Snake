#ifndef WINDOW_H
#define WINDOW_H

int setWindow(int **grille);
void fillSnake(int **g,int line,int column, int direction);
void fillObstacle(int **g,int line,int column);
void fillCell(int **g,int line,int column);
void fillField(int **g);

#endif