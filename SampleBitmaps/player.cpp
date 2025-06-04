#include <allegro5\allegro.h>
#include <allegro5\allegro_primitives.h>
#include <allegro5\allegro_image.h>
#include "player.h"

player::~player()
{
	al_destroy_bitmap(image);
}
player::player(int HEIGHT)
{

	image = al_create_bitmap(64,64);   
	if(!image) {
		exit(1);
	}

	al_set_target_bitmap(image);
	al_clear_to_color(al_map_rgb(0, 0, 0));

	al_draw_filled_rectangle(0,25,64,39,al_map_rgb(75, 75, 75));
	al_draw_filled_rectangle(25,0,39,64,al_map_rgb(50, 50, 50));		
	al_draw_circle(32,32,8,al_map_rgb(0, 0, 0),5);

	al_draw_line(0,32,64,32,al_map_rgb(255, 100, 255),2);
	al_draw_line(32,0,32,64,al_map_rgb(255, 100, 255),2);
	al_draw_circle(32,32,16,al_map_rgb(200, 200, 200),5);
	
	al_draw_filled_triangle(32, 0, 16, 14, 48, 14, al_map_rgb(255, 80, 80));//added distinct shape to indicate where the image is facing

	x = 20;
	y = HEIGHT / 2;

	speed = 7;
	boundx = al_get_bitmap_width(image);
	boundy = al_get_bitmap_height(image);

}
void player::DrawPlayer()
{
	switch (direction) {
	case 0 : 
		al_draw_rotated_bitmap(image, boundx / 2, boundy / 2, x + boundx / 2, y + boundy / 2, 0, 0);
		break;
	case 1 :
		al_draw_rotated_bitmap(image, boundx / 2, boundy / 2, x + boundx / 2, y + boundy / 2, ALLEGRO_PI, 0);
		break;
	case 2 :
		al_draw_rotated_bitmap(image, boundx / 2, boundy / 2, x + boundx / 2, y + boundy / 2, -ALLEGRO_PI / 2, 0);
		break;
	case 3:
		al_draw_rotated_bitmap(image, boundx / 2, boundy / 2, x + boundx / 2, y + boundy / 2, ALLEGRO_PI / 2, 0);
		break;
		}
}
void player::MoveUp()
{
	restoreX = x;
	restoreY = y;
	y -= speed;
	if(y < 0)
		y = 0;
	direction = 0;
}
void player::MoveDown(int HEIGHT)
{
	restoreX = x;
	restoreY = y;
	y += speed;
	if(y > HEIGHT-boundy)
		y = HEIGHT-boundy;
	direction = 1;
}
void player::MoveLeft()
{
	restoreX = x;
	restoreY = y;
	x -= speed;
	if(x < 0)
		x = 0;
	direction = 2;
}
void player::MoveRight(int WIDTH)
{
	restoreX = x;
	restoreY = y;
	x += speed;
	if(x > WIDTH-boundx)
		x = WIDTH-boundx;
	direction = 3;
}

//returns the direction the player is facing
int player::getDirection() {
	return direction;
}

void player::Collideplayer(BadGuy BadGuys[], int cSize)
{

	for (int j = 0; j < cSize; j++)
	{
		int leftX = BadGuys[j].getX();
		int rightX = BadGuys[j].getX() + (BadGuys[j].getBoundX() + (BadGuys[j].getBoundX() * .25));
		int upY = BadGuys[j].getY();
		int downY = BadGuys[j].getY() + (BadGuys[j].getBoundY() + (BadGuys[j].getBoundY() * .25));

		if (x < rightX &&
			x + boundx > leftX &&
			y < downY &&
			y + boundy > upY)
		{
			x = restoreX;
			y = restoreY;
			break;
		}
	}
}