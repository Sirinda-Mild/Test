#include "leon.h"

leon::leon(Texture* texture, Vector2u imageCount, float switchTime, float speed) :
	animation(texture, imageCount, switchTime)
{
	this->speed = speed;
	row = 5;

	leonk.setSize(Vector2f(80.0f, 80.0f));
	leonk.setOrigin(leonk.getSize() / 2.0f);
	leonk.setPosition(600, 800);
	leonk.setTexture(texture);
}

void leon::UpdateMovement(float deltaTime, Vector2f playerPosition, Vector2f size)
{
	float deltaX = leonk.getPosition().x - playerPosition.x;
	float deltaY = leonk.getPosition().y - playerPosition.y;
	float intersectX = abs(deltaX) - ((leonk.getSize().x / 2) + (size.x / 2));
	float intersectY = abs(deltaY) - ((leonk.getSize().y / 2) + (size.y / 2));
	movement = (Vector2f(0.0f, 0.0f));

	if (deltaY > 60 && abs(deltaX) > 0)
	{
		movement.y -= speed * deltaTime;
		row = 0;
	}
	else if (deltaY <= 60) {
		movement = (Vector2f(0.0f, 0.0f));
		row = 4;
	}

	animation.Update(row, deltaTime);
	leonk.setTextureRect(animation.uvRect);
	leonk.move(movement);

}

void leon::Draw(RenderTarget& window)
{
	window.draw(leonk);
}
