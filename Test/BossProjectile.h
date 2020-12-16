#pragma once
#include<SFML\Graphics.hpp>

using namespace sf;

class BossProjectile
{
public:
	int direction = 3;
	int movementSpeed = 10;
	bool destroy = false;
	bool enemyprojectile = false;
	int AttackDamage = 5;
	int counterLifetime = 0;
	int Lifetime = 30;

	BossProjectile();
	~BossProjectile();

	void Update();
	void Update2();
	void Update3();

	RectangleShape bullet;
	Texture bulletTexture;

private:
};

