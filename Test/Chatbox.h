#pragma once
#define SFML_NO_DEPRECATED_WARNINGS
#include<SFML/Graphics.hpp>
#include"ViewPlayer.h"

using namespace sf;

class Chatbox
{
public:
	Text chat1;
	RectangleShape chatbox;
	Font font, fonthpzombie, fontMenu;

	Chatbox(Vector2f size, Vector2f posi, Texture* texture);
	~Chatbox();
	void Draw1(RenderWindow& window);

};

