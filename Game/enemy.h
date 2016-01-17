#pragma once
#include "entity.h"

struct Enemy: public Entity
{
	enum { easy, normal, boss } type;
	Enemy(Image &image, String Name, String Type, Level &lvl, float X, float Y, int W, int H);
	void checkCollisionWithMap(float Dx, float Dy);
	void update(float time);
};