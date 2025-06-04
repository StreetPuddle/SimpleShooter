#ifndef PLAYERH
#define PLAYERH
#include <allegro5\allegro.h>
#include <allegro5\allegro_primitives.h>
#include "BadGuy.h"

class player
{
public:
	player(int HEIGHT);
	~player();
	void DrawPlayer();
	void MoveUp();
	void MoveDown(int HEIGHT);
	void MoveLeft();
	void MoveRight(int WIDTH);
	int getBoundX(){return boundx;}
	int getBoundY(){return boundy;}
	int getX(){return x;}
	int getY(){return y;}

	//returns the direction the player is facing
	int getDirection();

	//ensures the player doesn't clip through a badguy upon collision
	void player::Collideplayer(BadGuy BadGuys[], int cSize);
private:
	int x;
	int y;
	int speed;
	int boundx;
	int boundy;
	int archivedX;
	int archivedY;
	int direction;
	ALLEGRO_BITMAP *image;
};
#endif

