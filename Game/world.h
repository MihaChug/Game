#pragma once
#include "world_init.h"


struct World : public WorldInit 
{
public:
	void InitWorldObjects();
	void UpdateWorld(float time, RenderWindow &window);
	void DrawObjects(RenderWindow &window);
	void LogicObjects();
private:
	void InitObjects();
	void InitImages();
	void InitTextures();
	void InitSounds();
	void InitSprites();
};