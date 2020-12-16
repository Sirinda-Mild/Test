#include "Wall4.h"

Wall4::Wall4(Vector2f size, Vector2f playerPosition)
{
	wall.setSize(size);
	wall.setOrigin(wall.getSize() / 2.f);
	wall.setPosition(playerPosition.x, playerPosition.y);

	wall.setFillColor(Color::Transparent);
	wall.setOutlineThickness(1.f);
	wall.setOutlineColor(Color::Transparent);

}

void Wall4::Update()
{


}

void Wall4::Draw(RenderWindow& window)
{
	window.draw(wall);
}
