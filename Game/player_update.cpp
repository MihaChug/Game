#include "player.h"

void Player::animation(float &time) 
{
	offset.y = 16;
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

void Player::update(float time)
{
	control();
	if (speed != 0) {
		animation(time);
	}
	else {
		sprite.setTextureRect(IntRect(0, 0, w, h));
	}
	switch (state)
	{
	case right:
		dx = speed;
		if (scale < 0) {
			scale = 1;
		}
		break;
	case left:
		dx = -speed;
		if (scale > 0)
		{ 
			scale = -1;
		}
		break;
	}
	x += dx*time;
	checkCollisionWithMap(dx, 0);
	y += dy*time;
	checkCollisionWithMap(0, dy);
	sprite.setPosition(x + w / 2, y + h / 2);
	sprite.setScale(scale, 1);
	if (lives <= 0)
	{
		life = false;
		exit(0);
	}
	if (!isMove)
	{
		speed = 0;
	}
	if (!onGround)
	{
		sprite.setTextureRect(IntRect(16, 0, 16, 16));
	}
	dy = dy + 0.0015*time;
}
