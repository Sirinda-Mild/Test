#pragma once
#include <SFML\Graphics.hpp>
#include<SFML\Window.hpp>
#include<SFML\System.hpp>
#include<SFML\Audio.hpp>
#include "Animation.h"
#include "Collider.h"
#include"HitboxComponent.h"

using namespace sf;

class Player
{
public:
	Player(Texture* texture, Vector2u imageCount, float switchTime, float speed);
	~Player();

	void Update(float deltaTime);
	void Draw(RenderWindow& window);
	bool isGlock = false;
	bool isSMG = false;
	bool isShotgun = false;
	bool canMoveL = true;
	bool canMoveR = true;
	bool canMoveUp = true;
	bool canMoveDown = true;
	unsigned int face;

	HitboxComponent* hitboxPlayer;
	HitboxComponent* hitboxPlayerAll;
	HitboxComponent* hitboxPlayerSwordleft;
	HitboxComponent* hitboxPlayerSwordRight;
	HitboxComponent* hitboxPlayerSwordUp;
	HitboxComponent* hitboxPlayerSwordDown;

	//sound effects
	SoundBuffer bufferSword;
	Sound soundSword;

	SoundBuffer bufferSwordPress;
	Sound soundSwordPress;

	SoundBuffer bufferGlockPress;
	Sound soundGunPress;

	SoundBuffer bufferSMGPress;
	Sound soundSMGPress;

	SoundBuffer bufferShotgunPress;
	Sound soundShotgunPress;

	SoundBuffer bufferFootstep;
	Sound soundFootstep;

	RectangleShape body;
	int hp = 100;
	int maxhp = 100;
	int attackSword = 1;
	int getFace() {
		return face;
	}
	int getWeapon() {
		return weapon;
	}
	float getSpeed() {
		return speed;
	}

	Vector2f GetPosition() { return body.getPosition(); }
	int GetPositionX() { return body.getPosition().x; }
	int GetPositionY() { return body.getPosition().y; }
	Vector2f GetSize() { return body.getSize(); }
	Collider GetCollider() { return /*hitboxPlayer->GetCollider();*/ Collider(body); }

	void playerCollideEdge(Vector2f sizemap, Vector2f mapposition);

private:
	Animation animation;
	unsigned int weapon, row;
	float speed;

};

