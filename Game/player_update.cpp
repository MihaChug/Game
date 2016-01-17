#include "player.h"

void Player::update(float time)
{
	control();
	switch (state)
	{
	case right:dx = speed; break;
	case left:dx = -speed; break;
	}

	x += dx*time;
	checkCollisionWithMap(dx, 0);
	y += dy*time;
	checkCollisionWithMap(0, dy);
	sprite.setPosition(x + w / 2, y + h / 2);
	if (lives <= 0)
	{
		life = false;
		exit(0);
	}
	if (!isMove)
	{
		speed = 0;
	}
	dy = dy + 0.0015*time;
}
