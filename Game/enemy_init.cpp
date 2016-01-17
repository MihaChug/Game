#include "enemy.h"

Enemy::Enemy(Image &image, String Name, String Type, Level &lvl, float X, float Y, int W, int H) :Entity(image, Name, X, Y, W, H) 
{
	obj = lvl.GetObjects("block");
	if ((name == "enemy")&&(Type == "easy"))
	{
		sprite.setTextureRect(IntRect(0, 0, w, h));
		dx = 0.04;
	}
	else if ((name == "enemy") && (Type == "normal"))
	{
		sprite.setTextureRect(IntRect(0, 0, w, h));
		dx = 0.04;
	}
}
