#pragma once
#include<SFML/Graphics.hpp>
#include"Animation.h"
#include"Player.h"
#include"Random.h"
#include"TextDisplay.h"

using namespace sf;

class Enemy
{
public:
	Enemy(Texture* texture, Vector2u imageCount, float switchTime, float speed);
	~Enemy();

	void UpdateMovement(float deltaTime, Vector2f playerPosition, Vector2f size);
	void Update();
	void Draw(RenderTarget& window);

	int direction = 0;
	int enemy1hp = 5;
	int enemy1maxhp = 5;
	int enemy2hp = 5;
	int enemy2maxhp = 5;
	int enemy1attackDamage = 2;
	int enemy2attackDamage = 4;
	int face = 3;
	bool alive = true;
	bool canMoveL = true;
	bool canMoveR = true;
	bool canMoveUp = true;
	bool canMoveDown = true;
	unsigned int row;
	Vector2f movement;
	
	int shotgunHP() {
		return enemy1hp -= 1;
	}

	float speed;
	Text text;
	RectangleShape enemy;
	Vector2f GetPosition() { return enemy.getPosition(); }

private:
	Animation animation;
	Player player;
};

