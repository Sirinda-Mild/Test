#include "Collider.h"
#include<iostream>

using namespace std;

Collider::Collider(RectangleShape& body):
	body(body)
{
}

Collider::~Collider()
{
}

bool Collider::CheckCollision(Collider other, float push)
{
	Vector2f otherPosition = other.GetPosition();
	Vector2f otherHalfSize = other.GetHalfSize();
	Vector2f thisPositon = GetPosition();
	Vector2f thisHalfSize = GetHalfSize();

	float deltaX = otherPosition.x - thisPositon.x;
	float deltaY = otherPosition.y - thisPositon.y;
	float intersectX = abs(deltaX) - (otherHalfSize.x + thisHalfSize.x -22);
	float intersectY = abs(deltaY) - (thisHalfSize.y+27);

	if (intersectX < 0.0f && intersectY < 0.0f)
	{
		push = min(max(push, 0.0f), 1.0f);

		if (intersectX > intersectY)
		{
			if (deltaX > 0.0f)
			{
				Move(intersectX * (1.0f - push), 0.0f);
				other.Move(-intersectX * push, 0.0f);
			}
			else
			{
				Move(-intersectX * (1.0f - push), 0.0f);
				other.Move(intersectX * push, 0.0f);
			}
		}
		else
		{
			if (deltaY > 0.0f)
			{
				Move(0.0f, intersectY * (1.0f - push));
				other.Move(0.0f, -intersectY * push);
			}
			else
			{
				Move(0.0f, -intersectY * (1.0f - push));
				other.Move(0.0f, intersectY * push);
			}
		}

		return true;
	}

	return false;
}
