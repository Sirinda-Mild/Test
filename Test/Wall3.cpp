#include "Wall3.h"

Wall3::Wall3(Vector2f size, Vector2f playerPosition)
{
	wall.setSize(size);
	wall.setOrigin(wall.getSize() / 2.f);
	wall.setPosition(playerPosition.x, playerPosition.y);

	wall.setFillColor(Color::Transparent);
	wall.setOutlineThickness(1.f);
	//wall.setOutlineColor(Color::Red);
	wall.setOutlineColor(Color::Transparent);

}

void Wall3::Update()
{


}

void Wall3::Draw(RenderWindow& window)
{
	window.draw(wall);
}