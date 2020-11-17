#pragma once
#define SFML_NO_DEPRECATED_WARNINGS
#include<SFML/Graphics.hpp>
#include"ViewPlayer.h"

using namespace sf;

class Chatbox
{
public:
	Texture chatboxTexture;
	Text chat1;
	RectangleShape chatbox;
	Font font, fonthpzombie, fontMenu;

	Chatbox(Vector2f size, Vector2f posi);
	~Chatbox();
	void Draw1(RenderWindow& window);

};

