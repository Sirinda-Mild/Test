#include "Wall.h"

Wall::Wall(Vector2f size, Vector2f playerPosition)
{
	wall.setSize(size);
	wall.setOrigin(wall.getSize() / 2.f);
	wall.setPosition(playerPosition.x, playerPosition.y);
	
	wall.setFillColor(Color::Transparent);
	wall.setOutlineThickness(1.f);
	wall.setOutlineColor(Color::Transparent);

}

void Wall::Update()
{


}

void Wall::Draw(RenderWindow& window)
{
	window.draw(wall);
}