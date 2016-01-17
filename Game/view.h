#pragma once

using namespace sf;

static View view;
static void setPlayerCoordinateForView(float x, float y) {
	float tempX = x; float tempY = y;
	if (x < 175) tempX = 175;
	if (x > 1505) tempX = 1505;
	if (y < 150) tempY = 150; 
	if (y > 200) tempY = 200;
	view.setCenter(tempX, tempY);
}