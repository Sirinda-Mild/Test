#include "Enemy.h"

Enemy::Enemy(Texture* texture, Vector2u imageCount, float switchTime, float speed) :
	animation(texture, imageCount, switchTime)
{
	this->speed = speed;
	row = 4;

	enemy.setSize(Vector2f(30.0f, 55.0f));
	enemy.setOrigin(enemy.getSize() / 2.0f);
	enemy.setPosition(100.0f, 200.0f);
	enemy.setTexture(texture);
}

Enemy::~Enemy()
{
}

void Enemy::UpdateMovement(float deltaTime, Vector2f playerPosition, Vector2f size)
{
	float deltaX = enemy.getPosition().x - playerPosition.x;
	float deltaY = enemy.getPosition().y - playerPosition.y;
	float intersectX = abs(deltaX) - ((enemy.getSize().x / 2) + (size.x / 2));
	float intersectY = abs(deltaY) - ((enemy.getSize().y / 2) + (size.y / 2));
	movement = (Vector2f(0.0f, 0.0f));

	if (intersectX < 200.0f && intersectY < 200.0f)
	{
		if (intersectX > intersectY)
		{
			if (deltaX > 5.0f)
			{
				if (canMoveL == true) {
					movement.x -= speed * deltaTime;
					row = 3;
					face = 0;
					canMoveL = true;
					canMoveR = true;
					canMoveUp = true;
					canMoveDown = true;
				}
				/*else if(canMoveL == false)
				{
					if (deltaY > 0 && canMoveUp == true) {
						movement.y -= speed * deltaTime;
						row = 0;
						face = 2;
					}
					if (deltaY < 0 && canMoveDown == true) {
						movement.y += speed * deltaTime;
						row = 2;
						face = 3;
					}
				}*/
			}
			else if (deltaX < -5.0f)
			{
				if (canMoveR == true) {
					movement.x += speed * deltaTime;
					row = 1;
					face = 1;
					canMoveL = true;
					canMoveR = true;
					canMoveUp = true;
					canMoveDown = true;
				}
				/*else if (canMoveR == false)
				{
					if (deltaY > 0 && canMoveUp == true) {
						movement.y -= speed * deltaTime;
						row = 0;
						face = 2;
					}
					if (deltaY < 0 && canMoveDown == true) {
						movement.y += speed * deltaTime;
						row = 2;
						face = 3;
					}
				}*/
			}
		}
		else
		{
			if (deltaY > 5.0f)
			{
				if (canMoveUp == true) {
					movement.y -= speed * deltaTime;
					row = 0;
					face = 2;
					canMoveL = true;
					canMoveR = true;
					canMoveUp = true;
					canMoveDown = true;
				}
				/*else if (canMoveUp == false)
				{
					if (deltaX > 0 && canMoveL == true) {
						movement.x -= speed * deltaTime;
						row = 3;
						face = 0;
					}
					if (deltaX < 0 && canMoveR == true) {
						movement.x += speed * deltaTime;
						row = 1;
						face = 1;
					}
				}*/
			}
			else if(deltaY < -5.0f)
			{
				if (canMoveDown == true) {
					movement.y += speed * deltaTime;
					row = 2;
					face = 3;
					canMoveL = true;
					canMoveR = true;
					canMoveUp = true;
					canMoveDown = true;
				}
				/*else if (canMoveDown == false)
				{
					if (deltaX > 0 && canMoveL == true) {
						movement.x -= speed * deltaTime;
						row = 3;
						face = 0;
					}
					if (deltaX < 0 && canMoveR == true) {
						movement.x += speed * deltaTime;
						row = 1;
						face = 1;
					}
				}*/
			}
		}
	}
	else if (movement.x == 0.0f && movement.y == 0.0f)
	{
		row = 4;
	}

	animation.Update(row, deltaTime);
	enemy.setTextureRect(animation.uvRect);
	enemy.move(movement);
}

void Enemy::Update(Vector2f sizemap, Vector2f mapposition)
{
	text.setPosition(enemy.getPosition().x - enemy.getSize().x / 2 - 8, enemy.getPosition().y - enemy.getSize().y / 2 - 18);
	if (enemy.getPosition().x <= mapposition.x + 2)
	{
		canMoveL = false;
		enemy.move(1, 0);
	}
	if (enemy.getPosition().y <= mapposition.y + 5)
	{
		canMoveUp = false;
		enemy.move(0, 1);
	}
	if (enemy.getPosition().x >= sizemap.x - 30)
	{
		canMoveR = false;
		enemy.move(-1, 0);
	}
	if (enemy.getPosition().y >= sizemap.y - 50)
	{
		canMoveDown = false;
		enemy.move(0, -1);
	}
}

void Enemy::Draw(RenderTarget& window)
{
	window.draw(enemy);
}
