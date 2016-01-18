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
	current_frame += 0,005 * time;
	if (current_frame >= 4)
	{
		offset.x += 16;
		current_frame -= 4;
	}
	if (offset.x > 32)
	{
		offset.x = 0;
	}
	if (dx >= 0)
	{
		sprite.setTextureRect(IntRect(offset.x, offset.y, w, h));
	}
	else if (dx <= 0)
	{
		sprite.setTextureRect(IntRect(offset.x, offset.y, w, h));
	}

	if (lives <= 0)
	{
		life = false;
		exit(0);
	}
	if (!isMove)
	{
		speed = 0;
		sprite.setTextureRect(IntRect(0, 0, w, h));
	}

	if (!onGround)
	{
		sprite.setTextureRect(IntRect(13, 0, 16, 16));
	}
	dy = dy + 0.0015*time;
}
