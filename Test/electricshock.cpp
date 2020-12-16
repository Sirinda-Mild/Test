#include "electricshock.h"

electricshock::electricshock(Texture* texture, Vector2u imageCount, float switchTime)
	:animation(texture, imageCount, switchTime)
{
	row = 0;
	electric.setSize(Vector2f(109, 109));
	electric.setTexture(texture);
	electric.setPosition(Vector2f(510, 350));
}

electricshock::~electricshock()
{
}

void electricshock::Draw(RenderWindow& window)
{
	window.draw(electric);
}

void electricshock::Update(float deltaTime)
{
	animation.Update(row, deltaTime);
	electric.setTextureRect(animation.uvRect);
}
