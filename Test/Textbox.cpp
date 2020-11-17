#define SFML_NO_DEPRECATED_WARNINGS
#include "Textbox.h"

void Textbox::inputLogic(int charTyped)
{
	if (charTyped != DELETE_KEY && charTyped != ENTER_KEY && charTyped != ESCAPE_KEY)
	{
		text << static_cast<char>(charTyped);
	}
	else if (charTyped == DELETE_KEY)
	{
		if (text.str().length() > 0) {
			deleteLastChar();
		}
	}
	textbox.setString(text.str() + "_");
}

void Textbox::deleteLastChar()
{
	string t = text.str();
	string newT = "";
	for (int i = 0; i < t.length() - 1; i++) {
		newT += t[i];
	}
	text.str("");
	text << newT;

	textbox.setString(text.str());
}

void Textbox::setFont(Font& font)
{
	textbox.setFont(font);
}

void Textbox::setPosition(Vector2f pos)
{
	textbox.setPosition(pos);
}

void Textbox::setLimit(bool ToF)
{
	hasLimit = ToF;
}

void Textbox::setLimit(bool ToF, int lim)
{
	hasLimit = ToF;
	limit = lim - 1;
}

void Textbox::setSelected(bool sel)
{
	isSelected = sel;
	if (sel) {
		textbox.setString(text.str() + "_");
	}
	if (!sel) {
		string t = text.str();
		string newT = "";
		for (int i = 0; i < t.length(); i++) {
			newT += t[i];
		}
		textbox.setString(newT);
	}
}

Textbox::Textbox(int size, Color color, bool sel)
{
	textbox.setCharacterSize(size);
	textbox.setColor(color);
	textframe.setSize(Vector2f(400, 60));
	textframe.setPosition(Vector2f(200, 295));
	textframe.setFillColor(Color::Transparent);
	textframe.setOutlineThickness(4.5f);
	textframe.setOutlineColor(Color::White);

	isSelected = sel;
	if (sel) {
		textbox.setString("_");
	}
	else {
		textbox.setString("");
	}
}
