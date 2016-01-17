#include "enemy.h"

void Enemy::checkCollisionWithMap(float Dx, float Dy)
{
	for (int i = 0; i<obj.size(); i++)
		if (getRect().intersects(obj[i].rect))
		{
			if (Dy>0)
			{
				y = obj[i].rect.top - h;  dy = 0; onGround = true;
			}
			if (Dy<0)
			{
				y = obj[i].rect.top + obj[i].rect.height;   dy = 0;
			}
			if (Dx>0)
			{
				x = obj[i].rect.left - w;  dx = -0.1;
			}
			if (Dx<0)
			{
				x = obj[i].rect.left + obj[i].rect.width; dx = 0.1;
			}
		}
}
