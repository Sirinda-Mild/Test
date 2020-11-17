#include "GenBar.h"

GenBar::GenBar(Vector2f hitboxposi)
{
	genframe.setSize(Vector2f(70, 7));
	genframe.setOrigin(genframe.getSize() / 2.f);
	genframe.setPosition(hitboxposi);
	genframe.setFillColor(Color::Transparent);
	genframe.setOutlineThickness(2.f);
	genframe.setOutlineColor(Color::Black);

	genbar.setFillColor(Color::Green);
	genbar.setPosition(genframe.getPosition() - genframe.getSize() / 2.f);
}

void GenBar::Update(Vector2f size)
{
	genbar.setSize(size);
}

void GenBar::Draw(RenderWindow& window)
{
	window.draw(genbar);
	window.draw(genframe);
}
