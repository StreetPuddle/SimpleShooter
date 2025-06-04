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
	int getDirection();
	void player::Collideplayer(BadGuy BadGuys[], int cSize);
private:
	int x;
	int y;
	int speed;
	int boundx;
	int boundy;
	int restoreX;
	int restoreY;
	int direction;
	ALLEGRO_BITMAP *image;
};
#endif

