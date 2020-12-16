#include "Random.h"

int Random::generateRandom(int min, int max)
{
	int randomNumber = rand() % (max - min + 1) + min;
	int myRandom = randomNumber;
	return myRandom;
}

//int Random::generateRandom0(int max)
//{
//	int randomNumber = rand();
//	float random = (randomNumber % max);
//	int myRandom = random;
//	return myRandom;
//}
//
//bool Random::generateRandomBool()
//{
//	int randomNumber = rand();
//	float random = (randomNumber % 2) + 1;
//	int myRandom = random;
//	if (myRandom == 1) {
//		return true;
//	}
//	else {
//		return false;
//	}
//}
