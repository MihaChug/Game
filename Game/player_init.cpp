#include "player.h"

Player::Player(Image &image, String Name, Level &level, float X, float Y, int W, int H) : Entity(image, Name, X, Y, W, H)
{
	playerScore = 0;
	state = right;
	obj = level.GetAllObjects();
	jump_sound_buffer.loadFromFile("music/jump.ogg");
	jump_sound.setBuffer(jump_sound_buffer);
	boost = 0;
	if (name == "P1")
	{
		sprite.setTextureRect(IntRect(0, 0, w, h));
	}
}
