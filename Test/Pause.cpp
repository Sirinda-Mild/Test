#define SFML_NO_DEPRECATED_WARNINGS
#include "Pause.h"

Pause::Pause() 
{
	fontmenu.loadFromFile("Font/menufont.ttf");
	framet.loadFromFile("Pause/frame3.png");

	frame.setSize(Vector2f(1366, 768));
	frame.setTexture(&framet);
	frame.setPosition(Vector2f(0, 0));

	buttonPlay = new Button(400, 170, 76, 25,
		&fontmenu, "Play", 55, Color(Color::White), Color(Color(200, 100, 100)), Color(Color(200, 100, 100)));
	buttonQuit2 = new Button(400, 290, 76, 25,
		&fontmenu, "Quit", 55, Color(Color::White), Color(Color(200, 100, 100)), Color(Color(200, 100, 100)));
	
}

Pause::~Pause()
{
}

void Pause::UpdateButton(const Vector2i& mousePosWindow)
{
	buttonPlay->update(mousePosWindow);
	buttonQuit2->update(mousePosWindow);
}

void Pause::DrawBG(RenderWindow& window)
{
	window.draw(frame);
}

void Pause::DrawButton(RenderWindow& window)
{
	buttonPlay->render(window);
	buttonQuit2->render(window);
}

