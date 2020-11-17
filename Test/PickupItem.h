#pragma once
#include"SFML\System.hpp"
#include"SFML\Window.hpp"
#include"SFML\Graphics.hpp"
#include"SFML\Audio.hpp"
#include"SFML\Network.hpp"
#include"HitboxComponent.h"
#include "Collider.h"

using namespace sf;

class PickupItem
{
public:
	bool destroy = false;
	RectangleShape item;
	int hpBox = 3;
	HitboxComponent hitboxBox;

	PickupItem(Texture* texture, Vector2f size, Vector2f hitboxsize, float offset_x, float offset_y, Vector2f playerPosition);
	Vector2f GetPosition() { return item.getPosition(); }
	Vector2f GetHalfSize() { return item.getSize(); }

	Collider GetCollider() { return Collider(item); }

	void Update();
	void setPosition(Vector2f pos);
	void Draw(RenderWindow& window);
};

