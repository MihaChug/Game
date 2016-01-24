#pragma once
#include "player.h"

struct WorldInit 
{
public:
	View view;
	Music backgroundMusic;
	Level lvl;
	Image HeroImage, HeroBoost1Image, HeroBoost2Image;
	Image EasyEnemyImage;
	Image NormalEnemyImage;
	Image BonusImage;
	Object playerObj;
	list<Entity*>  entities;
	vector<Object> enemies;
	vector<Object> bonuses;
	unique_ptr<Player> player = nullptr;
	list<Entity*>::iterator it;
	list<Entity*>::iterator it2;
};