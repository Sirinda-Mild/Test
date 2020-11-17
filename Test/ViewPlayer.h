#pragma once
#include<SFML/Graphics.hpp>
#include "Player.h"
#include"Chatbox.h"

using namespace sf;

class ViewPlayer
{
public:
	ViewPlayer(Vector2f position, Vector2f size);

	View* view;
	void viewUpdate(Player player, RectangleShape map);
	void setView(RenderWindow& window);
	void Draw(RenderWindow& window);
	void DrawTask(RenderWindow& window);
	void DrawTask1(RenderWindow& window);

	Font font, fonthpzombie, fontMenu;
	Text glockBullet, smgBullet, shotgunBullet, HP, one, two, three, four, name, task, task1, task2, task3, task4, task5;

	RectangleShape playerhp;
	CircleShape playerpic;
	Texture playerpicTexture, Sword, Glock, SMG, Shotgun;
	RectangleShape boxSword, boxGlock, boxSMG, boxShotgun;

	RectangleShape hpbox, hpboxframe;
	float boxX = 150;
	float boxY = 15;
};

