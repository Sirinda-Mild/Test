#include "Enemy3.h"

Enemy3::Enemy3(Texture* texture, Vector2u imageCount, float switchTime, float speed) :
	animation(texture, imageCount, switchTime),
	player(texture, imageCount, switchTime, speed)
{
	this->speed = speed;
	row = 4;

	enemy.setSize(Vector2f(30.0f, 55.0f));
	enemy.setOrigin(enemy.getSize() / 2.0f);
	enemy.setPosition(100.0f, 200.0f);
	enemy.setTexture(texture);
}

Enemy3::~Enemy3()
{
}

void Enemy3::UpdateMovement(float deltaTime, Vector2f playerPosition, Vector2f size)
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
			}
			else
			{
				if (canMoveR == true) {
					if (face == 1) {
						row = 1;
						canMoveL = true;
						canMoveR = true;
						canMoveUp = true;
						canMoveDown = true;
					}
				}
				if (canMoveL == true) {
					if (face == 0) {
						row = 3;
						canMoveL = true;
						canMoveR = true;
						canMoveUp = true;
						canMoveDown = true;
					}
				}
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
			}
			else if (deltaY < -5.0f)
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
			}
			else
			{
				if (canMoveUp == true) {
					if (face == 2) {
						row = 0;
						canMoveL = true;
						canMoveR = true;
						canMoveUp = true;
						canMoveDown = true;
					}
				}
				if (canMoveDown == true) {
					if (face == 3) {
						row = 2;
						canMoveL = true;
						canMoveR = true;
						canMoveUp = true;
						canMoveDown = true;
					}
				}
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

void Enemy3::Update()
{
	text.setPosition(enemy.getPosition().x - enemy.getSize().x / 2 + 23, enemy.getPosition().y - enemy.getSize().y / 2 - 10);
}

void Enemy3::Draw(RenderTarget& window)
{
	window.draw(enemy);
}
