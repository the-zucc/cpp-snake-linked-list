#define MAXLIGNES 25
#define MAXCOLONNES 80
#pragma once

class Serpent
{
public:
	Serpent(char * nom);
	~Serpent();
	void leJeu();
	char * getNom();
};