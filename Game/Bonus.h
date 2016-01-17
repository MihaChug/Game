#pragma once
#include "entity.h"

struct Bonus : public Entity
{
	enum { coin, boost } Type;
	Bonus(Image &image, String Name, enum Type, Level &level, float X, float Y, int W, int H);
	void checkCollisionWithMap(float Dx, float Dy);
	void update(float time);
};