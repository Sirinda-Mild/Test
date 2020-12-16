#include "Boss.h"

Boss::Boss(Texture* texture, Vector2u imageCount, float switchTime, float speed) :
	animation(texture, imageCount, switchTime)
{
	this->speed = speed;
	row = 5;

	enemy.setSize(Vector2f(33.0f, 49.0f));
	enemy.setOrigin(enemy.getSize() / 2.0f);
	enemy.setPosition(600, 800);
	enemy.setTexture(texture);

	hpboxframe.setSize(Vector2f(70, 7));
	hpboxframe.setOrigin(hpboxframe.getSize() / 2.f);
	hpboxframe.setFillColor(Color::Transparent);
	hpboxframe.setOutlineThickness(2.f);
	hpboxframe.setOutlineColor(Color::Black);

	hpbox.setFillColor(Color::Red);
}

Boss::~Boss()
{
}

void Boss::UpdateMovement(float deltaTime, Vector2f playerPosition, Vector2f size)
{
	if (wesker == false && move == true && alive == true) {
		float deltaX = enemy.getPosition().x - playerPosition.x;
		float deltaY = enemy.getPosition().y - playerPosition.y;
		float intersectX = abs(deltaX) - ((enemy.getSize().x / 2) + (size.x / 2));
		float intersectY = abs(deltaY) - ((enemy.getSize().y / 2) + (size.y / 2));
		movement = (Vector2f(0.0f, 0.0f));

		/*if (intersectX < 500 && intersectY < 500)
		{*/
			if (intersectX > intersectY)
			{
				if (deltaX < 500 && deltaX > 200)
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
				else if (deltaX < 200 && deltaX > 0) {
					row = 5;
					face = 0;
				}
				else if (deltaX > -500 && deltaX < -280)
				{
					if (canMoveR == true) {
						movement.x += speed * deltaTime;
						row = 2;
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
				else if (deltaX > -280 && deltaX < 0) {
					row = 4;
					face = 1;
				}
			}
			else
			{
				if (deltaY < 500 && deltaY > 120)
				{
					if (canMoveUp == true) {
						movement.y -= speed * deltaTime;
						row = 1;
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
				else if (deltaY < 120 && deltaY > 0) {
					row = 7;
					face = 2;
				}
				else if (deltaY > -500 && deltaY < -180)
				{
					if (canMoveDown == true) {
						movement.y += speed * deltaTime;
						row = 0;
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
				else if (deltaY > -180 && deltaY < 0) {
					row = 6;
					face = 3;
				}
			}
		//}
	}
	//wesker
	if (wesker == true) {
		if (bosshp <= 0) {
			bosshp = 0;
			boxX = 0;
			movement.x = 0.0f;
			movement.y = 0.0f;
			row = 6;
		}
	}
	animation.Update(row, deltaTime);
	enemy.setTextureRect(animation.uvRect);
	enemy.move(movement);
}

void Boss::Update(Vector2f sizemap, Vector2f mapposition)
{
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

void Boss::Draw(RenderTarget& window)
{
	window.draw(enemy);
	if (wesker == true) {
		hpboxframe.setPosition(enemy.getPosition().x, enemy.getPosition().y - 33);
		hpbox.setSize(Vector2f(boxX, boxY));
		hpbox.setPosition(hpboxframe.getPosition() - hpboxframe.getSize() / 2.f);
		window.draw(hpbox);
		window.draw(hpboxframe);
	}
}