#pragma once
#define SFML_NO_DEPRECATED_WARNINGS
#include<SFML/Graphics.hpp>

using namespace sf;

class GenBar
{
public:
	RectangleShape genframe, genbar;
	GenBar(Vector2f hitboxposi);

	void Update(Vector2f size);
	void Draw(RenderWindow& window);
};

