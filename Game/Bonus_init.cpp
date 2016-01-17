#include "Bonus.h"

Bonus::Bonus(Image &image, String Name, enum Type, Level &level, float X, float Y, int W, int H) : Entity(image, Name, X, Y, W, H)
{
	obj = level.GetAllObjects();
	if (name == "Bonus")
	{
		sprite.setTextureRect(IntRect(0, 0, w, h));
	}
	if (type == "Coin")
	{
		Type = coin;
	}
	else if (type == "boost")
	{
		Type = boost;
	}
}
