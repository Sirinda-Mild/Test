#include "Player.h"
#include<iostream>

using namespace std;

Player::Player(Texture* texture, Vector2u imageCount, float switchTime, float speed) :
	animation(texture, imageCount, switchTime)
{
	bufferSword.loadFromFile("Sound/swordattack.wav");
	soundSword.setBuffer(bufferSword);

	bufferSwordPress.loadFromFile("Sound/press1sword.wav");
	soundSwordPress.setBuffer(bufferSwordPress);

	bufferGlockPress.loadFromFile("Sound/press4shotgun.wav");
	soundGunPress.setBuffer(bufferGlockPress);

	this->speed = speed;
	row = 31;
	face = 3;
	weapon = 1;

	body.setSize(Vector2f(80.0f, 80.0f));
	body.setOrigin(body.getSize().x /2.0f, body.getSize().y / 2.0f);
	body.setPosition(150.0f, 300.0f);
	body.setTexture(texture);


	hitboxPlayer = new HitboxComponent(0, 0, Vector2f(25, 25), this->GetPosition());
	hitboxPlayerAll = new HitboxComponent (0, 0, Vector2f(25, 45), this->GetPosition());
	hitboxPlayerSwordleft = new HitboxComponent  (0, 0, Vector2f(15, 8), this->GetPosition());
	hitboxPlayerSwordRight = new HitboxComponent (0, 0, Vector2f(15, 8), this->GetPosition());
	hitboxPlayerSwordUp = new HitboxComponent (0, 0, Vector2f(30, 8), this->GetPosition());
	hitboxPlayerSwordDown = new HitboxComponent (0, 0, Vector2f(30, 8), this->GetPosition());
}

Player::~Player()
{
}

void Player::Update(float deltaTime)
{
	Vector2f movement(0.0f, 0.0f);
	//walkfast
	if (Keyboard::isKeyPressed(Keyboard::LShift) )
	{
		speed = 150;
	}
	else 
	{
		speed = 100;
	}

	//walk
	if (Keyboard::isKeyPressed(Keyboard::Num1)) {
		if (weapon != 1) {
			soundSwordPress.play();
		}
		weapon = 1;
	}
	if (isGlock == true) {
		if (Keyboard::isKeyPressed(Keyboard::Num2)) {
			if (weapon != 2) {
				soundGunPress.play();
			}
			weapon = 2;
			isGlock = true;
		}
	}
	if (isSMG == true) {
		if (Keyboard::isKeyPressed(Keyboard::Num3)) {
			if (weapon != 3) {
				soundGunPress.play();
			}
			weapon = 3;
			isSMG = true;
		}
	}
	if (isShotgun == true) {
		if (Keyboard::isKeyPressed(Keyboard::Num4)) {
			if (weapon != 4) {
				soundGunPress.play();
			}
			weapon = 4;
			isShotgun = true;
		}
	}

	//weapon1
	if (weapon == 1) {
		if (Keyboard::isKeyPressed(Keyboard::A))
		{
			if (canMoveL == true) {
				movement.x -= speed * deltaTime;
				row = 33;
				face = 0;
				canMoveL = true;
				canMoveR = true;
				canMoveUp = true;
				canMoveDown = true;
			}
		}
		else if (Keyboard::isKeyPressed(Keyboard::D))
		{
			if (canMoveR == true) {
				movement.x += speed * deltaTime;
				row = 35;
				face = 1;
				canMoveL = true;
				canMoveR = true;
				canMoveUp = true;
				canMoveDown = true;
			}
		}
		else if (Keyboard::isKeyPressed(Keyboard::W))
		{
			if (canMoveUp == true) {
				movement.y -= speed * deltaTime;
				row = 32;
				face = 2;
				canMoveL = true;
				canMoveR = true;
				canMoveUp = true;
				canMoveDown = true;
			}
		}
		else if (Keyboard::isKeyPressed(Keyboard::S))
		{
			if (canMoveDown == true) {
				movement.y += speed * deltaTime;
				row = 34;
				face = 3;
				canMoveL = true;
				canMoveR = true;
				canMoveUp = true;
				canMoveDown = true;
			}
		}

		//walk&slash
		if (Keyboard::isKeyPressed(Keyboard::Space) && Keyboard::isKeyPressed(Keyboard::A))
		{
			soundSword.play();
			if (canMoveL == true) {
				row = 37;
				face = 0;
				canMoveL = true;
				canMoveR = true;
				canMoveUp = true;
				canMoveDown = true;
			}
		}
		else if (Keyboard::isKeyPressed(Keyboard::Space) && Keyboard::isKeyPressed(Keyboard::D))
		{
			soundSword.play();
			if (canMoveR == true) {
				row = 39;
				face = 1;
				canMoveL = true;
				canMoveR = true;
				canMoveUp = true;
				canMoveDown = true;
			}
		}
		else if (Keyboard::isKeyPressed(Keyboard::Space) && Keyboard::isKeyPressed(Keyboard::W))
		{
			soundSword.play();
			if (canMoveUp == true) {
				row = 36;
				face = 2;
				canMoveL = true;
				canMoveR = true;
				canMoveUp = true;
				canMoveDown = true;
			}
		}
		else if (Keyboard::isKeyPressed(Keyboard::Space) && Keyboard::isKeyPressed(Keyboard::S))
		{
			soundSword.play();
			if (canMoveDown == true) {
				row = 38;
				face = 3;
				canMoveL = true;
				canMoveR = true;
				canMoveUp = true;
				canMoveDown = true;
			}
		}
		//slash
		else if (Keyboard::isKeyPressed(Keyboard::Space))
		{
			soundSword.play();
			if (face == 0) //left
			{
				row = 25;
			}
			else if (face == 1) //right
			{
				row = 27;
			}
			else if (face == 2) //up
			{
				row = 24;
			}
			else if (face == 3) //down
			{
				row = 26;
			}
		}
		//stop
		else if (movement.x == 0.0f && movement.y == 0.0f)
		{
			if (face == 0) {
				row = 28;
			}
			if (face == 1) {
				row = 30;
			}
			if (face == 2) {
				row = 29;
			}
			if (face == 3) {
				row = 31;
			}

		}
	}
	//weapon2
	else if (weapon == 2) {
		//walk
		if (Keyboard::isKeyPressed(Keyboard::A))
		{
			if (canMoveL == true) {
				movement.x -= speed * deltaTime;
				row = 5;
				face = 0;
				canMoveL = true;
				canMoveR = true;
				canMoveUp = true;
				canMoveDown = true;
			}
		}
		else if (Keyboard::isKeyPressed(Keyboard::D))
		{
			if (canMoveR == true) {
				movement.x += speed * deltaTime;
				row = 7;
				face = 1;
				canMoveL = true;
				canMoveR = true;
				canMoveUp = true;
				canMoveDown = true;
			}
		}
		else if (Keyboard::isKeyPressed(Keyboard::W))
		{
			if (canMoveUp == true) {
				movement.y -= speed * deltaTime;
				row = 4;
				face = 2;
				canMoveL = true;
				canMoveR = true;
				canMoveUp = true;
				canMoveDown = true;
			}
		}
		else if (Keyboard::isKeyPressed(Keyboard::S))
		{
			if (canMoveDown == true) {
				movement.y += speed * deltaTime;
				row = 6;
				face = 3;
				canMoveL = true;
				canMoveR = true;
				canMoveUp = true;
				canMoveDown = true;
			}
		}
		//stop
		else if (movement.x == 0.0f && movement.y == 0.0f)
		{
			if (face == 0) {
				row = 1;
			}
			else if (face == 1) {
				row = 3;
			}
			else if (face == 2) {
				row = 0;
			}
			else if (face == 3) {
				row = 2;
			}
		}
	}
	//weapon3
	else if (weapon == 3) {
		//walk
		if (Keyboard::isKeyPressed(Keyboard::A))
		{
			if (canMoveL == true) {
				movement.x -= speed * deltaTime;
				row = 13;
				face = 0; 
				canMoveL = true;
				canMoveR = true;
				canMoveUp = true;
				canMoveDown = true;
			}
		}
		else if (Keyboard::isKeyPressed(Keyboard::D))
		{
			if (canMoveR == true) {
				movement.x += speed * deltaTime;
				row = 15;
				face = 1;
				canMoveL = true;
				canMoveR = true;
				canMoveUp = true;
				canMoveDown = true;
			}
		}
		else if (Keyboard::isKeyPressed(Keyboard::W))
		{
			if (canMoveUp == true) {
				movement.y -= speed * deltaTime;
				row = 12;
				face = 2;
				canMoveL = true;
				canMoveR = true;
				canMoveUp = true;
				canMoveDown = true;
			}
		}
		else if (Keyboard::isKeyPressed(Keyboard::S))
		{
			if (canMoveDown == true) {
				movement.y += speed * deltaTime;
				row = 14;
				face = 3;
				canMoveL = true;
				canMoveR = true;
				canMoveUp = true;
				canMoveDown = true;
			}
		}
		//stop
		else if (movement.x == 0.0f && movement.y == 0.0f)
		{
			if (face == 0) {
				row = 9;
			}
			else if (face == 1) {
				row = 11;
			}
			else if (face == 2) {
				row = 8;
			}
			else if (face == 3) {
				row = 10;
			}
		}
	}
	//weapon4
	else if (weapon == 4) {
		//walk
		if (Keyboard::isKeyPressed(Keyboard::A))
		{
			if (canMoveL == true) {
				movement.x -= speed * deltaTime;
				row = 21;
				face = 0;
				canMoveL = true;
				canMoveR = true;
				canMoveUp = true;
				canMoveDown = true;
			}
		}
		else if (Keyboard::isKeyPressed(Keyboard::D))
		{
			if (canMoveR == true) {
				movement.x += speed * deltaTime;
				row = 23;
				face = 1;
				canMoveL = true;
				canMoveR = true;
				canMoveUp = true;
				canMoveDown = true;
			}
		}
		else if (Keyboard::isKeyPressed(Keyboard::W))
		{
			if (canMoveUp == true) {
				movement.y -= speed * deltaTime;
				row = 20;
				face = 2;
				canMoveL = true;
				canMoveR = true;
				canMoveUp = true;
				canMoveDown = true;
			}
		}
		else if (Keyboard::isKeyPressed(Keyboard::S))
		{
			if (canMoveDown == true) {
				movement.y += speed * deltaTime;
				row = 22;
				face = 3;
				canMoveL = true;
				canMoveR = true;
				canMoveUp = true;
				canMoveDown = true;
			}
		}
		//stop
		else if (movement.x == 0.0f && movement.y == 0.0f)
		{
			if (face == 0) {
				row = 17;
			}
			else if (face == 1) {
				row = 19;
			}
			else if (face == 2) {
				row = 16;
			}
			else if (face == 3) {
				row = 18;
			}
		}
	}
	if (isGlock == false && weapon == 2) {
		weapon = 1;
	}
	if (isSMG == false && weapon == 3) {
		weapon = 1;
	}
	if (isShotgun == false && weapon == 4) {
		weapon = 1;
	}
	
	if (hp <= 0) {
		hp = 0;
		movement.x = 0.0f;
		movement.y = 0.0f;
		row = 40;

	}

	animation.Update(row, deltaTime);
	body.setTextureRect(animation.uvRect);
	body.move(movement);

}

void Player::Draw(RenderWindow& window)
{
	window.draw(body);
	hitboxPlayer->Draw(window);
	hitboxPlayerAll->Draw(window);
	hitboxPlayerSwordleft->Draw(window);
	hitboxPlayerSwordRight->Draw(window);
	hitboxPlayerSwordUp->Draw(window);
	hitboxPlayerSwordDown->Draw(window);
}

void Player::playerCollideEdge(Vector2f sizemap, Vector2f mapposition)
{
	if (hitboxPlayerAll->hitbox.getPosition().x <= mapposition.x+2)
	{
		canMoveL = false;
		body.move(1, 0);
	}
	if (hitboxPlayerAll->hitbox.getPosition().y <= mapposition.y+5)
	{
		canMoveUp = false;
		body.move(0, 1);
	}
	if (hitboxPlayerAll->hitbox.getPosition().x >= sizemap.x-30)
	{
		canMoveR = false;
		body.move(-1, 0);
	}
	if (hitboxPlayerAll->hitbox.getPosition().y >= sizemap.y-50)
	{
		canMoveDown = false;
		body.move(0, -1);
	}
}

