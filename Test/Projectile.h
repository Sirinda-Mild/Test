#pragma once
#include<SFML\Graphics.hpp>
#include"Player.h"

using namespace sf;

class Projectile
{
public:
	int direction = 3;
	int movementSpeed = 15;
	bool destroy = false;
	int gunAttackDamage = 1;
	int shotgunAttackDamage = 1;
	int counterLifetime = 0;
	int Lifetime = 14;

	Projectile();
	~Projectile();
	
	void Update();

	RectangleShape bullet;

private:
};

