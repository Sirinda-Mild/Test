#pragma once
#include<SFML/Graphics.hpp>
#include"Button.h"
#include"ViewPlayer.h"

using namespace sf;

class Pause
{
public:
	ViewPlayer* view;
	Texture howtop, framet;
	RectangleShape frame, howtoplay;
	Font fontmenu;
	Button* buttonPlay, * buttonQuit2;
	Pause();
	~Pause();

	void UpdateButton(const Vector2i& mousePosWindow);
	void DrawBG(RenderWindow& window);
	void DrawButton(RenderWindow& window);

};

