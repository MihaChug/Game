#include "app.h"

App::App() 
{
	window = new RenderWindow(VideoMode(640, 480), "Game");
	world = make_unique<World>();
	world->view.reset(FloatRect(0, 0, 320, 240));
	Run();
}

App::~App()
{
	delete window;
}

void App::Events()
{
	Event event;
	while (window->pollEvent(event))
	{
		if (event.type == Event::Closed)
			window->close();
	}

}

void App::Draw()
{
	window->clear(Color(0, 0, 0));
	world->DrawObjects(*window);
	window->display();
}

void App::Update(float const time) 
{
	world->LogicObjects();
	world->UpdateWorld(time,*window);
}

void App::Run()
{
	world->InitWorldObjects();
	Clock clock;
	while (window->isOpen())
	{
		float time = clock.getElapsedTime().asMicroseconds();
		clock.restart();
		time = time / 800;
		Events();
		Update(time);
		Draw();
	}
}