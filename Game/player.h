#pragma once
#include "entity.h"

struct Player: public Entity
{
	enum { left, right, jump } state;
	Player(Image &image, String Name, Level &level, float X, float Y, int W, int H);
	int playerScore;
	int boost;
	int current_frame;
	SoundBuffer jump_sound_buffer;
	Sound jump_sound;
	void control();
	void checkCollisionWithMap(float Dx, float Dy);
	void update(float time);
};