#pragma once
#include<SFML/Graphics.hpp>
#include"Animation.h"
#include"Button.h"

using namespace sf;

class MenuBG
{
public:
	Texture howtop;
	Animation animation;
	RectangleShape bg, howtoplay;
	unsigned int row;
	Font fontmenu;
	Text mainText1, mainText2;
	Text textname, texttime, textdead;
	Button* buttonStory, * buttonEndless, * buttonHighscore, * buttonQuit, * buttonNewgame, * buttonLoadgame, * buttonBack, * buttonBack2, * buttonBack3, * buttonOK, * buttonHow;
	MenuBG(Texture* texture, Vector2u imageCount, float switchTime);
	~MenuBG();

	void UpdateBG(float deltaTime);
	void UpdateButton(const Vector2i& mousePosWindow);
	void UpdateButton2(const Vector2i& mousePosWindow);
	void UpdateButton3(const Vector2i& mousePosWindow);
	void UpdateButton4(const Vector2i& mousePosWindow);
	void DrawBG(RenderWindow& window);
	void DrawBG2(RenderWindow& window);
	void DrawBG3(RenderWindow& window);
	void DrawButton(RenderWindow& window);
	void DrawButton2(RenderWindow& window);
	void DrawButton3(RenderWindow& window);

};

