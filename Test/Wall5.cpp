#include "Wall5.h"

Wall5::Wall5(Vector2f size, Vector2f playerPosition)
{
	wall.setSize(size);
	wall.setOrigin(wall.getSize() / 2.f);
	wall.setPosition(playerPosition.x, playerPosition.y);

	wall.setFillColor(Color::Transparent);
	wall.setOutlineThickness(1.f);
	wall.setOutlineColor(Color::Transparent);

}

void Wall5::Update()
{


}

void Wall5::Draw(RenderWindow& window)
{
	window.draw(wall);
}