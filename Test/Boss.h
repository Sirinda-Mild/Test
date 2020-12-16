#pragma once
#include<SFML/Graphics.hpp>
#include"Animation.h"
#include"Player.h"
#include"Random.h"
#include"TextDisplay.h"
#include"Projectile.h"

using namespace sf;

class Boss
{
public:
	Boss(Texture* texture, Vector2u imageCount, float switchTime, float speed);
	~Boss();

	void UpdateMovement(float deltaTime, Vector2f playerPosition, Vector2f size);
	void Update(Vector2f sizemap, Vector2f mapposition);
	void Draw(RenderTarget& window);

	int direction = 0;
	int bosshp = 100;
	int bossmaxhp = 100;
	int bossattackDamage = 5;
	int face = 3;
	bool alive = true;
	bool canMoveL = true;
	bool canMoveR = true;
	bool canMoveUp = true;
	bool canMoveDown = true;
	bool wesker = true;
	bool move = true;
	Vector2f movement;
	Vector2f weskersize = (Vector2f(35, 51));
	Vector2f nemesissize = (Vector2f(125, 125));

	RectangleShape hpbox, hpboxframe;
	float boxX = 70;
	float boxY = 7;

	float speed;
	unsigned int row;
	Texture bulletTexture;
	Text text;
	RectangleShape enemy;
	Vector2f GetPosition() { return enemy.getPosition(); }
	Animation animation;
	Projectile* bossbullet;
};

