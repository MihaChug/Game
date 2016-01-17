#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <iostream>
#include <sstream>
#include <list>
#include <vector>
#include "level.h"
#include <memory>

using namespace sf;
using namespace std;

struct Entity {
	std::vector<Object> obj;
	float dx, dy, x, y, speed, moveTimer;
	int w, h, lives;
	bool life, isMove, onGround;
	Texture texture;
	Sprite sprite;
	String name, type;

	Entity(Image &image, String Name, float X, float Y, int W, int H);

	FloatRect getRect();

	virtual void update(float time) = 0;
	virtual ~Entity();
};