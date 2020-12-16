#include "BossProjectile.h"

BossProjectile::BossProjectile()
{
	bulletTexture.loadFromFile("Item/bullet.png");
	bullet.setTexture(&bulletTexture);
	bullet.setSize(Vector2f(10, 10));
	bullet.setPosition(0, 0);
	bullet.setTextureRect(IntRect(0, 0, 50, 50));
}

BossProjectile::~BossProjectile()
{
}

void BossProjectile::Update()
{
	if (direction == 0) //left
	{
		bullet.move(-movementSpeed, 0);
	}
	if (direction == 1) //right
	{
		bullet.move(movementSpeed, 0);
	}
	if (direction == 2) //up
	{
		bullet.move(0, -movementSpeed);
	}
	if (direction == 3) //down
	{
		bullet.move(0, movementSpeed);
	}

	counterLifetime++;
	if (counterLifetime >= Lifetime)
	{
		destroy = true;
	}
}

void BossProjectile::Update2()
{
	if (direction == 0) //left
	{
		bullet.move(-movementSpeed, 0);
		bullet.move(0, -movementSpeed);
	}
	if (direction == 1) //right
	{
		bullet.move(movementSpeed, 0);
		bullet.move(0, -movementSpeed);
	}
	if (direction == 2) //up
	{
		bullet.move(movementSpeed, 0);
		bullet.move(0, -movementSpeed);
	}
	if (direction == 3) //down
	{
		bullet.move(movementSpeed, 0);
		bullet.move(0, movementSpeed);
	}

	counterLifetime++;
	if (counterLifetime >= Lifetime)
	{
		destroy = true;
	}
}

void BossProjectile::Update3()
{
	if (direction == 0) //left
	{
		bullet.move(-movementSpeed, 0);
		bullet.move(0, movementSpeed);
	}
	if (direction == 1) //right
	{
		bullet.move(movementSpeed, 0);
		bullet.move(0, movementSpeed);
	}
	if (direction == 2) //up
	{
		bullet.move(-movementSpeed, 0);
		bullet.move(0, -movementSpeed);
	}
	if (direction == 3) //down
	{
		bullet.move(-movementSpeed, 0);
		bullet.move(0, movementSpeed);
	}

	counterLifetime++;
	if (counterLifetime >= Lifetime)
	{
		destroy = true;
	}
}
