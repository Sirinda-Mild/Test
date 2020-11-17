#pragma once
#include"SFML\System.hpp"
#include"SFML\Window.hpp"
#include"SFML\Graphics.hpp"
#include"SFML\Audio.hpp"
#include"SFML\Network.hpp"

using namespace sf;
using namespace std;

class TextDisplay
{
public:
	float textMovementSpeed = 2;
	int counter = 0;
	int LifeTime = 14;
	bool destroy = false;

	Text text;

	TextDisplay();
	~TextDisplay();

	void Update();

private:
};

