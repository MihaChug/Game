#pragma once
#include "world.h"

struct App {
public:
	App();
	~App();
	void Run();
private:
	RenderWindow *window;
	unique_ptr<World> world = nullptr;
private:
	void Events();
	void Draw();
	void Update(float const time);
};