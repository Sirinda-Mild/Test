#include "HitboxComponent.h"

HitboxComponent::HitboxComponent(float offset_x, float offset_y, Vector2f size, Vector2f playerPosition)
{
	hitbox.setPosition(playerPosition.x + offset_x, playerPosition.y + offset_y);
	hitbox.setSize(size);
	hitbox.setFillColor(Color::Transparent);
	hitbox.setOutlineThickness(1.f);
	//hitbox.setOutlineColor(Color::Green);
	hitbox.setOutlineColor(Color::Transparent);

}

HitboxComponent::~HitboxComponent()
{
}

bool HitboxComponent::checkIntersect(const FloatRect& frect)
{
	return hitbox.getGlobalBounds().intersects(frect);
}

void HitboxComponent::Update(Vector2f playerPosition, float offset_x, float offset_y)
{
	hitbox.setPosition(playerPosition.x + offset_x, playerPosition.y + offset_y);
}

void HitboxComponent::Draw(RenderWindow& window)
{
	window.draw(hitbox);
}
