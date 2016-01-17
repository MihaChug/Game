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
	if (x > 1505)
		tempX = 1505;
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
		if ((*it)->getRect().intersects(player->getRect()))
		{
			if ((*it)->name == "enemy")
			{
				if ((player->dy>0) && (player->onGround == false))
				{
					(*it)->dx = 0;
					player->dy = -0.2; //TODO: magic -> const;
					(*it)->lives = 0;
				}
				else {
					player->lives = 0;
				}
			}
		}
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
			if ((*it)->name == "enemy")
			{
				if ((player->dy>0) && (player->onGround == false))
				{
					(*it)->dx = 0;
					player->dy = -0.2;
					(*it)->lives = 0;
				}
				else {
					player->lives = 0;
				}
			}
		}
		for (it2 = entities.begin(); it2 != entities.end(); it2++) {
			if ((*it)->getRect() != (*it2)->getRect())
				if (((*it)->getRect().intersects((*it2)->getRect())) && ((*it)->name == "Enemy") && ((*it2)->name == "Enemy"))
				{
					(*it)->dx *= -1;
					(*it)->sprite.scale(-1, 1);
				}
		}
	}
}