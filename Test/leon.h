#pragma once
#include<SFML/Graphics.hpp>
#include"Animation.h"
#include"Chatbox.h"

class leon
{
public:
	leon(Texture* texture, Vector2u imageCount, float switchTime, float speed);

	void UpdateMovement(float deltaTime, Vector2f playerPosition, Vector2f size);
	void Draw(RenderTarget& window);

	Animation animation;
	RectangleShape leonk;
	Vector2f movement;
	float speed;
	unsigned int row;
	int face = 3;
};

