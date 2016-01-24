#include "enemy.h"

Enemy::Enemy(Image &image, String Name, String Type, Level &lvl, float X, float Y, int W, int H) :Entity(image, Name, X, Y, W, H) 
{
	obj = lvl.GetAllObjects();
	lives = 1;
	dx = 0.02;
	offset = { 0, 0 };
	if ((Name == "enemy") && (Type == "easy"))
	{
		sprite.setTextureRect(IntRect(0, 0, w, h));
	}
	else if ((Name == "enemy") && (Type == "normal"))
	{
		sprite.setTextureRect(IntRect(0, 0, w, h));
	}
}
