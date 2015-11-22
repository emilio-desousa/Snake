#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <graph.h>
/*
HAUT=1
DROITE=2
BAS=3
GAUCHE=4
*/


void fillSnake(int **g,int line,int column,int direction)
{
	int x, y;
	x=column*15;
	y=line*15; 
	ChoisirCouleurDessin(CouleurParNom("Yellow"));
	if (direction==1 || direction==3)
	{
		RemplirRectangle(x,y,9,15);
	} else
	{
		RemplirRectangle(x,y,15,9);
	}	
}

void fillObstacle(int **g,int line,int column)
{
	
}

void fillCell(int **g,int line,int column)
{
	int x, y;
	x=column*15;
	y=line*15; 

	ChoisirCouleurDessin(CouleurParNom("Red"));
	RemplirArc(x,y,13,13,360,360);
}

void fillField(int **g)
{
	int line, column;
	for (line=1; line<41; line++)
	{
		for ( column = 1; column < 61; column++)
		{
			if (g[line][column]==1)
			{
				fillSnake(g,line,column,4);
			}
			/*else if (g[line][column]==2)
			{
				fillObstacle(g,line,column);
			}*/
			else if (g[line][column]==3)
			{
				fillCell(g,line,column);
			}
		}
	}
	
	
}

int setWindow(int **grille)
{
	InitialiserGraphique();
	CreerFenetre(50,50,930,680);
	EffacerEcran(CouleurParNom("black"));
	ChoisirCouleurDessin(CouleurParNom("Green"));
	DessinerRectangle(0,0,929,629);
	DessinerRectangle(14,14,899,599);
	fillField(grille);
	
}

