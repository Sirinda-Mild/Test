#pragma once
#include<SFML/Graphics.hpp>

using namespace sf;

class Animation
{
public:
	Animation(Texture* texture, Vector2u imageCount, float switchTime); //Constructor
	~Animation(); //Deconstructor
	void Update(int row, float deltaTime); //Function Member
public:  
	IntRect uvRect;
	Vector2u imageCount;
	Vector2u currentImage;
	float totalTime;
	float switchTime;
};