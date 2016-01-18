#include "world.h"
#include "player.h"
#include "enemy.h"

void World::InitObjects()
{
	lvl.LoadFromFile("mario_lvl.tmx");

	playerObj = lvl.GetObject("player");
	player = make_unique<Player>(heroImage, "P1", lvl, playerObj.rect.left, playerObj.rect.top, 16, 16);

	enemies = lvl.GetObjects("enemy");
	for (int i = 0; i < enemies.size(); i++)
	{
		if (enemies[i].type == "easy")
		{
			entities.push_back(new Enemy(EasyEnemyImage, "enemy", "easy", lvl, enemies[i].rect.left, enemies[i].rect.top, 16, 16)); //TODO: type.
		}
		else if (enemies[i].type == "normal")
		{
			entities.push_back(new Enemy(NormalEnemyImage, "enemy", "normal", lvl, enemies[i].rect.left, enemies[i].rect.top, 16, 24));
		}
	}

}

void World::InitImages()
{
	heroImage.loadFromFile("img/hero.png");
	EasyEnemyImage.loadFromFile("img/easy_enemy.png");
	NormalEnemyImage.loadFromFile("img/normal_enemy.png");

}

void World::InitSounds()
{
	backgroundMusic.openFromFile("music/Mario_Theme.ogg");
	backgroundMusic.setLoop(true);
	backgroundMusic.play();
}