#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <conio.h>
#include <time.h>

#include "Serpent.h"

//#include "ScoreBoard.h"

#define MAXBUFFER 15

int getligne(char *s, int taille){
	int i, c;

	i = 0;
	c = getchar();
	while (c != EOF && c != '\n' && i < taille - 1)
	{
		s[i] = c;
		i++;
		c = getchar();
	}

	if (c == EOF)
		return -1;

	s[i] = '\0';
	if (s[0] == 'q' || s[0] == 'Q')
		return -1;
	return i;
}

void main(){
	srand(time(NULL));
	//début du programme
	char * s = (char*)malloc(sizeof(char)*MAXBUFFER);
	getligne(s, MAXBUFFER);
	Serpent leSerpent = Serpent(s);
	leSerpent.leJeu();
	_getch();

}