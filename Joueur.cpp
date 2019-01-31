#include "Joueur.h"


Joueur::Joueur(char * nom, int score)
{
	Joueur::nom = (char *)malloc((strlen(nom)+1)*sizeof(char));
	strcpy(Joueur::nom, nom);
	Joueur::score = score;
}


Joueur::~Joueur()
{
}
