#pragma once
#include "player.h"

struct WorldInit 
{
public:
	View view;
	Music backgroundMusic;
	Level lvl;
	Image heroImage;
	Image EasyEnemyImage;
	Image NormalEnemyImage;
	Object playerObj;
	list<Entity*>  entities;
	vector<Object> enemies;
	unique_ptr<Player> player = nullptr;
	list<Entity*>::iterator it;
	list<Entity*>::iterator it2;
};