#include "enemy.h"

void Enemy::checkCollisionWithMap(float Dx, float Dy)
{
	for (int i = 0; i < obj.size(); i++)
		if (getRect().intersects(obj[i].rect))
		{
			if (obj[i].name == "block")
			{
				if (Dy > 0)
				{
					y = obj[i].rect.top - h / 2;
					dy = 0;
					onGround = true;
				}
				if (Dy < 0)
				{
					y = obj[i].rect.top + obj[i].rect.height;
					dy = 0;
				}
				if (Dx > 0)
				{
					x = obj[i].rect.left - w;
				}
				if (Dx < 0)
				{
					x = obj[i].rect.left + obj[i].rect.width;
				}
			}
		}
}
