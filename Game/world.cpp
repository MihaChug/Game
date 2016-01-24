#include "world.h"


void World::InitWorldObjects() 
{
	InitImages();
	InitSounds();
	InitObjects();
}

void setPlayerCoordinateForView(View &view, float x, float y) {
	float tempX = x;
	float tempY = y;
	if (x < 175)
		tempX = 175;
	if (x > 3710)
		tempX = 3710;
	if (y < 150)
		tempY = 150;
	if (y > 200)
		tempY = 200;
	view.setCenter(tempX, tempY);
}

void World::UpdateWorld(float time, RenderWindow &window) 
{
	player->update(time);
	setPlayerCoordinateForView(view, player->sprite.getPosition().x, player->sprite.getPosition().y);
	for (it = entities.begin(); it != entities.end(); it++)
	{
		(*it)->update(time);
	}
	window.setView(view);
}

void World::DrawObjects(RenderWindow &window)
{
	lvl.Draw(window);
	for (it = entities.begin(); it != entities.end(); it++)
	{
		window.draw((*it)->sprite);
	}

	window.draw(player->sprite);
}



void World::LogicObjects()
{
	for (it = entities.begin(); it != entities.end(); it++)
	{
		if ((*it)->getRect().intersects(player->getRect()))
		{
			if ((*it)->name == "enemy" && (*it)->lives > 0)
			{
				if (player->dy > 0 && player->onGround == false)
				{
					(*it)->dx = 0;
					player->dy = -0.2;
					(*it)->lives = 0;
				}
				else
				{
					player->lives -= 1;
				}
			}
			if ((*it)->name == "bonus" )
			{
				player->lives = 0;
			}
		}
	}
}