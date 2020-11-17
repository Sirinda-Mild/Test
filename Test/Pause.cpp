#define SFML_NO_DEPRECATED_WARNINGS
#include "Pause.h"

Pause::Pause() 
{
	fontmenu.loadFromFile("Font/menufont.ttf");
	framet.loadFromFile("Pause/frame3.png");

	frame.setSize(Vector2f(1366, 768));
	frame.setTexture(&framet);
	frame.setPosition(Vector2f(0, 0));

	howtop.loadFromFile("Menu/howtoplay.png");
	howtoplay.setSize(frame.getSize());
	howtoplay.setPosition(Vector2f(frame.getPosition().x, frame.getPosition().y));
	howtoplay.setTexture(&howtop);

	buttonPlay = new Button(315, 150, 76, 25,
		&fontmenu, "Play", 45, Color(Color::White), Color(Color(200, 100, 100)), Color(Color(200, 100, 100)));
	buttonHowTP = new Button(315, 230, 76, 25,
		&fontmenu, "How to play", 45, Color(Color::White), Color(Color(200, 100, 100)), Color(Color(200, 100, 100)));
	buttonMenu = new Button(315, 310, 76, 25,
		&fontmenu, "Menu", 45, Color(Color::White), Color(Color(200, 100, 100)), Color(Color(200, 100, 100)));
	
}

Pause::~Pause()
{
}

void Pause::UpdateButton(const Vector2i& mousePosWindow)
{
	buttonPlay->update(mousePosWindow);
	buttonHowTP->update(mousePosWindow);
	buttonMenu->update(mousePosWindow);
}

void Pause::DrawBG(RenderWindow& window)
{
	window.draw(frame);
}

void Pause::DrawButton(RenderWindow& window)
{
	buttonPlay->render(window);
	buttonHowTP->render(window);
	buttonMenu->render(window);
}

