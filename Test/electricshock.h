#pragma once
#include<SFML/Graphics.hpp>
#include"Animation.h"
#include"Button.h"

using namespace sf;

class electricshock
{
public:
	Animation animation;
	RectangleShape electric;
	unsigned int row;
	electricshock(Texture* texture, Vector2u imageCount, float switchTime);
	~electricshock();

	void Draw(RenderWindow& window);
	void Update(float deltaTime);
};

