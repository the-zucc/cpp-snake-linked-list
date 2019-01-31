#include <stdlib.h>
#include <string.h>
#include "ScoreBoard.h"
#include "Joueur.h"

struct joueur{
	char * nom;
	int score;
	joueur * droite;
	joueur * gauche;
};

struct joueur * initJoueur(char * nom, int score){
	joueur * nouveau = (joueur *)malloc(sizeof(joueur));
	/*
	nouveau->nom = (char *)malloc(strlen(nom)*sizeof(char)+1);
	strcpy(nouveau->nom, nom);
	*/
	nouveau->nom = nom;
	nouveau->score = score;
	nouveau->droite = NULL;
	nouveau->gauche = NULL;
}

/*


FAIRE EN UTILISANT LES ARBRES!!!!!!!!!!
pour ordonner les scores, etc


*/

ScoreBoard::ScoreBoard(){

}
void ScoreBoard::ajouterJoueurDatabase(char * nom, int score){

}