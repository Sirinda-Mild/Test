#include "Chatbox.h"

Chatbox::Chatbox(Vector2f size, Vector2f posi)
{
	chatboxTexture.loadFromFile("Chat/chatbox.png");
	//font
	font.loadFromFile("Font/ArcadeClassic.ttf");
	fonthpzombie.loadFromFile("Font/DisposableDroidBB.ttf");
	fontMenu.loadFromFile("Font/menufont.ttf");

	chatbox.setSize(size);
	chatbox.setOrigin(chatbox.getSize() / 2.f);
	chatbox.setTexture(&chatboxTexture);
	chatbox.setPosition(posi);

	chat1.setFont(fonthpzombie);
	chat1.setCharacterSize(25);
	chat1.setPosition(Vector2f(chatbox.getPosition().x - chatbox.getSize().x / 2 + 60, chatbox.getPosition().y-5));
	chat1.setFillColor(Color::Black);
}

Chatbox::~Chatbox()
{
}

void Chatbox::Draw1(RenderWindow& window)
{
	window.draw(chatbox);
	window.draw(chat1);
}
