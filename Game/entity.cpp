#include "entity.h"

Entity::Entity(Image &image, String Name, float X, float Y, int W, int H)
{
	x = X;
	y = Y;
	w = W;
	h = H;
	name = Name;
	moveTimer = 0;
	speed = 0;
	lives = 3;
	dx = 0;
	dy = 0;
	life = true;
	onGround = false;
	isMove = false;
	texture.loadFromImage(image);
	sprite.setTexture(texture);
	sprite.setOrigin(w / 2, h / 2);
}

Entity::~Entity() {};

FloatRect Entity::getRect()
{
	return FloatRect(x, y, w, h);
}
