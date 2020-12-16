#pragma once
#include<SFML/Graphics.hpp>
#include "Player.h"
#include"Chatbox.h"
#include"Button.h"

using namespace sf;

class ViewPlayer
{
public:
	ViewPlayer(Vector2f position, Vector2f size);

	View* view;
	Button* button, * button2;
	bool viewup = false;
	void viewUpdate(Player player, RectangleShape map);
	void setView(RenderWindow& window);
	void Draw(RenderWindow& window);
	void DrawTask(RenderWindow& window);
	void DrawTask1(RenderWindow& window);
	void DrawTryagain(RenderWindow& window);
	
	void updateButton(const Vector2i& mousePosWindow);
	void DrawButton(RenderWindow& window);

	Font font, fonthpzombie, fontMenu;
	Text glockBullet, smgBullet, shotgunBullet, HP, one, two, three, four, name, task, task1, task2, task3, task4, task5, task6;

	RectangleShape playerhp;
	CircleShape playerpic;
	Texture frame, playerpicTexture, Sword, Glock, SMG, Shotgun;
	RectangleShape boxSword, boxGlock, boxSMG, boxShotgun;


	RectangleShape hpbox, hpboxframe;
	float boxX = 150;
	float boxY = 15;

	RectangleShape tryagainframe;
	Text deadcount;
};

