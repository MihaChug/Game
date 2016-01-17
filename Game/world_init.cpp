#include "world.h"
#include "player.h"
#include "enemy.h"

void World::InitObjects()
{
	lvl.LoadFromFile("level.tmx");

	playerObj = lvl.GetObject("player");
	player = make_unique<Player>(heroImage, "P1", lvl, playerObj.rect.left, playerObj.rect.top, 12, 16);

	enemies = lvl.GetObjects("enemy");
	for (int i = 0; i < enemies.size(); i++) {
		entities.push_back(new Enemy(enemyImage, "enemy", "easy",  lvl, enemies[i].rect.left, enemies[i].rect.top, 15, 16)); //TODO: type.
	}

}

void World::InitImages()
{
	heroImage.loadFromFile("img/hero.png");
	enemyImage.loadFromFile("img/easy_enemy.png");
}

void World::InitSounds()
{
	backgroundMusic.openFromFile("music/Mario_Theme.ogg");
	backgroundMusic.setLoop(true);
	backgroundMusic.play();
}