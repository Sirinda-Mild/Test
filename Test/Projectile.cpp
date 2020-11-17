#include "Projectile.h"

Projectile::Projectile()
{
	bullet.setPosition(0, 0);
	bullet.setTextureRect(IntRect(0,0,50,50));
}

Projectile::~Projectile()
{
}

void Projectile::Update()
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
