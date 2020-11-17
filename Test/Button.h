#pragma once
#include<iostream>
#include<ctime>
#include<cstdlib>
#include<sstream>

#include"SFML\System.hpp"
#include"SFML\Window.hpp"
#include"SFML\Graphics.hpp"
#include"SFML\Audio.hpp"

enum button_states { BTN_IDLE = 0, BTN_HOVER, BTN_ACTIVE };

using namespace sf;
using namespace std;

class Button
{
private:
	short unsigned buttonState;

	RectangleShape shape;
	Font* font;

	Color textIdleColor;
	Color textHoverColor;
	Color textActiveColor;

	Color idleColor;
	Color hoverColor;
	Color activeColor;

	Color outlineIdleColor;
	Color outlineHoverColor;
	Color outlineActiveColor;

public:
	Text text;
	Button(float x, float y, float width, float height,
		Font* font, string text, unsigned character_size,
		Color text_idle_color, Color text_hover_color, Color text_active_color);
	~Button();

	//Accessors
	const bool isPressed() const;
	const string getText() const;

	//Modifiers
	void setText(const string text);

	//Functions
	void setPosi(Vector2f posi) { text.setPosition(posi); }
	void update(const Vector2i& mousePosWindow);
	void render(RenderWindow& window);


};

