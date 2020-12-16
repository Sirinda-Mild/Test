#pragma once
#include"SFML\System.hpp"
#include"SFML\Window.hpp"
#include"SFML\Graphics.hpp"
#include"SFML\Audio.hpp"
#include"SFML\Network.hpp"
#include "Collider.h"

using namespace sf;

class Wall3
{
public:
	RectangleShape wall;
	Wall3(Vector2f size, Vector2f position);
	Vector2f GetPosition() { return wall.getPosition(); }
	Vector2f GetHalfSize() { return wall.getSize() / 2.0f; }
	bool destroy = false;

	Collider GetCollider() { return Collider(wall); }

	void Update();
	void Draw(RenderWindow& window);
private:
};

