#include <stdlib.h>
#include <string.h>
#pragma once
class Joueur
{
private:
	char * nom;
	int score;
	Joueur * gauche;
	Joueur * droite;
public:
	Joueur(char * nom, int score);
	~Joueur();
};

