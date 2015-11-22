#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <graph.h>
#include <math.h>
/*
HAUT=1
DROITE=2
BAS=3
GAUCHE=4
*/


void fillSnake(int **g,int line,int column,int *dir)
{
	int x, y;
	x=column*15;
	y=line*15; 
	ChoisirCouleurDessin(CouleurParNom("Yellow"));
	if (g[line][column]==11 || g[line][column]==13)   //RemplirRectangle(x+3,y,9,15);
	{
		RemplirRectangle(x,y,15,15);
	} else
	{
		RemplirRectangle(x,y,15,15);
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

void fillHead(int **g, int line,int column, int *dir)
{
	int x,y;
	x=column*15;
	y=line*15;
	ChoisirCouleurDessin(CouleurParNom("Yellow"));
	if (*dir==1)
	{
		RemplirTriangle(x,y+15,x+15,y+15,x+7,y);
	}else if (*dir==2)
	{
		RemplirTriangle(x,y,x,y+15,x+15,y+7);
	}else if (*dir==3)
	{
		RemplirTriangle(x,y,x+15,y,x+7,y+15);
	}else 
	{
		RemplirTriangle(x+15,y,x+15,y+15,x,y+7);
	}

}

void fillField(int **g, int *dir)
{
	int line, column;
	for (line=1; line<41; line++)
	{
		for ( column = 1; column < 61; column++)
		{
			if ((g[line][column]>10) && (g[line][column]<15))
			{
				fillSnake(g,line,column,dir);
			}
			/*else if (g[line][column]==2)
			{
				fillObstacle(g,line,column);
			}*/
			else if (g[line][column]==3)
			{
				fillCell(g,line,column);
			}else if (g[line][column]==4)
			{
				fillHead(g,line,column,dir);
			}
		}
	}
	
	
}

int setWindow(int **grille, int *dir)
{
	InitialiserGraphique();
	CreerFenetre(50,50,930,680);
	EffacerEcran(CouleurParNom("black"));
	ChoisirCouleurDessin(CouleurParNom("Green"));
	DessinerRectangle(0,0,929,629);
	DessinerRectangle(14,14,899,599);
	fillField(grille,dir);
}

int moveSnake(int **g, int *dir, double *head, double *tail)
{
	int line, column,t;
	double c;
	if (ToucheEnAttente()==1)
	{
		t=Touche();
		if ((t==XK_Right))
		 {
		 	printf("Right\n");
		 	*dir=2;
		 	//refresh(g);
		 }else if ((t==XK_Left))
		{
			printf("Left\n");
			*dir=4;
			//refresh(g);
		}else if ((t==XK_Up))
		{
			printf("Up\n");
			*dir=1;
			//refresh(g);
		}else if ((t==XK_Down))
		{
			printf("Down\n");
			*dir=3;
			//refresh(g);
		}
	}
	c=floor(*head);
	line=(int)(c);

	c=floor((*head-c)*100);
	column=(int)(c);
	printf("next= %lf\n", *head);
	printf("line= %d\n",line );
	printf("column= %d\n",column);

	g[line][column]=10+*dir;

	if (*dir==1)
	{
		line--;
		*head=*head-1;
	}else if (*dir==2)
	{
		column++;
		*head=*head+0.01;
	}else if (*dir==3)
	{
		line++;
		*head=*head+1;
	}else
	{
		column--;
		*head=*head-0.01;
	}
	if ((line<41) && (column<61) && ((g[line][column]==0) || (g[line][column]==3)))
	{
		g[line][column]=4;
		return 0;
	}else 
	{
		return 1;
	}
	
}

void refresh(int **g, int *dir)
{
	ChoisirEcran(1);
	EffacerEcran(CouleurParNom("black"));
	ChoisirCouleurDessin(CouleurParNom("Green"));
	DessinerRectangle(0,0,929,629);
	DessinerRectangle(14,14,899,599);
	fillField(g, dir);
	ChoisirEcran(0);
	CopierZone(1,0,0,0,930,680,0,0);
	printf("Refresh\n");
}