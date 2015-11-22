#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/*
HAUT=1
DROITE=2
BAS=3
GAUCHE=4
*/

int main()
{
	InitialiserGraphique();
	CreerFenetre(50,50,930,680);
	EffacerEcran(CouleurParNom("black"));
	ChoisirCouleurDessin(CouleurParNom("Green"));
	
	RemplirArc(0,0,200,200,360,360);
	Touche();
	FermerGraphique();
	return EXIT_SUCCESS;
}