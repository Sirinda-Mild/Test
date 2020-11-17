#include "PickupItem.h"

PickupItem::PickupItem(Texture* texture, Vector2f size, Vector2f hitboxsize, float offset_x, float offset_y, Vector2f playerPosition)
	: hitboxBox(offset_x,  offset_y,  hitboxsize,  playerPosition)
{
	item.setSize(size);
	item.setTexture(texture); 
	hitboxBox.hitbox.setSize(hitboxsize);

}

void PickupItem::Update()
{
}

void PickupItem::setPosition(Vector2f pos)
{
	item.setPosition(pos);
	hitboxBox.hitbox.setPosition(item.getPosition().x,item.getPosition().y + 15);
	
}

void PickupItem::Draw(RenderWindow& window)
{
	window.draw(item);
	hitboxBox.Draw(window);
}
