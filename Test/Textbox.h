#pragma once
#include<iostream>
#include<SFML/Graphics.hpp>
#include<sstream>
using namespace sf;
using namespace std;

#define DELETE_KEY 8
#define ENTER_KEY 13
#define ESCAPE_KEY 27

class Textbox
{
public:
	Text textbox;
	RectangleShape textframe;
	ostringstream text;
	bool isSelected = false;
	bool hasLimit = false;
	int limit;
	void inputLogic(int charTyped);
	void deleteLastChar();
	void setFont(Font& font);
	void setPosition(Vector2f pos);
	void setLimit(bool ToF);
	void setLimit(bool ToF, int lim);
	void setSelected(bool sel);
	string getText() {
		return text.str();
	}
	void drawTo(RenderWindow& window) {
		window.draw(textbox);
		window.draw(textframe);
	}
	void typedOn(Event input) {
		if (isSelected) {
			int charTyped = input.text.unicode;
			if (charTyped < 128) {
				if (hasLimit) {
					if (text.str().length() <= limit) {
						inputLogic(charTyped);
					}
					else if (text.str().length() > limit && charTyped == DELETE_KEY) {
						deleteLastChar();
					}
				}
				else {
					inputLogic(charTyped);
				}
			}
		}
	}

	Textbox(int size, Color color, bool sel);
};

