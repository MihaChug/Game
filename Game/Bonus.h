#pragma once
#include "entity.h"

struct Bonus : public Entity
{
	enum { coin, boost } BonusType;
	Bonus(Image &image, String Name, String Type, Level &level, float X, float Y, int W, int H);
	int current_frame;
	void checkCollisionWithMap(float Dx, float Dy);
	void animation(float &time);
	void update(float time);
};