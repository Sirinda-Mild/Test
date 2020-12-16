#define SFML_NO_DEPRECATED_WARNINGS
#include "MenuBG.h"

MenuBG::MenuBG(Texture* texture, Vector2u imageCount, float switchTime) :
	animation(texture, imageCount, switchTime)
{
	row = 0;
	bg.setSize(Vector2f(1366, 768));
	bg.setPosition(0, 0);
	bg.setTexture(texture);
	howtop.loadFromFile("Menu/howtoplay.png");
	howtoplay.setSize(bg.getSize());
	howtoplay.setPosition(Vector2f(bg.getPosition().x, bg.getPosition().y));
	howtoplay.setTexture(&howtop);

	fontmenu.loadFromFile("Font/menufont.ttf");
	mainText1.setFont(fontmenu);
	mainText1.setCharacterSize(90);
	mainText1.setColor(Color::White);
	mainText1.setString("WALKING");
	mainText1.setPosition(Vector2f(bg.getPosition().x + 35, bg.getPosition().y + bg.getSize().y - 120));

	mainText2.setFont(fontmenu);
	mainText2.setCharacterSize(90);
	mainText2.setColor(Color(200, 100, 100));
	mainText2.setString("DEAD");
	mainText2.setPosition(Vector2f(bg.getPosition().x + 410, bg.getPosition().y + bg.getSize().y - 120));

	textname.setFont(fontmenu);
	textname.setString("name");
	textname.setFillColor(Color::White);
	textname.setPosition(100, 90);
	textname.setCharacterSize(50);

	texttime.setFont(fontmenu);
	texttime.setString("time");
	texttime.setFillColor(Color::White);
	texttime.setPosition(350, 90);
	texttime.setCharacterSize(50);

	textdead.setFont(fontmenu);
	textdead.setString("dead");
	textdead.setFillColor(Color::White);
	textdead.setPosition(600, 90);
	textdead.setCharacterSize(50);

	buttonStory = new Button(315, 150, 150, 50,
		&fontmenu, "New game", 45, Color(Color::White), Color(Color(200, 100, 100)), Color(Color(200, 100, 100)));
	buttonEndless = new Button(315, 230, 150, 50,
		&fontmenu, "Endless Mode", 45, Color(Color::White), Color(Color(200, 100, 100)), Color(Color(200, 100, 100)));
	buttonHow = new Button(315, 230, 150, 50,
		&fontmenu, "How to play", 45, Color(Color::White), Color(Color(200, 100, 100)), Color(Color(200, 100, 100)));
	buttonHighscore = new Button(315, 310, 150, 50,
		&fontmenu, "High scores", 45, Color(Color::White), Color(Color(200, 100, 100)), Color(Color(200, 100, 100)));
	buttonQuit = new Button(315, 390, 150, 50,
		&fontmenu, "Quit", 45, Color(Color::White), Color(Color(200, 100, 100)), Color(Color(200, 100, 100)));
	buttonNewgame = new Button(315, 200, 150, 50,
		&fontmenu, "New game", 50, Color(Color::White), Color(Color(200, 100, 100)), Color(Color(200, 100, 100)));
	buttonLoadgame = new Button(315, 300, 150, 50,
		&fontmenu, "Load game", 50, Color(Color::White), Color(Color(200, 100, 100)), Color(Color(200, 100, 100)));
	buttonBack = new Button(315, 400, 150, 50,
		&fontmenu, "Back", 40, Color(Color(200, 100, 100)), Color(Color::White), Color(Color::White));
	buttonBack2 = new Button(220, 400, 150, 50,
		&fontmenu, "Back", 40, Color(Color(200, 100, 100)), Color(Color::White), Color(Color::White));
	buttonBack3 = new Button(60, 650, 150, 50,
		&fontmenu, "Back", 40, Color(Color(200, 100, 100)), Color(Color::White), Color(Color::White));
	buttonOK = new Button(420, 400, 150, 50,
		&fontmenu, "OK", 40, Color(Color::White), Color(Color(200, 100, 100)), Color(Color(200, 100, 100)));
}

MenuBG::~MenuBG()
{
}

void MenuBG::UpdateBG(float deltaTime)
{
	animation.Update(row, deltaTime);
	bg.setTextureRect(animation.uvRect);
}


void MenuBG::UpdateButton(const Vector2i& mousePosWindow)
{
	buttonStory->update(mousePosWindow);
	//buttonEndless->update(mousePosWindow);
	buttonHow->update(mousePosWindow);
	buttonHighscore->update(mousePosWindow);
	buttonQuit->update(mousePosWindow);
}

void MenuBG::UpdateButton2(const Vector2i& mousePosWindow)
{
	//buttonNewgame->update(mousePosWindow);
	//buttonLoadgame->update(mousePosWindow);
	//buttonBack->update(mousePosWindow);
}

void MenuBG::UpdateButton3(const Vector2i& mousePosWindow)
{
	buttonBack2->update(mousePosWindow);
	buttonOK->update(mousePosWindow);
}

void MenuBG::UpdateButton4(const Vector2i& mousePosWindow)
{
	buttonBack3->update(mousePosWindow);
}

void MenuBG::DrawBG(RenderWindow& window)
{
	window.draw(bg);
	window.draw(mainText1);
	window.draw(mainText2);
}

void MenuBG::DrawButton(RenderWindow& window)
{
	buttonStory->render(window);
	/*buttonEndless->render(window);*/
	buttonHow->render(window);
	buttonHighscore->render(window);
	buttonQuit->render(window);
}

void MenuBG::DrawButton2(RenderWindow& window)
{
	/*buttonNewgame->render(window);
	buttonLoadgame->render(window);
	buttonBack->render(window);*/
}

void MenuBG::DrawButton3(RenderWindow& window)
{
	buttonBack2->render(window);
	buttonOK->render(window);
}

void MenuBG::DrawBG2(RenderWindow& window)
{
	window.draw(bg);
	window.draw(howtoplay);
	buttonBack3->render(window);
}

void MenuBG::DrawBG3(RenderWindow& window)
{
	window.draw(bg);
	window.draw(textdead);
	window.draw(textname);
	window.draw(texttime);
	buttonBack3->render(window);
}
