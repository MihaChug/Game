#include "enemy.h"

void Enemy::animation(float &time)
{
	offset.y = 0;
	current_frame += time;
	if (current_frame > 48)
	{
		offset.x += 16;
		current_frame = 0;
	}
	if (offset.x >= 32)
	{
		offset.x = 0;
	}
	sprite.setTextureRect(IntRect(offset.x, offset.y, w, h));
}

void Enemy::update(float time)
{
	moveTimer += time;
	animation(time);
	if (moveTimer > 3000)
	{
		dx *= -1;
		moveTimer = 0;
	}
	x += dx*time;
	//checkCollisionWithMap(dx, 0);
	y += dy*time;
	checkCollisionWithMap(0, dy);
	sprite.setPosition(x + w / 2, y);
	if (lives <= 0) 
	{ 
		life = false; 
		dx = 0;
		dy = 0;
		sprite.setTextureRect(IntRect(32, 0, w, h));

	}
	dy += 0.0015*time;
};