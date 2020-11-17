#pragma once
#include<iostream>
#include<ctime>
#include<cstdlib>
#include<vector>

#include"SFML\System.hpp"
#include"SFML\Window.hpp"
#include"SFML\Graphics.hpp"
#include"SFML\Audio.hpp"
#include"SFML\Network.hpp"

using namespace sf;

class HitboxComponent
{
public:
	HitboxComponent(float offset_x, float offset_y, Vector2f size, Vector2f playerPosition);
	~HitboxComponent();

	RectangleShape hitbox;
	bool checkIntersect(const FloatRect& frect);

	void Update(Vector2f playerPosition, float offset_x, float offset_y);
	void Draw(RenderWindow& window);
private:
};

