#include "Bonus.h"

void Bonus::animation(float &time)
{
	offset.y = 0;
	current_frame += time;
	if (current_frame > 48)
	{
		offset.x += 16;
		current_frame = 0;
	}
	if (offset.x >= 48)
	{
		offset.x = 0;
	}
	sprite.setTextureRect(IntRect(offset.x, offset.y, w, h));
}

void Bonus::update(float time)
{
	animation(time);
	//x += dx*time;
	//y += dy*time;
	//checkCollisionWithMap(0, dy);
	sprite.setPosition(x + w / 2, y + h / 2);
};