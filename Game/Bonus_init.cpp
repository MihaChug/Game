#include "Bonus.h"

Bonus::Bonus(Image &image, String Name, String Type, Level &level, float X, float Y, int W, int H) : Entity(image, Name, X, Y, W, H)
{
	obj = level.GetAllObjects();
	dx = 0;
	offset = { 0, 0 };
	if (name == "Bonus")
	{
		sprite.setTextureRect(IntRect(0, 0, w, h));
	}
	if (Type == "Coin")
	{
		BonusType = coin;
	}
	else if (Type == "boost")
	{
		BonusType = boost;
	}
}
