#include "TextDisplay.h"

TextDisplay::TextDisplay()
{
	text.setCharacterSize(30);
	text.setPosition(300, 300);
}

TextDisplay::~TextDisplay()
{
}

void TextDisplay::Update()
{
	text.move(0, -textMovementSpeed);

	counter++;
	if (counter >= LifeTime) 
	{
		destroy = true;
	}
}
