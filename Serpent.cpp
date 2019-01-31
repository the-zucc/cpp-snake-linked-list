#include "Serpent.h"
#include <stdlib.h>
#include <stdio.h>
#include <conio.h>
#include <string.h>
#include "C:/Users/Laurier/Documents/DOCS A CONSERVER - IMPORANT/Cours CVM/2015-2016 Automne - B11 Programmation structurée/headers c-c++/cvm.h"


struct pointSerpent{
	int x, y;
	struct pointSerpent * prochain;
};

//variables
char * nomJoueur;
pointSerpent * queueSerpent;
pointSerpent * pointARamasser;
char direction;
bool perdu;

//prototypes des methodes
pointSerpent * initPointSerpent(int x, int y);//initie un point de serpent avec un x et un y
pointSerpent * pop();
void push(int x, int y);//push quelque chose a la fin de la file
void initPointARamasser();//initie un point à ramasser


pointSerpent * initPointSerpent(int x, int y){
	pointSerpent * nouveau = (pointSerpent *)malloc(sizeof(pointSerpent));
	nouveau->x = x;
	nouveau->y = y;
	nouveau->prochain = NULL;
	return nouveau;
}
//initie un point de serpent avec un x et un y
void initPointARamasser(){
	pointARamasser = initPointSerpent(rand() % MAXCOLONNES, rand() % MAXLIGNES);
}
//initie un nouveau point à ramasser
void ramasserPointARamasser(){
	pointSerpent * tmp = queueSerpent;
	while (tmp->prochain != NULL)
		tmp = tmp->prochain;
	tmp->prochain = pointARamasser;
}
//ramasse le point à ramasser
void detruirePointSerpent(pointSerpent * point){
	free(point);
}
//les fonctions push() et pop()
void push(int x, int y){//push quelque chose a la fin de la file
	if (queueSerpent == NULL){
		queueSerpent = initPointSerpent(x, y);
	}
	else{
		struct pointSerpent * tmp = queueSerpent;
		while (tmp->prochain != NULL)
			tmp = tmp->prochain;
		tmp->prochain = initPointSerpent(x, y);
	}
}
pointSerpent * pop(){//pop la queueSerpent de la file
	struct pointSerpent * tmp = queueSerpent;
	queueSerpent = queueSerpent->prochain;
	return tmp;
}


//les focntions d'affichage
void bougerSerpent(char direction){
	pointSerpent * teteSerpent = queueSerpent;
	while (teteSerpent->prochain != NULL){
		if (teteSerpent != queueSerpent){
			if (teteSerpent->x == queueSerpent->x)
				if (teteSerpent->y == queueSerpent->y)
					perdu == true;
		}
		teteSerpent = teteSerpent->prochain;
	}
		
	int x, y;
	switch (direction){
	case 'w':
		x = teteSerpent->x; y = teteSerpent->y - 1; push(x, y); break;
	case 's':
		x = teteSerpent->x; y = teteSerpent->y + 1; push(x, y); break;
	case 'a':
		x = teteSerpent->x - 1; y = teteSerpent->y; push(x, y); break;
	case 'd':
		x = teteSerpent->x + 1; y = teteSerpent->y; push(x, y);
	}
	if (x == 80 || y == 25 || x == -1 || y == -1)
		perdu = true;
	pointSerpent * tmp = queueSerpent;
	while (tmp->prochain != NULL){
		if (tmp != teteSerpent){
			if (tmp->x == teteSerpent->x){
				if (tmp->y == teteSerpent->y){
					perdu = true;	
				}	
			}
		}
		tmp = tmp->prochain;
	}

	if (!(pointARamasser->x == x && pointARamasser->y == y))
		detruirePointSerpent(pop());
	else{
		detruirePointSerpent(pointARamasser);
		initPointARamasser();
	}

}
void imprimerPoint(struct pointSerpent * point){
gotoxy(point->x, point->y);
printf("0");
}//imprime un point passe en parametre
/*
void imprimerPointDebug(struct pointSerpent * point, int i){//imprime les coordonnees d'un point ainsi qu'un '0' aux coordonnees cartesiennes correspondantes
	printf("point %d:\n", i);
	printf("x: %d\n", point->x);
	printf("y: %d\n\n", point->y);
	imprimerPoint(point);
}*/
void imprimerEcran(){
	struct pointSerpent * tmp = queueSerpent;
	while (tmp != NULL){
		imprimerPoint(tmp);
		tmp = tmp->prochain;
	}
}/*
void imprimerGameOver(){
	int longueurMin = 34;
	int longueurMax = 49;
	int hauteurMin = 10;
	int hauteurMax = 14;
	for (int i = longueurMin; i <= longueurMax; i++){
		for (int j = hauteurMin; j < hauteurMax; j++){
			gotoxy(i, j);
			if (i == longueurMax || i == longueurMin || j == hauteurMax || j == hauteurMin){
				
				printf("*");
			}
			else
				printf(" ");
		}
	}
}
*/
//la fonction principale: le Tick.
void unTick(){
	Sleep(50);
	if (_kbhit()){
		char directionTMP = _getch();
		if (direction == 'w' && directionTMP != 's' || direction == 'a' && directionTMP != 'd' || direction == 's' && directionTMP != 'w' || direction == 'd' && directionTMP != 'a')
			direction = directionTMP;
	}
	bougerSerpent(direction);
	system("cls");
	imprimerEcran();
	imprimerPoint(pointARamasser);
}

//code visible à l'extérieur de la classe

void Serpent::leJeu(){
	while (!perdu)
		unTick();
}
Serpent::Serpent(char * nom)
{
	perdu = false;
	nomJoueur = nom;
	initPointARamasser();
	queueSerpent = NULL;
	direction = 's';
	push(0, 0);
	push(0, 1);
	push(0, 2);
	push(0, 3);
	
}
Serpent::~Serpent()
{
	//détruire et libérer les espaces mémoire
}
