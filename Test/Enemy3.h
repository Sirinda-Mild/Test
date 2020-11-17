#pragma once
#include<SFML/Graphics.hpp>
#include"Animation.h"
#include"Player.h"
#include"Random.h"
#include"TextDisplay.h"

using namespace sf;

class Enemy3
{
public:
	Enemy3(Texture* texture, Vector2u imageCount, float switchTime, float speed);
	~Enemy3();

	void UpdateMovement(float deltaTime, Vector2f playerPosition, Vector2f size);
	void Update();
	void Draw(RenderTarget& window);

	int direction = 0;
	int enemy3hp = 8;
	int enemy3maxhp = 8;
	int enemy3attackDamage = 8;
	int face = 3;
	bool alive = true;
	bool canMoveL = true;
	bool canMoveR = true;
	bool canMoveUp = true;
	bool canMoveDown = true;
	unsigned int row;
	Vector2f movement;

	float speed;
	Text text;
	RectangleShape enemy;
	Vector2f GetPosition() { return enemy.getPosition(); }

private:
	Animation animation;
	Player player;
};

