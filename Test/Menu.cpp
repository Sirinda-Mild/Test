/*#include "Menu.h"

void Menu::initKeybinds()
{
}

Menu::Menu(RenderWindow* window)
{
	fontMenu.loadFromFile("Font/menufont.ttf");
	menuBG.loadFromFile("Menu/mainmenu2.png");
	background.setSize(Vector2f(static_cast<float>(window->getSize().x), static_cast<float>(window->getSize().y)));
	background.setTexture(&menuBG);

	buttonNewgame = new Button(100, 100, 150, 50, 
		&fontMenu, "New Game", 16, Color(Color::White), Color(Color::Red), Color(Color::Red));
	buttonQuit = new Button(100, 300, 150, 50,
		&fontMenu, "Quit", 16, Color(Color::White), Color(Color::Red), Color(Color::Red));
}

Menu::~Menu()
{

}

void Menu::endState()
{
}

void Menu::updateInput(const float& dt)
{
}

void Menu::update(const float& dt)
{
}

void Menu::render(RenderWindow& window)
{
	window.draw(background);
	buttonNewgame->render(window);
	buttonQuit->render(window);

}*/
