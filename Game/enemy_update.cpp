#include "enemy.h"

void Enemy::update(float time)
{
	if (name == "enemy")
	{
		moveTimer += time;
		if (moveTimer>3000)
		{
			dx *= -1;
			moveTimer = 0;
		}
		checkCollisionWithMap(dx, 0);
		x += dx*time;
		sprite.setPosition(x + w / 2, y + h / 2);
		if (lives <= 0) { life = false; }
	}
};