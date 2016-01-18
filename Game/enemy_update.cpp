#include "enemy.h"

void Enemy::update(float time)
{
	moveTimer += time;
	if (moveTimer>3000)
	{
		dx *= -1;
		moveTimer = 0;
	}
	checkCollisionWithMap(dx, 0);
	x += dx*time;
	checkCollisionWithMap(0, dy);
	y += dy*time;
	sprite.setPosition(x, y);
	if (lives <= 0) 
	{ 
		life = false; 
		dx = 0;
		dy = 0;
		sprite.setTextureRect(IntRect(0, 32, w, h));

	}
	dy = dy + 0.0015*time;
};