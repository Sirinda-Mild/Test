/*#pragma once
#include<SFML/Graphics.hpp>
#include"Button.h"

using namespace sf;
using namespace std;

class Menu
{
private:
	//function
	void initKeybinds();
	Texture menuBG;
	RectangleShape background;
	Font fontMenu;

public:
	Menu(RenderWindow* window);
	~Menu();

	//function
	void endState();
	
	void updateInput(const float& dt);
	void update(const float& dt);
	void render(RenderWindow& window);
	Button* buttonNewgame, * buttonQuit;
};*/

