#include "world.h"
#include "player.h"
#include "enemy.h"
#include "Bonus.h"

void World::InitObjects()
{
	lvl.LoadFromFile("mario_lvl.tmx");

	playerObj = lvl.GetObject("player");
	player = make_unique<Player>(HeroImage, "P1", lvl, playerObj.rect.left, playerObj.rect.top, 16, 16);

	enemies = lvl.GetObjects("enemy");
	bonuses = lvl.GetObjects("bonus");
	for (int i = 0; i < enemies.size(); i++)
	{
		if (enemies[i].type == "easy")
		{
			entities.push_back(new Enemy(EasyEnemyImage, "enemy", "easy", lvl, enemies[i].rect.left, enemies[i].rect.top, 16, 16));
		}
		else if (enemies[i].type == "normal")
		{
			entities.push_back(new Enemy(NormalEnemyImage, "enemy", "normal", lvl, enemies[i].rect.left, enemies[i].rect.top, 16, 24));
		}
	}
	for (int i = 0; i < bonuses.size(); i++)
	{
		if (bonuses[i].type == "coin")
		{
			entities.push_back(new Bonus(BonusImage, "bonus", "coin", lvl, bonuses[i].rect.left, bonuses[i].rect.top, 16, 16));
		}
		else if (bonuses[i].type == "boost")
		{
			entities.push_back(new Bonus(BonusImage, "bonus", "boost", lvl, bonuses[i].rect.left, bonuses[i].rect.top, 16, 16));
		}
	}
	
}

void World::InitImages()
{
	HeroImage.loadFromFile("img/hero.png");
	HeroBoost1Image.loadFromFile("img/hero_boost_1.png");
	HeroBoost2Image.loadFromFile("img/hero_boost_2.png");
	EasyEnemyImage.loadFromFile("img/easy_enemy.png");
	NormalEnemyImage.loadFromFile("img/normal_enemy.png");
	BonusImage.loadFromFile("img/bonus.png");
}

void World::InitSounds()
{
	backgroundMusic.openFromFile("music/Mario_Theme.ogg");
	backgroundMusic.setLoop(true);
	backgroundMusic.play();
}