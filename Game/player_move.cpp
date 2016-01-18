#include "player.h"

void Player::control()
{
	if (Keyboard::isKeyPressed)
	{
		if (Keyboard::isKeyPressed(Keyboard::A))
		{
			state = left;
			speed = 0.1;
		}
		if (Keyboard::isKeyPressed(Keyboard::D))
		{
			state = right;
			speed = 0.1;
		}

		if ((Keyboard::isKeyPressed(Keyboard::W)) && (onGround))
		{
			state = jump;
			dy = -0.45;
			onGround = false;
			jump_sound.play();
		}
	}
}